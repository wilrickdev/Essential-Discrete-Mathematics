/**
 * 3. Design and implement  a matrix abstract data type (ADT)
 *    (in C++ use a template class) that permits the declaration
 *    of square matrices (in C++ this is a constructor), addition,
 *    multiplication, and scalar multiplication of square matrices
 *    of any dimension.
 */
#pragma once
#include <iomanip>
#include <vector>

namespace ex3
{
	/**
	 * Declarations 
	 */
	
	template<typename T>
	class SquareMatrix
	{
	public:
		SquareMatrix() = delete;
		SquareMatrix(std::vector<std::vector<T>>&& matrix);

		SquareMatrix<T>& operator=(const SquareMatrix& rhs);
		SquareMatrix& operator+=(const SquareMatrix& rhs);
		SquareMatrix operator+(const SquareMatrix& other) const;
		SquareMatrix& operator*=(const SquareMatrix& rhs);
		SquareMatrix operator*(const SquareMatrix& other) const;
		SquareMatrix& operator*=(T scalar);
		SquareMatrix operator*(T scalar) const;

		T getDeterminant() const;

		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const SquareMatrix<U>& matrix);

		static std::vector<std::vector<T>> getSubMatrix(const std::vector<std::vector<T>>& matrix, size_t pivot);
		static T calculateDeterminant(std::vector<std::vector<T>> matrix);
	private:
		std::vector<std::vector<T>> matrix;
	};

	template<typename T>
	SquareMatrix<T> operator*(T scalar, const SquareMatrix<T>& matrix);
	
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const SquareMatrix<T>& matrix);
	
	/**
	 * Definitions
	 */
	
	template<typename T>
	SquareMatrix<T>::SquareMatrix(std::vector<std::vector<T>>&& matrix)
		: matrix(matrix)
	{
	}

	template<typename T>
	SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix& rhs)
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

	template<typename T>
	SquareMatrix<T>& SquareMatrix<T>::operator+=(const SquareMatrix& rhs)
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

	template<typename T>
	SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix& other) const
	{
		return SquareMatrix(*this) += other;
	}

	template<typename T>
	SquareMatrix<T>& SquareMatrix<T>::operator*=(const SquareMatrix& rhs)
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

	template<typename T>
	SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix& other) const
	{
		return SquareMatrix(*this) *= other;
	}

	template<typename T>
	SquareMatrix<T>& SquareMatrix<T>::operator*=(T scalar)
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

	template<typename T>
	SquareMatrix<T> SquareMatrix<T>::operator*(T scalar) const
	{
		return SquareMatrix(*this) *= scalar;
	}

	template <typename T>
	T SquareMatrix<T>::getDeterminant() const
	{
		return calculateDeterminant(matrix);
	}

	template <typename T>
	std::vector<std::vector<T>> SquareMatrix<T>::getSubMatrix(const std::vector<std::vector<T>>& matrix, size_t pivot)
	{
		std::vector<std::vector<T>> subMatrix(matrix.size() - 1, std::vector<T>(matrix.size() - 1, 0));
		for (size_t row = 1; row < matrix.size(); ++row)
		{
			for (size_t column = 0; column < matrix[row].size(); ++column)
			{
				if (column < pivot)
				{
					subMatrix[row - 1][column] = matrix[row][column];
				}
				else if (column > pivot)
				{
					subMatrix[row - 1][column - 1] = matrix[row][column];
				}
			}
		}
		return subMatrix;
	}
	
	template <typename T>
	T SquareMatrix<T>::calculateDeterminant(std::vector<std::vector<T>> matrix)
	{
		if (matrix.size() > 2)
		{
			T result = 0;
			for (size_t column = 0; column < matrix.size(); ++column)
			{
				if (matrix[0][column] != 0)
				{
					auto subMatrix = getSubMatrix(matrix, column);
					result += matrix[0][column] * (column % 2 == 0 ? 1 : -1)
						* calculateDeterminant(std::move(subMatrix));
				}
			}
			return result;
		}
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	}

	template<typename T>
	SquareMatrix<T> operator*(T scalar, const SquareMatrix<T>& matrix)
	{
		return SquareMatrix<T>(matrix) *= scalar;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const SquareMatrix<T>& matrix)
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
}
