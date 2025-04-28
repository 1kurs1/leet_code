#pragma once

#include <cstddef>
#include <iostream>

class LinkedListNode{
public:
    LinkedListNode();
    LinkedListNode(int value) : m_value(value){}
    ~LinkedListNode();

    void push_back(int value);
    void remove_value(int value);
    void print();

    size_t m_size;
    int m_value;
    LinkedListNode* m_next;
};