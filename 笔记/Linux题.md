## Linux题

1. Which protocol is used to set the local time via Internet servers?

   使用哪个协议通过Internet服务器设置本地时间？

   > Network Time Protocol (NTP)  网络时间协议

2. Which command is used to enumerate the background processes running in the current terminal session?

   使用哪个命令枚举当前终端会话中运行的后台进程？

   > jobs

3. When did Linus Torvalds start writing the Linux kernel?

   > 1991

4. Which one of the following component actually loads Linux?

   下面哪个组件实际上加载Linux？

   > Boot loader
   >
   > 在嵌入式操作系统中，BootLeader是在操作系统内核运行之前运行。可以初始化硬件设备、建立内存空间映射图，从而将系统的硬件环境带到一个合适状态，以便为最终调用操作系统内核准备好正确的环境。在嵌入式系统中，通常并没有像BIOS那样的固件程序，因此**整个系统的加载启动任务就完全由BootLoader来完成。**
   >
   > **Bootloader是嵌入式系统在加电后执行的第一段代码**，在它完成CPU和相关硬件的初始化之后，再将操作系统映像或固化的嵌入式应用程序装在到内存中然后跳转到操作系统所在的空间，启动操作系统运行。
   >
   > **嵌入式LInux系统从软件角度通常分为四个层次：**
   >
   > 1. 引导加载程序：包括固化在固件（firmware）中的boot代码（可选），和BootLeader两大部分。
   > 2. Linux内核：特定于嵌入式板子的定制内核以及内核的启动参数。
   > 3. 文件系统：包括根文件系统和建立于Flash内存设备之上文件系统。通常用ramdisk来作为rootfs。
   > 4. 用户应用程序：特定于用户的应用程序。有时在用户应用程序和内核层之间可能还会包括一个嵌入式图形用户界面。常用的嵌入式GUI有：MicroWindows和MIniGUI等。
   >
   > 1.**自启动模式**：在这种模式下，bootloader从目标机上的某个固态存储设备上将操作系统加载到RAM中运行，整个过程并没有用户的介入。
   >
   > 2.**交互模式**：在这种模式下，目标机上的bootloader将通过串口或网络等通行手段从开发主机（Host）上下载内核映像等到RAM中。可以被bootloader写到目标机上的固态存储媒质中，或者直接进入系统的引导。也可以通过串口接收用户的命令。
   >
   > **Bootloader启动大多数都分为两个阶段。**第一阶段主要包含依赖于CPU的体系结构硬件初始化的代码，通常都用汇编语言来实现。这个阶段的任务有：
   >
   > 基本的硬件设备初始化（屏蔽所有的中断、关闭处理器内部指令/数据Cache等）。
   >
   > 为第二阶段准备RAM空间。
   >
   > 如果是从某个固态存储媒质中，则复制Bootloader的第二阶段代码到RAM。
   >
   > 设置堆栈。
   >
   > 在第一阶段中为什么要关闭Cache？通常使用Cache以及写缓冲是为了提高系统性能，但由于Cache的使用可能改变访问主存的数量、类型和时间，因此Bootloader通常是不需要的。
   >
   > 跳转到第二阶段的C程序入口点。
   >
   > 第二阶段通常用C语言完成，以便实现更复杂的功能，也使程序有更好的可读性和可移植性。这个阶段的任务有：
   >
   > 初始化本阶段要使用到的硬件设备。
   >
   > 检测系统内存映射。
   >
   > 将内核映像和根文件系统映像从Flash读到RAM。
   >
   > 为内核设置启动参数。
   >
   > 调用内核。

5. Which of the following steps initiates changing the desktop background? 

   下列步骤中的哪一个开始改变桌面背景？

   > Right-click on the desktop and select Change Desktop Background.
   >
   > 右键单击桌面并选择更改桌面背景。

6. What is a desktop environment?

   > A graphical user interface on top of the Operating System.
   >
   > 操作系统顶部的图形用户界面。
   >
   > GNOME、KDE、XFCE和FLUXBOX都是桌面环境。

7. What keyboard shortcut is used to lock the screen?

   > SUPER-L
   >
   > CTRL-ALT-L

8. What type of Linux configuration file(s) is/are used to automate the installation process?

   使用什么类型的Linux配置文件来自动化安装过程？

   > Kickstart

9. What is a command line?

   > An interface for typing commands for the Operating System to execute.
   >
   > 为操作系统键入命令以执行的接口。

10. The _____ shortcut is used to terminate(终止) a foreground process.

    > CTRL-C　(强制终止)
    >
    > (CTRL-Z　挂起)

11. What is a kernel?

    > The glue（胶水） between hardware(硬件) and applications(应用).
    >
    > **Kernel 操作系统内核** 操作系统内核是指大多数操作系统的核心部分。它由操作系统中用于管理存储器、文件、外设和系统资源的那些部分组成。操作系统内核通常运行进程，并提供进程间的通信。

12. Which of the following is a popular desktop environment and graphical user interface that runs on top of the Linux operating system?

    > GNOME
    >
    > **GNOME是一套纯粹自由的计算机软件，运行在操作系统上，提供图形桌面环境。**
    >
    > GNOME 包含了 Panel （用来启动此程式和显示目前的状态）、桌面 （应用程式和资料放置的地方）及一系列的标准桌面工具和应用程式，并且能让各个应用程式都能正常地运作。
    >
    > **项目构成**
    >
    > ATK：可达性工具包
    >
    > Bonobo：复合文档技术
    >
    > GObject：用于Ｃ语言的面向对象框架
    >
    > GConf：保存应用软件设置
    >
    > GNOME VFS：虚拟文件系统
    >
    > GNOME Keyring：安全系统
    >
    > GNOME Print：GNOME软件打印文档
    >
    > GStreamer：GNOME软件的多媒体框架
    >
    > GTK+：构件工具包
    >
    > Cairo：复杂的2D图形库
    >
    > Human Interface Guidelines：Sun微系统公司提供的使得GNOME应用软件易于使用的研究和文档
    >
    > LibXML：为GNOME设计的XML库
    >
    > ORBit：使软件组件化的CORBAORB
    >
    > Pango：i18n文本排列和变换库
    >
    > Metacity：窗口管理器
    >
    > **应用软件**
    >
    > Abiword：文字处理器
    >
    > Epiphany：网页浏览器
    >
    > Evolution：联系/安排和e-mail管理
    >
    > Gaim：即时通讯软件
    >
    > gedit：文本编辑器
    >
    > The Gimp：高级图像编辑器
    >
    > Gnumeric：电子表格软件
    >
    > GnomeMeeting：IP电话或者电话软件
    >
    > Inkscape：矢量绘图软件
    >
    > Nautilus：文件管理器
    >
    > Rhythmbox：类似Apple iTunes的音乐管理软件
    >
    > Totem：媒体播放器

13. What action saves the current state of the system in RAM? 

    什么动作在RAM中保存系统的当前状态？

    > Suspending(挂起)

14. Which of the following is responsible for starting system and network services at boot time?

    下列哪一个负责启动系统和网络服务在启动时间？

    > init
    >
    > init是Linux系统操作中不可缺少的程序之一。所谓的init进程，它是一个由内核启动的用户级进程。内核会在过去曾使用过init的几个地方查找它，它的正确位置（对Linux系统)来说）是/sbin/init。如果内核找不到init，它就会试着运行/bin/sh，如果运行失败，系统的启动也会失败。
    >
    > 内核自行启动（已经被载入内存，开始运行，并已初始化所有的设备驱动程序和数据结构等）之后，就通过启动一个用户级程序init的方式，完成引导进程。所以init始终是第一个进程（其进程编号始终为1）。

15. Assuming you are not the root user, which of the following commands would turn off the graphical desktop, depending on your specific Linux distribution Ubuntu? 

    假设您不是root用户，根据您的特定Linux发行版Ubuntu，下列哪个命令将关闭图形桌面？

    > sudo systemctl stop lightdm

16. Assuming you are the root user, which commands allow you to shut down your system without rebooting?

    假设您是root用户，哪些命令允许您在不重新启动的情况下关闭系统？

    > halt
    >
    > poweroff
    >
    > shutdown -h now

17. Which commands allow you to locate programs?

    > which
    >
    > whereis

18. Which package management utilities are used by **Ubuntu**?

    Ubuntu使用哪个包管理实用程序？

    > dpkg
    >
    > the Ubuntu Software Center

19. Whenever possible, Linux makes its components available via files. 

    Linux通过文件使其可用组件

20. In Linux all files are stored in one united directory tree, starting at "/", the system's root directory.

    在Linux中，所有文件都存储在一个联合目录树中，从“/”系统的根目录开始。

21. Processes, devices, and network sockets are all represented by file-like objects, and can often be worked with using the same utilities used for regular files.

    进程、设备和网络套接字都由类文件对象表示，并且通常可以使用与常规文件相同的实用程序来工作。

22. X Window System

    > X Window即X Window图形用户接口，是一种**计算机软件系统和网络协议**，提供了一个基础的图形用户界面（GUI）和丰富的输入设备能力联网计算机。其中软件编写使用广义的命令集，它创建了一个硬件抽象层，允许设备独立性和重用方案的任何计算机上实现。

23. BIOS

    > 基本输入输出系统
    >
    > 它是一组固化到计算机内主板上一个ROM芯片上的程序，它保存着计算机最重要的基本输入输出的程序、开机后自检程序和系统自启动程序，它可从CMOS中读写系统设置的具体信息。其主要功能是为计算机提供最底层的、最直接的硬件设置和控制。此外，BIOS还向作业系统提供一些系统参数。系统硬件的变化是由BIOS隐藏，程序使用BIOS功能而不是直接控制硬件。现代作业系统会忽略BIOS提供的抽象层并直接控制硬件组件。

24. NFS

    > **NFS（Network File System）即网络文件系统**，是FreeBSD支持的文件系统中的一种，它允许网络中的计算机之间通过TCP/IP网络共享资源。在NFS的应用中，本地NFS的客户端应用可以透明地读写位于远端NFS服务器上的文件，就像访问本地文件一样。

25. GUI

    > 图形用户界面（Graphical User Interface，简称 GUI，又称图形用户接口）是指采用图形方式显示的计算机操作用户界面。

26. GRUB

    > GNU GRUB（GRand Unified Bootloader简称“GRUB”）是一个来自GUN项目的多操作系统启动程序。GRUB是多启动规范的实现，它允许用户可以在计算机内同时拥有多个操作系统，并在计算机启动时选择希望运行的操作系统。GRUB可用于选择操作系统分区上的不同内核，也可用于向这些内核传递启动参数。

27. Identify the log file in which the sudo commands and failures are logged in by default under the Debian family:

    标识默认文件中的SDO命令和故障记录在Debian家族中的日志文件：

    > /var/log/auth.log

28. The at utility is used to execute:

    AT实用程序用于执行：

    > Non-interactive programs at a specific time
    >
    >  特定时间的非交互式程序

29. Which character is used to represent（表示） the continuation（延续） of a command over several lines?

    哪一个字符用来表示（连续）命令在多行上的延续？

    > \

30. The command tar zcvf backup.tar.gz ~ will archive(存档) which of the following in the file backup.tar.gz?

    > The user's entire home directory tree
    >
    > 用户的整个家庭目录树

31. Which command checks whether a host is online?

    > ping

32. Select the correct syntax to find the length of the string abc.

    > ${#abc}

33. Which of the following grep commands can be used to print out all of the lines that do not match the specified pattern?

    下列哪种GRIP命令可以用来打印出与指定模式不匹配的所有行？

    > grep -v [pattern] <filename>

34. Where does the shell store the command history?

    > ~/.bash_history

35. What do we call the user account possessing supreme authority over the system?

    我们怎么称呼拥有最高权限的用户帐户？

    > root

36. Which command is used to extract columns from a file to work on them later?

    哪一个命令用于从文件中提取列以稍后对它们进行处理？

    > cut

37. Which of the following configuration files shows which filesystems will be automatically mounted when the system is brought up into multi-user mode?

    下列哪个配置文件显示了当系统进入多用户模式时将自动挂载哪些文件系统？

    > /etc/fstab

38. If we want to debug the 15th line of a script, we must provide the _______ command on 14th line and the ___________command on 16th line of the script.

    > set -x, set +x

39. What information does the second line of the top output display on Linux?

    Linux上的顶级输出的第二行显示什么信息

    > stopped processes
    >
    > zombie processes(僵尸进程)

40. Which of the following are valid commands to use with ssh?

    > ssh -l haskell eddie.com
    >
    > ssh root@eddie.com yum -y update
    >
    > ssh -l haskell eddie.com whoami

41. Which of the following are command line utilities that can be used to download webpages?

    下面哪一个是可以用来下载网页的命令行实用程序？

    > wget
    >
    > curl

42. Which commands can be used to print the lines that contain the numbers 0–5 in a file?

    哪些命令可以用来打印包含文件中的数字0到5的行？

    > grep [0,1,2,3,4,5] filename
    >
    > grep [0-5] filename

43. Which of the following commands will replace all instances of the word "dog" with "pig" in the file named some_file and send the output to stdout?

    > sed -e s/dog/pig/g some_file
    >
    > sed -e s:dog:pig:g some_file
    >
    > cat some_file | sed -e s/dog/pig/g

44. Which of these are default directories available under the home directory?

    哪些目录是在主目录下可用的默认目录？

    > Documents(文件)
    >
    > Desktop(桌面)
    >
    > Downloads

45. The two commands gunzip foo and gzip -d foo do the same thing.

46. How would you change your system's hostname to HZstudent?

    > sudo hostname HZstudent

47. The /dev/null file is also known as the ____ or black hole.

    > bucket或bit bucket或垃圾桶

48. In the vim editor, which command is used to launch the tutorial?

    > vimtutor

49. Which command is used to display a line of text?

    > echo

50. 