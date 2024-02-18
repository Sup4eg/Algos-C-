#include <vector>
#include <string>

using namespace std;
class Trie {

  static const int ALPHABET_SIZE = 26;

  struct Node {
	vector<Node*> alphabet;
	bool isEndOfWord;
	Node() : alphabet(ALPHABET_SIZE, nullptr), isEndOfWord(false) {
	}
  };

  Node* root;
  
  void add(Node*& curr, const string& str, int ind) {
	if (curr == nullptr) {
	  curr = new Node();
	}

	if (str.size() == ind) {
	  curr->isEndOfWord = true;
	  return;
	}

	add(curr->alphabet[str[ind] - 'a'], str, ind + 1);
  }

  bool find(Node*& curr, const string& str, int ind) {
	if (curr == nullptr) {
	  return false;
	}

	if (str.size() == ind) {
	  return curr->isEndOfWord;
	}

	find(curr->alphabet[str[ind] - 'a'], str, ind + 1);
  }

  bool erase(Node*& curr, const string& str, int ind) {
	if (curr == nullptr) {
	  return false;
	}

	if (str.size() == ind) {
	  bool temp = curr->isEndOfWord;
	  curr->isEndOfWord = false;
	  return temp;
	}

	erase(curr->alphabet[str[ind] - 'a'], str, ind + 1);
  }

public:

  void add(const string& str) {
	add(root, str, 0);
  }

  bool find(const string& str) {
	return find(root, str, 0);
  }

  bool erase(const string& str) {
   return erase(root, str, 0);
  }

  Trie() : root(nullptr) {}
};