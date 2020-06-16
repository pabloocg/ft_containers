#include <iostream>
#include "list.hpp"
#include <list>

bool    greater_than_10(int n)
{
    return (n > 10);
}

bool compare(double a, double b) 
{ 
    return ((int)a == (int)b); 
} 

template <typename T>
bool equal_plus_one(T first, T second) {
	return (second == (first + 1));
}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main()
{
    /*{
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
        ft::list<int>   mylist;

        for (int i=1; i<10; ++i)
            mylist.push_back(i);

        mylist.resize(5);
        mylist.resize(8, 100);
        mylist.resize(12);

        std::cout << "mylist contains:";
        for (ft::list<int>::iterator it=mylist.cbegin(); it!=mylist.cend(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        ft::list<int> first (3, 100);   // three ints with a value of 100
        ft::list<int> second (5, 200);  // five ints with a value of 200

        first.swap(second);

        std::cout << "first contains:";
        for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "second contains:";
        ft::list<int>::iterator it = second.begin();
        while (it != second.end())
        {
            std::cout << ' ' << *it;
            it += 2;
        }
        std::cout << '\n';
    }
    {
        ft::list<int> mylist;
        ft::list<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

        it = mylist.begin();
        ++it;       // it points now to number 2           ^

        mylist.insert (it, 10);                        // 1 10 2 3 4 5
        std::cout << "mylist contains: ";
        for (ft::list<int>::iterator tmpit=mylist.begin(); tmpit!=mylist.end(); ++tmpit)
            std::cout << ' ' << *tmpit;
        std::cout << '\n';
        // "it" still points to number 2                      ^
        mylist.insert (it, 2, 20);                      // 1 10 20 20 2 3 4 5
        
        std::cout << "mylist contains: ";
        for (ft::list<int>::iterator tmpit=mylist.begin(); tmpit!=mylist.end(); ++tmpit)
            std::cout << ' ' << *tmpit;
        std::cout << '\n';
        --it;       // it points now to the second 20            ^

        ft::list<int> myvector (2, 30);
        mylist.insert (it, myvector.begin(), myvector.end());
                                                        // 1 10 20 30 30 20 2 3 4 5
                                                        //               ^
        std::cout << "mylist contains: ";
        for (ft::list<int>::iterator tmpit=mylist.begin(); tmpit!=mylist.end(); ++tmpit)
            std::cout << ' ' << *tmpit;
        std::cout << '\n';
    }
    {
        ft::list<int> mylist;
        ft::list<int>::iterator it1, it2;

        // set some values:
        for (int i=1; i<10; ++i) mylist.push_back(i*10);

                                    // 10 20 30 40 50 60 70 80 90
        it1 = it2 = mylist.begin(); // ^^
        it2 += 6;                   // ^                 ^
        ++it1;                      // ^   ^

        it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                                    //    ^           ^
        std::cout << "mylist contains:";
        for (ft::list<int>::iterator tmp=mylist.begin(); tmp!=mylist.end(); ++tmp)
            std::cout << ' ' << *tmp;
        std::cout << '\n';
        it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                                    //    ^           ^
        std::cout << "mylist contains:";
        for (ft::list<int>::iterator tmp=mylist.begin(); tmp!=mylist.end(); ++tmp)
            std::cout << ' ' << *tmp;
        std::cout << '\n';

        //++it1;                      //       ^        ^
        //--it2;                      //       ^     ^

        mylist.erase (it1,it2);     // 10 30 60 80 90
                                    //        ^

        std::cout << "mylist contains:";
        for (ft::list<int>::iterator tmp=mylist.begin(); tmp!=mylist.end(); ++tmp)
            std::cout << ' ' << *tmp;
        std::cout << '\n';
        mylist.clear();
    }
    {
        ft::list<int> mylist1, mylist2;
        ft::list<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=4; ++i) mylist1.push_back(i);      // mylist1: 1 2 3 4

        for (int i=1; i<=3; ++i) mylist2.push_back(i * 10);   // mylist2: 10 20 30

        it = mylist1.begin();
        ++it;                         // points to 2

        mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                        // mylist2 (empty)
                                        // "it" still points to 2 (the 5th element)

        std::cout << "mylist1 contains:";
        for (ft::list<int>::iterator tmpit=mylist1.begin(); tmpit!=mylist1.end(); ++tmpit)
            std::cout << ' ' << *tmpit;
        std::cout << "\n";

        std::cout << "mylist2 contains:";
        for (ft::list<int>::iterator tmpit=mylist2.begin(); tmpit!=mylist2.end(); ++tmpit)
            std::cout << ' ' << *tmpit;
        std::cout << '\n';
        
        mylist2.splice (mylist2.begin(), mylist1, it);
                                        // mylist1: 1 10 20 30 3 4
                                        // mylist2: 2
                                        // "it" is now invalid.
        std::cout << "mylist1 contains:";
        for (it=mylist1.begin(); it!=mylist1.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "mylist2 contains:";
        for (it=mylist2.begin(); it!=mylist2.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        it = mylist1.begin();
        it += 3;           // "it" points now to 30

        mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                        // mylist1: 30 3 4 1 10 20

        std::cout << "mylist1 contains:";
        for (it=mylist1.begin(); it!=mylist1.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "mylist2 contains:";
        for (it=mylist2.begin(); it!=mylist2.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        ft::list<int> l;
 
        l.push_back(1);
        l.push_back(100);
        l.push_back(2);
        l.push_back(3);
        l.push_back(10);
        l.push_back(11);
        l.push_back(-1);
        l.push_back(12);
        l.remove(1); // remove both elements equal to 1
        l.remove_if(greater_than_10); // remove all elements greater than 10
    
        for (ft::list<int>::iterator it = l.begin(); it != l.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
        std::cout << "Size:" << l.size() << std::endl;
    }
    {
        ft::list<int> x;
 
        x.push_back(1);
        x.push_back(1);
		x.push_back(2);
		x.push_back(1);
		x.push_back(2);
		x.push_back(3);
        x.push_back(3);
		x.push_back(2);
		x.push_back(6);

        std::cout << "contents before:";
        for (ft::list<int>::iterator it = x.begin(); it != x.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
        
        x.unique();

        std::cout << "contents after unique():";
        for (ft::list<int>::iterator it = x.begin(); it != x.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
    }
    {
        std::list<int> x;
 
        x.push_back(1);
        x.push_back(1);
		x.push_back(2);
		x.push_back(1);
		x.push_back(2);
		x.push_back(3);
        x.push_back(3);
		x.push_back(2);
		x.push_back(6);

        std::cout << "contents before:";
        for (std::list<int>::iterator it = x.begin(); it != x.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
        
        x.unique();

        std::cout << "contents after unique():";
        for (std::list<int>::iterator it = x.begin(); it != x.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
    }
    {
        ft::list<double> listy;
  
        listy.push_back(2.55);
        listy.push_back(3.15);
        listy.push_back(4.16);
        listy.push_back(4.16);
        listy.push_back(4.77);
        listy.push_back(12.65);
        listy.push_back(12.65);
        listy.push_back(13.59);

        std::cout << "contents before:";
        for (ft::list<double>::iterator it = listy.begin(); it != listy.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';

        std::cout << "contents after unique():"; 
    
        // unique operation on list with no parameters 
        listy.unique(); 
        // starts from the first element 
        // of the list to the last 
        for (ft::list<double>::iterator it = listy.begin(); it != listy.end(); ++it) 
            std::cout << *it << " "; 
        std::cout << '\n';
        // unique operation on list with parameter 
        listy.unique(compare); 
    
        std::cout << "contents after unique(compare):";
    
        // starts from the first element 
        // of the list to the last 
        for (ft::list<double>::iterator it = listy.begin(); it != listy.end(); ++it) 
            std::cout << *it << " "; 
        std::cout << '\n';
    }
    {
        ft::list<int> list1;
        ft::list<int> list2;
    
        list1.push_back(5);
        list1.push_back(9);
        list1.push_back(0);
        list1.push_back(1);
        list1.push_back(3);

        list2.push_back(8);
        list2.push_back(7);
        list2.push_back(2);
        list2.push_back(6);
        list2.push_back(4);
        list1.merge(list2);
        std::cout << "list1 after merge:  ";
        for (ft::list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';
        std::cout << "list2 after merge:  ";
        for (ft::list<int>::iterator it = list2.begin(); it != list2.end(); ++it)
            std::cout << *it << ' ';
        std::cout << '\n';

    }
    {
        ft::list<double> first, second;

        first.push_back (3.1);
        first.push_back (2.9);
        first.push_back (2.2);
        first.push_back (7.2);
        first.push_back (-2.2);
        first.push_back (4.2);
        first.push_back (1.2);

        second.push_back (7.1);
        second.push_back (3.7);
        second.push_back (1.4);
        second.push_back (10.4);
        second.push_back (-1.1);
        second.push_back (2.4);
        second.push_back (3.4);

        std::cout << "first contains:";
        for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        first.sort();

        std::cout << "first contains after sort:";
        for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        
        std::cout << "second contains:";
        for (ft::list<double>::iterator it=second.begin(); it!=second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        second.sort();
        std::cout << "second contains after sort:";
        for (ft::list<double>::iterator it=second.begin(); it!=second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        first.merge(second);

        std::cout << "first contains:";
        for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        // (second is now empty)

        second.push_back (2.1);

        first.merge(second, mycomparison);

        std::cout << "first contains:";
        for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        ft::list<int> mylist;

        for (int i=1; i<10; ++i) mylist.push_back(i);

        std::cout << "mylist contains:";
        for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        mylist.reverse();

        std::cout << "mylist contains after reverse:";
        for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }*/
    {
        ft::list<int> mylist;
        ft::list<int> syslist;

        mylist.push_back(2);
        mylist.push_back(10);
        mylist.push_back(3);
        mylist.push_back(4);

        syslist.push_back(2);
        syslist.push_back(10);
        syslist.push_back(3);
        syslist.push_back(4);

        if (mylist >= syslist)
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
    return (0);
}