#include <iostream>

int main(void){
	int i = 0, &ri = i;
	
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;
	return 0;
}

/*
结果:
$ ./a.out
10 10
分析:
i和ri除名字不同完全相同
*/
