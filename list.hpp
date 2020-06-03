#ifndef LIST_HPP
# define LIST_HPP
# include "tools/Node.hpp"
# include <limits>

namespace ft
{

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
        //typedef typename std::list<T, allocator_type>::iterator                      iterator;
        //typedef typename std::list<T, allocator_type>::const_iterator                const_iterator;
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
        //list (const list& x);

                    /*         Destructor           */

        virtual ~list(void)
        {
            this->clear();
            delete this->n_end;
        };

                    /*          Operators           */

        //list& operator= (const list& x);

                    /*          Iterators           */

        /*Return iterator to beginning*/
        //iterator begin();

        /*Return iterator to end*/
        //iterator end();

        /*Return reverse iterator to reverse beginning*/
        //reverse_iterator rbegin();

        /*Return reverse iterator to reverse end*/
        //reverse_iterator rend();

        /*Return const_iterator to beginning*/
        //const_iterator cbegin() const;

        /*Return const_iterator to end*/
        //const_iterator cend() const;

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
            return std::max<size_type>(std::numeric_limits<difference_type >::min(), std::numeric_limits<difference_type >::max());
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
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            this->clear();
            for (; first != last; first++)
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
                this->n_begin->insert_before(new node_type(val));
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
        //iterator insert (iterator position, const value_type& val);
        //void insert (iterator position, size_type n, const value_type& val);
        //template <class InputIterator>
        //void insert (iterator position, InputIterator first, InputIterator last);

        /*Erase elements*/
        //iterator erase (iterator position);
        //iterator erase (iterator first, iterator last);

        /*Swap content with other list*/
        //void swap (list& x);

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
            while (this->n_begin)
            {
                node_type *tmp = this->n_begin->node_next();
                free(this->n_begin);
                this->n_begin = tmp;
            }
            this->list_size = 0;
            this->init_list();
        };


                    /*              Operations                */

        /*Transfer elements from list to list*/
        //void splice (iterator position, list& x);
        //void splice (iterator position, list& x, iterator i);
        //void splice (iterator position, list& x, iterator first, iterator last);

        /*Remove elements with specific value*/
        //void remove (const value_type& val);

        /*Remove elements fulfilling condition*/
        //template <class Predicate>
        //void remove_if (Predicate pred);

        /*Remove duplicate values*/
        //void unique();
        //template <class BinaryPredicate>
        //void unique (BinaryPredicate binary_pred);

        /*Merge sorted lists*/
        //void merge (list& x);
        //template <class Compare>
        //void merge (list& x, Compare comp);

        /*Sort elements in container*/
        //void sort();
        //template <class Compare>
        //void sort (Compare comp);

        /*Reverses the order of the elements in the list container.*/
        //void reverse();

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
