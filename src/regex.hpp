#include "graph.hpp"
using namespace std;

class Regex {
  private:
    string regex;

  public:
    Regex(string regex);
    ~Regex();
    string getRegex();
    bool matchRegex(Graph * graph, string text);
};