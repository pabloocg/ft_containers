#ifndef VECTOR_SYS_CPP
# define VECTOR_SYS_CPP
# include <vector>
# include <iostream>
# include "utils.cpp"


void	vector_sys(void)
{
    
    {
        std::cout << "Assign Function: " << std::endl;
        std::vector<int> first;
        std::vector<int> second;
        std::vector<int> third;

        first.assign (7, 100);             // 7 ints with a value of 100

        std::vector<int>::iterator it;
        it = first.begin() + 1;

        second.assign (it, first.end() - 1); // the 5 central values of first

        int myints[] = {1776, 7, 4};
        third.assign (myints, myints + 3);   // assigning from array.

        std::cout << "first vector [100 100 100 100 100 100 100] = ";
        for (it = first.begin(); it != first.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "second vector [100 100 100 100 100] = ";
        for (it = second.begin(); it != second.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "third vector [1776 7 4] = ";
        for (it = third.begin(); it != third.end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "Size of first: " << int (first.size()) << std::endl;
        std::cout << "Size of second: " << int (second.size()) << std::endl;
        std::cout << "Size of third: " << int (third.size()) << std::endl;
    }
    {
        std::cout << "at element access function:" << std::endl;
        std::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        std::cout << "myvector contains at initialization construct:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector.at(i);
        for (size_t i = 0; i < myvector.size(); i++) myvector.at(i) = i;
        std::cout << std::endl << "myvector contains after assign new values:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector.at(i);
        std::cout << std::endl;
    }
    {
        std::cout << "back function:" << std::endl;
        std::vector<int> myvector;

        myvector.push_back(10);
        while (myvector.back() != 0) myvector.push_back (myvector.back() - 1);
        std::cout << "myvector contains:";
        for (size_t i = 0; i < myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;
    }
    {
        std::cout << "begin function:" << std::endl;
        std::vector<int> myvector;
        for (int i = 1; i <= 5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }
    {
        std::cout << "capacity function:" << std::endl;
        std::vector<int> myvector;

        // set some content in the vector:
        for (int i = 0; i < 100; i++) myvector.push_back(i);

        std::cout << "size: " << myvector.size() << '\n';
        std::cout << "capacity: " << myvector.capacity() << '\n';
        std::cout << "max_size: " << myvector.max_size() << '\n';
    }
    {
        std::cout << "clear function:" << std::endl;
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;

        std::cout << myvector.capacity() << std::endl;
        myvector.clear();
        std::cout << myvector.capacity() << std::endl;
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++) std::cout << ' ' << myvector[i];
        std::cout << std::endl;
        std::cout << myvector.capacity() << std::endl;
    }
    {
        std::cout << "empty | push_back | pop_back function:" << std::endl;
        std::vector<int> myvector;
        int sum (0);

        for (int i = 1; i <= 10; i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }
        std::cout << "total: " << sum << '\n';
    }
    {
        std::cout << "end function:" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i <= 5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.end() - 1 ; it != myvector.begin(); --it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        std::cout << "erase function:" << std::endl;
        std::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i = 1; i <= 10; i++) myvector.push_back(i);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';
        // erase the 6th element
        myvector.erase (myvector.begin() + 5);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';

        // erase the first 3 elements:
        myvector.erase (myvector.begin(), myvector.begin() + 3);
        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i) std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        std::cout << "front function:" << std::endl;
        std::vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
        std::cout << "myvector.back() is now " << myvector.back() << '\n';

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    {
        std::cout << "insert function:" << std::endl;
        std::vector<int> myvector (3, 100);
        std::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert(it, 200);

        myvector.insert(it, 2, 300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2, 400);
        myvector.insert (it + 2, anothervector.begin(), anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray + 3);

        std::cout << "myvector contains:";
        for (it = myvector.begin(); it < myvector.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        std::cout << "max_size function:" << std::endl;
        std::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
    }
    {
        std::cout << "operator= :" << std::endl;
        std::vector<int> foo (3, 1);
        std::vector<int> bar (5, 2);
        std::vector<int>::iterator it;
        std::cout << "bar vector contains:";
        for (it = bar.begin(); it < bar.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "foo vector contains:";
        for (it = foo.begin(); it < foo.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';

        bar = foo;
        std::cout << "bar vector contains:";
        for (it = bar.begin(); it < bar.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';
        foo = std::vector<int>(10, 100);
        std::cout << "foo vector contains:";
        for (it = foo.begin(); it < foo.end(); it++) std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "Size of foo: " << int(foo.size()) << '\n';
        std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }
    {
        std::cout << "operator[]:" << std::endl;
        std::vector<int> myvector (10);   // 10 zero-initialized elements

        std::vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        std::cout << "rbegin funtion:" << std::endl;
        std::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        std::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            *rit = ++i;

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        std::vector<int>::size_type sz;

        std::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        std::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }
    }
    {
        std::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (size_t i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
    }
    {
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
}

#endif
