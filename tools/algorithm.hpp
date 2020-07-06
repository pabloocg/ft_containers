#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

template <typename T>
bool    equal(T &value1, T &value2)
{
    return (value1 == value2);
}

template <typename T>
bool    less(T &value1, T &value2)
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

#endif
