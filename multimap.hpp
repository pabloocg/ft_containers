#ifndef MULTIMAP_HPP
# define MULTIMAP_HPP
# include "tools/BTree.hpp"
# include "tools/reverse_iterator.hpp"
# include <limits>
# include <memory>

namespace ft
{
template<typename Key, typename T, typename Compare = ft::less<Key> >
class multimapCompare:
	std::binary_function<std::pair<Key, T>, std::pair<Key, T>, bool>
{
public:
	typedef typename std::pair<Key, T> value_type;
private:
	Compare __comp;
public:
	multimapCompare(Compare const &__comp=Compare()): __comp(__comp) {}
	virtual ~multimapCompare() {}

	bool operator()(const value_type& a, const value_type& b) const
    {
		return (__comp(a.first, b.first));
	};
	bool operator()(const value_type& a, const Key& b) const
    {
		return (__comp(a.first, b));
	};
	bool operator()(const Key& a, const value_type& b) const
    {
		return (__comp(a, b.first));
	};
    bool operator()(const Key& a, const Key& b) const
    {
		return (__comp(a, b));
	};
};

template <typename Key, typename T, typename Compare = multimapCompare<Key, T>, class Alloc = std::allocator<std::pair<Key, T> > >
class multimap
{
    /*                      Member types                           */

public:
    typedef Key                                         key_type;
    typedef T                                           mapped_type;
    typedef typename std::pair<key_type, mapped_type>   value_type;
    typedef Compare                                     key_compare;
    typedef Alloc                                       allocator_type;
    typedef value_type                                  &reference;
    typedef value_type const                            &const_reference;
    typedef value_type                                  *pointer;
    typedef value_type const                            *const_pointer;
    typedef BTree<value_type, key_compare>              tree_type;
	typedef typename tree_type::NodeTree                node_type;
	typedef node_type*                                  node_pointer;
    typedef BTreeIterator<value_type, node_type>        iterator;
    typedef BTreeIterator<value_type const, node_type>  const_iterator;
    typedef ReverseIterator<iterator>                   reverse_iterator;
    typedef ReverseIterator<const_iterator>             const_reverse_iterator;
    typedef std::ptrdiff_t                              difference_type;
    typedef size_t                                      size_type;

    class value_compare : public ft::binary_function<value_type, value_type, bool>
    {
    protected:
        key_compare __comp;

    public:
        value_compare(key_compare c) : __comp(c){};
        ~value_compare(){};

        value_compare   &operator=(value_compare &other)
        {
            this->__comp = other.__comp;
            return (*this);
        }

        bool operator()(const value_type &x, const value_type &y) const
        {
            return __comp(x.first, y.first);
        }
    };

private:
    tree_type       __btree;
    size_type       __size_multimap;
    key_compare     __comp;

public:
    multimap(const key_compare &__comp = key_compare(),
        const allocator_type &alloc = allocator_type()) : __btree(), __size_multimap(0), __comp(__comp)
    {
        (void)alloc;
    };

    template <class InputIterator>
    multimap(InputIterator first, InputIterator last,
        const key_compare &__comp = key_compare(),
        const allocator_type &alloc = allocator_type()) : __btree(), __size_multimap(0), __comp(__comp)
    {
        (void)alloc;
        insert(first, last);
    };

    /*          copy constructor        */
    multimap(const multimap &x): __btree(x.__btree), __size_multimap(x.__size_multimap)
    {
    };

    /*          Destructor          */
    virtual ~multimap()
    {
        if (this->__size_multimap > 0)
            clear();
    };

    /*      Copies all the elements from x into the container       */
    multimap &operator=(const multimap &x)
    {
        clear();
        insert(x.begin(), x.end());
        return (*this);
    };

    /*      Iterators           */

    iterator begin()
    {
        return (iterator(this->__btree.begin()));
    };

    const_iterator begin() const
    {
        return (const_iterator(this->__btree.begin()));
    };

    iterator end()
    {
        return (iterator(this->__btree.end()));
    };

    const_iterator end() const
    {
        return (const_iterator(this->__btree.end()));
    };

    reverse_iterator rbegin()
    {
        return (reverse_iterator(this->__btree.end()));
    };

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(this->__btree.end()));
    };

    reverse_iterator rend()
    {
        return (reverse_iterator(this->__btree.begin()));
    };

    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(this->__btree.begin()));
    };

    /*              Capacity                                */

    //Returns whether the vector is empty
    bool empty() const
    {
        return (this->__size_multimap == 0);
    };

    //Return size
    size_type size() const
    {
        return (this->__size_multimap);
    };

    //Return maximum size
    size_type max_size() const
    {
        return (std::min<size_type>(std::numeric_limits<size_type>::max() / (sizeof(value_type) * (sizeof(mapped_type) + sizeof(key_type))),
                                    std::numeric_limits<difference_type>::max()));
    };

    /*          Modifiers                               */

    //Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted
    iterator insert(const_reference val)
    {
        return (insert(this->begin(), val));
    };

    iterator insert(iterator position, const_reference val)
    {
        ++this->__size_multimap;
        return (this->__btree.insert_tree(position.get_pointer(), val));
    };

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        while (first != last)
            this->insert(this->begin(), *first++);
    };

    //Removes from the multimap container either a single element or a range of elements ([first,last))
    void erase(iterator position)
    {
        this->__btree.erase_tree(position.get_pointer());
        --this->__size_multimap;
    };

    size_type erase(const key_type &k)
    {
        size_type erased;

		this->__size_multimap -= erased = this->__btree.erase_tree(k);
        return (erased);
    };

    void erase(iterator first, iterator last)
    {
        while (first != last)
        {
            first = this->__btree.erase_tree(first.get_pointer());
            --this->__size_multimap;
        }
    };

    //Exchanges the content of the container by the content of x, which is another multimap of the same type. Sizes may differ
    void swap(multimap &x)
    {
        this->__btree.swap(x.__btree);
        ft::swap(this->__size_multimap, x.__size_multimap);
    };

    //Removes all elements from the multimap container (which are destroyed), leaving the container with a size of 0
    void clear()
    {
        if (this->__size_multimap > 0)
            this->__btree.clear_tree();
        this->__size_multimap = 0;
    };

    /*          Observers                           */

    //Returns a copy of the comparison object used by the container to compare keys.
    key_compare key_comp() const
    {
        return (this->__btree.key_compare());
    };

    //Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
    value_compare value_comp() const
    {
        return (value_compare(this->__comp));
    };

    /*          Operations               */

    //Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to multimap::end.
    iterator find(const key_type &k)
    {
        node_pointer node;

        node = this->__btree.find_tree(k);
        if (node)
            return (iterator(node));
        return (this->end());
    };

    const_iterator find(const key_type &k) const
    {
        node_pointer node;

        if (!(node = this->__btree.find_tree(k)))
            return (this->end());
        return (const_iterator(node));
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

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator==(const ft::multimap<Key, T, Compare, Alloc> &lhs,
                const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator!=(const ft::multimap<Key, T, Compare, Alloc> &lhs,
                const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (!(lhs == rhs));
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator<(const ft::multimap<Key, T, Compare, Alloc> &lhs,
               const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator<=(const ft::multimap<Key, T, Compare, Alloc> &lhs,
                const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (!(rhs < lhs));
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator>(const ft::multimap<Key, T, Compare, Alloc> &lhs,
               const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (rhs < lhs);
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
bool operator>=(const ft::multimap<Key, T, Compare, Alloc> &lhs,
                const ft::multimap<Key, T, Compare, Alloc> &rhs)
{
    return (!(lhs < rhs));
};

template <typename Key,
          typename T,
          class Compare,
          class Alloc>
void swap(ft::multimap<Key, T, Compare, Alloc> &x, ft::multimap<Key, T, Compare, Alloc> &y)
{
    x.swap(y);
};

} // namespace ft

#endif
