#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

/**/
int main() 
{
	std::cout << "TEST : Empty array" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

	std::cout << "\nTEST : Default Init" << std::endl;
	Array<int> intArray(5);
	std::cout << "Size of intArray: " << intArray.size() << std::endl;
	std::cout << "Values (should be 0): ";
	for (unsigned int i = 0; i < intArray.size(); i++) 
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\nTEST : MODIFICATION AND COPY" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) 
	{
		intArray[i] = (i + 1) * 10;
	}

	Array<int> copyArray(intArray); // Copy constructor
	intArray[0] = 999; // modification [0]

	std::cout << "Original intArray[0]: " << intArray[0] << " (Modified)" << std::endl;
	std::cout << "Copy copyArray[0]:     " << copyArray[0] << " (Must stay 10)" << std::endl;

	std::cout << "\nTEST : Types std::string" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "42";
	strArray[2] = "School";

	for (unsigned int i = 0; i < strArray.size(); i++) 
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\nTEST : Out of Bounds Exception" << std::endl;
	try 
	{
		std::cout << "Trying to access index 42..." << std::endl;
		std::cout << intArray[42] << std::endl;
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "Trying to access index -1..." << std::endl;
		std::cout << intArray[-1] << std::endl;
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

/*
#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}*/