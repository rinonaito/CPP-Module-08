#include "Span.hpp"

Span::Span(){}
Span::Span(int maximum_size){}
Span::Span(const Span &other){}
Span::~Span(){}
Span &Span::operator=(const Span& other);
void Span::addNumber(int element){
	if (this->elements_.size() >= this->maximum_size_)
		throw std::runtime_error("Span has reached its maximum size of elements.");
	this->elements_.push_back(element);
	return;
}
void Span::addRandomNumbers(size_t size){
	for (size_t index = 0; index < size; index++){
		addNumber((int)index);
	}
	return ;
}
int Span::shortestSpan(){
	return 2;
}
int Span::longestSpan(){
	return 1;
}
