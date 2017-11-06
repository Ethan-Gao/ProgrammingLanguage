#include <stdio.h>

// 打印参数1
void f1(int argc, char **argv){
	int i = 0;
	
	printf("f1...\n");
	for(i = 0; i < argc; i++)
		printf("%d-%s ", i, argv[i]);
	printf("\n");
}

// 打印参数2
void f2(int argc, char **argv){
	printf("f2...\n");
	while(*argv != NULL){
		printf("%s ",*argv);
		argv++;
	}
	printf("\n");
}

// 打印地址关系
void f3(int argc, char **argv){
	printf("f3...\n");
	argv++;
	printf("[1]:argv=%p,*argv=%s [2]:(argv+1)=%p,*(argv+1)=%s\n",argv,*argv,argv+1,*(argv+1));
	printf("[1]:*argv=%p,**argv=%c [2]:(*argv)+1=%p,*((*argv)+1)=%c\n",*argv,**argv,(*argv)+1,*((*argv)+1));
}

int main(int argc, char **argv){
	f1(argc,argv);
	f2(argc,argv);
	f3(argc,argv);
	return 0;
}

/*
** 说明：
** argv为指向char*这块区域的指针，所以argv+1是以char*为单位移动，而非1
** (*argv)为指向char类型指针，因此(*argv)+1地址会增1
** 结果：
**	$ ./1.elf hello world // 此处argv[1]指向hello,因此argv[1][0]=h,[1][1]=e,[1][2]=l,..
**	f1...
**	0-./1.elf 1-hello 2-world
**	f2...
**	./1.elf hello world
**	f3...
**	[1]:argv=0x7ffc9dc95ef0,*argv=hello [2]:(argv+1)=0x7ffc9dc95ef8,*(argv+1)=world
**	[1]:*argv=0x7ffc9dc9782b,**argv=h [2]:(*argv)+1=0x7ffc9dc9782c,*((*argv)+1)=e
*/