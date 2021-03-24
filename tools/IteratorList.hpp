#ifndef ITERATORLIST_HPP
#define ITERATORLIST_HPP

namespace ft
{

template <typename T, typename Node>
class IteratorList
{
public:
    typedef T value_type;
    typedef Node node_type;
    typedef node_type *pointer;
    typedef node_type *const const_pointer;
    typedef value_type &reference;
    typedef value_type const &const_reference;

private:
    pointer _p;

    void set_pointer(node_type *ptr)
    {
        this->_p = ptr;
    };

public:
    IteratorList(void) : _p(nullptr){};
    IteratorList(pointer point) : _p(point){};
    IteratorList(IteratorList const &other) : _p(other.get_pointer()){};
    virtual ~IteratorList(){};

    pointer get_pointer() const
    {
        return (this->_p);
    };

    IteratorList &operator++()
    {
        this->_p = this->_p->node_next();
        return (*this);
    };

    IteratorList operator++(int)
    {
        IteratorList tmp(*this);
        this->_p = this->_p->node_next();
        return (tmp);
    };

    IteratorList operator++(int) const
    {
        IteratorList tmp(*this);
        this->_p = this->_p->node_next();
        return (tmp);
    };

    IteratorList &operator--()
    {
        this->_p = this->_p->node_previous();
        return (*this);
    };

    IteratorList operator--(int)
    {
        IteratorList tmp(*this);
        this->_p = this->_p->node_previous();
        return (tmp);
    };

    IteratorList operator--(int) const
    {
        IteratorList tmp(*this);
        this->_p = this->_p->node_previous();
        return (tmp);
    };

    reference operator*()
    {
        return (this->_p->node_value());
    };

    const_reference operator*() const
    {
        return (this->_p->node_value());
    };

    pointer operator->()
    {
        return (&this->_p->node_value());
    };

    const_pointer operator->() const
    {
        return (&this->_p->node_value());
    };

    IteratorList &operator=(const IteratorList &other)
    {
        this->_p = other.get_pointer();
        return (*this);
    };

    IteratorList operator+(int val)
    {
        IteratorList tmp(*this);

        for (int i = 0; i < val; i++)
        {
            tmp.set_pointer(tmp.get_pointer()->node_next());
            if (tmp.get_pointer()->node_next() == nullptr)
                break;
        }
        return (tmp);
    };

    IteratorList operator-(int val)
    {
        IteratorList tmp(*this);

        for (int i = 0; i < val; i++)
        {
            tmp.set_pointer(tmp.get_pointer()->node_previous());
            if (tmp.get_pointer()->node_previous() == nullptr)
                break;
        }
        return (tmp);
    };

    IteratorList &operator+=(int val)
    {
        for (int i = 0; i < val; i++)
        {
            this->_p = this->_p->node_next();
            if (this->_p->node_next() == nullptr)
                break;
        }
        return (*this);
    };

    IteratorList &operator-=(int val)
    {
        for (int i = 0; i < val; i++)
        {
            this->_p = this->_p->node_previous();
            if (this->_p->node_previous() == nullptr)
                break;
        }
        return (*this);
    };

    bool operator==(const IteratorList &other) const
    {
        return (this->_p == other.get_pointer());
    };

    bool operator!=(const IteratorList &other) const
    {
        return (this->_p != other.get_pointer());
    };

    bool operator>=(const IteratorList &other) const
    {
        return (this->_p >= other.get_pointer());
    };

    bool operator<=(const IteratorList &other) const
    {
        return (this->_p <= other.get_pointer());
    };

    bool operator<(const IteratorList &other) const
    {
        return (this->_p < other.get_pointer());
    };

    bool operator>(const IteratorList &other) const
    {
        return (this->_p > other.get_pointer());
    };
};
} // namespace ft

#endif
