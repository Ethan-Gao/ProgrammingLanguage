#include <stdio.h>

#define X	123
#define Y

int main(void){
	/* 1 */
	printf("file=%s line=%d date=%s time=%s stdc=%d\n",__FILE__, __LINE__, __DATE__, __TIME__, __STDC__);
	
	/* 2 */
#if X == 123
#define PTK(str) 	printf("%s\n",str)
#else
#define PTK(str)
#endif	
	PTK("hello world");
	
	/* 3 */
#ifdef Y
#define Z(x)	(x)*(x)
	printf("Y defined,Z(4)=%d\n",Z(4));
#endif

	return 0;
}
