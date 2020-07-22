// map::insert (C++98)
#include <iostream>
//#include <map>
#include "../map.hpp"

int main ()
{
	{
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int>       mymap;
		ft::map<char,int>::iterator it;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<ft::map<char,int>::iterator, bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	{
		std::cout << "Erase and empty function" << std::endl;
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		std::cout << "Size function" << std::endl;
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		mymap['d']=402;
		mymap['e']=502;
		mymap['f']=602;
		mymap['g']=702;

		std::cout << "mymap.size() is " << mymap.size() << '\n';

	}
    return 0;
}