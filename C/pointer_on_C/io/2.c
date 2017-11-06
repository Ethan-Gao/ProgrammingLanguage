#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F1	"2_1.txt"
#define F2	"2_2.txt"
#define F3	"2_3.txt"

void pabort(const char *s){
	perror(s);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
	FILE *fp = NULL;
	char x[100] = {0}, *y = "#include <stdio.h>", \
		*z = "this is just for test";
	
	// 写F1
	printf("1.writing %s...\n", F1);
	fp = fopen(F1, "w");if(fp == NULL) pabort("fopen");
	fwrite(y, sizeof(char), strlen(y), fp);
	fclose(fp);
	system("cat 2_1.txt\n");
	
	// 读F2
	printf("2.reading %s...\n", F2);
	fp = fopen(F2, "r");if(fp == NULL) pabort("fopen");
	fread(x, sizeof(char), 20, fp);
	fclose(fp);
	printf("%s\n",x);
	
	// 先写在读F3
	printf("3.first writing then reading %s...\n", F3);
	fp = fopen(F3, "w+");if(fp == NULL) pabort("fopen");
	fwrite(z, sizeof(char), strlen(z), fp);
	fseek(fp, 0, SEEK_SET);// 移动文件指针到起始位置
	fread(x, sizeof(char), strlen(z), fp);
	fclose(fp);	
	printf("%s\n",x);
	
	system("rm 2_1.txt 2_3.txt");
	
	return 0;
}

/*
** 说明：
** 1.fopen打开方式有
**	r r+ 只读、可读可写(起始位置开始写入)
**	w w+ 只写、可读可写(没有文件则创建，存在则被覆盖，起始位置开始写入)
**	a a+ 文件末尾写入
** 2.fseek用于在移动文件指针，主要有三个SEEK_SET,SEEK_END,SEEK_CUR
** 结果：
** $ ./a.out
** 1.writing 2_1.txt...
** #include <stdio.h>2.reading 2_2.txt...
** The build_bbb argume
** 3.first writing then reading 2_3.txt...
** this is just for test
*/
