#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class	Span{
	public:
		Span(size_t maximum_size);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span& other);
		void addNumber(int element);
		void addNumberWithIter(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void fillRange();
		int shortestSpan() const;
		int longestSpan() const;
		size_t getMaximumSize() const;
		std::vector<int> getElements() const;
		void printElements() const;

	private:
		size_t maximum_size_;
		std::vector<int> elements_;
		Span();
};
