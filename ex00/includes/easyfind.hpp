#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <exception>

class IntegerNotFound : public std::exception
{
	private:
		std::string msg_;
	public:
		IntegerNotFound(const std::string &msg) : msg_(msg) {}
		~IntegerNotFound() throw();
		const char *what() const throw() {return msg_.c_str();}
};

template <class T> int *easyfind(T c, int n)
{
	IntegerNotFound error("easyfind: Error: integer not found!" << std::endl;
	for (T::iterator it = c.begin(); it != c.end(); ++it)
	{
		if (*it == n)
			return (&(*it));
	}
	throw (error);
	return NULL;
}





#endif
