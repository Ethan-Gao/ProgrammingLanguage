#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

// 处理函数
int parse_arg(int argc, char **argv);
void process(char **argv);

// 选项标志
int option_a = FALSE, option_b = FALSE, option_c = FALSE, option_d = FALSE;

int parse_arg(int argc, char **argv){
	// 判断参数个数
	if(argc == 1){
		printf("arg error\n");
		return -1;
	}
	// 处理横杠
	while( ( *(++argv) != NULL ) && ( **argv != '-') );
	// 处理横杠后面的字母
	(*argv)++;
	while(**argv != '\0'){
		switch( **argv ){
			case 'a':
				option_a = TRUE;
				break;
			case 'b':
				option_b = TRUE;
				break;
			case 'c':
				option_c = TRUE;
				break;
			case 'd':
				option_d = TRUE;
				break;
		}
		(*argv)++;
	}	
	return 0;
}

void process(char **argv){
	int x = 0, y = 0;
	
	x = atoi(*(argv+2));y = atoi(*(argv+3));
	if(option_a) printf("%d+%d=%d\n",x,y,x+y);
	if(option_b) printf("%d-%d=%d\n",x,y,x-y);
	if(option_c) printf("%d*%d=%d\n",x,y,x*y);
	if(option_d) printf("%d/%d=%d\n",x,y,x/y);
}

int main(int argc, char **argv){
	// 判断参数
	if( parse_arg(argc, argv) == -1 ) return 1;
	// 处理任务
	process(argv);
	
	return 0;
}

/*
** 测试：./a.out -abc 8 4
** 结果：
**	8+4=12
**	8-4=4
**	8*4=32
*/