#include <iostream>

#include "exercise-01.h"
#include "exercise-02.h"
#include "exercise-03.h"

void exercise1();
void exercise2();
void exercise3();

int main()
{
	exercise3();
	return 0;
}

void exercise1()
{
	using namespace ex1;
	Polynomial equation1({ {1, 2}, {3, 4}, {2, 5} });
	Polynomial equation2({ {3, 2}, {2, 4} });
	Polynomial equation3({ {3, 2}, {4, 1} });
	std::cout << "equation1:      " << equation1 << std::endl;
	std::cout << "equation2:      " << equation2 << std::endl;
	std::cout << "addition:       " << (equation1 + equation2) << std::endl;
	std::cout << "subtraction:    " << (equation1 - equation2) << std::endl;
	std::cout << "multiplication: " << (equation1 * equation2) << std::endl;
	std::cout << "equation3:      " << equation3 << std::endl;
	std::cout << "equation3 x=3:  " << equation3(3) << std::endl;
}

void exercise2()
{
	using namespace ex2;

	Polynomial equation({ { 13, 0 }, { 2, 1 }, { 4, 2 } });
	std::cout << "equation:   " << equation << std::endl;
	std::cout << "derivative: " << equation.derivative() << std::endl;
}

void exercise3()
{
	using namespace ex3;
	std::set<int> set = { 1, 2, 3 };
	auto functions = findFunctions(set);

	for (auto& function : functions)
	{
		for (auto& pair : function)
		{
			std::cout << "(" << pair.first << "," << pair.second << "), ";
		}
		std::cout << std::endl;
	}
}
