#ifndef PRIORY_QUEUE_H
#define PRIORY_QUEUE_H
#include <iostream>

class Node{
    public:
    int vertex;
    int distance;
    Node* next;
    Node(int v, int d): vertex(v), distance(d) , next(nullptr) {}
};

class PriorityQueue {
    public:
    Node* head;
    int lenghth;

    PriorityQueue() : head(nullptr) ,lenghth(0) {}
    ~PriorityQueue() {
        while (head != nullptr) {
            decrease_priority();
        }
    }
    
    void add_with_priority(int vertex, int distance) {
        Node* newNode = new Node(vertex, distance);
        if(head == nullptr || head->distance > distance) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while(current->next != nullptr && current->next->distance <= distance) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        lenghth++;
    }

    void decrease_priority() {
        if(head == nullptr) {
            return;
        }
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        lenghth--;
    }
    
    int extract_min() {
        if(head == nullptr) {
            return -1;
        }
        int vertex = head->vertex;
        decrease_priority();
        return vertex;
    }
};

#endif