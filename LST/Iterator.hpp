#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.hpp"

template<typename Tp>
class Iterator {
    private:
       Node<Tp>* node; 
    public:
        using _Self         = Iterator;
        using pointer       = Tp*;
        using reference     = Tp&;

        Iterator(Node<Tp>* x = NULL) { this->node = x; }
        
        reference operator*() const { return this->node->data; }
        pointer operator->() const { return &this->node->data; }
        
        _Self& operator++() {
            if (this->node) { this->node = this->node->next; }
            return *this;
        }
        _Self operator++(int) {
            _Self it = *this;
            ++(*this);
            return it;
        }
        _Self& operator--() {
            if (this->node) { this->node = this->node->prev; }
            return *this;
        }
        
        bool operator==(const _Self& x) const { return (this->node == x.node); }
        bool operator!=(const _Self& x) const { return (this->node != x.node); }
        friend class List<Tp>;
};

#endif // !ITERATOR_H
