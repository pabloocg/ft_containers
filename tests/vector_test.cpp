//#include "../vector.hpp"
#include <vector>
#include <iostream>

int     main()
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
    return (0);
}
