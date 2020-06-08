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
        Node(const m_node &other): previous(other->node_previous()), value(other->node_value()), next(other->node_next()) {};
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
};

}

#endif
