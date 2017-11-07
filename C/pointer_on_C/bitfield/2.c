#include <stdio.h>

typedef struct _X_ {
	unsigned int a:4;// 4位,0~15
	signed int b:5;// 5位,-16~15
	int c:6;// 6位,-32~31
} X;

int main(void){
	X x = {1, 3, 7}, y = {16, 16, 32};
	printf("%d %d %d\n", x.a, x.b, x.c);
	printf("%d %d %d\n", y.a, y.b, y.c);
	return 0;
}

/*
<一>结果
$ ./a.out
4 1 3 7
4 0 -16 -32
分析:
a为unsigned int型，范围0~15，16溢出从0开始
b为signed int型，范围-16~15，16溢出变为-16
c为int型默认signed，范围-32~31，32溢出变为-32
*/