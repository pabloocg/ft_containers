#ifndef ITERATORLIST_HPP
# define ITERATORLIST_HPP

namespace ft
{

    template <typename T, typename Node>
    class IteratorList
    {
        public:

            typedef T                   value_type;
            typedef Node                node_type;
            typedef node_type*          node_pointer;
            typedef value_type &        reference;
            typedef value_type const &  const_reference;

        private:

            node_pointer    pointer;
        
        public:

            IteratorList(void): pointer(nullptr) {};
            IteratorList(node_pointer point): pointer(point) {};
            IteratorList(IteratorList const &other): pointer(other.get_pointer()) {};
            virtual ~IteratorList() {};

            node_pointer    get_pointer() const
            {
                return (this->pointer);
            }

            void        set_pointer(node_type *ptr)
            {
                this->pointer = ptr;
            }

            IteratorList& operator++ ()
            {
                this->pointer = this->pointer->node_next();
                return (*this);
            };

            IteratorList operator++ (int)
            {
                IteratorList   tmp(*this);
                this->pointer = this->pointer->node_next();
                return (tmp);
            };

            IteratorList operator++ (int) const
            {
                IteratorList   tmp(*this);
                this->pointer = this->pointer->node_next();
                return (tmp);
            };

            IteratorList& operator-- ()
            {
                this->pointer = this->pointer->node_previous();
                return (*this);
            };

            IteratorList operator-- (int)
            {
                IteratorList   tmp(*this);
                this->pointer = this->pointer->node_previous();
                return (tmp);
            };

            IteratorList operator-- (int) const
            {
                IteratorList   tmp(*this);
                this->pointer = this->pointer->node_previous();
                return (tmp);
            };

            reference operator* ()
            {
                return (this->pointer->node_value());
            };

            const_reference operator* () const
            {
                return (this->pointer->node_value());
            };

            IteratorList& operator= (const IteratorList & other)
            {
                this->pointer = other.get_pointer();
                return (*this);
            };

            
            IteratorList   operator+ (int val)
            {
                IteratorList   tmp(*this);

                for (int i = 0; i < val; i++)
                {
                    tmp.set_pointer(tmp.get_pointer()->node_next());
                    if (tmp.get_pointer()->node_next() == nullptr)
                        break ;
                }
                return (tmp);
            };

            IteratorList   operator- (int val)
            {
                IteratorList   tmp(*this);

                for (int i = 0; i < val; i++)
                {
                    tmp.set_pointer(tmp.get_pointer()->node_previous());
                    if (tmp.get_pointer()->node_previous() == nullptr)
                        break ;
                }
                return (tmp);
            };

            IteratorList&   operator+= (int val)
            {
                for (int i = 0; i < val; i++)
                {
                    this->pointer = this->pointer->node_next();
                    if (this->pointer->node_next() == nullptr)
                        break ;
                }
                return (*this);
            };

            IteratorList&   operator-= (int val)
            {
                for (int i = 0; i < val; i++)
                {
                    this->pointer = this->pointer->node_previous();
                    if (this->pointer->node_previous() == nullptr)
                        break ;
                }
                return (*this);
            };

            bool operator== (const IteratorList & other) const
            {
                return (this->pointer == other.get_pointer());
            };

            bool operator!= (const IteratorList & other) const
            {
                return (this->pointer != other.get_pointer());
            };

            bool operator>= (const IteratorList & other) const
            {
                return (this->pointer >= other.get_pointer());
            };

            bool operator<= (const IteratorList & other) const
            {
                return (this->pointer <= other.get_pointer());
            };

            bool operator< (const IteratorList & other) const
            {
                return (this->pointer < other.get_pointer());
            };

            bool operator> (const IteratorList & other) const
            {
                return (this->pointer > other.get_pointer());
            };

    };
}

#endif
