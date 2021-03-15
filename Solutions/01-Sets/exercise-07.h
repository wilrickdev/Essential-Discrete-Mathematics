/**
 * 7. Write a program that defines abstract data type (ADT) Set.
 *    The operations should include union, intersection, set
 *    difference, and complement, as well as some way to input
 *    and display sets. Programmers should be able to use your
 *    ADT to declare variables of type Set.
 *
 *    Note: the complement is missing as this implementation does not 
 *    define the universe of a set, therefore the complement is unknown.
 */
#pragma once
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

namespace ex7
{
	template<typename T>
	class Set
	{
	public:
		Set(std::set<T> set);
		Set(const std::vector<T>& set);

		Set& operator-=(const Set& B);
		Set operator-(const Set& B) const;
		Set& operator|=(const Set& B);
		Set operator|(const Set& B) const;
		Set& operator&=(const Set& B);
		Set operator&(const Set& B) const;

		std::vector<Set> power() const;
		bool contains(const Set& B) const;
		
	private:
		template<class U>
		std::vector<std::set<T>> power_next(U current,U end, 
			const std::set<T>& subset) const;

		template<typename U>
		friend std::ostream& operator<<(std::ostream& out, const Set<U>& set);
		
	private:
		std::set<T> set;
	};

	template <typename T>
	Set<T>::Set(std::set<T> set)
		: set(std::move(set))
	{
	}

	template <typename T>
	Set<T>::Set(const std::vector<T>& set)
		: set(set.begin(), set.end())
	{
	}

	template <typename T>
	Set<T>& Set<T>::operator-=(const Set& B)
	{
		if (this == &B)
		{
			set = {};
			return *this;
		}

		std::for_each(B.set.begin(), B.set.end(), [&](T i)
			{
				const auto it = std::find(set.begin(), set.end(), i);
				if (it != set.end())
					set.erase(it);
			}
		);

		return *this;
	}

	template <typename T>
	Set<T> Set<T>::operator-(const Set& B) const
	{
		return Set(*this) -= B;
	}

	template <typename T>
	Set<T>& Set<T>::operator|=(const Set& B)
	{
		if (this == &B)
		{
			return *this;
		}

		std::for_each(B.set.begin(), B.set.end(), [&](T i)
			{
				set.emplace(i);
			}
		);

		return *this;
	}

	template <typename T>
	Set<T> Set<T>::operator|(const Set& B) const
	{
		return Set(*this) |= B;
	}

	template <typename T>
	Set<T>& Set<T>::operator&=(const Set& B)
	{
		if (this == &B)
		{
			return *this;
		}

		std::set<int> intersection;
		std::for_each(set.begin(), set.end(), [&](T i)
			{
				if (std::find(B.set.begin(), B.set.end(), i) != B.set.end())
					intersection.emplace(i);
			}
		);

		set = intersection;

		return *this;
	}

	template <typename T>
	Set<T> Set<T>::operator&(const Set& B) const
	{
		return Set(*this) &= B;
	}

	template <typename T>
	std::vector<Set<T>> Set<T>::power() const
	{
		std::vector<Set> subsets{ Set(std::set<T>{}) };

		for (auto it = set.begin(); it != set.end(); ++it)
		{
			std::set<T> subset;
			subset.insert(*it);

			auto vec = power_next(it, set.end(), subset);

			subsets.emplace_back(subset);

			subsets.reserve(subsets.size() + vec.size());
			std::move(std::begin(vec), std::end(vec), std::back_inserter(subsets));
		}

		return subsets;
	}

	template <typename T>
	bool Set<T>::contains(const Set& B) const
	{
		if (set.size() < B.set.size())
		{
			return false;
		}

		return std::find_if(B.set.begin(), B.set.end(), [this](T element)
			{
				return set.find(element) == set.end();
			}
		) == B.set.end();
	}

	template <typename T>
	template <class U>
	std::vector<std::set<T>> Set<T>::power_next(U current, U end, const std::set<T>& subset) const
	{
		std::vector<std::set<T>> subsets;

		for (auto it = ++current; it != end; ++it)
		{
			std::set<T> expansion = subset;
			expansion.insert(*it);

			auto vec = power_next(it, end, expansion);

			subsets.push_back(std::move(expansion));

			subsets.reserve(subsets.size() + vec.size());
			std::move(std::begin(vec), std::end(vec), std::back_inserter(subsets));
		}

		return subsets;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Set<T>& set)
	{
		out << "{ ";
		std::for_each(set.set.begin(), set.set.end(), [&out](int i) { out << i << ", "; });
		out << "}";
		return out;
	}
}
