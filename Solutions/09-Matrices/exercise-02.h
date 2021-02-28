/**
 * 2. Write a program that adds, multiplies, and performs scalar
 *    multiplication on square matrices with up to 20 rows and columns.
 */
#pragma once
#include <vector>
#include <iostream>

namespace ex2
{
	class SquareMatrix
	{
	public:
		SquareMatrix() = delete;
		SquareMatrix(std::vector<std::vector<int>>&& matrix);

		SquareMatrix& operator=(const SquareMatrix& rhs);
		SquareMatrix& operator+=(const SquareMatrix& rhs);
		SquareMatrix operator+(const SquareMatrix& other) const;
		SquareMatrix& operator*=(const SquareMatrix& rhs);
		SquareMatrix operator*(const SquareMatrix& other) const;
		SquareMatrix& operator*=(int scalar);
		SquareMatrix operator*(int scalar) const;

		friend std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix);
	private:
		std::vector<std::vector<int>> matrix;
	};

	SquareMatrix operator*(int scalar, const SquareMatrix& matrix);
	std::ostream& operator<<(std::ostream& out, const SquareMatrix& matrix);
}