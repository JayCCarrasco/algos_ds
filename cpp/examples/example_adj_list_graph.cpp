#include "ds/adj_list_graph.hpp"
#include <iostream>

int main() {
    Adj_List_Graph g(5, false);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(3, 4);

    std::cout << "BFS desde 0: ";
    g.bfs(0);

    std::cout << "DFS desde 0: ";
    g.dfs(0);

    g.remove_edge(1, 2);

    std::cout << "BFS desde 0: ";
    g.bfs(0);

    std::cout << "DFS desde 0: ";
    g.dfs(0);
}
