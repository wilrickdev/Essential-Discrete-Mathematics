/**
 * 3. Write a program that outputs the number of subsets of each possible
 *    size. For example, a set of two elements has one subset of two
 *    elements, two subsets of one element each, and one subset with
 *    no elements.
 */
#pragma once
#include <iostream>
#include <set>
#include <vector>

namespace ex3
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

		int combinations(int subsetSize) const;
		void printCombinations() const;
		std::vector<Set> power() const;

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
