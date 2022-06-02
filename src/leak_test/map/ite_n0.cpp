#include "allMap.hpp"

#define int int
#define int int

int		t_ite_n0(void)
{
	ft::map<int, int> mp;
	mp[1] = 2;

	ft::map<int, int>::const_iterator ite = mp.begin();
	std::cout << ite->first << " " << ite->second;
	return (0);
}
