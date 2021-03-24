#ifndef MULTIMAP_SYS_CPP
# define MULTIMAP_SYS_CPP
# include <map>
# include "utils.cpp"

void        multimap_sys(void)
{
	{
		print_banner("Constructors and iterators begin - end");
		std::multimap<char,int>::iterator it;
		std::multimap<char,int> first;

		first.insert(std::pair<char,int>('a', 10));
		first.insert(std::pair<char,int>('c', 50));
		first.insert(std::pair<char,int>('b', 70));
		first.insert(std::pair<char,int>('b', 30));

		std::cout << "first map contains:\n";
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "second map contains:\n";
		std::multimap<char,int> second (first.begin(),first.end());
		for (it=second.begin(); it!=second.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "third map contains:\n";
		std::multimap<char,int> third (second);
		for (it=third.begin(); it!=third.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		print_banner("operator=");
		std::multimap<char,int> foo,bar;

		foo.insert(std::make_pair('x',32));
		foo.insert(std::make_pair('y',64));
		foo.insert(std::make_pair('y',96));
		foo.insert(std::make_pair('z',128));

		bar = foo;                  // bar now contains 4 ints
		foo.clear();                // and first is now empty

		std::cout << "Size of foo: " << foo.size() << '\n';
		std::cout << "Size of bar: " << bar.size() << '\n';
	}
	{
		print_banner("rbegin and rend iterators");
		std::multimap<char,int> mymultimap;

		mymultimap.insert (std::make_pair('x',10));
		mymultimap.insert (std::make_pair('y',20));
		mymultimap.insert (std::make_pair('y',150));
		mymultimap.insert (std::make_pair('z',9));

		// show content:
		std::multimap<char,int>::reverse_iterator rit;
		for (rit=mymultimap.rbegin(); rit!=mymultimap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	{
		print_banner("empty function");
		std::multimap<char,int> mymultimap;

		mymultimap.insert (std::pair<char,int>('b',101));
		mymultimap.insert (std::pair<char,int>('b',202));
		mymultimap.insert (std::pair<char,int>('q',505));

		while (!mymultimap.empty())
		{
			std::cout << mymultimap.begin()->first << " => ";
			std::cout << mymultimap.begin()->second << '\n';
			mymultimap.erase(mymultimap.begin());
		}
	}
	{
		print_banner("size function");
		std::multimap<char,int> mymultimap;

		mymultimap.insert(std::make_pair('x',100));
		mymultimap.insert(std::make_pair('y',200));
		mymultimap.insert(std::make_pair('y',350));
		mymultimap.insert(std::make_pair('z',500));

		std::cout << "mymultimap.size() is " << mymultimap.size() << '\n';
	}
	{
		print_banner("max_size function");
		std::multimap<char,int> mymultimap;
		std::cout << "mymap.max_size() is " << mymultimap.max_size() << '\n';
	}
	{
		print_banner("insert function");
		std::multimap<char,int> mymultimap;
		std::multimap<char,int>::iterator it;

		// first insert function version (single parameter):
		mymultimap.insert ( std::pair<char,int>('a',100) );
		mymultimap.insert ( std::pair<char,int>('z',150) );
		it=mymultimap.insert ( std::pair<char,int>('b',75) );

		// second insert function version (with hint position):
		mymultimap.insert (it, std::pair<char,int>('c',300));  // max efficiency inserting
		mymultimap.insert (it, std::pair<char,int>('a',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		std::multimap<char,int> anothermultimap;
		anothermultimap.insert(mymultimap.begin(),mymultimap.find('c'));

		// showing contents:
		std::cout << "mymultimap contains:\n";
		for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';

		std::cout << "anothermultimap contains:\n";
		for (it=anothermultimap.begin(); it!=anothermultimap.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';
	}
	{
		print_banner("erase function");
		std::multimap<char,int> mymultimap;

		// insert some values:
		mymultimap.insert(std::pair<char,int>('a',10));
		mymultimap.insert(std::pair<char,int>('b',20));
		mymultimap.insert(std::pair<char,int>('b',30));
		mymultimap.insert(std::pair<char,int>('c',40));
		mymultimap.insert(std::pair<char,int>('d',50));
		mymultimap.insert(std::pair<char,int>('d',60));
		mymultimap.insert(std::pair<char,int>('e',70));
		mymultimap.insert(std::pair<char,int>('f',80));

		std::multimap<char,int>::iterator it = mymultimap.find('b');

		mymultimap.erase (it);                     // erasing by iterator (1 element)

		mymultimap.erase ('d');                    // erasing by key (2 elements)

		it=mymultimap.find ('e');
		mymultimap.erase ( it, mymultimap.end() ); // erasing by range

		// show content:
		for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';
	}
	{
		print_banner("swap function");
		std::multimap<char,int> foo,bar;

		foo.insert(std::make_pair('x',100));
		foo.insert(std::make_pair('y',200));

		bar.insert(std::make_pair('a',11));
		bar.insert(std::make_pair('b',22));
		bar.insert(std::make_pair('a',55));

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (std::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';

		std::cout << "bar contains:\n";
		for (std::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';
	}
	{
		print_banner("clear function");
		std::multimap<char,int> mymultimap;
		std::multimap<char,int>::iterator it;

		mymultimap.insert(std::pair<char,int>('b',80));
		mymultimap.insert(std::pair<char,int>('b',120));
		mymultimap.insert(std::pair<char,int>('q',360));

		std::cout << "mymultimap contains:\n";
		for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';

		mymultimap.clear();

		mymultimap.insert(std::pair<char,int>('a',11));
		mymultimap.insert(std::pair<char,int>('x',22));

		std::cout << "mymultimap contains:\n";
		for (it=mymultimap.begin(); it != mymultimap.end(); ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';
	}
	{
		print_banner("find function");
		std::multimap<char,int> mymm;

		mymm.insert (std::make_pair('x',10));
		mymm.insert (std::make_pair('y',20));
		mymm.insert (std::make_pair('z',30));
		mymm.insert (std::make_pair('z',40));

		std::multimap<char,int>::iterator it = mymm.find('x');
		mymm.erase (it);
		mymm.erase (mymm.find('z'));

		// print content:
		std::cout << "elements in mymm:" << '\n';
		std::cout << "y => " << mymm.find('y')->second << '\n';
		std::cout << "z => " << mymm.find('z')->second << '\n';
	}
	{
		print_banner("count function");
		std::multimap<char,int> mymm;

		mymm.insert(std::make_pair('x',50));
		mymm.insert(std::make_pair('y',100));
		mymm.insert(std::make_pair('y',150));
		mymm.insert(std::make_pair('y',200));
		mymm.insert(std::make_pair('z',250));
		mymm.insert(std::make_pair('z',300));

		for (char c='x'; c<='z'; c++)
		{
			std::cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
			std::multimap<char,int>::iterator it;
			for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
			std::cout << ' ' << (*it).second;
			std::cout << '\n';
		}
	}
	{
		print_banner("lower_bound and upper_bound function");
		std::multimap<char,int> mymultimap;
		std::multimap<char,int>::iterator it,itlow,itup;

		mymultimap.insert(std::make_pair('a',10));
		mymultimap.insert(std::make_pair('b',121));
		mymultimap.insert(std::make_pair('c',1001));
		mymultimap.insert(std::make_pair('c',2002));
		mymultimap.insert(std::make_pair('d',11011));
		mymultimap.insert(std::make_pair('e',44));

		itlow = mymultimap.lower_bound ('b');  // itlow points to b
		itup = mymultimap.upper_bound ('d');   // itup points to e (not d)

		// print range [itlow,itup):
		for (it=itlow; it!=itup; ++it)
			std::cout << (*it).first << " => " << (*it).second << '\n';

	}
	{
		print_banner("equal_range function");
		std::multimap<char,int> mymm;

		mymm.insert(std::pair<char,int>('a',10));
		mymm.insert(std::pair<char,int>('b',20));
		mymm.insert(std::pair<char,int>('b',30));
		mymm.insert(std::pair<char,int>('b',40));
		mymm.insert(std::pair<char,int>('c',50));
		mymm.insert(std::pair<char,int>('c',60));
		mymm.insert(std::pair<char,int>('d',60));

		std::cout << "mymm contains:\n";
		for (char ch='a'; ch<='d'; ch++)
		{
			std::pair <std::multimap<char,int>::iterator, std::multimap<char,int>::iterator> ret;
			ret = mymm.equal_range(ch);
			std::cout << ch << " =>";
			for (std::multimap<char,int>::iterator it=ret.first; it!=ret.second; ++it)
			std::cout << ' ' << it->second;
			std::cout << '\n';
		}
	}
	{
		print_banner("comparaision operators");
		std::multimap<int, int> multimap1;
		multimap1.insert(std::make_pair(10, 57758));
		multimap1.insert(std::make_pair(10, 57758));
		multimap1.insert(std::make_pair(1, 80));
		multimap1.insert(std::make_pair(100, 34));

		std::multimap<int, int> multimap2;
		multimap2.insert(std::make_pair(10, 57758));
		multimap1.insert(std::make_pair(10, 57758));
		multimap2.insert(std::make_pair(1, 80));
		multimap2.insert(std::make_pair(100, 34));

		if (multimap1 == multimap2)
			std::cout << "multimap1 is equal to multimap2" << std::endl;
		if (multimap1 < multimap2)
			std::cout << "multimap1 is smaller than multimap2" << std::endl;
		if (multimap1 <= multimap2)
			std::cout << "multimap1 is smaller than or equal to multimap2" << std::endl;
		if (multimap1 > multimap2)
			std::cout << "multimap1 is larger than multimap2" << std::endl;
		if (multimap1 >= multimap2)
			std::cout << "multimap1 is larger than or equal to multimap2" << std::endl;
		multimap1.insert(std::make_pair(20, 123));
		if (multimap1 == multimap2)
			std::cout << "multimap1 is equal to multimap2" << std::endl;
		if (multimap1 < multimap2)
			std::cout << "multimap1 is smaller than multimap2" << std::endl;
		if (multimap1 <= multimap2)
			std::cout << "multimap1 is smaller than or equal to multimap2" << std::endl;
		if (multimap1 > multimap2)
			std::cout << "multimap1 is larger than multimap2" << std::endl;
		if (multimap1 >= multimap2)
			std::cout << "multimap1 is larger than or equal to multimap2" << std::endl;
	}
}

#endif
