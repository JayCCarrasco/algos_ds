#pragma once

#include<cstddef>
#include<vector>

class Adj_List_Graph{
public:
    //Constructor
    Adj_List_Graph(std::size_t n, bool directed);

    //Modification methods
    void add_edge(int u, int v);
    //void remove_edge(int u, int v);
    //bool has_edge(int u, int v);

    //Verification methods
    std::size_t num_vertices();
    //int num_edges();
    //bool is_directed();

    //Search methods
    void bfs(int start);
    void dfs(int start);

    
private:
    std::vector<std::vector<int>> adj;
    bool directed_;
    void dfs_util(std::vector<bool>& visited, int start);


};