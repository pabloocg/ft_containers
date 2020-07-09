#ifndef VECTOR_SYS_CPP
# define VECTOR_SYS_CPP
# include <vector>
# include <iostream>
# include "utils.cpp"


void	vector_sys(void)
{
    std::vector<int> vec;

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
