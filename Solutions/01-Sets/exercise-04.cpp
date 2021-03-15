#include "exercise-04.h"

#include <algorithm>

ex4::Set::Set(std::set<int> set)
	: set(std::move(set))
{
}

ex4::Set::Set(const std::vector<int>& vec)
	: set(vec.begin(), vec.end())
{
}

ex4::Set& ex4::Set::operator-=(const Set& B)
{
	if (this == &B)
	{
		set = {};
		return *this;
	}

	std::for_each(B.set.begin(), B.set.end(), [&](int i)
		{
			const auto it = std::find(set.begin(), set.end(), i);
			if (it != set.end())
				set.erase(it);
		}
	);

	return *this;
}

ex4::Set ex4::Set::operator-(const Set& B) const
{
	return Set(*this) -= B;
}

ex4::Set& ex4::Set::operator|=(const Set& B)
{
	if (this == &B)
	{
		return *this;
	}

	std::for_each(B.set.begin(), B.set.end(), [&](int i)
		{
			set.emplace(i);
		}
	);

	return *this;
}

ex4::Set ex4::Set::operator|(const Set& B) const
{
	return Set(*this) |= B;
}

ex4::Set& ex4::Set::operator&=(const Set& B)
{
	if (this == &B)
	{
		return *this;
	}

	std::set<int> intersection;
	std::for_each(set.begin(), set.end(), [&](int i)
		{
			if (std::find(B.set.begin(), B.set.end(), i) != B.set.end())
				intersection.emplace(i);
		}
	);

	set = intersection;

	return *this;
}

ex4::Set ex4::Set::operator&(const Set& B) const
{
	return Set(*this) &= B;
}

std::vector<ex4::Set> ex4::Set::power() const
{
	std::vector<Set> subsets{ Set(std::set<int>{}) };

	for (auto it = set.begin(); it != set.end(); ++it)
	{
		std::set<int> subset;
		subset.insert(*it);

		auto vec = power_next(it, set.end(), subset);

		subsets.emplace_back(subset);

		subsets.reserve(subsets.size() + vec.size());
		std::move(std::begin(vec), std::end(vec), std::back_inserter(subsets));
	}

	return subsets;
}

bool ex4::Set::contains(const Set& B) const
{
	if (set.size() < B.set.size())
	{
		return false;
	}

	return std::find_if(B.set.begin(), B.set.end(), [this](int element)
		{
			return set.find(element) == set.end();
		}
	) == B.set.end();
}

std::vector<std::set<int>> ex4::Set::power_next(
	std::set<int>::iterator current,
	std::set<int>::iterator end,
	const std::set<int>& subset) const
{
	std::vector<std::set<int>> subsets;

	for (auto it = ++current; it != end; ++it)
	{
		std::set<int> expansion = subset;
		expansion.insert(*it);

		auto vec = power_next(it, end, expansion);

		subsets.push_back(std::move(expansion));

		subsets.reserve(subsets.size() + vec.size());
		std::move(std::begin(vec), std::end(vec), std::back_inserter(subsets));
	}

	return subsets;
}

std::ostream& ex4::operator<<(std::ostream& out, const Set& set)
{
	out << "{ ";
	std::for_each(set.set.begin(), set.set.end(), [&out](int i) { out << i << ", "; });
	out << "}";
	return out;
}

int ex4::factorial(int n)
{
	if (n < 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 1;
	}
	return n * factorial(n - 1);
}
