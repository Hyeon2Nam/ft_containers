#include "allVector.hpp"

#define TESTED_TYPE int

int		v_rev_ite_construct(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

	/* error expected
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}
