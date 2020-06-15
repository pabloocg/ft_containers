#ifndef LIST_HPP
# define LIST_HPP
# include "tools/Node.hpp"
# include "tools/algorithm.hpp"
# include <limits>


namespace ft
{

template <typename T>
class iterator_list
{
    public:

        typedef T                   value_type;
        typedef Node<value_type>    node_type;
        typedef value_type &        reference;

    private:
        node_type  *pointer;
    
    public:
        iterator_list(void): pointer(nullptr) {};
        iterator_list(node_type *point): pointer(point) {};
        iterator_list(iterator_list  const &other): pointer(other.get_pointer()) {};
        virtual ~iterator_list() {};

        node_type   *get_pointer() const
        {
            return (this->pointer);
        }

        void        set_pointer(node_type *ptr)
        {
            this->pointer = ptr;
        }

        iterator_list& operator++ ()
        {
            this->pointer = this->pointer->node_next();
            return (*this);
        };

        iterator_list operator++ (int)
        {
            iterator_list   tmp(*this);
            this->pointer = this->pointer->node_next();
            return (tmp);
        };

        iterator_list& operator-- ()
        {
            this->pointer = this->pointer->node_previous();
            return (*this);
        };

        iterator_list operator-- (int)
        {
            iterator_list   tmp(*this);
            this->pointer = this->pointer->node_previous();
            return (tmp);
        };

        reference operator* ()
        {
            return (this->pointer->node_value());
        };

        iterator_list& operator= (const iterator_list & other)
        {
            this->pointer = other.get_pointer();
            return (*this);
        };

        
        iterator_list   operator+ (int val)
        {
            iterator_list   tmp(*this);

            for (int i = 0; i < val; i++)
            {
                tmp.set_pointer(tmp.get_pointer()->node_next());
                if (tmp.get_pointer()->node_next() == nullptr)
                    break ;
            }
            return (tmp);
        };

        iterator_list   operator- (int val)
        {
            iterator_list   tmp(*this);

            for (int i = 0; i < val; i++)
            {
                tmp.set_pointer(tmp.get_pointer()->node_previous());
                if (tmp.get_pointer()->node_previous() == nullptr)
                    break ;
            }
            return (tmp);
        };

        iterator_list&   operator+= (int val)
        {
            for (int i = 0; i < val; i++)
            {
                this->pointer = this->pointer->node_next();
                if (this->pointer->node_next() == nullptr)
                    break ;
            }
            return (*this);
        };

        iterator_list&   operator-= (int val)
        {
            for (int i = 0; i < val; i++)
            {
                this->pointer = this->pointer->node_previous();
                if (this->pointer->node_previous() == nullptr)
                    break ;
            }
            return (*this);
        };

        bool operator== (const iterator_list & other)
        {
            return (this->pointer == other.get_pointer());
        };

        bool operator!= (const iterator_list & other)
        {
            return (this->pointer != other.get_pointer());
        };

        bool operator>= (const iterator_list & other)
        {
            return (this->pointer >= other.get_pointer());
        };

        bool operator<= (const iterator_list & other)
        {
            return (this->pointer <= other.get_pointer());
        };

        bool operator< (const iterator_list & other)
        {
            return (this->pointer < other.get_pointer());
        };

        bool operator> (const iterator_list & other)
        {
            return (this->pointer > other.get_pointer());
        };

};

template <typename T, class Alloc = std::allocator<T> >
class list
{

    /*                      Member types                           */

    public:

        typedef T                               value_type;
        typedef Node<value_type>                node_type;
        typedef Alloc                           allocator_type;
        typedef value_type                  &   reference;
        typedef value_type const            &   const_reference;
        typedef value_type                  *   pointer;
        typedef value_type const            *   const_pointer;
        typedef iterator_list<value_type>       iterator;
        typedef iterator_list<value_type> const const_iterator;
        //typedef typename std::list<T, allocator_type>::reverse_iterator              reverse_iterator;
        //typedef typename std::list<T, allocator_type>::const_reverse_iterator        const_reverse_iterator;
        typedef std::ptrdiff_t                  difference_type;
        typedef size_t                          size_type;

    private:

        node_type         *n_begin;
        node_type         *n_end;
        size_type         list_size;

        void    init_list()
        {
            this->n_end = new node_type();
            this->n_begin = this->n_end;
        }

        void    reset()
        {
            this->n_end->connect_next(nullptr);
            this->n_end->connect_previous(nullptr);
            this->n_begin = this->n_end;
        }

    /*                      Member Functions                       */

    public:

                    /*       Constructor Types      */

        /*Default Constructor*/
        explicit list (void): n_begin(nullptr), n_end(nullptr), list_size(0)
        {
            this->init_list();
        };

        /*Constructor with value intialization*/
        explicit list (size_type n, const value_type& val = value_type()): n_begin(nullptr), n_end(nullptr), list_size(0)
        {
            this->init_list();
            this->assign(n, val);
        };

        /*Constructor with range iterator*/
        template <class InputIterator>
        list (InputIterator first, InputIterator last)
        {
            this->init_list();
            this->assign(first, last);
        };

        /*Constructor copy from other list*/
        list (const list& x): n_begin(nullptr), n_end(nullptr), list_size(0)
        {
            this->init_list();
            this->assign(x.cbegin(), x.cend());
        };

                    /*         Destructor           */

        virtual ~list(void)
        {
            this->clear();
            if (this->n_end)
                delete this->n_end;
        };

                    /*          Operators           */

        list& operator= (const list& x)
        {
            this->assign(x.cbegin(), x.cend());
            return (*this);
        };

                    /*          Iterators           */

        /*Return iterator to beginning*/
        iterator begin()
        {
            return (iterator(this->n_begin));
        };

        /*Return iterator to end*/
        iterator end()
        {
            return (iterator(this->n_end));
        };

        /*Return reverse iterator to reverse beginning*/
        //reverse_iterator rbegin();

        /*Return reverse iterator to reverse end*/
        //reverse_iterator rend();

        /*Return const_iterator to beginning*/
        const_iterator cbegin() const
        {
            return (const_iterator(this->n_begin));
        };

        /*Return const_iterator to end*/
        const_iterator cend() const
        {
            return (const_iterator(this->n_end));
        };

        /*Return const_reverse_iterator to reverse beginning*/
        //const_reverse_iterator crbegin() const;

        /*Return const_reverse_iterator to reverse end*/
        //const_reverse_iterator crend() const;


                    /*          Capacity            */
        
        /*Test whether container is empty*/
        bool empty() const
        {
            return (this->list_size == 0);
        };

        /*Return size*/
        size_type size() const
        {
            return (this->list_size);
        };

        /*Return maximum size*/
        size_type max_size() const
        {
            return std::max<size_type>(std::numeric_limits<difference_type >::min(),
                                std::numeric_limits<difference_type >::max());
        };


                    /*          Element Access      */
        
        /*Access first element*/
        reference front()
        {
            return (this->n_begin->node_value());
        };

        /*Access last element*/
        reference back()
        {
            return (this->n_end->node_previous()->node_value());
        };


                    /*          Modifiers           */

        /*Assign new content to container*/
                //Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.
        void assign (iterator first, iterator last)
        {
            this->clear();
            for (; first != last; ++first)
                this->push_back(*first);
        };

        void assign (size_type n, const value_type& val)
        {
            this->clear();
            for (size_t i = 0; i < n; i++)
                this->push_back(val);
        };

        /*Insert element at beginning*/
        void push_front (const value_type& val)
        {
            node_type *tmp = new node_type(val);
            if (this->empty())
                this->n_end->insert_before(tmp);
            else
                this->n_begin->insert_before(tmp);
            this->n_begin = tmp;
            this->list_size++;
        };

        /*Delete first element*/
        void pop_front()
        {
            if (this->empty())
                return ;
            node_type *tmp = this->n_begin->node_next();
            free(this->n_begin);
            this->n_begin = tmp;
            this->list_size--;
        };

        /*Add element at the end*/
        void push_back (const value_type& val)
        {
            node_type *tmp = new node_type(val);
            this->n_end->insert_before(tmp);
            if (this->empty())
                this->n_begin = tmp;
            this->list_size++;
        };

        /*Delete last element*/
        void pop_back()
        {
            if (this->empty())
                return ;
            node_type *tmp = this->n_end->node_previous()->node_previous();
            tmp->connect_next(this->n_end);
            free(this->n_end->node_previous());
            this->n_end->connect_previous(tmp);
            this->list_size--;
        };

        /*Insert elements*/
        iterator insert (iterator position, const value_type& val)
        {
            if (position.get_pointer()->node_previous() == nullptr)
            {
                this->push_front(val);
                return (this->begin());
            }
            else
            {
                position.get_pointer()->insert_before(new node_type(val));
                this->list_size++;
                return (iterator(position.get_pointer()->node_previous()));
            }
        };

        void insert (iterator position, size_type n, const value_type& val)
        {
            for (size_t i = 0; i < n; i++) this->insert(position, val);
        };

        void insert (iterator position, iterator first, iterator last)
        {
            for (; first != last; ++first) this->insert(position, *first);
        };

        /*Erase elements*/
        iterator erase (iterator position)
        {
            if (position.get_pointer() == this->n_begin)
            {
                this->pop_front();
                return (this->begin());
            }
            else if (position.get_pointer()->node_next() == this->n_end)
            {
                this->pop_back();
                return (this->end());
            }
            position.get_pointer()->node_previous()->connect_next(position.get_pointer()->node_next());
            position.get_pointer()->node_next()->connect_previous(position.get_pointer()->node_previous());
            node_type *tmp = position.get_pointer()->node_next();
            free(position.get_pointer());
            this->list_size--;
            return (iterator(tmp));
        };
        
        iterator erase (iterator first, iterator last)
        {
            iterator tmp;

            for (; first != last; ++first) tmp = this->erase(first);
            return (tmp);
        };

        /*Swap content with other list*/
        void swap (list& x)
        {
            list<value_type> tmp(x);
            x.assign(this->begin(), this->end());
            *this = tmp;
        };

        /*Change size*/
        void resize (size_type n, value_type val = value_type())
        {
            if (n > this->size())
                for (size_t i = this->size(); i < n; i++)
                    this->push_back(val);
            else if (n < this->size())
                for (size_t i = this->size(); i > n && n > 0; i--)
                    this->pop_back();
        };

        /*Clear list*/
        //Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
        void clear()
        {
            if (this->empty())
                return ;
            this->erase(this->begin(), this->end());
            this->list_size = 0;
            this->init_list();
        };


                    /*              Operations                */

        /*Transfer elements from list to list*/
        void splice (iterator position, list& x)
        {
            this->splice(position, x, x.begin(), x.end());
        };

        void splice (iterator position, list& x, iterator i)
        {
            iterator iend = i;
            this->splice(position, x, i, ++iend);
        };

        void splice (iterator position, list& x, iterator first, iterator last)
        {
            node_type *tmp;

            while (first != last)
            {
                tmp = first++.get_pointer();
                if (tmp == x.n_begin)
                    x.n_begin = tmp->node_next();
                tmp->leave_node();
                position.get_pointer()->insert_before(tmp);
                if (position.get_pointer() == this->n_begin)
                    this->n_begin = tmp;
                this->list_size++;
                x.list_size--;
            }
            if (x.empty())
                x.reset();
        };

        /*Remove elements with specific value*/
        void remove (const value_type& val)
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
        void remove_if (Predicate pred)
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
        void unique (BinaryPredicate binary_pred)
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
        void merge (list& x)
        {
            this->splice(iterator(this->n_end->node_previous()), x, x.begin(), x.end());
        };

        template <class Compare>
        void merge (list& x, Compare comp)
        {
            iterator it = this->begin();
            iterator itl = x.begin();

            while (it != this->end())
            {
                if (comp(*it, *itl))
                {
                    this->splice(it, x, itl++);
                    it = this->begin();
                }
                else
                {
                    if (it.get_pointer()->node_next() == this->end().get_pointer())
                    {
                        this->splice(it, x, itl++);
                        it = this->begin();
                    }
                    else
                        it++;
                }
                if (it.get_pointer()->node_next() == this->end().get_pointer() && itl.get_pointer()->node_next() != x.end().get_pointer())
                    it = this->begin();
            }
        };

        /*Sort elements in container*/
        void sort()
        {
            this->sort(less<value_type>);
        };

        template <class Compare>
        void sort (Compare comp)
        {
            iterator it;

            for (size_type i = 0; i < this->size(); i++)
            {
                it = this->begin();
                for (iterator it2 = this->begin() + 1; it2 != this->end(); it2++)
                {
                    if (it != it2 && comp(*it, *it2))
                    {
                        it.get_pointer()->swap(it2.get_pointer());
                        if (it == this->begin())
                            this->n_begin = it2.get_pointer();
                        else if (it2 == this->begin())
                            this->n_begin = it.get_pointer();
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

            for (size_type i = 0; i < this->size(); i++)
            {
                it = this->begin();
                it2 = it + 1;
                while (it2 != this->end() - i)
                {
                    it.get_pointer()->swap(it2.get_pointer());
                    if (it == this->begin())
                        this->n_begin = it2.get_pointer();
                    it2 = it + 1;
                }
            }
        };

};

/*          Non-member function overloads               */
/*
template <class T, class Alloc>
  bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y);
*/

}

#endif
