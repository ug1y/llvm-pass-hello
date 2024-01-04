#include "llvm/Pass.h" //添加头文件
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;  //使用 llvm 命名空间

namespace {   // 定义匿名命名空间
    struct HelloPass : public FunctionPass { // 定义 HelloPass 继承 FunctionPass
        static char ID;
        HelloPass() : FunctionPass(ID) {}

	bool runOnFunction(Function &F) override { // 重载 runOnFunction 函数，接受Function类型参数
	    errs() << "Hello: ";
	    errs().write_escaped(F.getName()) << '\n'; // 输出函数名
	    return false; // 没有修改 F，因此返回 false
	}
    };
}

char HelloPass::ID = 0; //id ，随便指定一个数字就可以

static RegisterPass<HelloPass> X("hello", "Hello World Pass"); // 注册Pass通过`opt -hello`运行

static void registerMyPass(const PassManagerBuilder &,
                           legacy::PassManagerBase &PM) {
    PM.add(new HelloPass()); // PM 用于添加 Pass
}
static RegisterStandardPasses
    RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                   registerMyPass); // 第一个参数表示加载的时间，枚举值，第二个参数是函数指针

