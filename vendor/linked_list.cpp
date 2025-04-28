#include "linked_list.hpp"

LinkedListNode::LinkedListNode(){
    m_size = 0;
    m_value = 0;
    m_next = nullptr;
}

LinkedListNode::~LinkedListNode(){}

void LinkedListNode::print(){
    LinkedListNode* current = m_next;
    while(current != nullptr){
        std::cout << current->m_value << ' ';
        current = current->m_next;
    }

    std::cout << '\n';
}

void LinkedListNode::push_back(int value){
    LinkedListNode* current = this;
    while(current->m_next != nullptr) current = current->m_next;

    current->m_next = new LinkedListNode();
    current->m_next->m_value = value;
    current->m_next->m_next = nullptr;
    m_size++;
}

void LinkedListNode::remove_value(int value){
    LinkedListNode* current = this;
    while(current != nullptr){
        if(current->m_next->m_value == value){
            LinkedListNode* temp = current->m_next;
            current->m_next = current->m_next->m_next;
            delete temp;
            m_size--;
            return;
        }
        current = current->m_next;
    }
}