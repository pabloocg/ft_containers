#ifndef MAP_HPP
# define MAP_HPP
# include "tools/algorithm.hpp"
# include "tools/reverse_iterator.hpp"
# include "tools/IteratorMap.hpp"
# include <limits>
# include <memory>
# include <utility>
# include "vector.hpp"

namespace ft
{
    template <
        typename Key,
        typename T,
        class Compare = ft::less<Key>,
        class Alloc = std::allocator<std::pair<const Key, T> > >
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
            typedef IteratorMap<value_type>                 iterator;
            typedef IteratorMap<value_type const>           const_iterator;
            typedef ReverseIterator<iterator>               reverse_iterator;
            typedef ReverseIterator<const_iterator>         const_reverse_iterator;
            typedef std::ptrdiff_t                          difference_type;
            typedef size_t                                  size_type;

        private:

            ft::vector<value_type>  _c;
            size_type               _size_map;
            key_compare             _f;

        public:

            explicit map (const key_compare& comp = key_compare(),
                            const allocator_type& alloc = allocator_type()): _size_map(0), _c(nullptr)
            {
                this->_f = comp;
                (void)alloc;
            };

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
            {
                this->_f = comp;
                (void)alloc;
                insert(first, last);
            };

            /*          copy constructor        */
            map (const map& x)
            {
                insert(x.begin(), x.end());
            };

            /*          Destructor          */
            virtual ~map()
            {
                clear();
            };

            /*      Copies all the elements from x into the container       */
            map& operator= (const map& x)
            {
                clear();
                insert(x.begin(), x.end());
                return (*this);
            };

        /*      Iterators           */

            iterator begin()
            {
                return (iterator(this->_c[0]));
            };

            const_iterator begin() const
            {
                return (const_iterator(this->_c[0]));
            };

            iterator end()
            {
                return (iterator(this->_c[this->_size_map]));
            };

            const_iterator end() const
            {
                return (const_iterator(this->_c[this->_size_map]));
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

            //Returns whether the vector is empty
            bool empty() const
            {
                return (this->_size_map == 0);
            };

            //Return size
            size_type size() const
            {
                return (this->_size_map);
            };

            //Return maximum size
            size_type max_size() const
            {
                return (std::numeric_limits<size_type>::max() / sizeof(pointer));
            };

        /*          Element Access                      */

            //If k matches the key of an element in the container, the function returns a reference to its mapped value
            mapped_type& operator[] (const key_type& k)
            {
                for (size_t i = 0; i < this->_size_map; i++)
                    if (this->_c[i].first == k)
                        return (this->_c[i].second);
                return ((*((this->insert(std::make_pair(k, mapped_type()))).first)).second);
            };

        /*          Modifiers                               */

            //Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted
            typename std::pair<iterator, bool>   insert(const_reference val)
            {
                iterator    rep;

                if ((rep = find(val.first)))
                    return (std::make_pair(rep, false));
                this->_c.push_back(val);
                this->_size_map++;
                return (std::make_pair(iterator(val), true));
            };

            iterator                    insert(iterator position, const_reference val)
            {
                iterator    rep;

                if ((rep = find(val.first)))
                    return (rep);
                rep = this->_c.insert(position, val);
                this->_size_map++;
                return (rep);
            };

            void                        insert(iterator first, iterator last)
            {
                while (first != last)
                    this->insert(*first++);
            };

            //Removes from the map container either a single element or a range of elements ([first,last))
            void erase (iterator position)
            {
                erase(position, position + 1);
            };

            size_type erase (const key_type& k)
            {
                for (size_t i = 0; i < this->_size_map; i++)
                    if (this->_c[i].first == k)
                    {
                        this->_c.erase(ft::vector<value_type>::iterator(this->_c[i]));
                        break ;
                    }
                return (--this->_size_map);
            };

            void erase (iterator first, iterator last)
            {
                while (first != last)
                    erase(first->first++);
            };

            //Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ
            void swap (map& x)
            {
                this->_c.swap(x._c);
                ft::swap(this->_size_map, x._size_map);
            };

            //Removes all elements from the map container (which are destroyed), leaving the container with a size of 0
            void clear()
            {
                erase(this->begin(), this->end());
            };

        /*          Observers                           */

            //Returns a copy of the comparison object used by the container to compare keys.
            key_compare key_comp() const
            {
                return (this->_f);
            };

            //Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
            value_compare value_comp() const
            {
                return (value_compare());
            };

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
