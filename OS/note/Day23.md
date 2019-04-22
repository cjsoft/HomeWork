# Day 23

![1555826349790](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555826349790.png)

这个是我们之前实验当中winhelo程序的详细信息，可以看到这个文件达到了惊人的7.48KB大小。使用二进制查看器

![1555826896762](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555826896762.png)

可以看到这个文件当中有大量的00，这显然有很多是没有用的。这些0是哪里来的呢？

原因在于winhelo2.c的`char buf[150 * 50]; `这相当于在可执行文件中插入了150×50＝7500个字节的00。

如果我们的操作系统可以在运行的时候动态给程序分配内存的话就好了。我们仿照c语言的命名，把这个api叫做malloc。

api_malloc

malloc不可以直接调用操作系统的memman_malloc，这是因为mamman_malloc分配的空间是在系统段当中，应用程序是无法访问这个区域的。

作者给出了一个什么样的解决方案呢？应用程序提前指定好自己会使用的最大内存量，提前给他准备好，当应用程序请求分配内存的时候就从这段内存当中拿出来一部分给他就好了。

在哪里给定这样的值呢？作者写的bim2hrb工具接受的第三个参数可以进行指定

```makefile
$(BIM2HRB) <filename>.bim <filename>.hrb <预存空间大小>
```

而这个指定的参数，则保存在hrb文件的0x0020处



mamman设计

初始化api

<table><tr><td>EDX</td><td>8</td></tr>
<tr><td>EBX</td><td>memman的地址</td></tr>
<tr><td>EAX</td><td>memman所管理的内存空间的起始地址</td></tr>
<tr><td>ECX</td><td>memman所管理的内存空间的字节数</td></tr></table>

分配api

<table><tr><td>EDX</td><td>9</td></tr>
<tr><td>EBX</td><td>memman的地址</td></tr>
<tr><td>ECX</td><td>需要请求的字节数</td></tr>
<tr><td>EAX</td><td>分配到的内存空间地址</td></tr></table>

释放api

<table><tr><td>EDX</td><td>10</td></tr>
<tr><td>EBX</td><td>memman的地址</td></tr>
<tr><td>EAX</td><td>需要释放的内存空间地址</td></tr>
<tr><td>ECX</td><td>需要释放的字节数</td></tr></table>



hrb_api修改的部分

```c
else if (edx == 8) {
    memman_init((struct MEMMAN *) (ebx + ds_base));
    ecx &= 0xfffffff0; /*以16字节为单位*/
    memman_free((struct MEMMAN *) (ebx + ds_base), eax, ecx);
} else if (edx == 9) {
    ecx = (ecx + 0x0f) & 0xfffffff0; /*以16字节为单位进位取整*/
    reg[7] = memman_alloc((struct MEMMAN *) (ebx + ds_base), ecx);
} else if (edx == 10) {
    ecx = (ecx + 0x0f) & 0xfffffff0; /*以16字节为单位进位取整*/
    memman_free((struct MEMMAN *) (ebx + ds_base), eax, ecx);
}
```

![1555835261489](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555835261489.png)

再整个画点的

<table><tr><td>EDX </td><td>11</td></tr>
<tr><td>EBX </td><td>窗口句柄</td></tr>
<tr><td>ESI </td><td>显示位置的x坐标</td></tr>
<tr><td>EDI </td><td>显示位置的y坐标</td></tr>
<tr><td>EAX </td><td>色号</td></tr>
</table>

```c
} else if (edx == 11) {
    sht = (struct SHEET *) ebx;
    sht->buf[sht->bxsize * edi + esi] = eax;
    sheet_refresh(sht, esi, edi, esi + 1, edi + 1);
}
```

测试程序

```c
void HariMain(void)
{
	char *buf;
	int win, y, x;
	api_initmalloc();
	buf = api_malloc(150 * 100);
	win = api_openwin(buf, 150, 100, -1, "star1");
	api_boxfilwin(win,  6, 26, 143, 93, 0 /* 黒 */);
	for (y = 26; y <= 93; y += 2) {
        for (x = 6; x <= 143; x += 2) {
            api_point(win, x, y, 3);
        }
    }
	api_end();
}
```



![1555839539059](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555839539059.png)

 我们发现，每次画点都会进行一次窗体刷新。这种做法效率是很低的，因为我们每次更新一个像素点，却要重新绘制整个窗口区域。可以考虑接受一个参数，从而决定是否在画点之后进行窗体刷新，并且设计一个新的刷新窗口的API

<table><tr><td>EDX </td><td> 12</td></tr>
<tr><td>EBX </td><td> 窗口句柄</td></tr>
<tr><td>EAX </td><td> x0</td></tr>
<tr><td>ECX </td><td> y0</td></tr>
<tr><td>ESI </td><td> x1</td></tr>
<tr><td>EDI </td><td> y1</td></tr></table>



```c
else if (edx == 11) {
    if ((ebx & 1) == 0) {
        sht->buf[((struct SHEET *)(ebx))->bxsize * edi + esi] = eax;
        sheet_refresh((struct SHEET *)(ebx), esi, edi, esi + 1, edi + 1);
    } else {
        sht->buf[((struct SHEET *)(ebx ^ 1))->bxsize * edi + esi] = eax;
        sheet_refresh((struct SHEET *)(ebx ^ 1), esi, edi, esi + 1, edi + 1);
    }
} else if (edx == 12) {
    sht = (struct SHEET *) ebx;
    sheet_refresh(sht, eax, ecx, esi, edi);
}
```

为了节省参数，可以把这个信息融入到窗口句柄中。struct SHEET的地址一定是一个偶数，那
么我们可以让程序在指定一个奇数（即在原来的数值上加1）的情况下不进行自动刷新。

```c
void HariMain(void)
{
	char *buf;
	int win, y, x;
	api_initmalloc();
	buf = api_malloc(150 * 100);
	win = api_openwin(buf, 150, 100, -1, "star1");
	api_boxfilwin(win,  6, 26, 143, 93, 0 /* 黒 */);
	for (y = 26; y <= 93; y += 2) {
        for (x = 6; x <= 143; x += 2) {
            api_point(win, x, y, 3);
        }
    }
    api_refreshwin(win, 6, 26, 144, 94);
	api_end();
}
```

运行正常



画直线

<table><tr><td>EDX </td><td> 13</td></tr>
<tr><td>EBX </td><td> 窗口句柄</td></tr>
<tr><td>EAX </td><td> x0</td></tr>
<tr><td>ECX </td><td> y0</td></tr>
<tr><td>ESI </td><td> x1</td></tr>
<tr><td>EDI </td><td> y1</td></tr>
<tr><td>EBP </td><td> 色号</td></tr></table>

```c
} else if (edx == 13) {
    sht = (struct SHEET *) (ebx & 0xfffffffe);
    hrb_api_linewin(sht, eax, ecx, esi, edi, ebp);
    if ((ebx & 1) == 0) {
        sheet_refresh(sht, eax, ecx, esi + 1, edi + 1);
    }
}
```

```c
void hrb_api_linewin(struct SHEET *sht, int x0, int y0, int x1, int y1, int col)
{
    int i, x, y, len, dx, dy;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0 << 10;
    y = y0 << 10;
    if (dx < 0) {
        dx = - dx;
    }
    if (dy < 0) {
        dy = - dy;
    }
    if (dx >= dy) {
        len = dx + 1;
        if (x0 > x1) {
            dx = -1024;
        } else {
            dx = 1024;
        }
        if (y0 <= y1) {
            dy = ((y1 - y0 + 1) << 10) / len;
        } else {
            dy = ((y1 - y0 - 1) << 10) / len;
        }
    } else {
        len = dy + 1;
        if (y0 > y1) {
            dy = -1024;
        } else {
            dy = 1024;
        }
        if (x0 <= x1) {
            dx = ((x1 - x0 + 1) << 10) / len;
        } else {
            dx = ((x1 - x0 - 1) << 10) / len;
        }
    }
    for (i = 0; i < len; i++) {
        sht->buf[(y >> 10) * sht->bxsize + (x >> 10)] = col;
        x += dx;
        y += dy;
    }
    return;
}
```

```c
int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);
void api_initmalloc(void);
char *api_malloc(int size);
void api_refreshwin(int win, int x0, int y0, int x1, int y1);
void api_linewin(int win, int x0, int y0, int x1, int y1, int col);
void api_end(void);
void HariMain(void)
{
    char *buf;
    int win, i;
    api_initmalloc();
    buf = api_malloc(160 * 100);
    win = api_openwin(buf, 160, 100, -1, "lines");
    for (i = 0; i < 8; i++) {
        api_linewin(win + 1, 8, 26, 77, i * 9 + 26, i);
        api_linewin(win + 1, 88, 26, i * 9 + 88, 89, i);
    }
    api_refreshwin(win, 6, 26, 154, 90);
    api_end();
}
```

略去了汇编语言的部分QAQ

![1555859045468](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555859045468.png)

关闭窗口

应用程序结束以后，窗口也应当清除

<table><tr><td>EDX</td><td>14</td></tr>
<tr><td>EBX</td><td>窗口句柄</td></tr></table>

```c
} else if (edx == 14) {
	sheet_free((struct SHEET *) ebx);
}
```

```c
void HariMain(void)
{
    char *buf;
    int win, i;
    api_initmalloc();
    buf = api_malloc(160 * 100);
    win = api_openwin(buf, 160, 100, -1, "lines");
    for (i = 0; i < 8; i++) {
        api_linewin(win + 1, 8, 26, 77, i * 9 + 26, i);
        api_linewin(win + 1, 88, 26, i * 9 + 88, 89, i);
    }
    api_refreshwin(win, 6, 26, 154, 90);
    api_closewin(win); /*这里！ */
    api_end();
}
```

![1555859269198](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555859269198.png)





键盘输入

<table><tr><td>EDX </td><td> 15</td></tr>
<tr><td rowspan="2">EAX </td><td> 0……没有键盘输入时返回1，不休眠</td></tr>
<tr><td> 1……休眠直到发生键盘输入</td></tr>
<tr><td>EAX </td><td> 输入的字符编码</td></tr></table>

```c
else if (edx == 15) {
    for (;;) {
        io_cli();
        if (fifo32_status(&task->fifo) == 0) {
            if (eax != 0) {
                task_sleep(task); /* FIFO为空，休眠并等待*/
            } else {
                io_sti();
                reg[7] = -1;
                return 0;
            }
        }
        i = fifo32_get(&task->fifo);
        io_sti();
        if (i <= 1) { /*光标用定时器*/
            /*应用程序运行时不需要显示光标，因此总是将下次显示用的值置为1*/
            timer_init(cons->timer, &task->fifo, 1); /*下次置为1*/
            timer_settime(cons->timer, 50);
        }
        if (i == 2) { /*光标ON */
            cons->cur_c = COL8_FFFFFF;
        }
        if (i == 3) { /*光标OFF */
            cons->cur_c = -1;
        }
        if (256 <= i && i <= 511) { /*键盘数据（通过任务A）*/
            reg[7] = i - 256;
            return 0;
        }
    }
}
```

我们将定时器放入了console当中

```c
void api_closewin(int win);
int api_getkey(int mode);
void api_end(void);
void HariMain(void)
{
    （中略）
        api_refreshwin(win, 6, 26, 154, 90);
    for (;;) {
        if (api_getkey(1) == 0x0a) {
            break;
        }
    }
    api_closewin(win);
    api_end();
}
```

我们等待回车键，回车键按下后再结束程序。



对了。如果用的是<kbd>Shift</kbd>+<kbd>F1</kbd>结束程序的话，窗口还是不会自动消失，这不够好。我们可以在sheet中添加一个task字段，里面写了它对应的应用程序。我们结束程序的时候检测以下所有sheet，如果有属于这个应用程序的sheet，那么我们就把它free掉。

![1555860456773](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1555860456773.png)