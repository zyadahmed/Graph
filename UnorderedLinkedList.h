//
// Created by ziad on 8/8/23.
//

#ifndef GRAPH_UNORDEREDLINKEDLIST_H
#define GRAPH_UNORDEREDLINKEDLIST_H
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class UnorderedLinkedList {
private:
    Node* head;

public:
    UnorderedLinkedList() : head(nullptr) {}

    ~UnorderedLinkedList() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    Node* getHead(){
        return head;
    }
    bool isAdjacent(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }


    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool remove(int value) {
        if (isEmpty()) {
            return false;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};











#endif //GRAPH_UNORDEREDLINKEDLIST_H
