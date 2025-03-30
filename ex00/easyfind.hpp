#pragma once
#include<iostream>
#include<exception>
#include<algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target){
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("[ERROR] Target Not Found.");
	return it;
};
