#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F	"3.txt"

int main(void){
	FILE *fp = NULL;
	int flen = 0;
	char *buf = NULL, *x = "hahaha", y[20] = {0};

	// 打开文件
	fp = fopen(F, "r+");
	
	/* 读取整个文件 */
	// 获取大小
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	// 分配存储
	buf = (char *)malloc(flen * sizeof(char));
	// 读取文件
	fread(buf, sizeof(char), flen, fp);
	// 打印内容
	printf("%s\n",buf);
	
	/* 移动文件指针 */
	fseek(fp, 10, SEEK_SET);// 从起始位置偏移10个char开始写入
	fwrite(x, sizeof(char), strlen(x), fp);
	fseek(fp, 0, SEEK_SET);
	fread(y, sizeof(char), 15, fp);
	printf("%s\n", y);
	
	/* 回写所有内容 */
	fseek(fp, 0, SEEK_SET);
	fwrite(buf, sizeof(char), flen, fp);
	
	// 释放空间
	fclose(fp);
	free(buf);
	
	return 0;
}

/*
结果：
$ ./a.out
First, we will encounter the following two options, which are related to each other. These
options are here to tune the level of parallelism used by BitBake, the actual driver behind
Yocto Project.
First, we hahah
*/
