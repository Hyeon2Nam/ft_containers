#include "vector/vector.hpp"
#include <vector>
#include <algorithm>
int main()
{
	// ======== [ft] ========
	std::cout << "a :[";
	ft::vector<int> tmp(3, 100);
	ft::vector<int> a(tmp.begin(), tmp.end());

	for (ft::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	// ======== [std] ========

	std::vector<int> c(5, 200);
	std::vector<int> b(3, 100);

	std::cout << std::distance(b.end(), b.begin()) << std::endl;

	std::cout << "b :[";
	for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	return (0);
}