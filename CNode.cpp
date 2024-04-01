#include "CNode.h"

CNode::CNode()
{
    CNode(0);
}

CNode::CNode(int data)
{
    m_data = data;
    m_nextNode = nullptr;
    m_prevNode = nullptr;
}

CNode::~CNode()
{
    if (m_nextNode != nullptr)
    {
        m_nextNode->setPrevNode(m_prevNode);
    }

    if (m_prevNode != nullptr)
    {
        m_prevNode->setNextNode(m_nextNode);
    }
}

int CNode::data()
{
    return m_data;
}

void CNode::setData(int data)
{
    m_data = data;
}

CNode *CNode::nextNode()
{
    return m_nextNode;
}

void CNode::setNextNode(CNode *node)
{
    m_nextNode = node;
}

CNode *CNode::prevNode()
{
    return m_prevNode;
}

void CNode::setPrevNode(CNode *node)
{
    m_prevNode = node;
}
