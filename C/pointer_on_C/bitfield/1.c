#include <stdio.h>

typedef struct node{
    unsigned int a:1;      //存在一个非0位的位段，则至少占4Byte 
} S0; 

typedef struct node1{       //在C++中占1字节的空间 ，在C中占0字节 
    unsigned int :0;
} S1;

typedef struct node2{
    unsigned int a:1;
    unsigned int  :0;     //下一个位段放在一个新的位段存储单元 ，所以占4+4=8Byte 
    unsigned c:31;         
} S2;

typedef struct node3{
    unsigned int a:4;
    unsigned int  :0;
    int :6;               //这个位段放在一个新的位段存储单元 
    unsigned c:32;        //由于6+32>32，所位段c也放在一个新的位段存储单元，所以占4+4+4=12Byte 
} S3;

typedef struct node4{
    unsigned int a:1;
    char b;                //在一个位段存储单元中能够存下所有的成员，所以占4Byte 
    int c:1;// 默认signed则-1~0
    int d:2;// 默认signed则-2~1
    unsigned int e:2;// unsigned范围0~3
} S4;

typedef struct node5 {
	unsigned int a:12;
	signed int b:12;
	int c:9;// 1个int存不下，c将会放到下一个int
} S5;

int main(void){
    S4 s4 = {1, 0, 1, 2, 4};
    printf("%d %d %d %d\n",s4.a,s4.c,s4.d,s4.e);
    printf("%d %d %d %d %d %d\n",sizeof(S0),sizeof(S1),sizeof(S2),sizeof(S3),sizeof(S4),sizeof(S5));
    return 0;
}

/*
<一>结果
1 -1 -2 0
4 0 8 12 4 8
<二>位段使用
参考: http://www.cnblogs.com/dolphin0520/archive/2011/10/14/2212590.html
注意事项
1.位段的类型只能是int、unsigned int、signed int三种类型，通常int默认为signed
2.位段占用位数不能超过该类型最大位数，例如int为32则最多只能32位
3.对位段赋值时，若超过最大范围会造成溢出
5.若位段占位数为0，则其为无名位段，下一个位段从下一个位段存储单元
空间占用
1.按存储位数取整，无法容纳则自动拓展到下一单元，比如33bit则会把多出部分放到第二个int
2.若位段含有位数为0无名位段，则只占1或0字节的空间(C语言中是占0字节，而C++中占1字节)
*/