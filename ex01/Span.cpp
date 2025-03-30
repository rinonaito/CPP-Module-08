#include "Span.hpp"

Span::Span(){}
Span::Span(size_t maximum_size) : maximum_size_(maximum_size){}
Span::Span(const Span &other){*this = other;}
Span::~Span(){}
Span &Span::operator=(const Span& other){
	this->maximum_size_ = other.getMaximumSize();
	this->elements_ = other.getElements();
	return *this;
}

size_t Span::getMaximumSize() const { return this->maximum_size_; }
std::vector<int> Span::getElements() const { return this->elements_; }
void Span::addNumber(int element){
	if ((size_t)(this->elements_.size()) >= this->maximum_size_)
		throw std::runtime_error("Span has reached its maximum size of elements.");
	this->elements_.push_back(element);
	return;
}

void Span::addNumberWithIter(std::vector<int>::iterator start, std::vector<int>::iterator end){
	size_t actual_size = this->elements_.size() + std::distance(start, end);
	if (actual_size > this->maximum_size_)
		throw std::runtime_error("Span has reached its maximum size of elements.");
	while (start != end){
		this->elements_.push_back(*start);
		start++;
	}
	return;
}

int Span::shortestSpan() const {
	if (this->elements_.size() <= 1)
		throw std::runtime_error("No span can be found.");
	std::vector<int> sorted_elements = this->elements_;
	std::sort(sorted_elements.begin(), sorted_elements.end());
	std::vector<int>::const_iterator it = sorted_elements.begin();
	std::vector<int>::const_iterator next_it = it + 1;
	int	shortest_span = (*next_it) - (*it);
	while (next_it != sorted_elements.end()){
		int this_span = (*next_it) - (*it);
		if (shortest_span > this_span)
			shortest_span = this_span;
		it++;
		next_it++;
	}
	return shortest_span;
}

int Span::longestSpan() const {
	if (this->elements_.size() <= 1)
		throw std::runtime_error("No span can be found.");
	std::vector<int>::const_iterator max_it = std::max_element(this->elements_.begin(), this->elements_.end());
	std::vector<int>::const_iterator min_it = std::min_element(this->elements_.begin(), this->elements_.end());
	return (*max_it) - (*min_it);
}

void Span::printElements() const{
	for(std::vector<int>::const_iterator it = this->elements_.begin();
		it != this->elements_.end(); it++){
			std::cout << "[" << std::distance(this->elements_.begin(), it) << "]: "<< *it << std::endl;
	}
}