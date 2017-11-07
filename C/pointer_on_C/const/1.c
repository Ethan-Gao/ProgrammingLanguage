#include <stdio.h>

int main(void){
	char a = 0x11, b = 0x22, c = 0x33, d = 0x44;
	const char *x = &a;// 限定*x不可更改,x可更改
	char const *y = &b;// 同上
	char* const z = &c;// 限定z不可更改,*x可更改
	
	printf("%x %x %x\n", *x, *y, *z);
	x = &d;printf("%x %x\n", *x, d);
//	*x = 0x12;
	x = &d;printf("%x %x\n", *y, d);
//	*x = 0x34;
	*z = 0x56;printf("%x %x\n", *z, c);
//	z = &d;
	
	return 0;
}

/*
** const指针判定:就近原则，挨哪个近则是那种类型
** 分析:
** *x、*y挨const近，所以*x、*y不可更改，但是x、y可以更改
** z挨const近，所以z不可更改，但是*z可以更改
*/