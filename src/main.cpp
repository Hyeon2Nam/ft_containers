#include "vector/vector.hpp"
#include <vector>

int main()
{
	std::cout << "a :[";
	ft::vector<int> a(3, 100);
	a.print_arr();

	std::cout << "]" << std::endl;

	std::cout << "b :[";
	std::vector<int> b(3, 100);
	for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " " << std::endl;
	std::cout << "]" << std::endl;
	
}