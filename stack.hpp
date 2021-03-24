#ifndef STACK_HPP
# define STACK_HPP
# include "list.hpp"

namespace ft
{
template <typename T, class Container = list<T> >
class stack
{

    /*                      Member types                           */

public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

private:
    container_type _c;

    /*                      Member Functions                       */
public:
    stack(const container_type &ctnr = container_type()) : _c(ctnr){};

    stack(const stack &other) : _c(other._c){};

    virtual ~stack(){};

    bool empty() const
    {
        return (this->_c.empty());
    };

    size_type size() const
    {
        return (this->_c.size());
    };

    value_type &top()
    {
        return (this->_c.back());
    };

    const value_type &top() const
    {
        return (this->_c.back());
    };

    void push(const value_type &val)
    {
        this->_c.push_back(val);
    };

    void pop()
    {
        this->_c.pop_back();
    };

    stack &operator=(const stack &other)
    {
        this->_c = other._c;
        return (*this);
    };

    // The keyword friend is allowed in non-member functiones overload
    /*          Non-member function overloads               */
    template <typename type, class C>
    friend bool operator==(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c == rhs._c);
    };

    template <typename type, class C>
    friend bool operator!=(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c != rhs._c);
    };

    template <typename type, class C>
    friend bool operator<(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c < rhs._c);
    };

    template <typename type, class C>
    friend bool operator<=(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c <= rhs._c);
    };

    template <typename type, class C>
    friend bool operator>(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c > rhs._c);
    };

    template <typename type, class C>
    friend bool operator>=(const stack<type, C> &lhs, const stack<type, C> &rhs)
    {
        return (lhs._c >= rhs._c);
    };
};

} // namespace ft

#endif
