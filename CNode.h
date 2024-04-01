#ifndef CNODE_H
#define CNODE_H

class CNode
{
private:
    int m_data;
    CNode *m_nextNode;
    CNode *m_prevNode;

public:
    CNode();
    CNode(int data);

    ~CNode();

    int data();
    void setData(int data);

    CNode *nextNode();
    void setNextNode(CNode *node);

    CNode *prevNode();
    void setPrevNode(CNode *node);
};

#endif // CNODE_H
