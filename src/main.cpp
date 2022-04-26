#include "vector/vector.hpp"
#include <vector>
#include <algorithm>
int main()
{
	// ======== [ft] ========
	ft::vector<int> d(5, 200);
	ft::vector<int> a(3, 100);


	a.insert(a.begin() + 2, d.begin(), d.end());


	std::cout << "a :[";
	for (ft::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;


	// ======== [std] ========

	std::vector<int> c(5, 200);
	std::vector<int> b(3, 100);

	b.insert(b.begin() + 2, c.begin(), c.end());

	std::cout << "b :[";
	for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " ";
	std::cout << "]" << std::endl;

	return (0);
}