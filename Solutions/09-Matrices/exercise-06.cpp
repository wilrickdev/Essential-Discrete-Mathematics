#include "exercise-06.h"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int ex6::calculateDeterminant(const Matrix& matrix, size_t currentRow, ColumnList& columns)
{
	if (matrix.size() - currentRow > 2)
	{
		int result = 0;
		bool bEven = true;
		
		for (size_t column = 0; column < matrix.size(); ++column)
		{
			if (columns[column].second == false)
			{
				columns[column].second = true;

				result += (bEven ? 1 : -1) * matrix[currentRow][column]
					* calculateDeterminant(matrix, currentRow + 1, columns);
				bEven = !bEven;
				
				columns[column].second = false;
			}
		}
		return result;
	}

	auto predicate = [](const Column& pair) {return !pair.second; };
	auto it1 = std::find_if(columns.begin(), columns.end(), predicate);
	auto it2 = std::find_if(it1 + 1, columns.end(), predicate);
	size_t size = matrix.size();
	
	return matrix[size - 2][it1->first] * matrix[size - 1][it2->first]
		- matrix[size - 1][it1->first] * matrix[size - 2][it2->first];
}

int ex6::determinant(const Matrix& matrix)
{
	ColumnList columns(matrix.size());
	for (size_t i = 0; i < columns.size(); ++i)
	{
		columns[i].first = i;
		columns[i].second = false;
	}
	
	int result = 0;
	bool bEven = true;
	
	size_t currentRow = 0;
	
	for (size_t column = 0; column < matrix[currentRow].size(); ++column)
	{
		columns[column].second = true;

		result += (bEven ? 1 : -1) * matrix[currentRow][column]
			* calculateDeterminant(matrix, currentRow + 1, columns);
		bEven = !bEven;
		
		columns[column].second = false;
	}
	return result;
}
