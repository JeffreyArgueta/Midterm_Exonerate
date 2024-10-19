#ifndef LIST_H
#define LIST_H

#include <cstddef>

template<typename T_list>
class list {
    private:
        template<typename T_node>
        class Node {
            private:
                T_node value;
                Node<T_node>* next;
                Node<T_node>* prev;
            public:
                Node(T_node& v, Node* n = NULL, Node* p = NULL) {
                    this->value = v;
                    this->next = n;
                    this->prev = p;
                }
                friend class list<T_node>;
        };
        template<typename T_it>
        class Iterator {
            private:
                Node<T_it>* node;
            public:
                using pointer       = T_it*;
                using reference     = T_it&;
                
                Iterator(Node<T_it>* n = NULL) { this->node = n; }

                reference operator*() const { return this->node->value; }
                pointer operator->() { return& this->node->value; }

                Iterator& operator++() {
                    if (this->node != NULL) { this->node = this->node->next; }
                    return* this;
                }
                Iterator& operator--() {
                    if (this->node != NULL) { this->node = this->node->prev; }
                    return* this;
                }
                bool operator==(const Iterator& other) const { return (this->node == other.node); }
                bool operator!=(const Iterator& other) const { return (this->node != other.node); }
                friend class list<T_it>;
        };
        Node<T_list>* first;
        Node<T_list>* last;
        std::size_t size;
    public:
        using iterator  = Iterator<T_list>;
        using node      = Node<T_list>*;

        list() {
            this->first = NULL;
            this->last = NULL;
            this->size = 0;
        }
        ~list() { this->clear(); }
        void push_front(T_list pfv) {
            node n = new Node<T_list>(pfv);
            if (!this->first) { this->first = this->last = n; }
            else {
                n->next = this->first;
                this->first->prev = n;
                this->first = n;    
            }
            this->size++;
        }
        void push_back(T_list pbv) {
            node n = new Node<T_list>(pbv);
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
