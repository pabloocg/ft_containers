#ifndef ITERATORMAP_HPP
# define ITERATORMAP_HPP

namespace ft
{
    template <typename T>
    class IteratorMap
    {
        public:

            typedef T                   value_type;
            typedef value_type *        pointer;
            typedef value_type &        reference;
            typedef value_type const &  const_reference;

        protected:

            pointer __p;

        public:

            IteratorMap(void): __p(nullptr) {};
            IteratorMap(pointer point): __p(point) {};
            IteratorMap(IteratorMap const & other): __p(other.__p) {};
            virtual ~IteratorMap() {};

            IteratorMap& operator++ ()
            {
                ++this->__p;
                return (*this);
            };

            IteratorMap operator++ (int)
            {
                IteratorMap   tmp(*this);

                ++this->__p;
                return (tmp);
            };

            IteratorMap& operator-- ()
            {
                --this->__p;
                return (*this);
            };

            IteratorMap operator-- (int)
            {
                IteratorMap   tmp(*this);

                --this->__p;
                return (tmp);
            };

            reference operator* ()
            {
                return (*this->__p);
            };

            const_reference operator* () const
            {
                return (*this->__p);
            };

            reference operator-> ()
            {
                return (*&this->__p);
            };

            const_reference operator-> () const
            {
                return (*&this->__p);
            };

            reference operator[](int val)
            {
                return (*(this->__p + val));
            }

            const_reference operator[](int val) const
            {
                return (*(this->__p + val));
            }

            IteratorMap& operator= (const IteratorMap & other)
            {
                this->__p = other.__p;
                return (*this);
            };

            
            IteratorMap   operator+ (int val)
            {
                IteratorMap   tmp(*this);

                tmp.__p = tmp.__p + val;
                return (tmp);
            };

            IteratorMap   operator- (int val)
            {
                IteratorMap   tmp(*this);

                tmp.__p = tmp.__p - val;
                return (tmp);
            };

            IteratorMap&   operator+= (int val)
            {
                this->__p = this->__p + val;
                return (*this);
            };

            IteratorMap&   operator-= (int val)
            {
                this->__p = this->__p - val;
                return (*this);
            };

            bool operator== (const IteratorMap & other) const
            {
                return (this->__p == other.__p);
            };

            bool operator!= (const IteratorMap & other) const
            {
                return (this->__p != other.__p);
            };

            bool operator>= (const IteratorMap & other) const
            {
                return (this->__p >= other.__p);
            };

            bool operator<= (const IteratorMap & other) const
            {
                return (this->__p <= other.__p);
            };

            bool operator< (const IteratorMap & other) const
            {
                return (this->__p < other.__p);
            };

            bool operator> (const IteratorMap & other) const
            {
                return (this->__p > other.__p);
            };

    };

}

#endif
