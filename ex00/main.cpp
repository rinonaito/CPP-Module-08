#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

static void printWithColor(std::string message, std::string color)
{
	const std::string kReset = "\033[0m";
	std::cout << color << message << kReset << std::endl; 
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
		
		std::cout << "[" << std::distance(container.begin(), it) << "]: "<< *it << std::endl;
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
	const std::string kBlue = "\033[36m";
	const std::string kGreen = "\033[32m";
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
	printWithColor(">> print container contents", kGreen);
	printWithColor("print int_vector", kBlue);
	printSequentialContainer(int_vector);
	printWithColor("print int_deque", kBlue);
	printSequentialContainer(int_deque);
	printWithColor("print int_list", kBlue);
	printSequentialContainer(int_list);
	printWithColor("print char_list", kBlue);
	printSequentialContainer(char_list);
	printWithColor("print int_vector_empty", kBlue);
	printSequentialContainer(int_vector_empty);

	//call easyfind
	printWithColor(">> print easyfind results", kGreen);
	const int default_target = 42;
	printWithColor("find 42 form int_vector", kBlue);
	printEasyfindResult(int_vector, default_target);
	printWithColor("find 43 from int_deque", kBlue);
	printEasyfindResult(int_deque, default_target + 1);
	printWithColor("find 44 from int_list", kBlue);
	printEasyfindResult(int_list, default_target + 2);
	printWithColor("find 45 from char_list", kBlue);
	printEasyfindResult(char_list, default_target + 3);
	printWithColor("find 42 from int_vector_empty", kBlue);
	printEasyfindResult(int_vector_empty, default_target);
	printWithColor("find 0 from list", kBlue);
	printEasyfindResult(int_list, 0);
	return 0;
}
