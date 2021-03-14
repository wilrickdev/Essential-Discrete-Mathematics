/**
 * 1. Devise some method for representing a (finite) set of
 *    integers. Write a program that inputs two sets (call them
 *    A and B) and then prints A, B, A union B, A intersection B,
 *    and A - B.
 */
#pragma once
#include <iostream>
#include <set>
#include <vector>

namespace ex1
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
		
		friend std::ostream& operator<<(std::ostream& out, const Set& set);;
		
	private:
		std::set<int> set;
	};

	std::ostream& operator<<(std::ostream& out, const Set& set);
}
