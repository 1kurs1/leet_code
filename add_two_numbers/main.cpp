#include <iostream>

#include "linked_list.hpp"

LinkedListNode* addTwoNumbers(LinkedListNode* l1, LinkedListNode* l2){
    LinkedListNode* p = new LinkedListNode();
    LinkedListNode* temp = p;
    int sum = 0, balance = 0;

    while(l1 || l2 || balance){
        sum = balance;

        if(l1){
            sum += l1->m_value;
            l1 = l1->m_next;
        }
        if(l2){
            sum += l2->m_value;
            l2 = l2->m_next;
        }

        int tmp = sum%10;
        balance = sum/10;
        p->m_next = new LinkedListNode(tmp);
        p = p->m_next;
    }
  
    LinkedListNode* res = temp->m_next;

    delete temp;
    return res;
}

void freeList(LinkedListNode* head){
    LinkedListNode* next;
    while(head != nullptr){
        next = head->m_next;
        delete head;
        head = next;
    }
}

int main(){

    LinkedListNode* l1 = new LinkedListNode();
    LinkedListNode* l2 = new LinkedListNode();

    l1->push_back(2);
    l1->push_back(4);
    l1->push_back(3);

    l2->push_back(5);
    l2->push_back(6);
    l2->push_back(4);

    LinkedListNode* l3 = addTwoNumbers(l1, l2);

    l3->print();
   
   freeList(l1);
   freeList(l2);
   freeList(l3);

    return EXIT_SUCCESS;
}