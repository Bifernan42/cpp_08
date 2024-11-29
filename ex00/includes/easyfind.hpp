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
		~IntegerNotFound() throw() {}
		const char *what() const throw() {return msg_.c_str();}
};

template <class T> int *easyfind(T c, int n)
{
	IntegerNotFound error("easyfind: Error: integer not found!");
	typename T::iterator it = std::find(c.begin(), c.end(), n);
	if (it == c.end())
	   throw (error);
	else
	{
	   return (&(*it));
	}
	return NULL;
}

#endif
