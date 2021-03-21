#include "exercise-01.h"

#include <algorithm>
#include <map>

ex1::Term::Term(int scalar, int exponent): scalar(scalar), exponent(exponent)
{
}

bool ex1::Term::operator==(const Term& other) const
{
	return exponent == other.exponent;
}

bool ex1::Term::operator!=(const Term& other) const
{
	return !(*this == other);
}

bool ex1::Term::operator<(const Term& other) const
{
	return exponent < other.exponent;
}

bool ex1::Term::operator<=(const Term& other) const
{
	return (*this == other) || (*this < other);
}

bool ex1::Term::operator>(const Term& other) const
{
	return exponent > other.exponent;
}

bool ex1::Term::operator>=(const Term& other) const
{
	return (*this == other) || (*this > other);
}

ex1::Term& ex1::Term::operator+=(const Term& rhs)
{
	if (this != &rhs)
	{
		scalar += rhs.scalar;
	}
	return *this;
}

ex1::Term ex1::Term::operator+(const Term& other) const
{
	return Term(*this) += other;
}

int ex1::Term::getScalar() const
{
	return scalar;
}

void ex1::Term::setScalar(int scalar)
{
	this->scalar = scalar;
}

int ex1::Term::getExponent() const
{
	return exponent;
}

void ex1::Term::setExponent(int exponent)
{
	this->exponent = exponent;
}

ex1::Polynomial::Polynomial(const std::vector<Term>& terms)
{
	std::map<int, int> accumulator;
	for (const auto& term : terms)
	{
		accumulator[term.getExponent()] += term.getScalar();
	}

	this->terms.clear();
	for (auto const& element : accumulator)
	{
		this->terms.emplace_back(element.second, element.first);
	}
}

ex1::Polynomial& ex1::Polynomial::operator+=(const Polynomial& rhs)
{
	if (this != &rhs)
	{
		std::map<int, int> accumulator;
		for (const auto& term : terms)
		{
			accumulator[term.getExponent()] += term.getScalar();
		}

		for (const auto& term : rhs.terms)
		{
			accumulator[term.getExponent()] += term.getScalar();
		}

		this->terms.clear();
		for (auto const& element : accumulator)
		{
			this->terms.emplace_back(element.second, element.first);
		}
	}
	return *this;
}

ex1::Polynomial ex1::Polynomial::operator+(const Polynomial& other) const
{
	return Polynomial(*this) += other;
}

ex1::Polynomial& ex1::Polynomial::operator-=(const Polynomial& rhs)
{
	if (this != &rhs)
	{
		std::map<int, int> accumulator;
		for (const auto& term : terms)
		{
			accumulator[term.getExponent()] += term.getScalar();
		}

		for (const auto& term : rhs.terms)
		{
			accumulator[term.getExponent()] -= term.getScalar();
		}

		this->terms.clear();
		for (auto const& element : accumulator)
		{
			this->terms.emplace_back(element.second, element.first);
		}
	}
	return *this;
}

ex1::Polynomial ex1::Polynomial::operator-(const Polynomial& other) const
{
	return Polynomial(*this) -= other;
}

ex1::Polynomial& ex1::Polynomial::operator*=(const Polynomial& rhs)
{
	if (this != &rhs)
	{
		std::map<int, int> accumulator;

		for (const auto& term : terms)
		{
			for (const auto& other : rhs.terms)
			{
				accumulator[term.getExponent() + other.getExponent()] += term.getScalar() * other.getScalar();
			}
		}
		
		this->terms.clear();
		for (auto const& element : accumulator)
		{
			this->terms.emplace_back(element.second, element.first);
		}
	}
	return *this;
}

ex1::Polynomial ex1::Polynomial::operator*(const Polynomial& other) const
{
	return Polynomial(*this) *= other;
}

int ex1::Polynomial::operator()(int x) const
{
	int sum = 0;
	std::for_each(terms.begin(), terms.end(), [&x, &sum](const Term& term)
		{
			sum += term.getScalar() * (int)pow(x, term.getExponent());
		}
	);
	
	return sum;
}

std::ostream& ex1::operator<<(std::ostream& out, const ex1::Term& term)
{
	out << (term.scalar > 0 ? "+" :  "") << term.scalar << "x^" << term.exponent;
	return out;
}

std::ostream& ex1::operator<<(std::ostream& out, const ex1::Polynomial& polynomial)
{
	for (const auto& term : polynomial.terms)
	{
		out << term << " ";
	}
	return out;
}
