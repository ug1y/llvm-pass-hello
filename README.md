# llvm-pass-hello

A simple Hello World for LLVM pass

关于llvm是什么，pass如何编写，推荐学习[LLVM Pass入门导引](https://zhuanlan.zhihu.com/p/122522485)。

## 依赖

- Ubuntu 22.04
- LLVM 13
- Clang 13

在Ubuntu系统里使用脚本安装llvm全套组件。
```bash
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 13 all
export CC=clang-13
export CXX=clang++-13
```

## 构建

把项目clone到本地，进入到`llvm-hello-pass`目录下，新建`build`目录并编译。
```bash
git clone https://github.com/ug1y/llvm-pass-hello.git
cd llvm-pass-hello
mkdir build
cd build
cmake ..
make
```

编译成功后会生成库文件`build/hello/libHelloPass.so`，本项目参考了[llvm-pass-skeleton](https://github.com/sampsyo/llvm-pass-skeleton)项目，源码结构是一样，但是这个项目的pass我没有通过。

## 测试

在源码`hello/Hello.cpp`文件中注册了两种pass，一种是通过`opt`运行，另一种是注册pass manager通过`clang`运行，关于如何运行编写好的pass，可以阅读这篇[LLVM入门教程至Pass编写](https://blog.yuuoniy.cn/posts/llvm-pass-1/)。

首先，可以通过`opt`的`-load`选项动态加载库文件，并使用`-help`命令查看编写的pass。
```bash
opt-13 -load build/hello/libHelloPass.so -help | grep hello
```

然后，编写一个测试程序`test.c`，并将其编译成LLVM IR。
```bash
clang-13 -c -emit-llvm test.c
```

由于编写的pass仍然使用旧版的pass manger，所以在使用`opt`运行时需要加上`-enable-new-pm=0`选项，详情可以浏览一下[网上论坛](https://groups.google.com/g/llvm-dev/c/kQYV9dCAfSg)。运行pass的命令如下：
```bash
opt-13 -enable-new-pm=0 -load build/hello/libHelloPass.so -hello test.bc -o /dev/null
```

运行结果：
```bash
Hello: func2
Hello: func
Hello: main
```