#include <vector>

using namespace std;

class SparceTable {

public:
  vector<int> a;
  vector<vector<int>> st;
  
  SparceTable(vector<int>& a) : a(a) {
	st.resize((int) a.size(), vector<int>((int) (log2((int) a.size()) + 1)));

	for (int i = 0; i < a.size(); ++i) {
	  st[i][0] = a[i]; //st[i][j] = [i, i + 2^j - 1]
	}

	for (int j = 1; j < st[0].size(); ++j) {
	  for (int i = 0; i + (1 << (j - 1)) < a.size(); ++i) {
		st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	  }
	}

	//st[i][j-1]                    //[i; i = 2^(j-1) - 1]
	//st[i + 2^(j-1)][j-1]          //[i + 2^(j-1); i + 2^j - 1]
  }

  int findMin(int l, int r) {
	int j = (int) log2(r - l + 1);
	return min(st[l][j], st[r - (1 << j) + 1][j]);
  }
};