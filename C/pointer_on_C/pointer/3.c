#include <stdio.h>
#include <stdlib.h>

void f0(char *p){
	p = (char *)0x5678;
	printf("p=%p\n",p);
}

// 字符串常量,不常用
void f1(void){
	printf("%p %p\n", "xyz", "xyz"+1);
	printf("%c %c %c\n", *"xyz", "xyz"[2], *("xyz"+1));
}

// 字符串常量,传值调用
void f2(char *p){
	char tmp = 0;
	
	printf("exchange: %c with %c\n", *p, *(p+1));
	tmp = *p;
	*p = *(p+1);
	*(p+1) = tmp;
}

int main(void){
	char *x = (char *)0x1234, y[] = "world", *z = "hello";
	
	f0(x);printf("x=%p\n",x);// 传值调用
	f1();
	f2(y);printf("%s\n",y);// 正常
	f2(z);printf("%s\n",z);// x只读，拷贝只读无法修改，导致段错误
	return 0;
}

/*
** 说明：
** 1.f0由于只是传值调用，所以无法修改p，若想修改必须传入&x
** 2.y存储于只读区，只读不可写，修改导致断错误；z存在于栈区，修改不会出错
** 结果：
**	$ ./3.elf
**	p=0x5678
**	x=0x1234
**	0x4007fa 0x4007fb
**	x z y
**	exchange: h with e
**	Segmentation fault (core dumped)
*/