#ifndef NODE_H
#define NODE_H

#include <cstddef>

template<typename Tp>
class Iterator;
template<typename Tp>
class List;

template<typename Tp>
class Node {
    private:
        Tp data;
        Node<Tp>* next;
        Node<Tp>* prev;
    public:
        Node(Tp d, Node* n = NULL, Node* p = NULL) {
            this->data = d;
            this->next = n;
            this->prev = p;
        }
        friend class Iterator<Tp>;
        friend class List<Tp>;
};

#endif // !NODE_H
