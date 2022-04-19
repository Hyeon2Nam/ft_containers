#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>

class Utils
{

	public:

		Utils();
		Utils( Utils const & src );
		~Utils();

		Utils &		operator=( Utils const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Utils const & i );

#endif /* *********************************************************** UTILS_H */