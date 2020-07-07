#ifndef STACK_HPP
# define STACK_HPP
# include "list.hpp"

namespace ft
{
    template <typename T, class Container = ft::list<T> >
    class stack
    {

        /*                      Member types                           */

        public:

            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;
        
            container_type  c;

            /*                      Member Functions                       */
        public:
                            /*       Constructor Types      */
            /*Default Constructor*/
            explicit stack (const container_type& ctnr = container_type()): c(ctnr) {};
            stack(const stack &other): c(other.c) {};
            virtual ~stack() {};


            bool empty() const
            {
                return (this->c.empty());
            };

            size_type size() const
            {
                return (this->c.size());
            };

            value_type& top()
            {
                return (this->c.back());
            };

            const value_type& top() const
            {
                return (this->c.back());
            };

            void push (const value_type& val)
            {
                this->c.push_back(val);
            };

            void pop()
            {
                this->c.pop_back();
            };

            stack &operator=(const stack &other) {
                this->c = other.c;
                return (*this);
            };
    };

/*          Non-member function overloads               */

template <typename T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c == rhs.c);
};

template <typename T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c != rhs.c);
};

template <typename T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c < rhs.c);
};

template <typename T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c <= rhs.c);
};

template <typename T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c > rhs.c);
};

template <typename T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c >= rhs.c);
};

}

#endif
