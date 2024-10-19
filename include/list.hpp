#ifndef LIST_H
#define LIST_H

#include <cstddef>

template<typename Tp>
class list {
    private:
        template<typename Tp>
        class Node {
            private:
                Tp value;
                Node<Tp>* next;
                Node<Tp>* prev;
            public:
                Node(Tp& v, Node* n = NULL, Node* p = NULL) {
                    this->value = v;
                    this->next = n;
                    this->prev = p;
                }
                friend class list;
        };
        template<typename Tp>
        class Iterator {
            private:
                Node<Tp>* node;
            public:
                using pointer       = Tp*;
                using reference     = Tp&;
                
                Iterator(Node<Tp>* n = NULL) { this->node = n; }

                reference operator*() const { return this->node->value; }
                pointer operator->() { return& this->node->value; }

                Iterator<Tp>& operator++() {
                    if (this->node != NULL) { this->node = this->node->next; }
                    return* this;
                }
                Iterator<Tp>& operator--() {
                    if (this->node != NULL) { this->node = this->node->prev; }
                    return* this;
                }
                bool operator==(const Iterator& other) const { return (this->node == other.node); }
                bool operator!=(const Iterator& other) const { return (this->node != other.node); }
                friend class list;
        };
        Node<Tp>* first;
        Node<Tp>* last;
        std::size_t size;
    public:
        using iterator  = Iterator<Tp>;
        using node      = Node<Tp>*;

        list() {
            this->first = NULL;
            this->last = NULL;
            this->size = 0;
        }
        ~list() { this->clear(); }
        void push_front(Tp pfv) {
            node n = new Node<Tp>(pfv);
            if (!this->first) { this->first = this->last = n; }
            else {
                n->next = this->first;
                this->first->prev = n;
                this->first = n;    
            }
            this->size++;
        }
        void push_back(Tp pbv) {
            node n = new Node<Tp>(pbv);
            if (!this->last) { this->first = this->last = n; }
            else {
                n->prev = this->last;
                this->last->next = n;
                this->last = n;
            }
            this->size++;
        }
        void pop_front() { this->erase(iterator(this->first)); }
        void pop_back() { this->erase(iterator(this->last)); }
        bool erase(iterator pos) {
            if (pos != this->end()) {
                node nd = pos.node;
                
                if (nd->prev) { nd->prev->next = nd->next; }
                else {
                    if (nd->next) { nd->next->prev = nd->prev; }
                    else {
                        this->first = nd->next;
                        this->last = nd->prev;
                    }
                }
                
                delete nd;
                this->size--;
                return true;
            }
            return false;
        }
        bool empty() { return (this->first == NULL); }
        void clear() { while (!empty()) { this->pop_front(); } }
        std::size_t getSize() { return this->size; }
        
        iterator begin() { return iterator(this->first); }
        iterator end() { return iterator(this->last->next); }

        node front() { return *(this->begin()); }
        node back() {
            iterator tmp = this->end();
            tmp--;
            return *tmp;
        }
};

#endif // !LIST_H
