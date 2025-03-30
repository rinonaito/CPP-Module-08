#pragma once
#include<iostream>
#include<exception>

// this function has to find the first occurrence
// of the second parameter in the first parameter
template <typename T>
typename T::iterator easyfind(T &container, int target){
	typename T::iterator it = find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("[ERROR] Target Not Found.");
	return it;
};
