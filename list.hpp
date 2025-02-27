#ifndef LIST_HPP
# define LIST_HPP

# include "tools/Node.hpp"
# include "tools/algorithm.hpp"
# include "tools/IteratorList.hpp"
# include "tools/reverse_iterator.hpp"
# include <limits>

namespace ft
{

template <class T, class Alloc = std::allocator<T> >
class list
{

    /*                      Member types                           */

public:
    typedef T                                               value_type;
protected:
    typedef Node<value_type>                                node_type;
    typedef node_type                                       *node_pointer;
public:
    typedef Alloc                                           allocator_type;
    typedef value_type                                      &reference;
    typedef value_type const                                &const_reference;
    typedef value_type                                      *pointer;
    typedef value_type const                                *const_pointer;
    typedef IteratorList<value_type, node_type>             iterator;
    typedef IteratorList<value_type const, node_type const> const_iterator;
    typedef ReverseIterator<iterator>                       reverse_iterator;
    typedef ReverseIterator<const_iterator>                 const_reverse_iterator;
    typedef std::ptrdiff_t                                  difference_type;
    typedef size_t                                          size_type;

private:
    node_pointer    _nbegin;
    node_pointer    _nend;
    size_type       _size;

    void init_list()
    {
        this->_nend = new node_type();
        this->_nbegin = this->_nend;
    }

    void reset()
    {
        this->_nend->connect_next(nullptr);
        this->_nend->connect_previous(nullptr);
        this->_nbegin = this->_nend;
    }

    /*                      Member Functions                       */

public:
    /*       Constructor Types      */

    /*Default Constructor*/
    list(void) : _nbegin(nullptr), _nend(nullptr), _size(0)
    {
        this->init_list();
    };

    /*Constructor with value intialization*/
    list(size_type n, const_reference val = value_type(),
            const allocator_type& alloc = allocator_type()) : _nbegin(nullptr), _nend(nullptr), _size(0)
    {
        (void)alloc;
        this->init_list();
        this->assign(n, val);
    };

    /*Constructor with range iterator*/
    template <typename InputIterator>
    list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    {
        (void)alloc;
        this->init_list();
        this->assign(first, last);
    };

    /*Constructor copy from other list*/
    list(const list &x) : _nbegin(nullptr), _nend(nullptr), _size(0)
    {
        this->init_list();
        this->assign(x.begin(), x.end());
    };

    /*         Destructor           */

    virtual ~list(void)
    {
        this->clear();
        if (this->_nend)
            delete this->_nend;
    };

    /*          Operators           */

    list &operator=(const list &x)
    {
        this->assign(x.begin(), x.end());
        return (*this);
    };

    /*          Iterators           */

    /*Return iterator to beginning*/
    iterator begin()
    {
        return (iterator(this->_nbegin));
    };

    /*Return const_iterator to beginning*/
    const_iterator begin() const
    {
        return (const_iterator(this->_nbegin));
    };

    /*Return iterator to end*/
    iterator end()
    {
        return (iterator(this->_nend));
    };

    /*Return const_iterator to end*/
    const_iterator end() const
    {
        return (const_iterator(this->_nend));
    };

    /*Return reverse iterator to reverse beginning*/
    reverse_iterator rbegin()
    {
        return (reverse_iterator(this->end()));
    };

    /*Return const_reverse_iterator to reverse beginning*/
    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(this->end()));
    };

    /*Return reverse iterator to reverse end*/
    reverse_iterator rend()
    {
        return (reverse_iterator(this->begin()));
    };

    /*Return const_reverse_iterator to reverse end*/
    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(this->begin()));
    };

    /*          Capacity            */

    /*Test whether container is empty*/
    bool empty() const
    {
        return (this->_size == 0);
    };

    /*Return _size*/
    size_type size() const
    {
        return (this->_size);
    };

    /*Return maximum _size*/
    size_type max_size() const
    {
        return (std::numeric_limits<size_type>::max() / (sizeof(node_type) - sizeof(pointer)));
    };

    /*          Element Access      */

    /*Access first element*/
    reference front()
    {
        return (this->_nbegin->node_value());
    };

    /*Access last element*/
    reference back()
    {
        return (this->_nend->node_previous()->node_value());
    };

    /*          Modifiers           */

    /*Assign new content to container*/
    //Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.
    void assign(iterator first, iterator last)
    {
        this->clear();
        for ((void)first; first != last; first++)
            this->push_back(*first);
    };

    void assign(const_iterator first, const_iterator last)
    {
        this->clear();
        for ((void)first; first != last; first++)
            this->push_back(*first);
    };

    void assign(size_type n, const_reference val)
    {
        this->clear();
        for (size_type i = 0; i < n; i++)
            this->push_back(val);
    };

    /*Insert element at beginning*/
    void push_front(const_reference val)
    {
        node_type *tmp = new node_type(val);
        if (this->empty())
            this->_nend->insert_before(tmp);
        else
            this->_nbegin->insert_before(tmp);
        this->_nbegin = tmp;
        this->_size++;
    };

    /*Delete first element*/
    void pop_front()
    {
        if (this->empty())
            return;
        node_type *tmp = this->_nbegin->node_next();
        free(this->_nbegin);
        this->_nbegin = tmp;
        this->_size--;
        if (this->_size == 0)
            this->reset();
    };

    /*Add element at the end*/
    void push_back(const_reference val)
    {
        node_type *tmp = new node_type(val);
        this->_nend->insert_before(tmp);
        if (this->empty())
            this->_nbegin = tmp;
        this->_size++;
    };

    /*Delete last element*/
    void pop_back()
    {
        if (this->empty())
            return;
        else if (this->_size == 1)
        {
            free(this->_nend->node_previous());
            this->_nbegin = _nend;
        }
        else
        {
            node_type *tmp = this->_nend->node_previous()->node_previous();
            tmp->connect_next(this->_nend);
            free(this->_nend->node_previous());
            this->_nend->connect_previous(tmp);
        }
        this->_size--;
        if (this->_size == 0)
            this->reset();
    };

    /*Insert elements*/
    iterator insert(iterator position, const_reference val)
    {
        if (position.get_pointer()->node_previous() == nullptr)
        {
            this->push_front(val);
            return (this->begin());
        }
        else
        {
            position.get_pointer()->insert_before(new node_type(val));
            this->_size++;
            return (iterator(position.get_pointer()->node_previous()));
        }
    };

    void insert(iterator position, size_type n, const_reference val)
    {
        for (size_type i = 0; i < n; i++)
            this->insert(position, val);
    };

    void insert(iterator position, iterator first, iterator last)
    {
        for (; first != last; ++first)
            this->insert(position, *first);
    };

    /*Erase elements*/
    iterator erase(iterator position)
    {
        if (position.get_pointer() == this->_nbegin)
        {
            this->pop_front();
            return (this->begin());
        }
        else if (position.get_pointer()->node_next() == this->_nend)
        {
            this->pop_back();
            return (this->end());
        }
        position.get_pointer()->node_previous()->connect_next(position.get_pointer()->node_next());
        position.get_pointer()->node_next()->connect_previous(position.get_pointer()->node_previous());
        node_type *tmp = position.get_pointer()->node_next();
        free(position.get_pointer());
        this->_size--;
        return (iterator(tmp));
    };

    iterator erase(iterator first, iterator last)
    {
        iterator tmp;

        for (; first != last; ++first)
            tmp = this->erase(first);
        return (tmp);
    };

    /*Swap content with other list*/
    void swap(list &x)
    {
        list<value_type> tmp(x);
        x.assign(this->begin(), this->end());
        *this = tmp;
    };

    /*Change _size*/
    void resize(size_type n, value_type val = value_type())
    {
        if (n > this->_size)
            for (size_type i = this->_size; i < n; i++)
                this->push_back(val);
        else if (n < this->_size)
            for (size_type i = this->_size; i > n && n >= 0; i--)
                this->pop_back();
    };

    /*Clear list*/
    //Removes all elements from the list container (which are destroyed), and leaving the container with a _size of 0.
    void clear()
    {
        if (this->empty())
            return;
        this->erase(this->begin(), this->end());
        this->_size = 0;
        this->init_list();
    };

    /*              Operations                */

    /*Transfer elements from list to list*/
    void splice(iterator position, list &x)
    {
        this->splice(position, x, x.begin(), x.end());
    };

    void splice(iterator position, list &x, iterator i)
    {
        iterator iend = i;
        this->splice(position, x, i, ++iend);
    };

    void splice(iterator position, list &x, iterator first, iterator last)
    {
        node_type *tmp;

        while (first != last)
        {
            tmp = first++.get_pointer();
            if (tmp == x._nbegin)
                x._nbegin = tmp->node_next();
            tmp->leave_node();
            position.get_pointer()->insert_before(tmp);
            if (position.get_pointer() == this->_nbegin)
                this->_nbegin = tmp;
            this->_size++;
            x._size--;
        }
        if (x.empty())
            x.reset();
    };

    /*Remove elements with specific value*/
    void remove(const_reference val)
    {
        iterator it = this->begin();
        iterator save;

        while (it != this->end())
        {
            save = it + 1;
            if (*it == val)
                this->erase(it);
            it = save;
        }
        if (this->empty())
            this->reset();
    };

    /*Remove elements fulfilling condition*/
    template <class Predicate>
    void remove_if(Predicate pred)
    {
        iterator it = this->begin();
        iterator save;

        while (it != this->end())
        {
            save = it + 1;
            if (pred(*it))
                this->erase(it);
            it = save;
        }
        if (this->empty())
            this->reset();
    };

    /*Remove duplicate values*/
    void unique(void)
    {
        this->unique(equal<value_type>);
    };

    template <class BinaryPredicate>
    void unique(BinaryPredicate binary_pred)
    {
        iterator it = this->begin();
        iterator next = it + 1;

        while (it != this->end())
        {
            if (binary_pred(*it, *next))
                this->erase(next);
            else
                it = next;
            if (++next == this->end())
                it = next;
        }
    };

    /*Merge sorted lists*/
    void merge(list &x)
    {
        this->merge(x, &less_than<value_type>);
    };

    template <class Compare>
    void merge(list &x, Compare comp)
    {
        iterator it = this->begin();
        iterator itend = this->end();
        iterator itl = x.begin();
        iterator itlend = x.end();

        while (it != itend && itl != itlend)
        {
            if ((*comp)(*itl, *it) && it != itl)
            {
                this->splice(it, x, itl);
                it = this->begin();
                itl = x.begin();
            }
            else
                it++;
        }
        this->splice(itend, x);
    };

    /*Sort elements in container*/
    void sort()
    {
        this->sort(&less_than<value_type>);
    };

    template <class Compare>
    void sort(Compare comp)
    {
        iterator it;

        for (size_type i = 0; i < this->_size; i++)
        {
            it = this->begin();
            for (iterator it2 = this->begin() + 1; it2 != this->end(); it2++)
            {
                if (it != it2 && (*comp)(*it2, *it))
                {
                    it.get_pointer()->swap(it2.get_pointer());
                    if (it == this->begin())
                        this->_nbegin = it2.get_pointer();
                    else if (it2 == this->begin())
                        this->_nbegin = it.get_pointer();
                    it2 = it;
                }
                else
                    it++;
            }
        }
    };

    /*Reverses the order of the elements in the list container.*/
    void reverse()
    {
        iterator it;
        iterator it2;

        for (size_type i = 0; i < this->_size; i++)
        {
            it = this->begin();
            it2 = it + 1;
            while (it2 != this->end() - i)
            {
                it.get_pointer()->swap(it2.get_pointer());
                if (it == this->begin())
                    this->_nbegin = it2.get_pointer();
                it2 = it + 1;
            }
        }
    };
};

/*          Non-member function overloads               */

template <typename T>
bool operator==(const list<T> &lhs, const list<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return (false);
    typename list<T>::const_iterator it = lhs.begin();
    typename list<T>::const_iterator it2 = rhs.begin();
    while (it != lhs.end())
        if (*it++ != *it2++)
            return (false);
    return (true);
};

template <typename T>
bool operator!=(const list<T> &lhs, const list<T> &rhs)
{
    return (!(lhs == rhs));
};

template <typename T>
bool operator<(const list<T> &lhs, const list<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return (lhs.size() < rhs.size());
    typename list<T>::const_iterator it = lhs.begin();
    typename list<T>::const_iterator it2 = rhs.begin();
    while (it != lhs.end())
        if (*it++ < *it2++)
            return (true);
    return (false);
};

template <typename T>
bool operator<=(const list<T> &lhs, const list<T> &rhs)
{
    return ((lhs < rhs) || (lhs == rhs));
};

template <typename T>
bool operator>(const list<T> &lhs, const list<T> &rhs)
{
    return (rhs < lhs);
};

template <typename T>
bool operator>=(const list<T> &lhs, const list<T> &rhs)
{
    return ((rhs < lhs) || (rhs == lhs));
};

template <typename T>
void swap(list<T> &x, list<T> &y)
{
    x.swap(y);
};

} // namespace ft

#endif
