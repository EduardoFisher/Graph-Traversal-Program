#include "graph.h"
#include "queue.h"

Graph::Graph()
{
    this->adj_list = NULL;
    this->_size = 0;
}

//This function is to only be called once!
void Graph::insert()
{
    if(this->_size == 0)
    {
        this->_size++;
        this->adj_list = new node<int>*[this->_size];
    }
}

void Graph::insert(int a, int b)
{
    node<int>** _copy;
    this->_copyAdj_list(_copy);
    this->_delete_all();
    this->adj_list = new node<int>*[this->_size + 1];
    for(unsigned int i = 0; i < this->_size; i++)
    {
        if(_copy[i] != NULL)
            this->adj_list[i] = copy(_copy[i]);
    }

    this->_size++;

    //make A -> B
    _insert_head(this->adj_list[a], b);
    //make B -> A
    _insert_head(this->adj_list[b], a);

}

void Graph::add_edge(int a, int b)
{
    //make A -> B
    _insert_head(this->adj_list[a], b);
    //make B -> A
    _insert_head(this->adj_list[b], a);
}

void Graph::traversalD()
{
    this->visited = new bool[this->_size];
    for(unsigned int i = 0; i < this->_size; i++)
    {
        this->visited[i] = false;
    }
    for(unsigned int i = 0; i < this->_size; i++)
    {
        if(!this->visited[i])
        {
            this->dfs(i);
        }
    }
    delete this->visited;
}

void Graph::traversalB()
{
    this->visited = new bool[this->_size];
    for(unsigned int i = 0; i < this->_size; i++)
    {
        this->visited[i] = false;
    }
    for(unsigned int i = 0; i < this->_size; i++)
    {
        if(!this->visited[i])
            this->bfs(i);
    }
    delete this->visited;
}

void Graph::dfs(int i)
{
    this->visited[i] = true;
    cout << i << " ";
    for(node<int>* walker = this->adj_list[i]; walker != NULL; walker = walker->_next)
    {
        if(!this->visited[walker->_item])
            this->dfs(walker->_item);
    }
}

void Graph::bfs(int i)
{
    Queue<int> q;
    int number;
    this->visited[i] = true;
    q.push(i);
    while(!q.empty())
    {
        number = q.pop();
        cout << number << " ";
        for(node<int>* walker = this->adj_list[number]; walker != NULL; walker= walker->_next)
        {
            if(!this->visited[walker->_item])
            {
                visited[walker->_item] = true;
                q.push(walker->_item);
            }
        }
    }
}

void Graph::_delete_all()
{
    //delete this->visited;
    for(unsigned int i = 0; i < this->_size; i++)
    {
        delete adj_list[i];
    }
    delete adj_list;
    adj_list = NULL;
}

void Graph::_copyAdj_list(node<int>**& to)
{
    if(this->_size != 0)
    {
        to = new node<int>*[this->_size];
        for(unsigned int i = 0; i < this->_size; i++)
        {
            if(this->adj_list[i] != NULL)
                to[i] = copy(this->adj_list[i]);
        }
    }
}
