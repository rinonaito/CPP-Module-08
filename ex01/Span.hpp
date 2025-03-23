#pragma once

class	Span{
	public:
		void addNumber();
		int shortestSpan();
		int longestSpan();
	private:
		int maximum_;
		int *elements_;
};
