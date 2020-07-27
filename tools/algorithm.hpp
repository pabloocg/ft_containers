#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

#include <functional>

namespace ft
{

    template <typename T>
	void swap(T &a, T &b)
	{
		T c(a);

		a = b;
		b = c;
	}

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    }

    template <typename T>
    bool    equal(T &value1, T &value2)
    {
        return (value1 == value2);
    }

    template<typename T>
    struct less: public std::binary_function<T, T, bool>
    {
        bool operator()(const T& value1, const T& value2) const
        {
            return (value1 < value2);
        }
    };

    template<class T>
    bool less_than(T &value1, T &value2)
    {
        return (value1 < value2);
    }

    template <typename T>
    bool    greater(T &value1, T &value2)
    {
        return (value1 > value2);
    }

    template <typename T>
    bool    less_or_equal(T &value1, T &value2)
    {
        return (value1 < value2);
    }

    template <typename T>
    bool    greater_or_equal(T &value1, T &value2)
    {
        return (value1 > value2);
    }

}

#endif
