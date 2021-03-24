#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include "algorithm.hpp"
#include "BtreeIterator.hpp"
#include <utility>

namespace ft
{

template <typename T, typename Compare>
class BTree
{
public:
    /*                      Member types                           */
    typedef T           value_type;
    typedef value_type &reference;
    typedef value_type const &const_reference;
    typedef value_type *pointer;
    typedef value_type const *const_pointer;
    typedef size_t      size_type;
    struct NodeTree
    {
        NodeTree *parent;
        NodeTree *left;
        NodeTree *right;
        value_type value;

        NodeTree(const_reference val = value_type()) : parent(nullptr), left(nullptr), right(nullptr), value(val){};
        NodeTree(NodeTree const &other) : parent(nullptr), left(nullptr), right(nullptr), value(other.value){};
    };
    typedef NodeTree                                node;
    typedef node                                    *node_pointer;
    typedef BTreeIterator<value_type, node>        iterator;
    typedef BTreeIterator<value_type const, node>  const_iterator;

protected:
    node_pointer    __root;
    node_pointer    __begin;
    node_pointer    __end;
    Compare         __comp;

    void disconnect_node(node_pointer node)
    {
        if (!node)
            return;
        node->right = node->left = node->parent = nullptr;
    };

    void insert_data(node_pointer node, node_pointer new_node)
    {
        if (this->__comp(new_node->value, node->value)) // the condition is met -> left
        {
            if (node->left)
                this->insert_data(node->left, new_node);
            else
            {
                node->left = new_node;
                new_node->parent = node;
            }
        }
        else // the condition is not met -> right
        {
            if (node->right)
                this->insert_data(node->right, new_node);
            else
            {
                node->right = new_node;
                new_node->parent = node;
            }
        }
    };
    
    void        copy_node(node_pointer *destination, node_pointer source, node_pointer end)
    {
        if (!source)
            return ;
        *destination = new NodeTree(*source);
        if (source->left)
        {
            copy_node(&(*destination)->left, source->left, end);
            (*destination)->left->parent = *destination;
        }
        if (source->right && source->right != end)
        {
            copy_node(&(*destination)->right, source->right, end);
            (*destination)->right->parent = *destination;
        }
    };

    node_pointer erase_no_child(node_pointer data)
    {
        node_pointer parent;

        if (data == this->__root)
        {
            this->__root = this->__begin = this->__end;
            this->disconnect_node(this->__end);
        }
        if ((parent = data->parent))
        {
            if (parent->left == data)
                parent->left = nullptr;
            else
            {
                parent->right = nullptr;
                if (parent->parent)
                    parent = parent->parent;
            }
        }
        if (data->right == this->__end)
            parent = this->__end;
        delete data;
        return (parent);
    };

    node_pointer erase_left_child(node_pointer data)
    {
        node_pointer parent;

        if ((parent = data->parent))
        {
            if (parent->left == data) // Connect parent with left-child
                parent->left = data->left;
            else
                parent->right = data->left;
        }
        data->left->parent = parent;
        if (data == this->__root)
            this->__root = data->left;
        delete data;
        return (parent);
    };

    node_pointer erase_right_child(node_pointer data)
    {
        node_pointer parent;

        if ((parent = data->parent))
        {
            if (parent->left == data) // Connect parent with right-child
                parent->left = data->right;
            else
                parent->right = data->right;
        }
        data->right->parent = parent;
        if (data == this->__root)
            this->__root = data->right;
        parent = data->right;
        delete data;
        return (parent);
    };

    node_pointer erase_both_childs(node_pointer data)
    {
        node_pointer    parent;
        node_pointer    tmp;

        tmp = data->left;
        while (tmp && tmp->right)   //Find Predecesor
            tmp = tmp->right;
        if ((parent = data->parent))
        {
            if (parent->left == data) // Connect parent with right-child
                parent->left = tmp;
            else
                parent->right = tmp;
        }
        tmp->parent = parent;
        if (!tmp->left && tmp != data->left)
        {
            tmp->left = data->left;
            data->left->parent = tmp;
        }
        if (!tmp->right && tmp != data->right)
        {
            tmp->right = data->right;
            data->right->parent = tmp;
        }
        if (data == this->__root)
            this->__root = tmp;
        parent = data->right;
        delete data;
        return (parent);
    };

    node_pointer erase_data(node_pointer data)
    {
        if (!data->left && !data->right)
            return (erase_no_child(data));
        else if (data->left && !data->right)
            return (erase_left_child(data));
        else if (data->right && !data->left)
            return (erase_right_child(data));
        else // Two Childs
            return (erase_both_childs(data));
    };

    template <typename K>
    node_pointer find_data(node_pointer node, K const &data_ref)
    {
        if (node && node != this->__end)
        {
            if (!this->__comp(data_ref, node->value) && !this->__comp(node->value, data_ref))
                return (node);
            if (find_data(node->left, data_ref))
                return (find_data(node->left, data_ref));
            if (find_data(node->right, data_ref))
                return (find_data(node->right, data_ref));
        }
        return (nullptr);
    };

    void delete_tree(node_pointer node)
    {
        if (!node || node == this->__end)
            return;
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    };

    void reconnect_tree(void)
    {
        node_pointer tmp = this->__root;

        while (tmp->left) // Go to the first element of the BTree
            tmp = tmp->left;
        this->__begin = tmp;
        tmp = this->__root;
        while (tmp->right) // Go to the last element of the BTree
            tmp = tmp->right;
        tmp->right = this->__end;
        this->__end->parent = tmp;
    };

public:
    BTree() : __root(nullptr), __begin(nullptr), __end(nullptr)
    {
        this->__root = this->__end = this->__begin = new NodeTree();
    };

    BTree(BTree const &other) : __root(other.__root), __comp(other.__comp)
    {
        this->__root = this->__end = this->__begin = new NodeTree();
        this->copy_tree(other);
    };

    virtual ~BTree()
    {
        clear_tree();
        if (this->__end)
            delete this->__end;
    };

    BTree &operator=(BTree const &other)
    {
        if (this->__begin != this->__end)
            clear_tree();
        this->__comp = other.__comp;
        this->copy_tree(other);
        return (*this);
    };

    void    copy_tree(BTree const &other)
    {
        if (other.__root == other.__end)
            return ;
        this->__root = new NodeTree(*other.__root);
        if (other.__root->left)
        {
			this->copy_node(&this->__root->left, other.__root->left, other.__end);
			this->__root->left->parent = this->__root;
		}
		if (other.__root->right)
        {
			this->copy_node(&this->__root->right, other.__root->right, other.__end);
			this->__root->right->parent = this->__root;
		}
        this->reconnect_tree();
    };

    iterator insert_tree(value_type new_val)
    {
        node_pointer new_nodetree = new NodeTree(new_val);

        if (this->__root == this->__end) // First element
            this->__root = new_nodetree;
        else
        {
            if (this->__end->parent)
                this->__end->parent->right = nullptr;
            insert_data(this->__root, new_nodetree);
        }
        this->reconnect_tree();
        return (iterator(new_nodetree));
    };

    iterator insert_tree(node_pointer node, value_type new_val)
    {
        if (!node || this->__root == this->__end || (node->parent && (__comp(new_val, node->parent->value) || __comp(node->parent->value, new_val))))
			return (this->insert_tree(new_val));
        node_pointer new_nodetree = new NodeTree(new_val);
        if (this->__end->parent)
            this->__end->parent->right = nullptr;
        this->insert_data(node, new_nodetree);
        this->reconnect_tree();
        return (iterator(new_nodetree));
    };

    node_pointer    erase_tree(node_pointer del_node)
    {
        if (this->__end->parent)
            this->__end->parent->right = nullptr;
        node_pointer last = this->erase_data(del_node);
        this->reconnect_tree();
        return (last);
    };

    template<typename Tp>
	size_type   erase_tree(Tp const &key)
    {
		node_pointer    node = nullptr;
		size_type       erased = 0;

		if (this->__end->parent)
            this->__end->parent->right = nullptr;
		while ((node = this->find_tree(key)))
        {
			this->erase_tree(node);
			++erased;
		}
		this->reconnect_tree();
		return (erased);
	};

    template <typename K>
    node_pointer find_tree(const K &val)
    {
        return (this->find_data(this->__root, val));
    };

    template <typename K>
    node_pointer find_tree(node_pointer node, const K &val)
    {
        if (!node)
            return (this->find_data(this->__root, val));
        if (!this->__comp(val, node->value) && !this->__comp(node->value, val))
            return (node);
        return (this->find_data(node, val));
    };

    void    swap(BTree &other)
    {
        ft::swap(this->__begin, other.__begin);
        ft::swap(this->__end, other.__end);
        ft::swap(this->__root, other.__root);
        ft::swap(this->__comp, other.__comp);
    };

    void clear_tree(void)
    {
        delete_tree(this->__root);
        this->__end->parent = nullptr;
        this->__end->left = nullptr;
        this->__end->right = nullptr;
        this->__begin = this->__root = this->__end;
    };

    Compare     key_compare() const
    {
        return (this->__comp);
    };

    /*Return iterator to beginning*/
    node_pointer begin()
    {
        return (this->__begin);
    };

    /*Return iterator to end*/
    node_pointer end()
    {
        return (this->__end);
    };

    /*Return iterator to beginning*/
    node_pointer begin() const
    {
        return (this->__begin);
    };

    /*Return iterator to end*/
    node_pointer end() const
    {
        return (this->__end);
    };
};

} // namespace ft

#endif
