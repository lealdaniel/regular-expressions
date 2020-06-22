#include "regex.hpp"

Regex::Regex(string regex) {
  this->regex = regex;
}

string Regex::getRegex() {
  return regex;
}

Regex::~Regex() {}

bool Regex::matchRegex(Graph * graph, string text) {
  vector<int> reachableVertex(graph->getVertices() + 1, 0);
  graph->dfs(0, reachableVertex);

  for (unsigned int i = 0; i < text.length(); i++) {
    vector<int> currentVertex(graph->getVertices() + 1, 0);
    for (unsigned int j = 0; j < graph->getVertices(); j++)
      if (reachableVertex[j] && regex[j] == text[i])
        currentVertex[j + 1] = 1;

    vector<int> marked(graph->getVertices() + 1, 0);
    fill(reachableVertex.begin(), reachableVertex.end(), 0);

    for (unsigned int j = 0; j < reachableVertex.size(); j++) {
      if (currentVertex[j]) {
        fill(marked.begin(), marked.end(), 0);

        graph->dfs(j, marked);
        for (unsigned int k = 0; k < reachableVertex.size(); k++)
          if (marked[k])
            reachableVertex[k] = true;
      }
    }
  }

  if (reachableVertex[graph->getVertices()])
    return true;
  
  return false;
}