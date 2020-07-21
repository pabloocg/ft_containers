#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template <typename T>
    class Iterator
    {
        public:

            typedef T                   value_type;
            typedef value_type *        pointer;
            typedef value_type &        reference;
            typedef value_type const &  const_reference;

        protected:

            pointer __p;

        public:

            Iterator(void): __p(nullptr) {};
            Iterator(pointer point): __p(point) {};
            Iterator(Iterator const & other): __p(other.__p) {};
            virtual ~Iterator() {};

            Iterator& operator++ ()
            {
                ++this->__p;
                return (*this);
            };

            Iterator operator++ (int)
            {
                Iterator   tmp(*this);

                ++this->__p;
                return (tmp);
            };

            Iterator& operator-- ()
            {
                --this->__p;
                return (*this);
            };

            Iterator operator-- (int)
            {
                Iterator   tmp(*this);

                --this->__p;
                return (tmp);
            };

            reference operator* ()
            {
                return (this->__p->value);
            };

            const_reference operator* () const
            {
                return (this->__p->value);
            };

            reference operator-> ()
            {
                return (&this->__p->value);
            };

            const_reference operator-> () const
            {
                return (&this->__p->value);
            };

            reference operator[](int val)
            {
                return (*(this->__p + val));
            }

            const_reference operator[](int val) const
            {
                return (*(this->__p + val));
            }

            Iterator& operator= (const Iterator & other)
            {
                this->__p = other.__p;
                return (*this);
            };

            
            Iterator   operator+ (int val)
            {
                Iterator   tmp(*this);

                tmp.__p = tmp.__p + val;
                return (tmp);
            };

            Iterator   operator- (int val)
            {
                Iterator   tmp(*this);

                tmp.__p = tmp.__p - val;
                return (tmp);
            };

            Iterator&   operator+= (int val)
            {
                this->__p = this->__p + val;
                return (*this);
            };

            Iterator&   operator-= (int val)
            {
                this->__p = this->__p - val;
                return (*this);
            };

            bool operator== (const Iterator & other) const
            {
                return (this->__p == other.__p);
            };

            bool operator!= (const Iterator & other) const
            {
                return (this->__p != other.__p);
            };

            bool operator>= (const Iterator & other) const
            {
                return (this->__p >= other.__p);
            };

            bool operator<= (const Iterator & other) const
            {
                return (this->__p <= other.__p);
            };

            bool operator< (const Iterator & other) const
            {
                return (this->__p < other.__p);
            };

            bool operator> (const Iterator & other) const
            {
                return (this->__p > other.__p);
            };

    };

}

#endif
