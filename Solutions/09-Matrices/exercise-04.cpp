#include "exercise-04.h"

#include <cassert>

int ex4::calculateDeterminant(const std::vector<std::vector<int>>& matrix)
{
	assert(matrix.size() == 2 && matrix[0].size() == 2 && matrix[1].size() == 2);
	return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}
