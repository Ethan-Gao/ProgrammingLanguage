#include <stdio.h>

int main(void){
	/* 定义 */
	int a = 0, b = 123, c = 234;
	int w1[3] = {1, 2, 3}, (*w)[3] = &w1;// 数组指针
	int *x0 = &a, *x1 = &b, *x2 = &c, *x[3] = {x0, x1, x2};// 指针数组
	int (*y)(void) = main;// 函数指针
	int *z(int val){return (int *)0x1234;}// 指针函数
	/* 打印 */
	printf("w=%p w1=%p *w=%p (*w)[1]=%d\n",w,w1,*w,(*w)[1]);
	printf("x1=%p x[1]=%p *x[1]=%d\n",x1,x[1],*x[1]);
	printf("main=%p y=%p\n",main,y);
	printf("z_return=%p\n",z(1));
	return 0;
}

/*
  Q: 如何判断指针数组、数组指针、函数指针、指针函数
  A: 1.根据优先级判断，例如(*a)[10]由于()优先级高于[]，所以指针，合起来数组指针
     2.linux下面可以使用cdecl解释，如下> explain int (*a)[10];

  结果:
	w=0x7ffcfe869b00 w1=0x7ffcfe869b00 *w=0x7ffcfe869b00 (*w)[1]=2
	x1=0x7ffcfe869ad0 x[1]=0x7ffcfe869ad0 *x[1]=123
	main=0x40053b y=0x40053b
	z_return=0x1234
*/
