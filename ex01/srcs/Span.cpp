#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <unistd.h>

Span::Span() {}

Span::Span(unsigned int N)
{
    if (N >= v_.max_size() || N < 2)
    {
        Span::InvalidSize e("Invalid size: Expected 2 or more!");
        throw e;
    }
    v_.reserve(N);
    size_ = N;
    effectiveSize_ = 0;
}

Span    &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        v_ = other.v_;
        size_ = other.size_;
    }
    return *this;
}

int Span::randomInt() const
{
    usleep(1000);
    int seed = static_cast<int>(std::chrono::system_clock::now().time_since_epoch().count());
    std::srand(seed);
    int r = std::rand() % 500000;
    //std::cout << "random val = " << r << std::endl;
    return r;
}

Span::Span(const Span &other)
{
    v_ = other.v_;
	size_ = other.size_;
}

Span::~Span()
{

}
		//required
void Span::addNumber(int n)
{
    Span::Full e("Already reached max capacity!");
    if (effectiveSize_ == size_)
        throw e;
    v_.insert(v_.begin(), n);
    effectiveSize_ += 1;
}

void Span::addMany(void)
{
    for (unsigned int i = 0; i < size_; ++i)
    {
        v_.push_back(this->randomInt());
    }
    effectiveSize_ = size_;
}

int Span::shortestSpan()
{
    Span::NotFull e("Added numbers don't match container size!");
    if (effectiveSize_ != size_)
        throw e;
    int span = std::numeric_limits<int>::max();
    std::sort(v_.begin(), v_.end());
    for (std::vector<int>::iterator it = v_.begin() + 1; it != v_.end(); ++it)
    {
        std::vector<int>::iterator prev = it - 1;
        if ((*it - *prev) < span)
            span = *it - *prev;
    }
    return (span);
}

int Span::longestSpan()
{
    Span::NotFull e("Added numbers don't match container size!");
    if (effectiveSize_ != size_)
        throw e;
    return (*(std::max_element(v_.begin(), v_.end())) - *(std::min_element(v_.begin(), v_.end())));
}

void Span::print()
{
    std::cout << "longest span  = " << this->longestSpan() << std::endl;
    std::cout << "shortest span = " << this->shortestSpan() << std::endl;
}

const unsigned int &Span::getSize() const
{
    return size_;
}
