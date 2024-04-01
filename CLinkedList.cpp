#include <iostream>

#include "CLinkedList.h"

using namespace std;

CLinkedList::CLinkedList()
{
    m_headNode = nullptr;
    m_tailNode = nullptr;
}

CLinkedList::~CLinkedList()
{
    CNode *node = m_headNode;

    while (node != nullptr)
    {
        CNode *nextNode = node->nextNode();

        delete node;

        node = nextNode;
    }
}

bool CLinkedList::isEmpty()
{
    return (m_headNode == nullptr && m_tailNode == nullptr);
}

void CLinkedList::insertAfter(CNode *newNode, CNode *refNode)
{
    if (refNode == nullptr)
        return;

    CNode *nextNode = refNode->nextNode();

    refNode->setNextNode(newNode);
    newNode->setNextNode(nextNode);
    newNode->setPrevNode(refNode);

    if (nextNode != nullptr)
        nextNode->setPrevNode(newNode);

    if (refNode == m_tailNode)
        m_tailNode = newNode;
}

void CLinkedList::insertBefore(CNode *newNode, CNode *refNode)
{
    if (refNode == nullptr)
        return;

    CNode *prevNode = refNode->prevNode();

    refNode->setPrevNode(newNode);
    newNode->setNextNode(refNode);
    newNode->setPrevNode(prevNode);

    if (prevNode != nullptr)
        prevNode->setNextNode(newNode);

    if (refNode == m_headNode)
        m_headNode = newNode;
}

CNode *CLinkedList::insertAfter(int data, CNode *refNode)
{
    if (refNode == nullptr)
        return nullptr;

    CNode *newNode = new CNode(data);

    insertAfter(newNode, refNode);

    return newNode;
}

CNode *CLinkedList::insertBefore(int data, CNode *refNode)
{
    if (refNode == nullptr)
        return nullptr;

    CNode *newNode = new CNode(data);

    insertBefore(newNode, refNode);

    return newNode;
}

CNode *CLinkedList::append(int data)
{
    CNode *newNode = new CNode(data);

    if (isEmpty())
    {
        m_headNode = newNode;
        m_tailNode = newNode;
        return newNode;
    }

    insertAfter(newNode, m_tailNode);

    return newNode;
}

CNode *CLinkedList::prepend(int data)
{
    CNode *newNode = new CNode(data);

    if (isEmpty())
    {
        m_headNode = newNode;
        m_tailNode = newNode;
        return newNode;
    }

    insertBefore(newNode, m_headNode);

    return newNode;
}

CNode *CLinkedList::find(int data)
{
    CNode *node = m_headNode;

    while (node != nullptr)
    {
        if (node->data() == data)
            break;

        node = node->nextNode();
    }

    return node;
}

void CLinkedList::removeOne(CNode *node)
{
    if (node == nullptr)
        return;

    if (node == m_headNode && node == m_tailNode)
    {
        m_headNode = nullptr;
        m_tailNode = nullptr;
    }
    else if (node == m_headNode)
        m_headNode = node->nextNode();
    else if (node == m_tailNode)
        m_tailNode = node->prevNode();

    delete node;
}

void CLinkedList::removeOne(int data)
{
    removeOne(find(data));
}

void CLinkedList::removeFirst()
{
    removeOne(m_headNode);
}

void CLinkedList::removeLast()
{
    removeOne(m_tailNode);
}

void CLinkedList::display()
{
    CNode *node = m_headNode;

    while (node != nullptr)
    {
        cout << node->data() << " ";

        node = node->nextNode();
    }

    cout << endl;
}