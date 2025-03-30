#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class	Span{
	public:
		Span();
		Span(int maximum_size);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span& other);
		void addNumber(int element);
		void addRandomNumbers(size_t size);
		int shortestSpan();
		int longestSpan();
	private:
		int maximum_size_;
		 std::vector elements_;
};
