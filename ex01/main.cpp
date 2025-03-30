#include "Span.hpp"
static void printWithColor(std::string message, std::string color)
{
	const std::string kReset = "\033[0m";
	std::cout << color << message << kReset << std::endl; 
}

int	main(void){
	const std::string kBlue = "\033[36m";
	const std::string kGreen = "\033[32m";

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

	// init span with addRandomNumbers()
	printWithColor(">> add element with addRandomNumbers()", kGreen);
	const int num_of_elem = 10;
	Span span = Span(num_of_elem);
	span.addRandomNumbers(num_of_elem);
	printWithColor("elements", kBlue);
	span.printElements();
	printWithColor("shortest span", kBlue);
	std::cout << span.shortestSpan() << std::endl;
	printWithColor("longest span", kBlue);
	std::cout << span.longestSpan() << std::endl;

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
