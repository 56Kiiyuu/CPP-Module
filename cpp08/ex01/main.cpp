#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	std::cout << "TEST" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(10);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Doit afficher 2
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;  // Doit afficher 14
	}

	std::cout << "\nTEST 20 000 ELEM (Range of Iterators)" << std::endl;
	{
		std::srand(std::time(NULL));

		std::vector<int> bigVector;
		for (int i = 0; i < 20000; ++i)
		{
			bigVector.push_back(std::rand());
		}

		Span sp = Span(20000);

		// ADD Big vector
		sp.addNumber(bigVector.begin(), bigVector.end());

		std::cout << "Shortest span (20 000 numbers): " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span  (20 000 numbers): " << sp.longestSpan() << std::endl;
	}

	std::cout << "\nTEST EXCEPTIONS" << std::endl;
	{
		Span sp = Span(1);
		sp.addNumber(42);

		try
		{
			std::cout << "Trying to add a second element to Span(1)..." << std::endl;
			sp.addNumber(21);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			std::cout << "Trying to compute span on single element..." << std::endl;
			sp.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
