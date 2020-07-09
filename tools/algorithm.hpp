#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

#include <functional>

namespace ft
{
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
