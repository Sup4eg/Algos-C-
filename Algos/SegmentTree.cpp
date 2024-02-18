#include <vector>

using namespace std;

const int n = 8;
class SegmentTree {
	
public:
  vector<int> tree;

  void buildTree(const vector<int>& a, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
	  tree[v] = a[l];
	  return;
	}
	int m = (l + r) / 2;
	buildTree(a, v * 2, l, m);
	buildTree(a, v * 2 + 1, m + 1, r);
	//key point here
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
	//tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }

  int sum(int i, int j, int v = 1, int l = 0, int r = n - 1) {
	if (i > j) {
	  return 0;
	}
	if (i == l && j == r) {
	  return tree[v];
	}
	int m = (l + r) / 2;
	return sum(i, min(m, j), v * 2, l, m) + sum(max(m + 1, i), j, v * 2 + 1, m + 1, r);
  }

  int min_query(int i, int j, int v = 1, int l = 0, int r = n - 1) {
	if (i > j) {
	  return 10000000;
	}
	if (i == l && j == r) {
	  return tree[v];
	}
	int m = (l + r) / 2;
	return min(sum(i, min(m, j), v * 2, l, m), sum(max(m + 1, i), j, v * 2 + 1, m + 1, r));
  }

  void update(int i, int x, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
	  tree[v] = x;
	  return;
	}
	int m = (l + r) / 2;
	if (i <= m) {
	  update(i, x, v * 2, l, m);
	}
	else {
	  update(i, x, v * 2 + 1, m + 1, r);
	}
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
	//tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }


};