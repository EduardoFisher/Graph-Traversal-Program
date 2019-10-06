#ifndef QUEUE
#define QUEUE

#include "node.h"
#include "link_list_functions.h"

template<typename T>
class Queue
{
public:
    Queue();
    //The Big 3!
    ~Queue();
    Queue(const Queue& other);
    Queue<T>& operator =(const Queue<T> &other);
    ostream& print(ostream& os);
    void push(T item);
    T pop();
    bool empty();
    T front()const;
    T back()const;
    template<typename O>
    friend ostream& operator <<(std::ostream& os, Queue<O> &print);
private:
    node<T>* headPtr;
    node<T>* footPtr;
};

template<typename T>
Queue<T>::Queue()
{
    headPtr = NULL;
    footPtr = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
    _clear_all(headPtr);

}

template<typename T>
Queue<T>::Queue(const Queue &other)
{
    footPtr = NULL;
    headPtr = NULL;
    headPtr = copy(other.headPtr, footPtr);
}

template<typename T>
T Queue<T>::pop()
{
    T number;
    node<T>* temp = headPtr;
    headPtr = headPtr->_next;
    number = _delete(temp, temp);
    return number;
}

template<typename T>
void Queue<T>::push(T item)
{
    if(headPtr == NULL)
    {
        headPtr = _insert_head(headPtr, item);
        footPtr = headPtr;
    }
    else
    {
        footPtr = _insert_after(footPtr, item);
    }
}

template<typename T>
bool Queue<T>::empty()
{
    if(headPtr == NULL)
    {
        return true;
    }
    return false;
}

template<typename T>
T Queue<T>::front() const
{
    return headPtr->_item;
}

template<typename T>
T Queue<T>::back() const
{
    return footPtr->_item;
}

template<typename T>
Queue<T>& Queue<T>::operator =(const Queue<T> &other)
{
    if(this != &other)
    {
        _clear_all(headPtr);
        headPtr = NULL;
        footPtr = NULL;
        headPtr = copy(other.headPtr, footPtr);
    }
    return *this;
}

template<typename T>
ostream& Queue<T>::print(ostream &os)
{

    return _print(os, headPtr);
}

template<typename O>
ostream& operator <<(std::ostream& os, Queue<O> &print_me)
{
    return print_me.print(os);
}

#endif // QUEUE

