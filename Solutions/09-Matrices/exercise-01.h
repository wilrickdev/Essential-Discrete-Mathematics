/**
 * 1. Write a program that adds, multiplies, and performs scalar
 *    multiplication on 3 x 3 matrices with integer entries.
 */
#pragma once
#include <vector>
#include <iostream>

namespace ex1
{
	class SquareMatrix3
	{
	public:
		SquareMatrix3() = delete;
		SquareMatrix3(std::vector<std::vector<int>>&& matrix);

		SquareMatrix3& operator=(const SquareMatrix3& rhs);
		SquareMatrix3& operator+=(const SquareMatrix3& rhs);
		SquareMatrix3 operator+(const SquareMatrix3& other) const;
		SquareMatrix3& operator*=(const SquareMatrix3& rhs);
		SquareMatrix3 operator*(const SquareMatrix3& other) const;
		SquareMatrix3& operator*=(int scalar);
		SquareMatrix3 operator*(int scalar) const;
		
		friend std::ostream& operator<<(std::ostream& out, const SquareMatrix3& matrix);
	private:
		std::vector<std::vector<int>> matrix;
	};

	SquareMatrix3 operator*(int scalar, const SquareMatrix3& matrix);
	std::ostream& operator<<(std::ostream& out, const SquareMatrix3& matrix);
}