#ifndef MULTISET_SYS_CPP
# define MULTISET_SYS_CPP
# include <set>
# include "utils.cpp"

void        multiset_sys(void)
{
	{
		print_banner("Class Constructors");
		std::multiset<int> first;
		std::multiset<int>::iterator it;

		first.insert(50);
		first.insert(70);
		first.insert(30);
		first.insert(50);
		first.insert(20);

		std::cout << "first map contains:\n";
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "second map contains:\n";
		std::multiset<int> second (first.begin(),first.end());
		for (it=second.begin(); it!=second.end(); ++it)
			std::cout << *it<< '\n';

		std::cout << "third map contains:\n";
		std::multiset<int> third (second);
		for (it=third.begin(); it!=third.end(); ++it)
			std::cout << *it<< '\n';
	}
	{
		print_banner("operator=");
		int myints[]={ 19,81,36,36,19 };
		std::multiset<int> first (myints,myints+5);   // multiset with 5 ints
		std::multiset<int> second;                    // empty multiset

		second=first;                                 // now second contains the 5 ints
		first=std::multiset<int>();                   // and first is empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	{
		print_banner("rbegin and rend iterator functions");
		int myints[] = {77,16,2,30,30};
		std::multiset<int> mymultiset (myints,myints+5);

		std::cout << "mymultiset contains:";
		for (std::multiset<int>::reverse_iterator rit=mymultiset.rbegin(); rit!=mymultiset.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}
	{
		print_banner("empty and erase function");
		std::multiset<int> mymultiset;

		mymultiset.insert(10);
		mymultiset.insert(20);
		mymultiset.insert(10);

		std::cout << "mymultiset contains:";
		while (!mymultiset.empty())
		{
			std::cout << ' ' << *mymultiset.begin();
			mymultiset.erase(mymultiset.begin());
		}
		std::cout << '\n';
	}
	{
		print_banner("size and max_size functions");
		std::multiset<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.insert(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (5);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.erase (5);
		std::cout << "3. size: " << myints.size() << '\n';
		std::cout << "max_size: " << myints.max_size() << '\n';
	}
	{
		print_banner("insert function");
		std::multiset<int> mymultiset;
		std::multiset<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) mymultiset.insert(i*10);  // 10 20 30 40 50

		it=mymultiset.insert(25);

		it=mymultiset.insert (it,27);    // max efficiency inserting
		it=mymultiset.insert (it,29);    // max efficiency inserting
		it=mymultiset.insert (it,24);    // no max efficiency inserting (24<29)

		int myints[]= {5,10,15};
		mymultiset.insert (myints,myints+3);

		std::cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("swap function");
		int myints[]={19,72,4,36,20,20};
		std::multiset<int> first (myints,myints+3);     // 4,19,72
		std::multiset<int> second (myints+3,myints+6);  // 20,20,36

		first.swap(second);

		std::cout << "first contains:";
		for (std::multiset<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (std::multiset<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("clear function");
		std::multiset<int> mymultiset;

		mymultiset.insert (11);
		mymultiset.insert (42);
		mymultiset.insert (11);

		std::cout << "mymultiset contains:";
		for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mymultiset.clear();
		mymultiset.insert (200);
		mymultiset.insert (100);

		std::cout << "mymultiset contains:";
		for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		print_banner("find function");
		std::multiset<int> mymultiset;
		std::multiset<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50

		it=mymultiset.find(20);
		mymultiset.erase (it);
		mymultiset.erase (mymultiset.find(40));

		std::cout << "mymultiset contains:";
		for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("count function");
		int myints[]={10,73,12,22,73,73,12};
  		std::multiset<int> mymultiset (myints,myints+7);

  		std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";
	}
	{
		print_banner("equal_range function");
		int myints[]= {77,30,16,2,30,30};
		std::multiset<int> mymultiset (myints, myints+6);  // 2 16 30 30 30 77

		std::pair<std::multiset<int>::iterator,std::multiset<int>::iterator> ret = mymultiset.equal_range(30); //      ^        ^

		mymultiset.erase(ret.first,ret.second);

		std::cout << "mymultiset contains:";
		for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		print_banner("comparaision operators");
		std::multiset<int> multiset1;
		multiset1.insert(10);
		multiset1.insert(1);
		multiset1.insert(1);
		multiset1.insert(100);

		std::multiset<int> multiset2;
		multiset2.insert(10);
		multiset2.insert(1);
		multiset2.insert(1);
		multiset2.insert(100);

		if (multiset1 == multiset2)
			std::cout << "multiset1 is equal to multiset2" << std::endl;
		if (multiset1 < multiset2)
			std::cout << "multiset1 is smaller than multiset2" << std::endl;
		if (multiset1 <= multiset2)
			std::cout << "multiset1 is smaller than or equal to multiset2" << std::endl;
		if (multiset1 > multiset2)
			std::cout << "multiset1 is larger than multiset2" << std::endl;
		if (multiset1 >= multiset2)
			std::cout << "multiset1 is larger than or equal to multiset2" << std::endl;
		multiset1.insert(20);
		if (multiset1 == multiset2)
			std::cout << "multiset1 is equal to multiset2" << std::endl;
		if (multiset1 < multiset2)
			std::cout << "multiset1 is smaller than multiset2" << std::endl;
		if (multiset1 <= multiset2)
			std::cout << "multiset1 is smaller than or equal to multiset2" << std::endl;
		if (multiset1 > multiset2)
			std::cout << "multiset1 is larger than multiset2" << std::endl;
		if (multiset1 >= multiset2)
			std::cout << "multiset1 is larger than or equal to multiset2" << std::endl;
	}
}

#endif
