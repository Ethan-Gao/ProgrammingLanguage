#include <stdio.h>
#include <stdlib.h>

int main(void){
#define MAX(a,b) ((a)>(b)?(a):(b))
	printf("%d\n",MAX(1+3,2+5));
#define MALLOC(type,n) ( (type *)malloc((n) * sizeof(type)) )
	printf("%p\n",MALLOC(int,10));
	
	return 0;
}

/*
** 常用宏定义
** 结果：
**	$ ./a.out
**	7
**	0x19ab010
*/