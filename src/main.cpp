#include "vector/vector.hpp"
#include <vector>
#include <algorithm>
int main()
{
	// ======== [ft] ========
	ft::vector<int> a(3, 100);

	// for (size_t i = 0; i < 5; i++)
		// a.push_back(i);

	std::cout << "a :[";
	for (ft::vector<int>::reverse_iterator i = a.rbegin(); i != a.rend(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	// ======== [std] ========

	std::vector<int> b(3, 100);

	// for (size_t i = 0; i < 5; i++)
	// 	a.push_back(i);


	std::cout << "b :[";
	for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	return (0);
}