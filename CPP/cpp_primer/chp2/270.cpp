#include <iostream>

int main(void){
	// 方式1
#define TRUE1	1
#define FALSE1	0
	std::cout << TRUE1 << " " << FALSE1 << std::endl;
	// 方式2
	const int TRUE2 = 3;
	const int FALSE2 = 4;
	std::cout << TRUE2 << " " << FALSE2 << std::endl;
	// 方式3
	enum _X_ {TRUE3 = 5, FALSE3 = 6};
	std::cout << TRUE3 << " " << FALSE3 << std::endl;
	return 0;
}
