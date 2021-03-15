/**
 * 4. Write a program that inputs two sets and determines
 *    whether one is contained in the other. 
 */
#pragma once
#include <iostream>
#include <set>
#include <vector>

namespace ex4
{
	class Set
	{
	public:
		Set(std::set<int> set);
		Set(const std::vector<int>& set);

		Set& operator-=(const Set& B);
		Set operator-(const Set& B) const;
		Set& operator|=(const Set& B);
		Set operator|(const Set& B) const;
		Set& operator&=(const Set& B);
		Set operator&(const Set& B) const;

		std::vector<Set> power() const;
		bool contains(const Set& B) const;
	private:
		std::vector<std::set<int>> power_next(
			std::set<int>::iterator current,
			std::set<int>::iterator end,
			const std::set<int>& subset
		) const;

		friend std::ostream& operator<<(std::ostream& out, const Set& set);
	private:
		std::set<int> set;
	};

	std::ostream& operator<<(std::ostream& out, const Set& set);

	int factorial(int n);
}

