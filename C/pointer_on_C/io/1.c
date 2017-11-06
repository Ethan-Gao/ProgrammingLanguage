#include <stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
	FILE *fp = NULL;
	
	fp = fopen(argv[1],"r+");
	// 打印执行结果
	perror("fopen");
	// 出错则终止执行
	if(fp == NULL){
		printf("File doesn't exist\n");
		exit(EXIT_FAILURE);
	}
	printf("File exist\n");
	
	return 0;
}

/*
** 结果：
** $ ./a.out
** fopen: Bad address
** File doesn't exist
** $ ./a.out README
** fopen: Success
** File exist
** $ ./a.out 123.txt
** fopen: No such file or directory
** File doesn't exist
*/
