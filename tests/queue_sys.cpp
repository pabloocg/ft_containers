#ifndef QUEUE_SYS_HPP
# define QUEUE_SYS_HPP
# include "utils.cpp"
# include <queue>
# include <deque>
# include <list>

void	queue_sys(void)
{
	{
		print_banner("Constructors and size function");
		std::deque<int> mydeck (3,100);        // deque with 3 elements
		std::list<int> mylist (2,200);         // list with 2 elements

		std::queue<int> first;                 // empty queue
		std::queue<int, std::deque<int> > second (mydeck);       // queue initialized to copy of deque

		std::queue<int, std::list<int> > third; // empty queue with list as underlying container
		std::queue<int, std::list<int> > fourth (mylist);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	{
		print_banner("push, empty, front and pop function");
		std::queue<int> myqueue;
		int sum (0);

		for (int i=1;i<=10;i++) myqueue.push(i);

		while (!myqueue.empty())
		{
			sum += myqueue.front();
			myqueue.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	{
		print_banner("push, front and back function");
		std::queue<int> myqueue;

		myqueue.push(12);
		myqueue.push(75);   // this is now the back

		myqueue.back() -= myqueue.front();

		std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
	}
	{
		print_banner("with list container");
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(99);
		display_container("[5, 42, 43, 99] {List}:", lst);
			assert(lst.size() == 4);

		std::queue<int, std::list<int> > que(lst);
		std::cout << "queue empty? " << que.empty() << '\n';
		std::cout << "queue size " << que.size() << '\n';
			assert(!que.empty());
			assert(que.size() == 4);

		std::cout << "[5, 42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 3);
		que.pop();
		std::cout << "[43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 2);
		que.pop();
		std::cout << "[99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 1);
		que.pop();
		std::cout << "[] (size: " << que.size() << ")\n";
			assert(que.size() == 0);

		display_container("[5, 42, 43, 99] {List<int> after, no change}:", lst);
	}

	{
		print_banner("Relational operators");
		std::queue<int> que;
		que.push(5);
		que.push(42);
		assert(que.size() == 2);

		std::queue<int> que2;
		que2.push(5);
		que2.push(42);
		assert(que2.size() == 2);

		std::queue<int> que3;
		que3.push(5);
		que3.push(42);
		que3.push(43);
		assert(que3.size() == 3);

		std::queue<int> que4;
		que4.push(99);
		que4.push(5);
		que4.push(42);
		assert(que4.size() == 3);

		std::cout << "same queue:" << '\n'
			<< "comparison == " << (que == que2) << '\n'
			<< "comparison != " << (que != que2) << '\n'
			<< "comparison <  " << (que < que2) << '\n'
			<< "comparison >  " << (que > que2) << '\n'
			<< "comparison <= " << (que <= que2) << '\n'
			<< "comparison >= " << (que >= que2) << '\n';
		assert(que == que2);
		assert(!(que != que2));
		assert(!(que < que2));
		assert(!(que > que2));
		assert(que <= que2);
		assert(que >= que2);

		std::cout << "lesser queue:" << '\n'
			<< "comparison == " << (que == que3) << '\n'
			<< "comparison != " << (que != que3) << '\n'
			<< "comparison <  " << (que < que3) << '\n'
			<< "comparison >  " << (que > que3) << '\n'
			<< "comparison <= " << (que <= que3) << '\n'
			<< "comparison >= " << (que >= que3) << '\n';
		assert(!(que == que3));
		assert(que != que3);
		assert(que < que3);
		assert(!(que > que3));
		assert(que <= que3);
		assert(!(que >= que3));

		std::cout << "upper queue:" << '\n'
			<< "comparison == " << (que4 == que) << '\n'
			<< "comparison != " << (que4 != que) << '\n'
			<< "comparison <  " << (que4 < que) << '\n'
			<< "comparison >  " << (que4 > que) << '\n'
			<< "comparison <= " << (que4 <= que) << '\n'
			<< "comparison >= " << (que4 >= que) << '\n';
		assert(!(que4 == que));
		assert(que4 != que);
		assert(!(que4 < que));
		assert(que4 > que);
		assert(!(que4 <= que));
		assert(que4 >= que);
		std::cout << '\n';
	}
}

#endif
