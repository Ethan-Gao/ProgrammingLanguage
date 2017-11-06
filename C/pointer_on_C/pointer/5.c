#include <stdio.h>

int main(void){
	char x[10], *y[10], **z = y;
	printf("x=%p &x[0]=%p\n",x,&x[0]);
	printf("y=%p &y[0]=%p\n",y,&y[0]);
	printf("z=%p z+1=%p &y[1]=%p\n",z,z+1,&y[1]);
	
	return 0;
}

/*
** 数组名无论何时都代表数组首元素地址，即char x[10]则x=&x[0]，拓展到
** 其他类型数组同样适用，比如指针数组char *x[10]则x=&x[0]
*/