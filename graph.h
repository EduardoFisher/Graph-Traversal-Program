#ifndef GRAPH_H
#define GRAPH_H

#include "link_list_functions.h"

class Graph
{
public:
    Graph();
    void insert();
    void insert(int a, int b);
    void add_edge(int a, int b);
    void traversalD();
    void traversalB();

    friend ostream& operator <<(ostream& os, const Graph& g)
    {
        for(unsigned int i = 0; i < g._size; i++)
        {
            cout << "[" << i << "]" << "->";
            _print(os, g.adj_list[i]);
            cout << endl;
        }
        return os;
    }

private:
    void _delete_all();
    void _copyAdj_list(node<int> **&to);
    void dfs(int i);
    void bfs(int i);
    node<int>** adj_list;
    bool* visited;
    unsigned int _size;
};

#endif // GRAPH_H
