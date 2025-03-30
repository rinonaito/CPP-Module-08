#include "Span.hpp"
#include <ctime>
static void printWithColor(std::string message, std::string color)
{
	const std::string kReset = "\033[0m";
	std::cout << color << message << kReset << std::endl; 
}
static std::vector<int> crateRandomVector(size_t size){
	int new_element;
	std::vector<int> ret;
	for (size_t index = 0; index < size; index++){
		new_element = rand() % 100;
		ret.push_back(new_element);
		std::cout << "add " << new_element << " to the src vector" << std::endl;
	}
	return ret;
}
int	main(void){
	const std::string kBlue = "\033[36m";
	const std::string kGreen = "\033[32m";
	std::srand(std::time(NULL));

	// init span with addNumber()
	printWithColor(">> test in subject", kGreen);
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// add element beyond the limit
	printWithColor(">> add element beyond the limit", kGreen);
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// init span with addNumberWithIter()
	printWithColor(">> add element with addNumberWithIter()", kGreen);
	const int num_of_elem = 10;
	Span span = Span(num_of_elem);
	std::vector<int> src = crateRandomVector(num_of_elem);
	span.addNumberWithIter(src.begin(), src.end());
	printWithColor("elements", kBlue);
	span.printElements();
	printWithColor("shortest span", kBlue);
	std::cout << span.shortestSpan() << std::endl;
	printWithColor("longest span", kBlue);
	std::cout << span.longestSpan() << std::endl;
	// add element beyond the limit
	printWithColor(">> add element beyond the limit", kGreen);
	try
	{
		std::vector<int> src2 = crateRandomVector(1);
		span.addNumberWithIter(src2.begin(), src2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	printWithColor(">> call shortestSpan() when no numbers stored", kGreen);
	Span span_with_no_span(42);
	printWithColor("elements", kBlue);
	span_with_no_span.printElements();
	try
	{
		printWithColor("shortest span", kBlue);
		span_with_no_span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	printWithColor(">> call longestSpan() when only one number is stored", kGreen);
	span_with_no_span.addNumber(42);	
	printWithColor("elements", kBlue);
	span_with_no_span.printElements();
	try
	{
		printWithColor("longest span", kBlue);
		span_with_no_span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
