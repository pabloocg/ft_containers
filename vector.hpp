#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "tools/algorithm.hpp"
# include "tools/Iterator.hpp"
# include "tools/reverse_iterator.hpp"
# include <limits>
# include <memory>
# include <iostream>

namespace ft
{

    template < typename T, class Alloc = std::allocator<T> >
    class vector
    {

        /*                      Member types                           */

        public:

            typedef T                                   value_type;
            typedef Alloc                               allocator_type;
            typedef value_type                  &       reference;
            typedef value_type const            &       const_reference;
            typedef value_type                  *       pointer;
            typedef value_type const            *       const_pointer;
            typedef Iterator<value_type>                iterator;
            typedef Iterator<value_type const>          const_iterator;
            typedef ReverseIterator<iterator>           reverse_iterator;
            typedef ReverseIterator<const_iterator>     const_reverse_iterator;
            typedef std::ptrdiff_t                      difference_type;
            typedef size_t                              size_type;
        
        private:

            pointer     __c;
            size_type   __size;
            size_type   __capacity;
        
        /*                  Member functions                */
        public:
            //empty container constructor (default constructor)
            explicit vector (const allocator_type& alloc = allocator_type()): __c(nullptr), __size(0), __capacity(0)
            {
                (void)alloc;
            };

            /*      Constructs a container with n elements. Each element is a copy of val.      */
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type())
            {
                (void)alloc;
                this->assign(n, val);
            };

            /*              Range constructor        */
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type())
            {
                (void)alloc;
                this->assign(first, last);
            };

            /*          copy constructor        */
            vector (const vector& x)
            {
                this->__size = x.size();
                this->__capacity = x.capacity();
                if (this->__size > 0)
                    this->__c = new value_type[this->__size]();
                for (size_type i = 0; i < this->__size; i++)
                    this->__c[i] = x[i];
            };

            /*          Destructor          */
            virtual ~vector()
            {
                if (this->__c != nullptr)
                    delete[] this->__c;
                this->__size = 0;
            };

            /*      Copies all the elements from x into the container       */
            vector& operator= (const vector& x)
            {
                if (this->__size > 0)
                    delete[] this->__c;
                this->__c = nullptr;
                this->__size = x.size();
                if (this->__size > 0)
                {
                    this->__c = new value_type[this->__size]();
                    for (size_type i = 0; i < this->__size; i++)
                        this->__c[i] = x[i];
                }
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
                return (iterator(this->__c + this->__size));
            };

            const_iterator end() const
            {
                return (const_iterator(this->__c + this->__size));
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

            //Return size
            size_type size() const
            {
                return (this->__size);
            };

            //Return maximum size
            size_type max_size() const
            {
                //Check
                return (std::numeric_limits<size_type>::max() / sizeof(pointer));
            };

            //Resizes the container so that it contains n elements
            void resize (size_type n, value_type val = value_type());

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
            void reserve (size_type n);
            
        /*          Element Access                      */

            //Returns a reference to the element at position n in the vector container
            reference operator[] (size_type n)
            {
                if (n < 0 || n >= this->__size)
                    throw "Vector Exception: Outbound of limits";
                else
                    return (this->__c[n]);
            };

            const_reference operator[] (size_type n) const
            {
                if (n < 0 || n >= this->__size)
                    throw "Vector Exception: Outbound of limits";
                else
                    return (this->__c[n]);
            };

            //Returns a reference to the element at position n in the vector
            reference at (size_type n)
            {
                if (n < 0 || n >= this->__size)
                    throw "Vector Exception: Outbound of limits";
                else
                    return (this->__c[n]);
            };

            const_reference at (size_type n) const
            {
                if (n < 0 || n >= this->__size)
                    throw "Vector Exception: Outbound of limits";
                else
                    return (this->__c[n]);
            };

            //Returns a reference to the first element in the vector
            reference front()
            {
                return (this->__c[0]);
            };

            const_reference front() const
            {
                return (this->__c[0]);
            };
            
            //Returns a reference to the last element in the vector
            reference back()
            {
                return (this->__c[this->__size]);
            };

            const_reference back() const
            {
                return (this->__c[this->__size]);
            };

        /*          Modifiers                               */
            //Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
            void assign (iterator first, iterator last);
            void assign (size_type n, const value_type& val);

            //Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element
            void push_back (const value_type& val)
            {
                new (&this->__c[this->__size++]) value_type(val);
            };

            //Removes the last element in the vector, effectively reducing the container size by one
            void pop_back();

            //Insert elements
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);

            //Removes from the vector either a single element (position) or a range of elements ([first,last))
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);

            //Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ
            void swap (vector& x);

            //Removes all elements from the vector (which are destroyed), leaving the container with a size of 0
            void clear();

    };

template <typename T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}

#endif
