#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
    template <typename It>
    class ReverseIterator: public It
    {
        public:

            using typename It::value_type;
            using typename It::node_type;
	        using typename It::node_pointer;
            using typename It::reference;
            using typename It::const_reference;



            ReverseIterator(): It() {};
            ReverseIterator(It const &other): It(other) {};
            ReverseIterator(ReverseIterator const &other): It(other.get_pointer()) {};


            reference operator* ()
            {
                It  tmp(*this);

                return (*--tmp);
            };

            const_reference operator* () const
            {
                It  tmp(*this);

                return (*--tmp);
            };

            ReverseIterator operator++(int)
            {
                ReverseIterator tmp(*this);

                operator++();
                return (tmp);
            }

            It &operator++()
            {
                return (this->It::operator--());
            }

            ReverseIterator operator--(int)
            {
                ReverseIterator tmp(*this);
            
                operator--();
                return (tmp);
            }

            It &operator--()
            {
                return (this->It::operator++());
            }

            ReverseIterator& operator= (const ReverseIterator & other)
            {
                this->pointer = other.get_pointer();
                return (*this);
            };
    };    
}

#endif
