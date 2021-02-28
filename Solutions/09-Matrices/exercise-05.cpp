#include "exercise-05.h"

#include <cassert>

int ex5::calculateDeterminant(const std::vector<std::vector<int>>& matrix)
{
	assert(matrix.size() == 3 && matrix[0].size() == 3 
		&& matrix[1].size() == 3 && matrix[2].size() == 3);
	
	return (1 * matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]))
		+ (-1 * matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]))
		+ (1 * matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]));
}
