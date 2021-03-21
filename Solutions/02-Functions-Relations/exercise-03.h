/**
 * 3. Write a program that prints out all the functions on a
 *    given set S. Here the input will be the elements in a set.
 *
 * Note: Possible wrong interpretation (and implementation).
 */
#pragma once
#include <map>
#include <set>
#include <vector>

namespace ex3
{
	typedef std::map<int, int> Function;
	typedef std::vector<Function> Functions;
	
	Functions findFunctions(const std::set<int>& set);
	Functions findNextFunctions(
		const std::vector<int>& set, 
		size_t index,
		Function& partialFunction
	);
}
