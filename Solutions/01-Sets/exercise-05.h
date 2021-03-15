/**
 * 5. Write a program that inputs a set and then randomly
 *    chooses an element from that set. Write a program that
 *    inputs a set and then display the elements of the set
 *    in a random order.
 */
#pragma once
#include <iostream>
#include <set>
#include <vector>

namespace ex5
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

		int random() const;
		void printShuffled() const;
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

