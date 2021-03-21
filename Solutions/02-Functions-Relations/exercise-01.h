/**
 * 1. Write a program that inputs two polynomials and prints
 *    their sum, difference, and product. You will need first to
 *    decide how to store a polynomial.
 */
#pragma once
#include <iostream>
#include <vector>

namespace ex1
{
	class Term
	{
	public:
		Term() = delete;
		Term(int scalar, int exponent);

		bool operator==(const Term& other) const;
		bool operator!=(const Term& other) const;
		bool operator<(const Term& other) const;
		bool operator<=(const Term& other) const;
		bool operator>(const Term& other) const;
		bool operator>=(const Term& other) const;

		Term& operator+=(const Term& rhs);
		Term operator+(const Term& other) const;

		int getScalar() const;
		void setScalar(int scalar);
		int getExponent() const;
		void setExponent(int exponent);

	protected:
		friend std::ostream& operator<<(std::ostream& out, const Term& term);
		
	private:
		int scalar;
		int exponent;
	};

	class Polynomial
	{
	public:
		Polynomial(const std::vector<Term>& terms);

		Polynomial& operator+=(const Polynomial& rhs);
		Polynomial operator+(const Polynomial& other) const;
		Polynomial& operator-=(const Polynomial& rhs);
		Polynomial operator-(const Polynomial& other) const;
		Polynomial& operator*=(const Polynomial& rhs);
		Polynomial operator*(const Polynomial& other) const;

		int operator()(int x) const;
		
	protected:
		friend std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);
		
	private:
		std::vector<Term> terms;
	};

	std::ostream& operator<<(std::ostream& out, const Term& term);
	std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);
}