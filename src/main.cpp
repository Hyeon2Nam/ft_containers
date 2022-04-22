#include "vector/vector.hpp"
#include <vector>

int main()
{
	// ======== [ft] ========
	std::cout << "a :[";
	ft::vector<int> tmp(3, 100);
	ft::vector<int> tmp2(tmp);
	ft::vector<int> a(2, 200);
	a = tmp2;

	for (ft::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;


	// ======== [std] ========
	std::cout << "b :[";
	std::vector<int> b(3, 100);
	for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	return (0);
}