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

    PriorityQueue() : head(nullptr) {}
    ~PriorityQueue() {
        while (head != nullptr) {
            remove_min();
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
    }

    void decrease_priority(int vertex, int new_distance) {
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->vertex != vertex) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            add_with_priority(vertex, new_distance);
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;

        add_with_priority(vertex, new_distance);
    }

    
    int extract_min() {
        if(head == nullptr) {
            return -1;
        }
        int vertex = head->vertex;
        remove_min();
        return vertex;
    }
    void remove_min() {
        if (head == nullptr) {
            return;
        }
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
};

#endif