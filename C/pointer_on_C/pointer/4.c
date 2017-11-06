#include <stdio.h>
#include <stdlib.h>

// "hello world"为字符串常量，储存于只读数据段，函数退出不会被回收
char *f1(void){  
    char *p = "hello world";   
    return p;   
}

// "hello world"存储于栈区，函数退出内存被释放，很可能失败，不推荐使用
char *f2(void){   
    char p[] = "hello world";
    return p;   
}

// static指针存在于整个程序运行期间，知道退出，函数结束不会释放内存
char *f3(void){   
    static char p[] = "hello world";   
    return p;   
}

// 自动或静态局部变量，只是返回值，并未返回地址，不会导致错误
int f4(void){
	int a = 234;
	return a;
}

// 局部自动变量，函数退出，内存被释放，&a为地址变成野指针
char *f5(void){
	char a = '#';
	return &a;
} 

// 局部静态变量，存在于整个程序的生命周期，知道整个程序结束
char *f6(void){
	static char a = '#';
	return &a;
}

// malloc分配内存由用户决定声明周期，函数退出不会释放内存
char *f7(void){
	char *p = (char *)malloc(sizeof(char));  
	return p;
}

int main(void){
	char *p = NULL;
	
	printf("%d\n",f4());
	p = f2();
	printf("%p %s\n",p,p);
	return 0;
}

/*
** 详细参考：
** http://blog.csdn.net/u012317833/article/details/40779297
** http://blog.csdn.net/kai8wei/article/details/44699493
** <<C和指针>>第18章：运行时环境
*/