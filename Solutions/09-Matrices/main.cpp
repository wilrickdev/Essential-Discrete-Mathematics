#include <iostream>
#include "exercise-01.h"
#include "exercise-02.h"

void exercise1();
void exercise2();

int main(void)
{
	exercise1();
	return 0;
}

void exercise1()
{
	using namespace ex1;
	
	SquareMatrix3 a = {
		{
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		}
	};
	SquareMatrix3 b = a;
	
	std::cout << a << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << a << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << a << std::endl;
	std::cout << (3 * a) << std::endl;
	std::cout << a << std::endl;
	std::cout << (a * 4) << std::endl;
	std::cout << a << std::endl;
}

void exercise2()
{
	using namespace ex2;
	
	SquareMatrix a = {
		{
			{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
			{2, 3, 4, 5, 6, 7, 8, 9, 10, 1}, 
			{3, 4, 5, 6, 7, 8, 9, 10, 1, 2}, 
			{4, 5, 6, 7, 8, 9, 10, 1, 2, 3}, 
			{5, 6, 7, 8, 9, 10, 1, 2, 3, 4}, 
			{6, 7, 8, 9, 10, 1, 2, 3, 4, 5}, 
			{7, 8, 9, 10, 1, 2, 3, 4, 5, 6}, 
			{8, 9, 10, 1, 2, 3, 4, 5, 6, 7}, 
			{9, 10, 1, 2, 3, 4, 5, 6, 7, 8}, 
			{10, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
		}
	};
	SquareMatrix b = a;
	
	std::cout << a << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << a << std::endl;
	std::cout << (a * b) << std::endl;
	std::cout << a << std::endl;
	std::cout << (3 * a) << std::endl;
	std::cout << a << std::endl;
	std::cout << (a * 4) << std::endl;
	std::cout << a << std::endl;
}
