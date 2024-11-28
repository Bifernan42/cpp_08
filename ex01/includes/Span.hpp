#ifndef SPAN_HPP
# define SPAN_HPP
# include "cpplib.hpp"
# include <exception>
# include <cstdlib>
# include <ctime>

class Span
{
	private:
		std::vector<int> v_;
		unsigned int size_;
		Span();
		unsigned int effectiveSize_;
	public:
		Span(unsigned int N);
		Span &operator=(const Span &);
		Span(const Span &);
		~Span();
		//required
		void addNumber(int n);
		void addMany(void);
		int shortestSpan();
		int longestSpan();
		int randomInt() const;
		const unsigned int &getSize() const;
		class InvalidSize;
		class Full;
		class NotFull;
		void print();
};

class Span::InvalidSize : public std::exception
{
    private:
        std::string msg_;
    public:
        InvalidSize(const std::string &msg)
        {
            msg_ = msg;
        }
        ~InvalidSize() throw() {}
        const char *what() const throw()
        {
            return msg_.c_str();
        }
};

class Span::Full : public std::exception
{
    private:
        std::string msg_;
    public:
        Full(const std::string &msg)
        {
            msg_ = msg;
        }
        ~Full() throw() {}
        const char *what() const throw()
        {
            return msg_.c_str();
        }
};

class Span::NotFull : public std::exception
{
    private:
        std::string msg_;
    public:
        NotFull(const std::string &msg)
        {
            msg_ = msg;
        }
        ~NotFull() throw() {}
        const char *what() const throw()
        {
            return msg_.c_str();
        }
};

#endif
