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

	std::vector<int> vec = { 2, 3, 1, 5, 4, 3, 6 };
	std::set<int> set = { 3, 4, 5, 1, 9, 10, 13 };
	
	Set A{ vec };
	Set B{ set };
	
	std::cout << "A     " << A << std::endl;
	std::cout << "B     " << B << std::endl;
	std::cout << "A - B " << A - B << std::endl;
	std::cout << "A     " << A << std::endl;
	std::cout << "A | B " << (A | B) << std::endl;
	std::cout << "A     " << A << std::endl;
	std::cout << "A & B " << (A & B) << std::endl;
	std::cout << "A     " << A << std::endl;
}

void exercise2()
{
	using namespace ex2;

	std::set<int> set = { 1,2,3,4,5 };
	Set A{ set };
	auto subsets = A.power();
	
	for (auto& subset : subsets)
		std::cout << subset << std::endl;
}

void exercise3()
{
	using namespace ex3;
	std::set<int> set = { 1,2,3,4,5 };
	Set A{ set };
	A.printCombinations();
}
