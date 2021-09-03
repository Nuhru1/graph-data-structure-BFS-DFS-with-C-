#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList(){
        for(int i = 0; i < V; i++){
            cout<<i<<"-> " ;
            for(int x: l[i]){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }

    // BFS Traversal
    void BFS(int s){
        queue<int> q;
        list<int>::iterator i;

        bool *visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }

        q.push(s);
        // cout<<s<<", ";
        visited[s] = true;

        while(!q.empty()){
            s = q.front();
            cout<<s<<", ";
            q.pop();

            for(i = l[s].begin(); i != l[s].end(); ++i){
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }


    }

    // DFS Traversal 
    void DFS_helper(int start, vector<bool> visited){
        // if(visited[start]) return ;
        cout<<start<<"  ";
        visited[start] = true;

        for(list<int>::iterator it=l[start].begin(); it != l[start].end(); ++it){
            if(!visited[*it]){
                cout<<"going to vertex "<< *it<<" from vertex "<<start<<endl;
                DFS_helper(*it, visited);
            }
        }

    }
    void DFS(int start){
        vector<bool> visited(V, false);

        DFS_helper(start, visited);

    }


};


int main(){

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printAdjList();
    cout<<"=========BFS ======="<<endl;
    g.BFS(0);
    cout<<endl;
    cout<<"=========DFS========"<<endl;
    g.DFS(0);

    return 0;
}