#ifndef VECTOR_TEST_CPP
# define VECTOR_TEST_CPP

# include "../vector.hpp"
# include <iostream>
# include "utils.cpp"


void	vector_test(void)
{
    ft::vector<int> vec;

    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
    vec.push_back(4);
    std::cout << vec.capacity() << std::endl;
}

#endif
