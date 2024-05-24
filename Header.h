//
//  Header.h
//  Unittest
//
//  Created by 문정환 on 5/24/24.
//

//#ifndef SORTEDTYPE_H
//#define SORTEDTYPE_H
//
//#include<iostream>
//using namespace std;
//
//
//template<class ItemType>
//struct NodeType
//{
//    ItemType value;
//    NodeType* next;
//};
//
//template <class ItemType>
//class SortedType
//{
//public:
//    SortedType();
//    ~SortedType();
//    bool isFull();
//    bool isEmpty();
//    int  size();
//    bool findItem(ItemType& item);
//    void insertItem(ItemType item);
//    void removeItem(ItemType item);
//
//    void clear();
//    ItemType getItem(int pos);
//    void printList();
//    
//private:
//    NodeType<ItemType>* listData;
//    int length;
//};
//
//
//
//
//
//template <class ItemType>
//SortedType<ItemType>::SortedType()
//{
//    length = 0;
//    listData = nullptr;
//}
//
//
//template <class ItemType>
//SortedType<ItemType>::~SortedType()
//{
//    
//
//    NodeType<ItemType>* tempPtr;
//    while (listData != nullptr) {
//        tempPtr = listData;
//        listData = listData->next;
//        delete tempPtr;
//    }
//    length = 0;
//    
//}
//
//
//template<class ItemType>
//bool SortedType<ItemType>::isFull()
//{
//    NodeType<ItemType>* tempPtr;
//    try
//    {
//        tempPtr = new NodeType<ItemType>;
//        delete tempPtr;
//        return false;
//    }
//    catch(std::bad_alloc exception)
//    {
//        return true;
//    }
//}
//
//template<class ItemType>
//bool SortedType<ItemType>::isEmpty()
//{
//    return (listData == nullptr);
//}
//
//
//template <class ItemType>
//int SortedType<ItemType>::size()
//{
//    return length;
//}
//
//
//template <class ItemType>
//bool SortedType<ItemType>::findItem(ItemType& item)
//{
//    NodeType<ItemType>* tempPtr;
//    tempPtr = listData;
//    
//    
//    while(tempPtr != nullptr){
//        if((tempPtr->value) == item ){
//            item = tempPtr -> value;
//            return true;
//        }
//        else{
//            tempPtr = tempPtr -> next;
//        }
//    }
//    return false;
//}
//
//
//template <class ItemType>
//void SortedType<ItemType>::insertItem(ItemType item)
//{
//    
//    
//    NodeType<ItemType>* newNode = new NodeType<ItemType>;
//    newNode->value = item;
//    
//    // 첫 번째 노드보다 작거나 리스트가 비어있는 경우
//    if (listData == nullptr || item < listData->value) {
//        newNode->next = listData;
//        listData = newNode;
//    } else {
//        NodeType<ItemType>* predLoc = listData;
//        NodeType<ItemType>* location = listData->next;
//        while (location != nullptr && item > location->value) {
//            predLoc = location;
//            location = location->next;
//        }
//        newNode->next = location;
//        predLoc->next = newNode;
//    }
//    length++;
//
//    
//    
//}
//
//
//template <class ItemType>
//void SortedType<ItemType>::removeItem(ItemType item)
//{
//    
//
//    if (listData == nullptr) return; // 리스트가 비어있는 경우
//    
//    if (listData->value == item) { // 첫 번째 노드가 삭제할 아이템인 경우
//        NodeType<ItemType>* tempPtr = listData;
//        listData = listData->next;
//        delete tempPtr;
//        length--;
//    } else {
//        NodeType<ItemType>* predLoc = listData;
//        NodeType<ItemType>* location = listData->next;
//        while (location != nullptr && location->value != item) {
//            predLoc = location;
//            location = location->next;
//        }
//        if (location != nullptr) {
//            predLoc->next = location->next;
//            delete location;
//            length--;
//        }
//    }
//    
//    
//}
//
//
//template <class ItemType>
//ItemType SortedType<ItemType>::getItem(int pos)
//{
//    
//    if (pos < 0 || pos >= length) return -1; // pos가 범위 밖인 경우
//    
//    NodeType<ItemType>* tempPtr = listData;
//    for (int i = 0; i < pos; i++) {
//        tempPtr = tempPtr->next;
//    }
//    return tempPtr->value;
//    
//}
//
//
//
//template <class ItemType>
//void SortedType<ItemType>::printList(){
//    NodeType<ItemType>* tempPtr = listData;
//    
//    std::cout << "[\t";
//    while (tempPtr != NULL)
//    {
//        std::cout << tempPtr->value << "\t";
//        tempPtr = tempPtr->next;
//    }
//    
//    std::cout << "]" << std::endl;
//    
//}
//
//#endif


#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
struct NodeType
{
    ItemType value;
    NodeType* next;
};

template <class ItemType>
class SortedType
{
public:
    SortedType();
    ~SortedType();
    bool isFull();
    bool isEmpty();
    int size();
    bool findItem(ItemType& item);
    void insertItem(ItemType item);
    void removeItem(ItemType item);
    void clear();
    ItemType getItem(int pos);
    void printList();

private:
    NodeType<ItemType>* listData;
    int length;
};

template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = nullptr;
}

template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    clear();
}

template<class ItemType>
bool SortedType<ItemType>::isFull()
{
    try
    {
        NodeType<ItemType>* tempPtr = new NodeType<ItemType>;
        delete tempPtr;
        return false;
    }
    catch (std::bad_alloc& exception)
    {
        return true;
    }
}

template<class ItemType>
bool SortedType<ItemType>::isEmpty()
{
    return (listData == nullptr);
}

template <class ItemType>
int SortedType<ItemType>::size()
{
    return length;
}

template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType& item)
{
    NodeType<ItemType>* tempPtr = listData;

    while (tempPtr != nullptr) {
        if (tempPtr->value == item) {
            item = tempPtr->value;
            return true;
        } else {
            tempPtr = tempPtr->next;
        }
    }
    return false;
}

template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType item)
{
    NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->value = item;

    if (listData == nullptr || item < listData->value) {
        newNode->next = listData;
        listData = newNode;
    } else {
        NodeType<ItemType>* predLoc = listData;
        NodeType<ItemType>* location = listData->next;
        while (location != nullptr && item > location->value) {
            predLoc = location;
            location = location->next;
        }
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType item)
{
    if (listData == nullptr) return;

    if (listData->value == item) {
        NodeType<ItemType>* tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
        length--;
    } else {
        NodeType<ItemType>* predLoc = listData;
        NodeType<ItemType>* location = listData->next;
        while (location != nullptr && location->value != item) {
            predLoc = location;
            location = location->next;
        }
        if (location != nullptr) {
            predLoc->next = location->next;
            delete location;
            length--;
        }
    }
}

template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos)
{
    if (pos < 0 || pos >= length) {
        throw out_of_range("Index out of range");
    }

    NodeType<ItemType>* tempPtr = listData;
    for (int i = 0; i < pos; i++) {
        tempPtr = tempPtr->next;
    }
    return tempPtr->value;
}

template <class ItemType>
void SortedType<ItemType>::clear()
{
    NodeType<ItemType>* tempPtr;
    while (listData != nullptr) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
void SortedType<ItemType>::printList()
{
    NodeType<ItemType>* tempPtr = listData;

    cout << "[\t";
    while (tempPtr != nullptr) {
        cout << tempPtr->value << "\t";
        tempPtr = tempPtr->next;
    }
    cout << "]" << endl;
}

#endif
