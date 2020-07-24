#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "list.hpp"

namespace ft
{
template <typename T, class Container = list<T>>
class queue
{

    /*                      Member types                           */

public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

private:
    container_type c;

    /*                      Member Functions                       */
public:
    explicit queue(const container_type &ctnr = container_type()) : c(ctnr){};

    queue(const queue &other) : c(other.c){};

    virtual ~queue(){};

    bool empty() const
    {
        return (this->c.empty());
    };

    size_type size() const
    {
        return (this->c.size());
    };

    value_type &front()
    {
        return (this->c.front());
    };

    const value_type &front() const
    {
        return (this->c.front());
    };

    value_type &back()
    {
        return (this->c.back());
    };

    const value_type &back() const
    {
        return (this->c.back());
    };

    void push(const value_type &val)
    {
        this->c.push_back(val);
    };

    void pop()
    {
        this->c.pop_front();
    };

    queue &operator=(const queue &other)
    {
        this->c = other.c;
        return (*this);
    };

    // The keyword friend is allowed in non-member functiones overload
    /*          Non-member function overloads               */
    template <typename type, class C>
    friend bool operator==(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c == rhs.c);
    };

    template <typename type, class C>
    friend bool operator!=(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c != rhs.c);
    };

    template <typename type, class C>
    friend bool operator<(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c < rhs.c);
    };

    template <typename type, class C>
    friend bool operator<=(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c <= rhs.c);
    };

    template <typename type, class C>
    friend bool operator>(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c > rhs.c);
    };

    template <typename type, class C>
    friend bool operator>=(const queue<type, C> &lhs, const queue<type, C> &rhs)
    {
        return (lhs.c >= rhs.c);
    };
};

} // namespace ft

#endif
