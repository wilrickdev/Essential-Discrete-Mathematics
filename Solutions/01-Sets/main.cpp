#include <iostream>
#include <iomanip>

#include "exercise-01.h"
#include "exercise-02.h"
#include "exercise-03.h"
#include "exercise-04.h"
#include "exercise-05.h"
#include "exercise-06.h"
#include "exercise-07.h"

void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();

int main()
{
	exercise7();
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

void exercise4()
{
	using namespace ex4;
	
	std::set<int> set1 = { 1,2,3,4,5 };
	Set A{ set1 };
	std::set<int> set2 = { 1,2,3 };
	Set B{ set2 };
	
	std::cout << std::boolalpha << A.contains(B) << std::endl;
}

void exercise5()
{
	using namespace ex5;
	std::set<int> set1 = { 1,2,3,4,5,6,7,8,9,10 };
	Set A{ set1 };
	std::cout << A.random() << std::endl;
	A.printShuffled();
}

void exercise6()
{
	using namespace ex6;
	std::set<int> set1 = { 1,2,3,4,5,6,7,8,9,10 };
	Set A{ set1 };
	std::set<int> set2 = {11, 12, 13, 14, 15};
	Set B{ set2 };
	
	auto product = A.cartesian(B);
	
	for (auto& row : product)
	{
		for (auto& pair : row)
		{
			std::cout << "( " << std::setw(3) << pair.first << ", "
				<< std::setw(3) << pair.second << " ), ";
		}
		std::cout << std::endl;
	}
}

void exercise7()
{
	using namespace ex7;

	std::set<int> set1 = { 1,2,3,4,5,6,7,8,9,10 };
	Set A{ set1 };
	std::set<int> set2 = { 6,7,8,9,10,11,12,13,14,15 };
	Set B{ set2 };

	std::cout << "A     " << A << std::endl;
	std::cout << "B     " << B << std::endl;
	std::cout << "A - B " << A - B << std::endl;
	std::cout << "A | B " << (A | B) << std::endl;
	std::cout << "A & B " << (A & B) << std::endl;

	auto subsets = A.power();
	for (auto& subset : subsets)
	{
		std::cout << subset << std::endl;
	}
}
