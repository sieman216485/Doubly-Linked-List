#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include "CNode.h"

class CLinkedList
{
private:
    CNode *m_headNode;
    CNode *m_tailNode;

    void insertAfter(CNode *newNode, CNode *refNode);
    void insertBefore(CNode *newNode, CNode *refNode);

public:
    CLinkedList();
    ~CLinkedList();

    bool isEmpty();

    CNode *insertAfter(int data, CNode *refNode);
    CNode *insertBefore(int data, CNode *refNode);

    CNode *append(int data);
    CNode *prepend(int data);

    CNode *find(int data);

    void removeOne(CNode *node);
    void removeOne(int data);
    void removeFirst();
    void removeLast();

    void display();
};

#endif // CLINKEDLIST_H
