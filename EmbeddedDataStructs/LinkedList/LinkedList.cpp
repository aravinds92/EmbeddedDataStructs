//
//  LinkedList.cpp
//  Embedded_data_structs
//
//  Created by Aravind Sridhar on 1/23/22.
//


#include <iostream>
using namespace std;

#include "LinkedList.hpp"
// Node definitions
int Node::getDataFromNode()
{
    return data;
}

Node* Node::getNextNode()
{
    return next;
}

void Node::createNextNode(int data)
{
    next = new Node(data);
}

void Node::setNextNode(Node* next)
{
    this->next = next;
}



//LinkedList definitions
Node* LinkedList::getNodeAtIndex(int index)
{
    if(index > (length - 1))
    {
        return NULL;
    }
    
    Node* node = head;
    for(int i = 0; i<index; i++)
    {
        if(node != NULL)
        {
            node = node->getNextNode();
        }
    }
    
    return node;
}



int LinkedList::getNumberOfElementsInList()
{
    return length;
}


Node* LinkedList::traverseList(bool print)
{
    Node* node = head;
    while(node != NULL)
    {
        if(print)
            cout<<"Data: "<<node->getDataFromNode() <<"\n";
        
        
        if(node->getNextNode() == NULL)
            break;
        
        else
            node = node->getNextNode();
        
    }
    
    return node;
}


void LinkedList::addNodeAtEnd(int data)
{
    Node* endNode = traverseList(false);
    endNode->createNextNode(data);
    length++;
}

void LinkedList::addNodeAtBeginning(int data)
{
    Node* newHead = new Node(data);
    newHead->setNextNode(head);
    head = newHead;
    length++;
}



void LinkedList::addNodeAtIndex(int data, int index)
{
    Node* insertAtIndex = getNodeAtIndex(index);
    
    if(insertAtIndex == NULL)
        return;
    
    Node* newNode = new Node(data);
    newNode->setNextNode(insertAtIndex->getNextNode());
    insertAtIndex->setNextNode(newNode);
    length++;
}




void LinkedList::deleteFromBeginning()
{
    Node* node = head->getNextNode();
    delete head;
    head = node;
    length--;
}

void LinkedList::deleteFromEnd()
{
    Node* previousNode = getNodeAtIndex(length-2);
    Node* nodeToBeDeleted = previousNode->getNextNode();
    
    delete nodeToBeDeleted;
    previousNode->setNextNode(NULL);
    length--;
}

void LinkedList::deleteAtIndex(int index)
{
    switch(index)
    {
        case 0:
            deleteFromBeginning();
            return;
        default:
            break;
    }
    
    
    Node* previousNode = getNodeAtIndex(index-1);
    Node* nodeToBeDeleted = previousNode->getNextNode();
    
    previousNode->setNextNode(nodeToBeDeleted->getNextNode());
    delete nodeToBeDeleted;
    length--;
    
}

bool LinkedList::isElementInList(int key)
{
    Node* node = head;
    while(node != NULL)
    {
        int data = node->getDataFromNode();
        
        if(data == key)
            return true;
        
        node = node->getNextNode();
    }
    
    return false;
}
