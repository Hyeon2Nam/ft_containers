#ifndef iterator_TPP
#define iterator_TPP

#include "iterator.hpp"

template <class InputIterator, class Distance>
  void advance (InputIterator& it, Distance n);



/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

iterator::iterator()
{
}

iterator::iterator( const iterator & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

iterator::~iterator()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

iterator &				iterator::operator=( iterator const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, iterator const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

#endif

/* ************************************************************************** */