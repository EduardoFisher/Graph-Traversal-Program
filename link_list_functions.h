#ifndef LINK_LIST_FUNCTIONS
#define LINK_LIST_FUNCTIONS

#include "node.h"
#include <iostream>
#include <cassert>

using namespace std;

/// \abstract: NOTE: This is all within one header file because templating doesnt
/// work across multiple files.
template<typename T>
node<T>* _beginning(node<T>* &head_ptr);
template<typename T>
node<T>* _insert_head(node<T>* &head_ptr, T item);
template<typename T>
node<T>* _insert_after(node<T>* after, T item);
template<typename T>
node<T>* _insert_previous(node<T>* &head_ptr, node<T>* &previous, T item);
template<typename T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item);
template<typename T>
node<T>* _find_item(node<T>* head_ptr, T item);
template<typename T>
node<T>* _find_item_sorted(node<T>* head_ptr, T item);
template<typename T>
node<T>* _previous_node(node<T>* &head_ptr, node<T>* &node_ptr);
template<typename T>
node<T>* _remove_node(node<T>* &head_ptr, T item);
template<typename T>
node<T>* _where_this_goes(node<T>* &head_ptr, T item);
template<typename T>
T _delete(node<T>* &head_ptr, node<T>* delete_node);
template<typename T>
void _clear_all(node<T>* &headPtr);
template<typename T>
node<T>* copy(const node<T>* head_ptr);
template<typename T>
node<T>* copy(const node<T> *head_ptr, const node<T>* foot_ptr);
template<typename T>
ostream& _print(ostream& os, const node<T>* head_ptr);

template<typename T>
node<T>* _beginning(node<T>* &head_ptr)
{
    return head_ptr;
}

template<typename T>
node<T>* _insert_head(node<T>* &head_ptr, T item)
{
    //1. create new node:
    node<T>* temp = new node<T>(item);
    //2. temp's next poits to where head_ptr is pointing:
    temp->_next = head_ptr;
    //3. Point head_ptr to where temp is pointing:
    head_ptr = temp;
    return temp; //or head_ptr;
}

template<typename T>
node<T>* copy(const node<T> *head_ptr)
{
    node<T>* newHeadPtr = NULL;
    _insert_head(newHeadPtr, head_ptr->_item);

    node<T>* curr = newHeadPtr;
    head_ptr = head_ptr->_next;
    while(head_ptr != NULL)
    {
        curr = _insert_after(curr, head_ptr->_item);
        head_ptr = head_ptr->_next;
    }
    return newHeadPtr;
}

template<typename T>
node<T>* copy(const node<T> *head_ptr, node<T> *foot_ptr)//used for Queue
{
    node<T>* newHeadPtr = NULL;
    const node<T>* curr = head_ptr;
    if(curr != NULL)
    {
        newHeadPtr = _insert_head(newHeadPtr, curr->_item);
        foot_ptr = newHeadPtr;
        curr = curr->_next;
    }

    while(curr != NULL)
    {
        foot_ptr = _insert_after(foot_ptr, curr->_item);

        curr = curr->_next;
    }

    return newHeadPtr;
}

template<typename T>
node<T>* _find_item(node<T> *head_ptr, T item)
{
    node<T>* curr = head_ptr;
    //Trasversing the list to find the node.
    while(curr != NULL)
    {
        if(curr->_item == item)
        {
            break;
        }
        else
        {
            curr = curr->_next;
        }
    }
    return curr;
}

template<typename T>
node<T>* _previous_node(node<T> *&head_ptr, node<T> *&node_ptr)
{
    node<T>* curr = head_ptr;
    node<T>* trail = NULL;
    //Trasverse the list to find the node.
    while(curr != NULL)
    {
        if(curr == node_ptr)
        {
            break;
        }
        else
        {
            trail = curr;
            curr = curr->_next;
        }
    }
    assert(curr != NULL);
    return trail;
}

//Removes a certain Node from the linked list.
//Takes a head pointer of the start of the lisk
template<typename T>
node<T>* _remove_node(node<T> *&head_ptr, T item)
{
    node<T>* curr = NULL;
    node<T>* trail = NULL;
    if(_find_item(head_ptr, item))
    {
        curr = _find_item(head_ptr, item);
        trail = _previous_node(head_ptr, curr);
        //Case 1: If removing head.
        if(head_ptr == curr)
        {
            head_ptr = head_ptr ->_next;
        }
        //Case 2: Removing from later list.
        else
        {
            trail = _previous_node(head_ptr, curr);
            trail->_next = curr->_next;
        }
    }
    return curr;
}

template<typename T>
T _delete(node<T> *&headPtr, node<T> *delete_node)
{
    node<T>* _toBeDeleted = _remove_node(headPtr, delete_node->_item);
    if(_toBeDeleted == NULL)
    {
        assert(_toBeDeleted = NULL);
    }
    T item = _toBeDeleted->_item;
    delete _toBeDeleted;
    return item;
}

//goes through and clear the whole linked list.
//Takes the head pointer of the head of the linked list.
template<typename T>
void _clear_all(node<T> *&headPtr)
{
    node<T>* curr = headPtr;
    node<T>* hold = NULL;
    while(curr != NULL)
    {
        hold = curr;
        curr = curr->_next;
        _delete(headPtr, hold);
    }
    headPtr = NULL;
}

//Creates and inserts a new node after a specific node is on the list.
//Take the node of where you want to insert after and the item.
template<typename T>
node<T>* _insert_after(node<T> *after, T item)
{
    node<T>* temp = NULL;
    //Checking to see if the pointer we are inserting is NULL.
    if(after == NULL)
    {
        assert(after != NULL);
    }
    else
    {
        //1. create new node:
        temp = new node<T>(item);
        //2. temp's next poits to where after is pointing:
        temp->_next = after->_next;
        //3. Point after to where temp is pointing:
        after->_next = temp;
    }
    return temp;
}

//Only works if the list that we are working with is sorted.
//Creates or adds a new node on a sorted list.
//Takes a head pointer and a T item.
template<typename T>
node<T>* _insert_sorted(node<T> *&head_ptr, T item)
{
    node<T>* temp = _where_this_goes(head_ptr, item);
    node<T>* new_node = NULL;
    //Checking to see if the node should be placed at the start of the list.
    if(temp == NULL)
    {
        new_node = _insert_head(head_ptr, item);
    }
    else
    {
        new_node = _insert_after(temp, item);
    }
    return new_node;
}

//Works with the insert sorted function.
//Finds the node where we should insert a new node to(SORTED LIST ONLY).
//Takes a head pointer and a T item.
template<typename T>
node<T>* _where_this_goes(node<T> *&head_ptr, T item)
{
    if(head_ptr == NULL)
    {
        return NULL;
    }
    node<T>* trail = head_ptr;
    node<T>* curr = head_ptr->_next;
    //Checks if we need to insert at the head of the list.
    if(item <= trail->_item)
    {
        return NULL;
    }
    //If not at the head of the list.
    while(curr != NULL)
    {
        if(item >= trail->_item)
        {
            if(item <= curr->_item)
                return trail;
        }
        trail = curr;
        curr = curr->_next;
    }
    if(curr == NULL)
    {
        return trail;
    }
    return curr;
}

//Creates a and inserts a new node previous
template<typename T>
node<T>* _insert_previous(node<T> *&head_ptr, node<T> *&previous, T item)
{
    node<T>* temp = NULL;
    node<T>* trail = NULL;
    if(previous == NULL)
    {
        assert(previous != NULL);
    }
    else
    {
        trail = _previous_node(head_ptr, previous);
        _insert_after(trail, item);
    }
    return temp;
}

template<typename T>
ostream& _print(ostream& os, const node<T>* head_ptr){
    const node<T>* curr = head_ptr;
    os << "Start->";
    while (curr != NULL)
    {
        os << "[" << curr->_item << "] ";
        curr = curr->_next;
    }
    os << "End of List";
    return os;
}

#endif // LINK_LIST_FUNCTIONS

