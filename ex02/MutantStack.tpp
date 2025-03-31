#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}
template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>(other){}
template<typename T>
MutantStack<T>::~MutantStack(){}
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other){
	std::stack<T>::operator=(other);
	return *this;
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}
template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
	return this->c.rbegin();
}
template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
	return this->c.rend();
}
template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}

template <typename T>
void MutantStack<T>::print() const{
	for (MutantStack<T>::const_iterator it = this->begin(); it != this->end(); it++){
		std::cout << *it;
	}
	std::cout << '\n';
}

template <typename T>
void MutantStack<T>::tolower(){
	for (MutantStack<T>::iterator it = this->begin(); it != this->end(); it++){
		*it = std::tolower(*it);
	}
}

template <typename T>
void MutantStack<T>::rprint() const{
	for (MutantStack<T>::const_reverse_iterator it = this->rbegin(); it != this->rend(); it++){
		std::cout << *it;
	}
	std::cout << '\n';
}

template <typename T>
void MutantStack<T>::rtoupper(){
	for (MutantStack<T>::reverse_iterator it = this->rbegin(); it != this->rend(); it++){
		*it = std::toupper(*it);
	}
}