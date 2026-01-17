#include "ds/adj_list_graph.hpp"
#include "ds/queue.hpp"
#include <iostream>
#include <algorithm>

//Constructor
Adj_List_Graph::Adj_List_Graph(size_t n, bool directed) :
                    adj(n), directed_(directed){
    std::cout<<"Adjacency list created" << '\n';
}

//Modification methods
void Adj_List_Graph::add_edge(int u, int v){
    adj[u].push_back(v);
    if (!directed_) {
        adj[v].push_back(u);
    }
}

void Adj_List_Graph::remove_edge(int u, int v){
    auto it = std::find(adj[u].begin(), adj[u].end(), v);
    if(it != adj[u].end()){
        adj[u].erase(it);
    }

    if(!directed_){
        it = std::find(adj[v].begin(), adj[v].end(), u);
        if(it != adj[v].end()){
            adj[v].erase(it);
        }
    }
}

//Verification methods
std::size_t Adj_List_Graph::num_vertices(){
    return adj.size();
}


//Search methods
void Adj_List_Graph::bfs(int start){
    std::vector<bool> visited(adj.size(), false);
    Queue<int> q(adj.size());

    visited[start] = true;
    q.push(start);

    while(!q.isEmpty()){
        int current = q.front();
        std::cout<<current<<" ";
        q.pop();

        for(int x : adj[current]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void Adj_List_Graph::dfs(int start){
    std::vector<bool> visited(adj.size(), false);
    visited[start] = true;
    dfs_util(visited, start);
}

void Adj_List_Graph::dfs_util(std::vector<bool>& visited, int start){
    std::cout<<start<<" ";
    
    for(int x : adj[start]){
        if(!visited[x]){
            visited[x] = true;
            dfs_util(visited, x);
        }
    }
}
