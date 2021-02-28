#include "exercise-01.h"

#include <cassert>
#include <iomanip> 

using namespace ex1;

SquareMatrix3::SquareMatrix3(std::vector<std::vector<int>>&& matrix)
	: matrix(matrix)
{
	assert(matrix.size() == 3 && matrix[0].size() == 3
		&& matrix[1].size() == 3 && matrix[2].size() == 3);
}

SquareMatrix3& SquareMatrix3::operator=(const SquareMatrix3& rhs)
{
	if (this != &rhs)
	{
		for (size_t row = 0; row < matrix.size(); ++row)
		{
			for (size_t column = 0; column < matrix[row].size(); ++column)
			{
				matrix[row][column] = rhs.matrix[row][column];
			}
		}
	}
	return *this;
}

SquareMatrix3& SquareMatrix3::operator+=(const SquareMatrix3& rhs)
{
	for (size_t row = 0; row < matrix.size(); ++row)
		{
		for (size_t column = 0; column < matrix[row].size(); ++column)
		{
			matrix[row][column] += rhs.matrix[row][column];
		}
	}
	return *this;
}

SquareMatrix3 SquareMatrix3::operator+(const SquareMatrix3& other) const
{
	return SquareMatrix3(*this) += other;
}

SquareMatrix3& SquareMatrix3::operator*=(const SquareMatrix3& rhs)
{
	auto result = SquareMatrix3(std::vector<std::vector<int>>(this->matrix.size(), std::vector<int>(this->matrix.size(), 0)));
	for (size_t row = 0; row < matrix.size(); ++row)
	{
		for (size_t column = 0; column < matrix[row].size(); ++column)
		{
			for (size_t indexer = 0; indexer < matrix[row].size(); ++indexer)
			{
				result.matrix[row][column] += matrix[row][indexer] * rhs.matrix[indexer][column];
			}
		}
	}
	return *this = result;
}

SquareMatrix3 SquareMatrix3::operator*(const SquareMatrix3& other) const
{
	return SquareMatrix3(*this) *= other;
}

SquareMatrix3& SquareMatrix3::operator*=(int scalar)
{
	for (size_t row = 0; row < matrix.size(); ++row)
	{
		for (size_t column = 0; column < matrix[row].size(); ++column)
		{
			matrix[row][column] *= scalar;
		}
	}
	return *this;
}

SquareMatrix3 SquareMatrix3::operator*(int scalar) const
{
	return SquareMatrix3(*this) *= scalar;
}

SquareMatrix3 ex1::operator*(int scalar, const SquareMatrix3& matrix)
{
	return SquareMatrix3(matrix) *= scalar;
}

std::ostream& ex1::operator<<(std::ostream& out, const SquareMatrix3& matrix)
{
	for (const auto& row : matrix.matrix)
	{
		for (const auto& col : row)
		{
			out << std::setw(5) << col;
		}
		out << std::endl;
	}
	return out;
}
