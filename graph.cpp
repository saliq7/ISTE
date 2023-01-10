#include<bits/stdc++.h>
using namespace std;

class node
{
    private:
    string label;
    bool visited;
    vector<node*> list;

    public: 
    string getLabel(){
        return this->label;
    }
    bool getVisited(){
        return visited;
    }
    vector<node*> getList(){
        return list;
    }
    void setLabel(string label){
        this->label=label;
    }
    void setVisited(bool visited){
        this->visited=visited;
    }
    void setEdge(node* label)
    {
        list.push_back(label);
    }
    void delEdge(node * name)
    {
        for(auto i=list.begin();i!=list.end();i++)
        {
            node * t= *i;
            if(t->getLabel()==name->label) list.erase(i);
            break;
        }
    }
};

class graph
{
    public:
    vector<node*> array;

    void addVertex(string label)
    {
        node* n= new node;
        n->setLabel(label);
        n->setVisited(false);
        array.push_back(n);
    }

    void delVertex(string name)
    {
        for(auto i=array.begin();i!=array.end();i++)
        {
            node * t= *i;
            if(t->getLabel()==name) array.erase(i);
            t->setLabel("-1");
            break;
        }
        return;
    }

    void addEdge(node *vertex,node*name)
    {
        vertex->setEdge(name);
    }

    void addEdge(string vertex,string name)
    {
        node * ver=NULL;
        node * nam=NULL;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]->getLabel()==vertex) ver=array[i];
            if(array[i]->getLabel()==name) nam=array[i];
        }
        addEdge(ver,nam);
    }
    
    void delEdge(node * vertex, node * name)
    {
        vertex->delEdge(name);
    }

    void delEdge(string vertex,string name)
    {
        node * ver=NULL;
        node * nam=NULL;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]->getLabel()==vertex) ver=array[i];
            if(array[i]->getLabel()==name) nam=array[i];
        }
        delEdge(ver,nam);
    }

    void printGraph()
    {
        cout<<"\nGraph is as under: "<<endl<<endl;
        for(int i=0;i<array.size();i++)
        {
            cout<<array[i]->getLabel()<<" : ";
            vector<node*> temp= array[i]->getList();
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]->getLabel()=="-1") continue;
                cout<<temp[i]->getLabel()<<" , ";
            }
            cout<<"END"<<endl;
        }
        cout<<endl;
    }

    //why dfs not working?
    /*void DFS(node * root)
    {
            cout<<root->getLabel()<<" ";
            root->setVisited(1);
            vector<node*> temp= root->getList();
            if(temp.size()==0) return ;
            for(int i=0;i<temp.size();i++)
            {
                DFS(temp[i]);
            }
    }

    void DFS()
    {
        cout<<"\nDFS of graph : "<<endl<<endl;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]->getVisited()==false) DFS(array[i]);
        }
    }*/
};

int main()
    {
    graph myGraph;

    //hard code creation
    myGraph.addVertex("A");myGraph.addVertex("B");myGraph.addVertex("C");myGraph.addVertex("D");myGraph.addVertex("E");myGraph.addVertex("F");myGraph.addVertex("G");myGraph.addVertex("H");myGraph.addVertex("I");myGraph.addVertex("J");
    myGraph.addEdge("A","B");myGraph.addEdge("A","C");myGraph.addEdge("A","D");myGraph.addEdge("A","E");myGraph.addEdge("A","F");
    myGraph.addEdge("B","C");myGraph.addEdge("B","D");myGraph.addEdge("B","G");myGraph.addEdge("B","H");
    myGraph.addEdge("C","E");
    myGraph.addEdge("D","A");myGraph.addEdge("D","F");
    myGraph.addEdge("E","F");myGraph.addEdge("E","I");
    myGraph.addEdge("F","B");myGraph.addEdge("F","J");

    myGraph.printGraph();
    return 0;
    }