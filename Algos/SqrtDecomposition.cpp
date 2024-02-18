#include <vector>

using namespace std;

class SqrtDecomposition {

private:
  vector<int> a,b;
  int s;

public:
  
  SqrtDecomposition(vector<int>& a) : a(a) {
	s = (int) sqrt((int) a.size());
	++s;
	b.resize(s);
	for (int i = 0; i < a.size(); ++i) {
	  b[i / s] += a[i];
	}
  }

  int sum(int l, int r) {
	int sum = 0;
	for (int i = l; i <= r;) {
	  if (i % s == 0 && i + s - 1 <= r) {
		sum += b[i / s];
		i += s;
	  }
	  else {
		sum += a[i];
		++i;
	  }
	}
	return sum;
  }
};