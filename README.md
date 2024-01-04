# llvm-pass-hello

A simple Hello World for LLVM pass

关于llvm是什么，pass如何编写，推荐学习[LLVM Pass入门导引](https://zhuanlan.zhihu.com/p/122522485)。

## Requirement:

- Ubuntu 22.04
- LLVM 13
- clang 13

在Ubuntu系统里使用脚本安装llvm全套组件。
```bash
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 13 all
```

## Build

把仓库clone到本地，进入到`llvm-hello-pass`目录下，新建build目录并编译。
```bash
git clone https://github.com/ug1y/llvm-pass-hello.git
cd llvm-pass-hello
mkdir build
cd build
cmake ..
make
```

本仓库参考了[llvm-pass-skeleton](https://github.com/sampsyo/llvm-pass-skeleton)项目，基本结构都是一样，但是这个项目的pass我没有实验成功，所以才写了这个项目。

## Test

