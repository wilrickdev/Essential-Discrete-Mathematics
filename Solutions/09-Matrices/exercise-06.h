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
	typedef std::pair<int, bool> Column;
	typedef std::vector<Column> ColumnList;
	
	int calculateDeterminant(const Matrix& matrix, size_t currentRow, ColumnList& columns);
	int determinant(const Matrix& matrix);
}
