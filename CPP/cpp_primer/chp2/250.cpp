#include <iostream>

int main(void){
	int a = 12, &b = a, *c = &a;
	//const &d = a;// a不是const类型,编译报错
	const int x = 11, &y = x;// x是const类型,y为其引用
	const int &z = 56;
	//int &w = 123;// 报错，常量引用没加const
	
	std::cout << "b:" << &b << " " << b << std::endl;
	std::cout << "c:" << c << " " << *c << std::endl;
	std::cout << "y:" << &y << " " << y << std::endl;
	std::cout << "z:" << &z << " " << z << std::endl;
	return 0;
}

/*
** 引用:
** 1.引用变量为原变量别名，唯一不同只有名字
** 2.const引用必须指向const对象
** 结果:
** b:0x7ffcdda87bc0 12
** c:0x7ffcdda87bc0 12
** y:0x7ffcdda87bc4 11
** z:0x7ffe7ad8a85c 56
*/
