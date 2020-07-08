#ifndef MAP_HPP
# define MAP_HPP
# include "tools/algorithm.hpp"
//# include "tools/reverse_iterator.hpp"
# include <limits>
# include <memory>
# include <utility>

namespace ft
{
    template <typename Key, typename T, class Compare = ft::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
         /*                      Member types                           */

        public:

            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef std::pair<const key_type, mapped_type>  value_type;
            typedef Compare                                 key_compare;
            typedef Compare                                 value_compare;
            typedef Alloc                                   allocator_type;
            typedef value_type                  &           reference;
            typedef value_type const            &           const_reference;
            typedef value_type                  *           pointer;
            typedef value_type const            *           const_pointer;
            //typedef Iterator<value_type>                  iterator;
            //typedef Iterator<value_type const>            const_iterator;
            //typedef ReverseIterator<iterator>             reverse_iterator;
            //typedef ReverseIterator<const_iterator>       const_reverse_iterator;
            typedef std::ptrdiff_t                          difference_type;
            typedef size_t                                  size_type;

        private:

            value_type  c;
            size_type   size_map;

        public:

            explicit map (const key_compare& comp = key_compare(),
                            const allocator_type& alloc = allocator_type());	

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type());

            /*          copy constructor        */
            map (const map& x);

            /*          Destructor          */
            virtual ~map();

            /*      Copies all the elements from x into the container       */
            map& operator= (const map& x);

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

            //Returns whether the vector is empty
            bool empty() const;

            //Return size
            size_type size() const;

            //Return maximum size
            size_type max_size() const;

        /*          Element Access                      */

            //If k matches the key of an element in the container, the function returns a reference to its mapped value
            mapped_type& operator[] (const key_type& k);

        /*          Modifiers                               */

            //Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted
            std::pair<iterator, bool> insert (const value_type& val);
            iterator insert (iterator position, const value_type& val);
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last);

            //Removes from the map container either a single element or a range of elements ([first,last))
            void erase (iterator position);
            size_type erase (const key_type& k);
            void erase (iterator first, iterator last);

            //Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ
            void swap (map& x);

            //Removes all elements from the map container (which are destroyed), leaving the container with a size of 0
            void clear();

        /*          Observers                           */

            //Returns a copy of the comparison object used by the container to compare keys.
            key_compare key_comp() const;

            //Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
            value_compare value_comp() const;

        /*          Operations                      */
            
            //Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
            iterator find (const key_type& k);
            const_iterator find (const key_type& k) const;

            //Count elements with a specific key
            //Searches the container for elements with a key equivalent to k and returns the number of matches.
            size_type count (const key_type& k) const;

            //Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
            iterator lower_bound (const key_type& k);
            const_iterator lower_bound (const key_type& k) const;

            //Returns an iterator pointing to the first element in the container whose key is considered to go after k.
            iterator upper_bound (const key_type& k);
            const_iterator upper_bound (const key_type& k) const;

            //Get range of equal elements
            //Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            pair<iterator,iterator>             equal_range (const key_type& k);
    };

}

#endif
