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
//走査（begin() ～ end()）
//要素の変更（*it = value）
//挿入（insert(it, value)）
//削除（erase(it)）
//逆順走査（rbegin() ～ rend()）
//検索（std::find()）
}

int	main(void){
	const std::string kBlue = "\033[36m";
	const std::string kGreen = "\033[32m";
	printWithColor("test in subject with MutantStack", kGreen);
	subjectTestMutantStack();
	printWithColor("test in subject with std::list", kGreen);
	subjectTestList();
	printWithColor("my test", kGreen);
	myTest();
	return 0;
}