#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

static void printWithBlueColor(std::string message)
{
	const std::string kBulue = "\033[36m";
	const std::string kReset = "\033[0m";
	std::cout << kBulue << message << kReset << std::endl; 
}

template<typename T>
void	initializeSequentialContainer(T &container, size_t size){
	for (size_t index = 0; index < size; index++){
		container.push_back((int)(index) + 42);
	}
}

template<typename T>
void printSequentialContainer(T &container){
	for (typename T::iterator it = container.begin(); it != container.end(); it++){
		std::cout << *it << std::endl;
	}
	return;
}

template<typename T>
void printEasyfindResult(T &container, int target){
	try
	{
		typename T::iterator it = easyfind(container, target);
		std::cout << "found: " << *it << " at " << std::distance(container.begin(), it)<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void){
	//create sequense containers
	std::vector<int> int_vector;
	std::deque<int> int_deque;
	std::list<int> int_list;
	std::list<char> char_list;
	std::vector<int> int_vector_empty;
	initializeSequentialContainer(int_vector, 5);
	initializeSequentialContainer(int_deque, 5);
	initializeSequentialContainer(int_list, 5);
	initializeSequentialContainer(char_list, 5);

	//print container contents
	printWithBlueColor("print int_vector");
	printSequentialContainer(int_vector);
	printWithBlueColor("print int_deque");
	printSequentialContainer(int_deque);
	printWithBlueColor("print int_list");
	printSequentialContainer(int_list);
	printWithBlueColor("print char_list");
	printSequentialContainer(char_list);
	printWithBlueColor("print int_vector_empty");
	printSequentialContainer(int_vector_empty);

	//call easyfind
	const int default_target = 42;
	printWithBlueColor("find 1 form int_vector");
	printEasyfindResult(int_vector, default_target);
	printWithBlueColor("find 2 from int_deque");
	printEasyfindResult(int_deque, default_target + 1);
	printWithBlueColor("find 3 from int_list");
	printEasyfindResult(int_list, default_target + 2);
	printWithBlueColor("find 4 from char_list");
	printEasyfindResult(char_list, default_target + 3);
	printWithBlueColor("find 4 from int_vector_empty");
	printEasyfindResult(int_vector_empty, default_target);
	printWithBlueColor("find 0 from list");
	printEasyfindResult(int_list, 0);
	return 0;
}
