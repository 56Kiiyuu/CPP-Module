#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <exception>
# include <stdexcept>
# include <iostream>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();
		void addNumber(int number);

		//add template functional with other containers
		template <typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end)
		{
			if (this->_numbers.size() + std::distance(begin, end) > this->_maxSize)
			{
				throw std::out_of_range("Adding this range exceeds Span capacity!");
			}
			this->_numbers.insert(this->_numbers.end(), begin, end);
		}

		int	shortestSpan();
		int	longestSpan();

		// Exceptions
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span is already full!";
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough elements to find a span (need at least 2)";
				}
		};
};

#endif
