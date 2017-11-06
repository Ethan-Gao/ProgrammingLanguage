#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	/* 整数转字符串,使用sprintf */
    // 整数转十进制字符串
    char str[10];
    int a=1234321;
    sprintf(str,"%d",a);
    // 小数转十进制字符串 
    char str1[10];
    double b=123.321;
    sprintf(str1,"%.3lf",b);
    // 十进制整数转十六进制字符串
    char str2[10];
    int c=175;
    sprintf(str2,"%x",c);
	// 打印结果
	printf("%s %s %s\n", str, str1, str2);
    
    /* 字符串转数字,使用sscanf */
    //字符串转整数 
    char str3[]="1234321";
    int d;
    sscanf(str3,"%d",&d); 
    //字符串转小数
    char str4[]="123.321";
    double e;
    sscanf(str4,"%lf",&e);
    //十六进制字符串转十进制整数
    char str5[]="AF";
    int f;
    sscanf(str5,"%x",&f); 
	// 打印结果
	printf("%d %lf %d\n", d, e, f);
}

/*
结果：
$ ./a.out
1234321 123.321 af
1234321 123.321000 175
*/