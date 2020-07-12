#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "tools/algorithm.hpp"
#include "tools/Iterator.hpp"
#include "tools/reverse_iterator.hpp"
#include <limits>
#include <memory>
#include <iostream>
#include <stdexcept>

/*
    - All operators
    - Test pasados
        - Mirar reverse iterator
        - Comprobar que el reverse de contenedor list no ha cambiado
*/

namespace ft
{

template <typename T, class Alloc = std::allocator<T> >
class vector
{

    /*                      Member types                           */

public:
    typedef T                               value_type;
    typedef Alloc                           allocator_type;
    typedef value_type &                    reference;
    typedef value_type const &              const_reference;
    typedef value_type *                    pointer;
    typedef value_type const *              const_pointer;
    typedef Iterator<value_type>            iterator;
    typedef Iterator<value_type const>      const_iterator;
    typedef ReverseIterator<iterator>       reverse_iterator;
    typedef ReverseIterator<const_iterator> const_reverse_iterator;
    typedef std::ptrdiff_t                  difference_type;
    typedef size_t                          size_type;

private:
    pointer __c;
    size_type __size;
    size_type __capacity;

    size_type  distance(iterator it1, iterator it2)
    {
        size_type  dis = 0;

        while (it1 != it2)
        {
            ++it1;
            dis++;
        }
        return (dis);
    }

    /*                  Member functions                */
public:
    //empty container constructor (default constructor)
    explicit vector(const allocator_type &alloc = allocator_type()) : __c(nullptr), __size(0), __capacity(0)
    {
        (void)alloc;
    };

    /*      Constructs a container with n elements. Each element is a copy of val.      */
    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type()) : __c(nullptr), __size(0), __capacity(0)
    {
        (void)alloc;
        this->assign(n, val);
    };

    /*              Range constructor        */
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
           const allocator_type &alloc = allocator_type()): __c(nullptr), __size(0), __capacity(0)
    {
        (void)alloc;
        this->assign(first, last);
    };

    /*          copy constructor        */
    vector(const vector &x)
    {
        this->__size = x.size();
        this->__capacity = x.capacity();
        if (this->__size > 0)
            this->__c = new value_type[this->__size]();
        for (size_type i = 0; i < this->__size; i++) this->__c[i] = x[i];
    };

    /*          Destructor          */
    virtual ~vector()
    {
        if (this->__c != nullptr)
            delete[] this->__c;
        this->__capacity = this->__size = 0;
    };

    /*      Copies all the elements from x into the container       */
    vector &operator=(const vector &x)
    {
        this->clear();
        this->__size = x.size();
        if (this->__capacity < x.capacity())
            this->reserve(x.capacity());
        for (size_type i = 0; i < this->__size; i++)
            this->__c[i] = x[i];
        return (*this);
    };

    /*      Iterators           */

    iterator begin()
    {
        return (iterator(this->__c));
    };

    const_iterator begin() const
    {
        return (const_iterator(this->__c));
    };

    iterator end()
    {
        return (iterator(&(this->__c[this->__size])));
    };

    const_iterator end() const
    {
        return (const_iterator(&(this->__c[this->__size])));
    };

    reverse_iterator rbegin()
    {
        return (reverse_iterator(this->end()));
    };

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(this->end()));
    };

    reverse_iterator rend()
    {
        return (reverse_iterator(this->begin()));
    };

    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(this->begin()));
    };

    /*              Capacity                                */

    //Return container size
    size_type size() const
    {
        return (this->__size);
    };

    //Return maximum size
    size_type max_size() const
    {
        return (std::numeric_limits<size_type>::max() / sizeof(value_type));
    };

    //Resizes the container so that it contains n elements
    void resize(size_type n, value_type val = value_type())
    {
        if (this->__size < n)
            this->insert(this->end(), n - this->__size, val);
        else if (n >= 0 && this->__size > n)
            this->erase(this->begin() + n, this->end());
    };

    //Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
    size_type capacity() const
    {
        return (this->__capacity);
    };

    //Returns whether the vector is empty
    bool empty() const
    {
        return (this->__size == 0);
    };

    //Requests that the vector capacity be at least enough to contain n elements
    void reserve(size_type n)
    {
        if (n > this->__capacity)
        {
            size_type new_size = (n > this->__capacity * 2) ? n : this->__capacity * 2;
            pointer tmp = new value_type[new_size]();
            if (this->__c)
            {
                for (size_type i = 0; i < this->__size; i++) tmp[i] = this->__c[i];
                delete[] this->__c;
            }
            this->__c = tmp;
            this->__capacity = new_size;
        }
    };

    /*          Element Access                      */

    //Returns a reference to the element at position n in the vector container
    reference operator[](size_type n)
    {
        if (n < 0 || n >= this->__size)
            throw std::out_of_range("Vector Exception: Out of range");
        else
            return (this->__c[n]);
    };

    const_reference operator[](size_type n) const
    {
        if (n < 0 || n >= this->__size)
            throw std::out_of_range("Vector Exception: Out of range");
        else
            return (this->__c[n]);
    };

    //Returns a reference to the element at position n in the vector
    reference at(size_type n)
    {
        if (n < 0 || n >= this->__size)
            throw std::out_of_range("Vector Exception: Out of range");
        else
            return (this->__c[n]);
    };

    const_reference at(size_type n) const
    {
        if (n < 0 || n >= this->__size)
            throw std::out_of_range("Vector Exception: Out of range");
        else
            return (this->__c[n]);
    };

    //Returns a reference to the first element in the vector
    reference front()
    {
        return (*this->begin());
    };

    const_reference front() const
    {
        return (*this->begin());
    };

    //Returns a reference to the last element in the vector
    reference back()
    {
        return (*--this->end());
    };

    const_reference back() const
    {
        return (*--this->end());
    };

    /*          Modifiers                               */

    //Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
    void assign(iterator first, iterator last)
    {
        this->clear();
        this->insert(this->begin(), first, last);
    };

    void assign(size_type n, const value_type &val)
    {
        this->clear();
        this->insert(this->begin(), n, val);
    };

    //Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element
    void push_back(const value_type &val)
    {
        this->insert(this->end(), val);
    };

    //Removes the last element in the vector, effectively reducing the container size by one
    void pop_back()
    {
        this->erase(--this->end());
    };

    //Insert elements
    iterator insert(iterator position, const value_type &val)
    {
        size_type posIt = this->distance(this->begin(), position);
        this->insert(position, 1, val);
        return (iterator(this->begin() + posIt));
    };

    void insert(iterator position, size_type n, const value_type &val)
    {
        size_type new_size = this->__size + n;
        iterator it = this->begin();

        if (new_size > this->__capacity)
            this->reserve(new_size);
        size_type posIt = this->distance(it, position);
        for (size_type i = this->__size; i > posIt; i--)
            this->__c[i + n - 1] = this->__c[i - 1];
        for (size_type i = 0; i < n; i++)
            this->__c[i + posIt] = val;
        this->__size += n;
    };

    void insert(iterator position, iterator first, iterator last)
    {
        size_type n = this->distance(first, last);
        size_type new_size = this->__size + n;
        iterator it = this->begin();

        if (new_size > this->__capacity)
            this->reserve(new_size);
        size_type posIt = this->distance(it, position);
        for (size_type i = this->__size; i > posIt; i--)
            this->__c[i + n - 1] = this->__c[i - 1];
        for (size_type i = 0; i < n; i++)
            this->__c[i + posIt] = *first++;
        this->__size += n;
    };

    //Removes from the vector either a single element (position) or a range of elements ([first,last))
    iterator erase(iterator position)
    {
        return (this->erase(position, position + 1));
    };

    iterator erase(iterator first, iterator last)
    {
        size_type posIt = this->distance(this->begin(), first);
        size_type n = this->distance(first, last);

        for (iterator it = first; it != last; it++) *it = value_type();
        if (last < this->end())
            for (iterator it = first; last != this->end(); ++it) *it = *last++;
        this->__size -= n;
        return (iterator(&this->__c[posIt]));
    };

    //Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ
    void swap(vector &x)
    {
        ft::swap(this->__size, x.__size);
        ft::swap(this->__capacity, x.__capacity);
        ft::swap(this->__c, x.__c);
    };

    //Removes all elements from the vector (which are destroyed), leaving the container with a size of 0
    void clear()
    {
        this->erase(this->begin(), this->end());
    };
};

template <typename T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

template <typename T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
    x.swap(y);
};

} // namespace ft

#endif
