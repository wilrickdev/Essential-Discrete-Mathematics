#include <iostream>
#include "exercise-01.h"
#include "exercise-02.h"
#include "exercise-03.h"
#include "exercise-04.h"
#include "exercise-05.h"
#include "exercise-06.h"

void exercise1();
void exercise2();
void exercise4();
void exercise3();
void exercise5();
void exercise6();

int main(void)
{
	exercise6();
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

void exercise3()
{
	using namespace ex3;
	SquareMatrix<double> a = {
		{
			{6.0, 1.0, 1.0},
			{4.0, -2.0, 5.0},
			{2.0, 8.0, 7.0},
		}
	};
	std::cout << a << std::endl;
	std::cout << a.getDeterminant() << std::endl;
}

void exercise4()
{
	using namespace ex4;
	
	std::vector<std::vector<int>> matrix = { {1, 3}, {2, 8} };
	
	std::cout << calculateDeterminant(matrix) << std::endl;
}

void exercise5()
{
	using namespace ex5;
	
	std::vector<std::vector<int>> identity = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
	
	std::cout << calculateDeterminant(identity) << std::endl;
}

void exercise6()
{
	using namespace ex6;

	std::vector<std::vector<int>> mat = {
		{6, 1, 1},
		{4, -2, 5},
		{2, 8, 7}
	};

	std::cout << determinant(mat) << std::endl;
}
