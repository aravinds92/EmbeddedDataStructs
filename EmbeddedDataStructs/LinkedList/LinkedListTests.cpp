//
//  LinkedListTests.cpp
//  EmbeddedDataStructs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#include <iostream>
using namespace std;

#include "LinkedList.hpp"

void testLinkedList()
{
    LinkedList* list = new LinkedList(1);
    list->addNodeAtEnd(2);
    list->addNodeAtEnd(3);
    list->addNodeAtEnd(4);
    list->addNodeAtEnd(5);

    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";

    list->addNodeAtBeginning(0);
    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";

    list->addNodeAtIndex(1, 0);
    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";

    list->deleteFromBeginning();
    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";

    list->deleteFromEnd();
    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";

    list->deleteAtIndex(0);
    list->traverseList(true);
    cout<< "Number of elements in list: " << list->getNumberOfElementsInList() << "\n";



    cout<<list->isElementInList(1)<<"\n";
    cout<<list->isElementInList(2)<<"\n";
    cout<<list->isElementInList(3)<<"\n";
    cout<<list->isElementInList(4)<<"\n";
    cout<<list->isElementInList(5)<<"\n";
    
    
    delete list;

}

