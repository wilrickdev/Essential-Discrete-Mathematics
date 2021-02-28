#include "exercise-06.h"

ex6::Matrix ex6::getSubMatrix(const Matrix& matrix, unsigned int pivot)
{
	ex6::Matrix subMatrix(matrix.size() - 1, std::vector<int>(matrix.size() - 1, 0));
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

int ex6::calculateDeterminant(Matrix matrix)
{
	if (matrix.size() > 2)
	{
		int result = 0;
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
