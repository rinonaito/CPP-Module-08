#include "Span.hpp"
#include <vector>

int	main(void){
	Span<std::vector<int> > span;
	span.addNumber(1);
	span.addRandomNumbers(4);
	(void)span;



	return 0;
}
