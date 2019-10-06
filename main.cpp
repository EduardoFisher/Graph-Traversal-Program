#include "graph.h"
#include "queue.h"

using namespace std;

void graph_test();
void QueueTest();

int main()
{

    graph_test();
    //QueueTest();
//    node<int>** adj_list;
//    adj_list = new node<int>*[2];


//    _insert_head(adj_list[0], 5);
//    _insert_head(adj_list[0], 6);
//    _insert_head(adj_list[0], 7);

//    _insert_head(adj_list[1], 8);
//    _insert_head(adj_list[1], 9);
//    _insert_head(adj_list[1], 10);

//    _print(cout, adj_list[0]);
//    cout << endl;
//    _print(cout, adj_list[1]);
//    cout << endl;

    return 0;
}

void QueueTest()
{
    Queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;


}

void graph_test()
{
    Graph g;
    g.insert();
    //cout << g << endl;
    g.insert(1, 0);
    g.insert(2, 1);
    g.insert(3, 1);
    g.insert(4, 0);
    g.add_edge(3, 2);
    g.add_edge(4, 1);
    g.add_edge(4, 3);
    cout << g << endl;


    cout << endl;

    cout << "DFS of this Graph: ";
    g.traversalD();
    cout << endl;

    cout << "BFS of this Graph: ";
    g.traversalB();
    cout << endl;

}
