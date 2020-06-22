#include <iostream>
#include <string>
#include "regex.hpp"
using namespace std;

/*
  Daniel Oliveira Sanches Leal
  11321180
*/

int main() {
  Regex * regex;
  Graph * graph;
  string exp, text;
  int input = 1;

  cout << "Digite a expressão regular: ";
  cin >> exp;
  regex = new Regex(exp);
  graph = new Graph(regex->getRegex());

  while (input) {
    cout << "Digite uma frase: ";
    cin >> text;
    if (regex->matchRegex(graph, text))
      cout << "A frase é reconhecida pela expressão regular\n";
    else
      cout << "A frase não é reconhecida pela expressão regular\n";
    
    cout << "0 - Sair | 1 - Continuar\n";
    cin >> input;
  }
  
  delete graph;
  delete regex;
  
  return 1;
}