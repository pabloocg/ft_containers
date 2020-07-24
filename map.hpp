#ifndef MAP_HPP
#define MAP_HPP
#include "tools/algorithm.hpp"
#include "tools/reverse_iterator.hpp"
#include <limits>
#include <memory>
#include <utility>
#include "vector.hpp"

/*
    Hacer funcion insert que use el Compare y ordene los valores.
    All operators
    More tests
*/

namespace ft
{
template <
    typename Key,
    typename T,
    class Compare = ft::less<Key>,
    class Alloc = std::allocator<std::pair<Key, T>>>
class map
{
    /*                      Member types                           */

public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef Alloc allocator_type;
    typedef value_type &reference;
    typedef value_type const &const_reference;
    typedef value_type *pointer;
    typedef value_type const *const_pointer;
    typedef Iterator<value_type> iterator;
    typedef Iterator<value_type const> const_iterator;
    typedef ReverseIterator<iterator> reverse_iterator;
    typedef ReverseIterator<const_iterator> const_reverse_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

private:
    ft::vector<value_type> _c;
    size_type _size_map;
    key_compare _f;

public:
    map(const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type()) : _c(), _size_map(0), _f(comp)
    {
        (void)alloc;
    };

    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type()) : _c(), _size_map(0), _f(comp)
    {
        (void)alloc;
        insert(first, last);
    };

    /*          copy constructor        */
    map(const map &x)
    {
        insert(x.begin(), x.end());
    };

    /*          Destructor          */
    virtual ~map()
    {
        if (this->_size_map > 0)
            clear();
    };

    /*      Copies all the elements from x into the container       */
    map &operator=(const map &x)
    {
        clear();
        insert(x.begin(), x.end());
        return (*this);
    };

    /*      Iterators           */

    iterator begin()
    {
        return (this->_c.begin());
    };

    const_iterator begin() const
    {
        return (this->_c.begin());
    };

    iterator end()
    {
        return (this->_c.end());
    };

    const_iterator end() const
    {
        return (this->_c.end());
    };

    reverse_iterator rbegin()
    {
        return (this->_c.rbegin());
    };

    const_reverse_iterator rbegin() const
    {
        return (this->_c.rbegin());
    };

    reverse_iterator rend()
    {
        return (this->_c.rend());
    };

    const_reverse_iterator rend() const
    {
        return (this->_c.rend());
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
    mapped_type &operator[](const key_type &k)
    {
        for (size_t i = 0; i < this->_size_map; i++)
            if (this->_c[i].first == k)
                return (this->_c[i].second);
        return ((*((this->insert(std::make_pair(k, mapped_type()))).first)).second);
    };

    /*          Modifiers                               */

    //Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted
    typename std::pair<iterator, bool> insert(const_reference val)
    {
        iterator rep;

        rep = find(val.first);
        if (rep != this->end())
            return (std::make_pair(rep, false));
        rep = this->_c.insert(this->end(), val);
        this->_size_map++;
        return (std::make_pair(rep, true));
    };

    iterator insert(iterator position, const_reference val)
    {
        iterator rep;

        rep = find(val.first);
        if (rep != this->end())
            return (rep);
        rep = this->_c.insert(position, val);
        this->_size_map++;
        return (rep);
    };

    void insert(iterator first, iterator last)
    {
        while (first != last)
            this->insert(*first++);
    };

    //Removes from the map container either a single element or a range of elements ([first,last))
    void erase(iterator position)
    {
        erase(position, position + 1);
    };

    size_type erase(const key_type &k)
    {
        for (size_t i = 0; i < this->_size_map; i++)
            if (this->_c[i].first == k)
            {
                this->_c.erase(this->_c.begin() + i);
                break;
            }
        return (--this->_size_map);
    };

    void erase(iterator first, iterator last)
    {
        this->_c.erase(first, last);
        this->_size_map = this->_c.size();
    };

    //Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ
    void swap(map &x)
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

    /*          Operations               */

    //Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
    iterator find(const key_type &k)
    {
        for (iterator it = this->begin(); it != this->end(); it++)
        {
            if (it->first == k)
                return (it);
        }
        return (this->end());
    };

    const_iterator find(const key_type &k) const
    {
        for (const_iterator it = this->begin(); it != this->end(); it++)
        {
            if (it->first == k)
                return (it);
        }
        return (this->end());
    };

    //Count elements with a specific key
    //Searches the container for elements with a key equivalent to k and returns the number of matches.
    size_type count(const key_type &k) const
    {
        size_type c = 0;

        for (const_iterator it = this->begin(); it != this->end(); it++)
        {
            if (!this->key_comp()(k, it->first) && !this->key_comp()(it->first, k))
                c++;
        }
        return (c);
    };

    //Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
    iterator lower_bound(const key_type &k)
    {
        iterator itend = this->end();

        for (iterator it = this->begin(); it != itend; it++)
        {
            if (!this->key_comp()(it->first, k))
                return (it);
        }
        return (this->end());
    };

    const_iterator lower_bound(const key_type &k) const
    {
        const_iterator itend = this->end();

        for (const_iterator it = this->begin(); it != itend; it++)
        {
            if (!this->key_comp()(it->first, k))
                return (it);
        }
        return (this->end());
    };

    //Returns an iterator pointing to the first element in the container whose key is considered to go after k.
    iterator upper_bound(const key_type &k)
    {
        iterator itend = this->end();

        for (iterator it = this->begin(); it != itend; it++)
        {
            if (this->key_comp()(k, it->first))
                return (it);
        }
        return (this->end());
    };

    const_iterator upper_bound(const key_type &k) const
    {
        const_iterator itend = this->end();

        for (const_iterator it = this->begin(); it != itend; it++)
        {
            if (this->key_comp()(k, it->first))
                return (it);
        }
        return (this->end());
    };

    //Get range of equal elements
    //Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
    std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
    {
        return (std::make_pair(lower_bound(k), upper_bound(k)));
    };

    std::pair<iterator, iterator> equal_range(const key_type &k)
    {
        return (std::make_pair(lower_bound(k), upper_bound(k)));
    };
};
} // namespace ft

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
                const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
                const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
               const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
                const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
               const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
                const ft::map<Key, T, Compare, Alloc> &rhs);

template <typename Key, typename T, class Compare = ft::less<Key>,
          class Alloc = std::allocator<std::pair<Key, T>>>
void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{
    x.swap(y);
};

#endif
