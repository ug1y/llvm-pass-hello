#include <stdio.h>
void func2(){
        printf("hello world\n");
}
void func(){
        func2();
}
int main(){
        func();
        return 0;
}
