#ifndef QUEUE_SYS_HPP
# define QUEUE_SYS_HPP
# include <queue>
# include <list>
# include <iostream>
# include "utils.cpp"

void	queue_sys(void)
{
	std::cout << "\n---basic\n\n";

	std::queue<int> empty_queue;
	{
		std::cout << "empty? " << empty_queue.empty() << '\n';
		std::cout << "empty queue size = " << empty_queue.size() << '\n';
			assert(empty_queue.empty());
			assert(empty_queue.size() == 0);
	}

	std::queue<int> que;
	std::cout << "[] (size: " << que.size() << ")\n";
	que.push(5);
	std::cout << "[5] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ", empty? " << que.empty() << ")\n";
		assert(que.size() == 1);
	que.push(42);
	std::cout << "[5, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";

	std::cout << "queue [5, 42].size() = " << que.size() << '\n';
		assert(que.size() == 2);

	que.front() = 99;
	std::cout << "[99, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		assert(que.front() == 99);
		assert(que.back() == 42);
	que.pop();
	std::cout << "[42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		assert(que.back() == 42);
		assert(que.front() == 42);
	que.pop();
	std::cout << "[] (size: " << que.size() << ")\n";
		assert(que.size() == 0);

	std::cout << "\n---with container\n\n";
	{
		std::deque<int> ctn;
		ctn.push_back(5);
		ctn.push_back(42);
		ctn.push_back(43);
		ctn.push_back(99);
		display_container("[5, 42, 43, 99] {List or Deque}:", ctn);
			assert(ctn.size() == 4);

		std::queue<int> stk(ctn);
		std::cout << "stack empty? " << stk.empty() << '\n';
		std::cout << "stack size = " << stk.size() << '\n';
			assert(!stk.empty());
			assert(stk.size() == 4);

		std::cout << "[5, 42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[5, 42, 43] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 3);
		que.pop();
		std::cout << "[5, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 2);
		que.pop();
		std::cout << "[5] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 1);
		que.pop();
		std::cout << "[] (size: " << que.size() << ")\n";
			assert(que.size() == 0);

		display_container("[5, 42, 43, 99] {std::List after, no change}:", ctn);
	}

	std::cout << "\n---comparison\n\n";
	{
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
	}

	std::cout << '\n';
}

#endif
