#include "exercise-01.h"

#include <algorithm>

ex1::Set::Set(std::set<int> set)
	: set(std::move(set))
{
}

ex1::Set::Set(const std::vector<int>& vec)
	: set(vec.begin(), vec.end())
{
}

ex1::Set& ex1::Set::operator-=(const Set& B)
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

ex1::Set ex1::Set::operator-(const Set& B) const
{
	return Set(*this) -= B;
}

ex1::Set& ex1::Set::operator|=(const Set& B)
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

ex1::Set ex1::Set::operator|(const Set& B) const
{
	return Set(*this) |= B;
}

ex1::Set& ex1::Set::operator&=(const Set& B)
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

ex1::Set ex1::Set::operator&(const Set& B) const
{
	return Set(*this) &= B;
}

std::ostream& ex1::operator<<(std::ostream& out, const Set& set)
{
	out << "{ ";
	std::for_each(set.set.begin(), set.set.end(), [&out](int i) { out << i << ", "; });
	out << "}";
	return out;
}
