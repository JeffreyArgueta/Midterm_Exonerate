#ifndef LIST_H
#define LIST_H

#include "Iterator.hpp"
#include "Node.hpp"

template<typename Tp>
class List {
    private:
        Node<Tp>* first;
        Node<Tp>* last;
        std::size_t length;
    public:
        using iterator  = Iterator<Tp>;
        using node      = Node<Tp>;

        List() {
            this->first = NULL;
            this->last = NULL;
            this->length = 0;
        }
        ~List() { this->clear(); }

        iterator begin() { return iterator(this->first); }
        iterator end() { return iterator(NULL); }
        bool empty() { return (this->length == 0); }
        std::size_t size() { return this->length; }
        void clear() {
            while (!this->empty()) {
                this->pop_front();
            }
        }
        node* front() { return this->begin().node; }
        node* back() { return --this->end().node; }
        void push_front(Tp x) { this->insert(this->begin(), x); }
        void pop_front() { this->erase(this->begin()); }
        void push_back(Tp x) { this->insert(this->end(), x); }
        void pop_back() { this->erase(this->end()); }
        void insert(iterator pos, Tp x) {
            node* newNode = new node(x);
            
            if (empty()) { this->first = this->last = newNode; }
            else {
                if (pos.node == this->first) {
                    newNode->next = this->first;
                    this->first->prev = newNode;
                    this->first = newNode;
                }
                else {
                    node* tmp = this->last;
                    this->last = newNode;
                    tmp->next = this->last;
                    this->last->prev = tmp;
                }
            }
            this->length++;
        }
        void erase(iterator pos) {
            node* tmp = pos.node;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            this->length--;
        }
};

#endif // !LIST_H
