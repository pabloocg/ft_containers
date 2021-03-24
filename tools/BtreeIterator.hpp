#ifndef BTREEITERATOR_HPP
# define BTREEITERATOR_HPP
# include <iostream>

namespace ft
{

template <typename T, typename BtreeNode>
class BTreeIterator
{

public:

    typedef T                   value_type;
    typedef value_type          *pointer;
    typedef value_type const    *const_pointer;
    typedef value_type          &reference;
    typedef value_type const    &const_reference;
    typedef BtreeNode           node_type;
    typedef node_type           *node_pointer;
    typedef node_type const     *const_node_pointer;

protected:

    node_pointer    _p;

    void            next_node()
    {
        if (this->_p->right)
        {
            this->_p = this->_p->right;
            while (this->_p->left)
                this->_p = this->_p->left;
        }
        else
        {
            node_pointer    tmp(this->_p);

            this->_p = this->_p->parent;
            while (this->_p->left != tmp)
            {
                tmp = this->_p;
                this->_p = this->_p->parent;
            }
        }
    };

    void            previous_node()
    {
        if (this->_p->left)
        {
            this->_p = this->_p->left;
            while (this->_p->right)
                this->_p = this->_p->right;
        }
        else
        {
            node_pointer    tmp(this->_p);

            this->_p = this->_p->parent;
            while (this->_p->right != tmp)
            {
                tmp = this->_p;
                this->_p = this->_p->parent;
            }
        }
    };
public:

    BTreeIterator(void): _p(nullptr) {};
    BTreeIterator(node_pointer point): _p(point) {};
    BTreeIterator(BTreeIterator const &other): _p(other._p) {};
    virtual ~BTreeIterator() {};

    BTreeIterator& operator= (const BTreeIterator & other)
    {
        this->_p = other.get_pointer();
        return (*this);
    };

    node_pointer    get_pointer() const
    {
        return (this->_p);
    };

    BTreeIterator& operator++ ()
    {
        this->next_node();
        return (*this);
    };

    BTreeIterator operator++ (int)
    {
        BTreeIterator   tmp(*this);

        this->next_node();
        return (tmp);
    };

    BTreeIterator& operator-- ()
    {
        this->previous_node();
        return (*this);
    };

    BTreeIterator operator-- (int)
    {
        BTreeIterator   tmp(*this);

        this->previous_node();
        return (tmp);
    };

    reference operator*()
    {
        return (this->_p->value);
    };

    const_reference operator*() const
    {
        return (this->_p->value);
    };

    pointer         operator->()
    {
        return (&this->_p->value);
    };

    const_pointer   operator->() const
    {
        return (&this->_p->value);
    };
    
    BTreeIterator   operator+ (int val)
    {
        BTreeIterator   tmp(*this);

        if (val > 0)
            for (int i = 0; i < val; i++)
                tmp.next_node();
        else
            for (int i = 0; i < val; i++)
                tmp.previous_node();
        return (tmp);
    };

    BTreeIterator   operator- (int val)
    {
        BTreeIterator   tmp(*this);

        tmp.operator+(-val);
        return (tmp);
    };

    BTreeIterator&   operator+= (int val)
    {
        if (val > 0)
            for (int i = 0; i < val; i++)
                next_node();
        else
            for (int i = 0; i < val; i++)
                previous_node();
        return (*this);
    };

    BTreeIterator&   operator-= (int val)
    {
        this->operator+=(-val);
        return (*this);
    };

    bool operator== (const BTreeIterator & other) const
    {
        return (this->_p == other.get_pointer());
    };

    bool operator!= (const BTreeIterator & other) const
    {
        return (this->_p != other.get_pointer());
    };

    bool operator>= (const BTreeIterator & other) const
    {
        return (this->_p >= other.get_pointer());
    };

    bool operator<= (const BTreeIterator & other) const
    {
        return (this->_p <= other.get_pointer());
    };

    bool operator< (const BTreeIterator & other) const
    {
        return (this->_p < other.get_pointer());
    };

    bool operator> (const BTreeIterator & other) const
    {
        return (this->_p > other.get_pointer());
    };


};

}

#endif
