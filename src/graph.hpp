#include <string>
#include <vector>
using namespace std;

class Graph {
  private:
    vector<vector<int>> graph;
    int vertices;
    void buildGraph(string regex);
  
  public:
    Graph(string regex);
    ~Graph();
    void dfs(int v, vector<int> & visited);
    int getVertices();
};