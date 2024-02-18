#include <vector>

using namespace std;


class FenwickTree {

public:
  vector<int> tree;

  FenwickTree(int n)
  {
  	tree.resize(n);
  }


  void update(int i, int x) //h(x) = x | (x + 1) 
  {
	for (int j = i; j < tree.size(); j = (j | (j + 1))) {
	  tree[j] += x;
	}

  }

  void buildTree(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) 
	{
	  update(i, a[i]);
	}
  }

  int sum(int r) // [0;r] 
  {
	int result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) {
	  result += tree[r];
	}
	return result;
  }

  int sum(int l, int r) // [l;r] 
  {
	return sum(r) - sum(l - 1);
  }

};