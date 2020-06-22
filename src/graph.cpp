#include "graph.hpp"
#include <iostream>
#include <stack>

Graph::Graph(string regex) {
  unsigned int i;
  for (i = 0; i < regex.length(); i++)
    graph.push_back(vector<int> (1, i));
  
  graph.push_back(vector<int> (1, i));

  vertices = regex.length();
  buildGraph(regex);
}

Graph::~Graph() {}

void Graph::buildGraph(string regex) {
  stack<int> stack; 
  
  for (unsigned int i = 0; i < regex.length(); i++) {
    int prev = i;
    if (regex[i] == '(' || regex[i] == '|')
      stack.push(i);
    else if (regex[i] == ')') {
      int top = stack.top();
      stack.pop();
      if (regex[top] == '|') {
        prev = stack.top();
        stack.pop();
        graph[prev].push_back(top + 1);
        graph[top].push_back(i);
      }
      else 
        prev = top;
    }

    if (i < regex.size() - 1 && regex[i+1] == '*') {
      graph[prev].push_back(i + 1);
      graph[i + 1].push_back(prev);

    }

    if (regex[i] == '*' || regex[i] == '(' || regex[i] == ')')
      graph[i].push_back(i + 1);

  }
}


void Graph::dfs(int v, vector<int> & visited) {
  visited[v] = 1;

  for (unsigned int i = 1; i < graph[v].size(); i++) {
    int k = graph[v][i];
    if (!visited[k])
      dfs(k, visited);
  }
}

int Graph::getVertices() {
  return vertices;
}
