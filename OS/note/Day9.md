# Day 9

## Phase 1

整理源文件，将键盘鼠标的处理函数和中断处理函数分别移动到新建的`keyboard.c`和`mouse.c`中

不要忘记对`Makefile`进行修改

## Phase 2

内存容量检查



### SubPhase 1

检查CPU是否是486以上的型号

> 感觉这个好老啊，虚拟机应该都是模拟486以上的CPU吧

检测原理是设置eflags的AC位，由于386没有AC位，所以设置AC位之后再次读取eflags，AC位还会是0

```c
#define EFLAGS_AC_BIT 0x00040000
char is486 = 0;
unsigned int eflg;
eflg = io_load_eflags();
eflg |= EFLAGS_AC_BIT;
io_store_eflags(eflg);
eflg = io_load_eflags();
if (eflg & EFLAGS_AC_BIT) is486 = 1;
```

### SubPhase 2

关闭缓存

```c
if (is486) {
	cr0 = load_cr0();
	cr0 |= CR0_CACHE_DISABLE; /* 禁止缓存 */
	store_cr0(cr0);
}
```

允许缓存

```c
if (is486) {
    cr0 = load_cr0();
    cr0 &= ~CR0_CACHE_DISABLE; /* 允许缓存 */
    store_cr0(cr0);
}
```

注意cr0寄存器不是c语言能够直接读写的，所以我们需要增加一个naskfunc，由于没啥特别的地方，这里就不体现代码了

### SubPhase 3

在关闭缓存后，我们可以开始测试内存的大小了。具体原理是先读一个内存位值，然后经过多次修改存取，如果有一次结果不符合预期，则说明这个内存位置不可用，否则说明这个内存位置可用，则这个位置之前的内存也可用。