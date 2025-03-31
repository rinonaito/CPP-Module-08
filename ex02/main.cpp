#include "MutantStack.hpp"
#include <list>

static void printWithColor(std::string message, std::string color)
{
	const std::string kReset = "\033[0m";
	std::cout << color << message << kReset << std::endl; 
}

static void subjectTestMutantStack(){
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

static void subjectTestList(){
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

static void myTest(){
	const std::string kBlue = "\033[36m";
	MutantStack<char> myStack;
	myStack.push('H');
	myStack.push('E');
	myStack.push('L');
	myStack.push('L');
	myStack.push('O');
	//copy constructor
	MutantStack<char> copyConstructed(myStack);
	//copy assignment operator
	MutantStack<char> copyAssigned = copyConstructed;
	MutantStack<char> empty;
	//change MutantStack
	myStack.push('!');
	copyConstructed.pop();
	(*copyAssigned.begin()) = '*';
	printWithColor("original stack", kBlue);
	myStack.print();
	printWithColor("copy constructed stack", kBlue);
	copyConstructed.print();
	printWithColor("copy assigned stack", kBlue);
	copyAssigned.print();
	printWithColor("empty stack", kBlue);
	empty.print();
	//top
	printWithColor("top", kBlue);
	std::cout << "myStack        : " << myStack.top() << std::endl;
	std::cout << "copyConstructed: " << copyConstructed.top() << std::endl;
	std::cout << "copyAssigned   : " << copyAssigned.top() << std::endl;
	//empty
	printWithColor("empty", kBlue);
	std::cout << "myStack        : " << myStack.empty() << std::endl;
	std::cout << "copyConstructed: " << copyConstructed.empty() << std::endl;
	std::cout << "copyAssigned   : " << copyAssigned.empty() << std::endl;
	std::cout << "empty          : " << empty.empty() << std::endl;
	//size
	printWithColor("size", kBlue);
	std::cout << "myStack        : " << myStack.size() << std::endl;
	std::cout << "copyConstructed: " << copyConstructed.size() << std::endl;
	std::cout << "copyAssigned   : " << copyAssigned.size() << std::endl;
	std::cout << "empty          : " << empty.size() << std::endl;
	//const_iterator
	printWithColor("const_iterator", kBlue);
	myStack.print();
	//iterator
	printWithColor("iterator", kBlue);
	myStack.tolower();
	myStack.print();
	//const_reverse_iterator1
	printWithColor("const_reverse_iterator", kBlue);
	myStack.rprint();
	//const_reverse_iterator1
	printWithColor("reverse_iterator", kBlue);
	myStack.rtoupper();
	myStack.rprint();
}

int	main(void){
	const std::string kGreen = "\033[32m";
	printWithColor(">> test in subject with MutantStack", kGreen);
	subjectTestMutantStack();
	printWithColor(">> test in subject with std::list", kGreen);
	subjectTestList();
	printWithColor(">> my test", kGreen);
	myTest();
	return 0;
}