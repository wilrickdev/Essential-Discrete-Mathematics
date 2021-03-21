#include "exercise-03.h"

#include <iterator>

ex3::Functions ex3::findFunctions(const std::set<int>& set)
{
	Functions functions;
	std::vector<int> vec(set.begin(), set.end());

	for (size_t i = 0; i < set.size(); ++i)
	{
		Function function;
		function[vec[0]] = vec[i];
		auto found = findNextFunctions(vec, 1, function);

		functions.reserve(functions.size() + found.size());
		std::move(std::begin(found), std::end(found), std::back_inserter(functions));
	}
	
	return functions;
}

ex3::Functions ex3::findNextFunctions(
	const std::vector<int>& set, 
	size_t index, 
	Function& partialFunction)
{
	Functions functions;
	
	for (size_t i = 0; i < set.size(); ++i)
	{
		Function function = partialFunction;
		function[set[index]] = set[i];

		if (index + 1 == set.size())
		{
			functions.emplace_back(function);
		}
		else
		{
			auto found = findNextFunctions(set, index + 1, function);
			functions.reserve(functions.size() + found.size());
			std::move(std::begin(found), std::end(found), std::back_inserter(functions));
		}
	}

	return functions;
}
