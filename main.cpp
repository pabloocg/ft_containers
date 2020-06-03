#include <iostream>
#include "list.hpp"


int main()
{
    {
        ft::list<int>   i1;

        i1.push_back(10);
        std::cout << "List size: " << i1.size() << std::endl;
        std::cout << "Front element in list " << i1.front() << std::endl;
        i1.pop_front();
        std::cout << "List size: " << i1.size() << std::endl;
        i1.push_back(4);
        i1.push_back(2);
        std::cout << "Back element in list " << i1.back() << std::endl;
        i1.pop_back();
        std::cout << "Back element in list " << i1.back() << std::endl;
        i1.push_front(20);
        std::cout << "Front element in list " << i1.front() << std::endl;
    }
    {
        ft::list<int> mylist;

        for (int i=1; i<10; ++i)
            mylist.push_back(i);

        mylist.resize(5);
        mylist.resize(8, 100);
        mylist.resize(12);

        std::cout << "mylist contains:";
        for (; mylist.size() > 0;)
        {
            std::cout << ' ' << mylist.front();
            mylist.pop_front();
        }
        std::cout << '\n';
    }
    return (0);
}