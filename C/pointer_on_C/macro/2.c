#include <stdio.h>

int main(void){
#define F1(x)	x*x
#define F2(x)	(x)*(x)
	printf("%d %d\n", F1(2), F1(2+1));
	printf("%d %d\n", F2(2), F2(2+1));
	
#define F3(x)	x+x	
#define F4(x)	(x)+(x)	
#define F5(x)	((x)+(x))	
	printf("%d %d\n", F3(2), 10*F3(2+1));
	printf("%d %d\n", F4(2), 10*F4(2+1));
	printf("%d %d\n", F5(2), 10*F5(2+1));
	
#define PRINT1(FORMAT,VALUE)	printf("The value is "FORMAT"\n",VALUE)
#define PRINT2(FORMAT,VALUE)	printf("The value if "#VALUE" is "FORMAT"\n",VALUE)
	PRINT1("%d",12);
	int x = 34;
	PRINT2("%d",x+3);

#define ADD_TO_SUM(sum_number,value)	sum##sum_number += value
	int sum5 = 56;
	ADD_TO_SUM(5,25);// 等效于sum5 += 25
	printf("%d\n",sum5);
	
	return 0;
}

/*
** 特别注意：
** 1.宏只会做简单替换，不会进行任何实际操作(比如计算值)
** 2.所有用于对数值表达式进行求值的宏定义都应加上括号
** 3.宏插入字符串常量有两种方式:参考PRINT1和PRINT2
** 4.##用于连接符，表示将左右合并
** 结果：
**	$ ./a.out
**	4 5
**	4 9
**	4 24
**	4 33
**	4 60
**	The value is 12
**	The value if x+3 is 37
**	81
*/
