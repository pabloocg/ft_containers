#ifndef QUEUE_HPP
# define QUEUE_HPP
# include "list.hpp"

namespace ft
{
template <typename T, class Container = list<T> >
class queue
{

    /*                      Member types                           */

public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

private:
    container_type  _c;

    /*                      Member Functions                       */
public:
    queue(const container_type &ctnr = container_type()) : _c(ctnr){};

    queue(const queue &other) : _c(other._c){};

    virtual ~queue(){};

    bool empty() const
    {
        return (this->_c.empty());
    };

    size_type size() const
    {
        return (this->_c.size());
    };

    value_type &front()
    {
        return (this->_c.front());
    };

    const value_type &front() const
    {
        return (this->_c.front());
    };

    value_type &back()
    {
        return (this->_c.back());
    };

    const value_type &back() const
    {
        return (this->_c.back());
    };

    void push(const value_type &val)
    {
        this->_c.push_back(val);
    };

    void pop()
    {
        this->_c.pop_front();
    };

    queue &operator=(const queue &other)
    {
        this->_c = other._c;
        return (*this);
    };

    // The keyword friend is allowed in non-member functiones overload
    /*          Non-member function overloads               */
    template <typename type, class Cont>
    friend bool operator==(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c == rhs._c);
    };

    template <typename type, class Cont>
    friend bool operator!=(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c != rhs._c);
    };

    template <typename type, class Cont>
    friend bool operator<(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c < rhs._c);
    };

    template <typename type, class Cont>
    friend bool operator<=(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c <= rhs._c);
    };

    template <typename type, class Cont>
    friend bool operator>(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c > rhs._c);
    };

    template <typename type, class Cont>
    friend bool operator>=(const queue<type, Cont> &lhs, const queue<type, Cont> &rhs)
    {
        return (lhs._c >= rhs._c);
    };
};

} // namespace ft

#endif
