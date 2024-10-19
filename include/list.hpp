#ifndef LIST_H
#define LIST_H

#include <cstddef>

template<typename Tp>
class list {
    private:
        class Node {
            private:
                Tp value;
                Node* next;
                Node* prev;
            public:
                Node(const Tp& v, Node* n = nullptr, Node* p = nullptr) {
                    this->value = v;
                    this->next = n;
                    this->prev = p;
                }
                friend class list;
        };
        template<typename Tp_i>
        class Iterator {
            private:
                Node* node;
            public:
                using pointer       = Tp_i*;
                using reference     = Tp_i&;
                
                Iterator(Node* n = nullptr) { this->node = n; }

                reference operator*() const { return this->node->value; }
                pointer operator->() { return &this->node->value; }

                Iterator& operator++() {
                    if (this->node) { this->node = this->node->next; }
                    return *this;
                }
                Iterator& operator--() {
                    if (this->node) { this->node = this->node->prev; }
                    return *this;
                }
                bool operator==(const Iterator& other) const { return (this->node == other.node); }
                bool operator!=(const Iterator& other) const { return (this->node != other.node); }
                friend class list<Tp_i>;
        };
        Node* first;
        Node* last;
        std::size_t size;
    public:
        using iterator  = Iterator<Tp>;
        using node      = Node*;

        list() {
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
        ~list() {
            while (this->first) {
                node tmp = this->first;
                this->first = this->first->next;
                delete tmp;
            }
        }
        void push_front(Tp pfv) {
            node n = new Node(pfv);
            if (this->empty()) { this->first = this->last = n; }
            else {
                this->first->prev = n;
                n->next = this->first;
                this->first = n;
            }
            ++this->size;
        }
        void push_back(Tp pbv) {
            node n = new Node(pbv);
            if (this->empty()) { this->first = this->last = n; }
            else {
                this->last->next = n;
                n->prev = this->last;
                this->last = n;
            }
            ++this->size;
        }
        void pop_front() { this->erase(iterator(this->first)); }
        void pop_back() { this->erase(iterator(this->last)); }
        void erase(iterator pos) {
            if (!this->empty()) {
                node nd = pos.node;
                if (this->first == this->last) { this->first = this->last = nullptr; }
                else {
                    if (nd->prev) { nd->prev->next = nd->next; }
                    else { this->first = nd->next; }

                    if (nd->next) { nd->next->prev = nd->prev; }
                    else { this->last = nd->prev; }
                }
                delete nd;
                --this->size;
            }
        }
        bool empty() { return (this->first == nullptr); }
        std::size_t getSize() { return this->size; }
        
        iterator begin() { return iterator(this->first); }
        iterator end() { return iterator(nullptr); }
};

#endif // !LIST_H
