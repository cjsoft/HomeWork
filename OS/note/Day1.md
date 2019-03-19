# Day1

##  Phase 1

首先我先搞了个十六进制编辑器。我去网上搜了一发，找到了一个叫`Hex Editor Neo`的免费软件。
他长这个样子：
![1551493733834](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551493733834.png)

先按照书上的指导编制`helloos.img`，然后解压光盘内容，尝试使用作者提供的模拟器载入这个镜像。先在`tolset`中建好文件夹并打开`!cons_nt.bat`，运行`run.bat`，提示`FATAL: Not a bootable disk`
![1551494777749](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551494777749.png)

咋回事呢？我多次对照书本检查，看起来无误。最后直接去看光盘里的`helloos.img`，发现书上只写了前70行代码中的一部分，实际上并不是完整的代码。直接使用光盘里提供的`helloos.img`，成功载入
![1551495777170](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551495777170.png)

除此之外，我还尝试了使用虚拟机程序`Oracle VM VirtualBox`直接载入`helloos.img`。我新建了一个Windows 95兼容的空虚拟机，分配软盘镜像
![1551496087608](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551496087608.png)![1551496089554](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551496089554.png)

点击启动，成功！
![1551496130570](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551496130570.png)

## Phase 2

### 无脑转成汇编

将`helloos.img`用汇编语言的`DB`指令无脑转写。
`DB`指令就是插入若干二进制数据，我们用其他语言可以写一个程序来无脑的完成`helloos.img`到`nas`的转换。

只需要读入字节并以16进制方式打印出来，中间加逗号，行首加`DB<SPACE>`即可。

### 初步缩小代码大小

使用`RESB`指令来替代连续的0

加判断，出现连续为0字节时计数，用`RESB <字节数>`替代

### 继续加工润色

我们来分析一下书上的代码

`DB`中数据的顺序与`helloos.img`相同，为什么`DW 512`对应的是`00 02`呢？这是因为`WORD`是两个字节，而我们的模拟环境/英特尔的CPU使用的是小端序，低有效字节处于低地址。

以下代码验证了`nask`使用小端序

![1551502598719](C:\Users\egwcy\AppData\Roaming\Typora\typora-user-images\1551502598719.png)

`$`这个关键字可以减少我们修改代码之后索要进行的二次修改工作

## Phase 3

小小的总结一下：借用十六进制编辑器，我们可以制作任意一个文件，精确的控制文件中的每一个bit。而汇编语言，则提供给了我们一个更方便的用十六进制组成文件方法，减少我们直接用十六进制编辑器的工作量。