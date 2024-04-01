#include "CLinkedList.h"

int main(int argc, char **argv)
{
    CLinkedList *list = new CLinkedList();

    CNode *node1 = list->append(1);
    CNode *node2 = list->append(2);
    CNode *node0 = list->prepend(0);
    CNode *node3 = list->append(3);
    list->display(); // Expect: 0 1 2 3

    CNode *newNode1 = list->insertAfter(11, node1);
    list->display(); // Expect: 0 1 11 2 3

    CNode *newNode2 = list->insertBefore(22, node3);
    list->display(); // Expect: 0 1 11 2 22 3

    list->removeOne(node2);
    list->display(); // Expect: 0 1 11 22 3

    list->removeOne(newNode2);
    list->display(); // Expect: 0 1 11 3

    list->append(4);
    list->prepend(-1);
    list->display(); // Expected: -1 0 1 11 3 4

    list->insertAfter(33, list->find(3));
    list->insertAfter(44, list->find(4));
    list->display(); // Expected: -1 0 1 11 3 33 4 44

    list->insertBefore(-2, list->find(-1));
    list->insertBefore(-11, list->find(0));
    list->display(); // Expected: -2 -1 -11 0 1 11 3 33 4 44

    list->removeOne(0);
    list->removeOne(1);
    list->display(); // Expected: -2 -1 -11 11 3 33 4 44

    list->removeFirst();
    list->removeLast();
    list->display(); // Expected: -1 -11 11 3 33 4

    list->removeOne(-1);
    list->removeOne(4);
    list->display(); // Expected: -11 11 3 33

    delete list;
}
