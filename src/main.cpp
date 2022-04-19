#include "Iterator/iterator.hpp"
#include "Iterator/Reverse_iterator.hpp"
#include <vector>

int main()
{
	std::vector<int> a;

	for (int i = 0; i < 5; i++)
		a.push_back(i);
	for (std::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		std::cout << *i << " " << std::endl;
}