/**
 * 6. Write a program that computes the determinant for any square
 *    matrix. Hint: Recursion may be useful here. If you succeed
 *    with this program, insert the function you have written into
 *    the ADT you write in Problem 3.
 */
#pragma once
#include <vector>

namespace ex6
{
	typedef std::vector<std::vector<int>> Matrix;
	
	Matrix getSubMatrix(const Matrix& matrix, unsigned int pivot);
	int calculateDeterminant(Matrix matrix);
}
