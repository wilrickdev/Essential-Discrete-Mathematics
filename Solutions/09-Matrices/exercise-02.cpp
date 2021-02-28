#include "exercise-02.h"

#include <iomanip> 

using namespace ex2;

SquareMatrix::SquareMatrix(std::vector<std::vector<int>>&& matrix)
	: matrix(matrix)
{
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& rhs)
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

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& rhs)
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

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const
{
	return SquareMatrix(*this) += other;
}

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& rhs)
{
	auto result = SquareMatrix(std::vector<std::vector<int>>(this->matrix.size(), std::vector<int>(this->matrix.size(), 0)));
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

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const
{
	return SquareMatrix(*this) *= other;
}

SquareMatrix& SquareMatrix::operator*=(int scalar)
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

SquareMatrix SquareMatrix::operator*(int scalar) const
{
	return SquareMatrix(*this) *= scalar;
}

SquareMatrix ex2::operator*(int scalar, const SquareMatrix& matrix)
{
	return SquareMatrix(matrix) *= scalar;
}

std::ostream& ex2::operator<<(std::ostream& out, const SquareMatrix& matrix)
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
