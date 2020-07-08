#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "tools/algorithm.hpp"
//# include "tools/reverse_iterator.hpp"
# include <limits>
# include <memory>

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
            //typedef IteratorList<value_type>          iterator;
            //typedef IteratorList<value_type const>    const_iterator;
            //typedef ReverseIterator<iterator>         reverse_iterator;
            //typedef ReverseIterator<const_iterator>   const_reverse_iterator;
            typedef std::ptrdiff_t                      difference_type;
            typedef size_t                              size_type;
        
        private:

            pointer     c;
            size_type   size_c;
        
        /*                  Member functions                */
        public:
            /*      empty container constructor (default constructor)       */
            explicit vector (const allocator_type& alloc = allocator_type());

            /*      Constructs a container with n elements. Each element is a copy of val.      */
            explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type());

            /*              Range constructor        */
            template <class InputIterator>
                    vector (InputIterator first, InputIterator last,
                            const allocator_type& alloc = allocator_type());

            /*          copy constructor        */
            vector (const vector& x);

            /*          Destructor          */
            virtual ~vector();

            /*      Copies all the elements from x into the container       */
            vector& operator= (const vector& x);

        /*      Iterators           */

            iterator begin();
            const_iterator begin() const;

            iterator end();
            const_iterator end() const;

            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;

            reverse_iterator rend();
            const_reverse_iterator rend() const;

        /*              Capacity                                */

            //Return size
            size_type size() const;

            //Return maximum size
            size_type max_size() const;

            //Resizes the container so that it contains n elements
            void resize (size_type n, value_type val = value_type());

            //Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
            size_type capacity() const;

            //Returns whether the vector is empty
            bool empty() const;

            //Requests that the vector capacity be at least enough to contain n elements
            void reserve (size_type n);
            
        /*          Element Access                      */

            //Returns a reference to the element at position n in the vector container
            reference operator[] (size_type n);
            const_reference operator[] (size_type n) const;

            //Returns a reference to the element at position n in the vector
            reference at (size_type n);
            const_reference at (size_type n) const;

            //Returns a reference to the first element in the vector
            reference front();
            const_reference front() const;
            
            //Returns a reference to the last element in the vector
            reference back();
            const_reference back() const;

        /*          Modifiers                               */
            //Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);
            void assign (size_type n, const value_type& val);

            //Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element
            void push_back (const value_type& val);

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
