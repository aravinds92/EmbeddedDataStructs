//
//  LinkedList.hpp
//  Embedded_data_structs
//
//  Created by Aravind Sridhar on 1/23/22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
/*
class LinkedList {
    LinkedList* getNodeForData(int data);
    LinkedList* getPreviousNodeForData(int data);
    bool addNodeAfter(int data, int after);
    bool deleteNode(int data);
};
*/

class Node{
private:
    int data;
    Node* next;
    
public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
    ~Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    
    int getDataFromNode();
    Node* getNextNode();
    void createNextNode(int data);
    void setNextNode(Node* next);
};


class LinkedList {

private:
    Node* head;     //The pointer to the head node of the list
    int length;     //Number of nodes in the list
    Node* getNodeAtIndex(int index);

public:
    //general
    int getNumberOfElementsInList();
    Node* traverseList(bool print);
    
    
    //Addition operations
    void addNodeAtEnd(int data);
    void addNodeAtBeginning(int data);
    void addNodeAtIndex(int data, int index);
    
    //Deletion
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAtIndex(int index);
    
    //Search
    bool isElementInList(int key);
    
    LinkedList(int data)
    {
        head = new Node(data);
        length = 1;
    }
    
};


#endif /* LinkedList_hpp */
