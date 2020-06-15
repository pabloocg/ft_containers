#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{

template <typename T>
class Node
{
    public:

        typedef T                   value_type;
        typedef Node<value_type>    *m_node;

    private:

        m_node              previous;
        value_type          value;
        m_node              next;

    public:

        Node(): previous(nullptr), value(), next(nullptr) {};
        Node(T const val): previous(nullptr), value(val), next(nullptr) {};
        Node(const m_node &other): previous(other->previous), value(other->value), next(other->next) {};
        virtual ~Node() {};

        void        leave_node()
        {
            if (this->previous)
                this->previous->next = this->next;
            if (this->next)
                this->next->previous = this->previous;
            this->previous = nullptr;
            this->next = nullptr;
        }

        value_type  &node_value(void)
        {
            return (this->value);
        }

        //value_type  node_value(void) const
        //{
        //    return (this->value);
        //}

        m_node      node_previous(void)
        {
            return (this->previous);
        }

        m_node      node_next(void)
        {
            return (this->next);
        }

        void    connect_previous(m_node new_node)
        {
            this->previous = new_node;
        }

        void    connect_next(m_node new_node)
        {
            this->next = new_node;
        }

        void    insert_before(m_node new_node)
        {
            if (this->previous)
            {
                this->previous->next = new_node;
                new_node->previous = this->previous;
            }
            new_node->next = this;
            this->previous = new_node;
        }

        void    insert_after(m_node new_node)
        {
            if (this->next)
            {
                this->next->previous = new_node;
                new_node->next = this->next;
            }
            new_node->previous = this;
            this->next = new_node;
        }

        void    swap(m_node other_node)
        {
            Node<value_type>    tmp(other_node);

            if (tmp.node_next() && tmp.node_next() != this)
                tmp.node_next()->previous = this;
            if (tmp.node_previous() && tmp.node_previous() != this)
                tmp.node_previous()->next = this;

            if (this->next && this->next != other_node)
                this->next->previous = other_node;
            if (this->previous && this->previous != other_node)
                this->previous->next = other_node;

            if (this->next && this->next == other_node)
                other_node->next = this;
            else
                other_node->next = this->next;
            if (this->previous == other_node)
                other_node->previous = this;
            else
                other_node->previous = this->previous;

            if (tmp.node_previous() && tmp.node_previous() == this)
                this->previous = other_node;
            else
                this->previous = tmp.node_previous();
            if (tmp.node_next() && tmp.node_next() == this)
                this->next = other_node;
            else
                this->next = tmp.node_next();
        }

        m_node& operator= (const m_node & other)
        {
            this->value = other->node_value();
            this->next = other->node_next();
            this->previous = other->node_previous();
            return (*this);
        };
};

}

#endif
