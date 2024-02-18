#include <iostream>
#include "Trie.cpp"

using namespace std;

int main()
{
  Trie trie;
  trie.add("he");
  trie.add("she");
  trie.add("his");
  //trie.add("hers");

  cout << trie.find("he");
  cout << trie.find("her");
  cout << trie.find("hers");

  cout << endl;
  cout << trie.erase("he");

  cout << endl;
  return 0;
}
