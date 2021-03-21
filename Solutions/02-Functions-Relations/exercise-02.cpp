#include "exercise-02.h"

#include <algorithm>
#include <map>

ex2::Term::Term(int scalar, int exponent) : scalar(scalar), exponent(exponent)
{
}

bool ex2::Term::operator==(const Term& other) const
{
	return exponent == other.exponent;
}

bool ex2::Term::operator!=(const Term& other) const
{
	return !(*this == other);
}

bool ex2::Term::operator<(const Term& other) const
{
	return exponent < other.exponent;
}

bool ex2::Term::operator<=(const Term& other) const
{
	return (*this == other) || (*this < other);
}

bool ex2::Term::operator>(const Term& other) const
{
	return exponent > other.exponent;
}

bool ex2::Term::operator>=(const Term& other) const
{
	return (*this == other) || (*this > other);
}

ex2::Term& ex2::Term::operator+=(const Term& rhs)
{
	if (this != &rhs)
	{
		scalar += rhs.scalar;
	}
	return *this;
}

ex2::Term ex2::Term::operator+(const Term& other) const
{
	return Term(*this) += other;
}

int ex2::Term::getScalar() const
{
	return scalar;
}

void ex2::Term::setScalar(int scalar)
{
	this->scalar = scalar;
}

int ex2::Term::getExponent() const
{
	return exponent;
}

void ex2::Term::setExponent(int exponent)
{
	this->exponent = exponent;
}

ex2::Polynomial::Polynomial(const std::vector<Term>& terms)
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

ex2::Polynomial& ex2::Polynomial::operator+=(const Polynomial& rhs)
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

ex2::Polynomial ex2::Polynomial::operator+(const Polynomial& other) const
{
	return Polynomial(*this) += other;
}

ex2::Polynomial& ex2::Polynomial::operator-=(const Polynomial& rhs)
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

ex2::Polynomial ex2::Polynomial::operator-(const Polynomial& other) const
{
	return Polynomial(*this) -= other;
}

ex2::Polynomial& ex2::Polynomial::operator*=(const Polynomial& rhs)
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

ex2::Polynomial ex2::Polynomial::operator*(const Polynomial& other) const
{
	return Polynomial(*this) *= other;
}

int ex2::Polynomial::operator()(int x) const
{
	int sum = 0;
	std::for_each(terms.begin(), terms.end(), [&x, &sum](const Term& term)
		{
			sum += term.getScalar() * (int)pow(x, term.getExponent());
		}
	);

	return sum;
}

ex2::Polynomial ex2::Polynomial::derivative() const
{
	Polynomial result({});

	for (const auto& term : terms)
	{
		if (term.getExponent() > 0)
		{
			result.terms.emplace_back(
				term.getScalar() * term.getExponent(), 
				term.getExponent() - 1
			);
		}
	}

	return result;
}

std::ostream& ex2::operator<<(std::ostream& out, const ex2::Term& term)
{
	out << (term.scalar > 0 ? "+" : "") << term.scalar << "x^" << term.exponent;
	return out;
}

std::ostream& ex2::operator<<(std::ostream& out, const ex2::Polynomial& polynomial)
{
	for (const auto& term : polynomial.terms)
	{
		out << term << " ";
	}
	return out;
}
