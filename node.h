#ifndef NODE
#define NODE

#include<iostream>

template<typename T>
struct node
{
public:
    friend std::ostream& operator <<(std::ostream& os, const node<T> print_me)
    {
        os << print_me._item;
        return os;
    }
    node();
    node(T item);
    T _item;
    node* _next;

};

template<typename T>
node<T>::node():_item(T()), _next(NULL)
{
    //nothing needs to be here.
}

template<typename T>
node<T>::node(T item):_item(item), _next(NULL)
{
    //nothing needs to be here.
}

#endif // NODE

