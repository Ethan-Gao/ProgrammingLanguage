#include <stdio.h>

int f1(int a, int b){return a+b;}

typedef int (*CB)(int a, int b);// 定义回调接口
int f2(int a, int b){return a+b;}// 定义回调函数
void f2_x(int a, int b, int (*f)(int,int)){// 回调方式1：函数指针
	printf("f2_x: %d+%d=%d\n",a,b,f(a,b));// 此处写作(*f)(a,b)和f(a,b)意义相同
}
void f2_y(int a, int b, CB f){// 回调方式2：名字
	printf("f2_y: %d+%d=%d\n",a,b,f(a,b));
}

enum {
	ADD = 0, SUB = 1, MUL = 2, DIV = 3,
};
int f3_add(int a, int b){return a+b;}
int f3_sub(int a, int b){return a-b;}
int f3_mul(int a, int b){return a*b;}
int f3_div(int a, int b){return a/b;}

int main(void){
	int value = 0, a = 0, b = 0;
	
	/* 函数指针 */
	int (*x)(int, int) = f1;
	printf("1+2=%d\n",x(1,2));
	/* 回调函数 */
	f2_x(3,4,f2);
	f2_y(5,6,f2);
	/* 转移表 */
	int (*f3[4])(int, int) = {f3_add, f3_sub, f3_mul, f3_div};
	while(1){
		printf("0-add 1-sub 2-mul 3-div 4-exit \n");
		scanf("%d", &value);
		if( value == 4 ) return 0;
		else {
			scanf("%d %d", &a, &b);
			printf("value=%d a=%d b=%d ops=%d\n",value, a, b, (f3[value])(a, b));			
		}
	}
	return 0;
}

/*
  1.回调函数：定义回调函数、定义回调方式
  2.转移表：定义函数指针，初始化为相同类型的函数，然后调用
  3.结果：
	1+2=3
	f2_x: 3+4=7
	f2_y: 5+6=11
	0-add 1-sub 2-mul 3-div 4-exit
	0
	1
	5
	value=0 a=1 b=5 ops=6
	0-add 1-sub 2-mul 3-div 4-exit
	3
	9
	3
	value=3 a=9 b=3 ops=3
	0-add 1-sub 2-mul 3-div 4-exit
	4
*/