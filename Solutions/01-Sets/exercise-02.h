/**
 * 2. Write a program to list the elements in the power set of a
 *    given (finite) set.
 */
#pragma once
#include <iostream>
#include <set>
#include <vector>

namespace ex2
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
		
	private:
		std::vector<std::set<int>> power_next(
			std::set<int>::iterator current,
			std::set<int>::iterator end,
			const std::set<int>& subset
		) const;
		
		friend std::ostream& operator<<(std::ostream& out, const Set& set);;
	private:
		std::set<int> set;
	};

	std::ostream& operator<<(std::ostream& out, const Set& set);
}
