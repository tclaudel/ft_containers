//
// Created by tclaudel on 10/13/20.
//

#include <iostream>
#include <vector>
#include "main.hpp"

int 	test_allocator(void) {
	std::vector<int, ft::Allocator<int>> array;
	array.push_back(5);
	std::cout << array[0] << std::endl;
	return 0;
}

int 	main(void)
{
	test_allocator();
}