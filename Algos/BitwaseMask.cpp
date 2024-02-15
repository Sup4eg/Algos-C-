#include <vector>
#include <iostream>

using namespace std;

class BitwiseMask11
{
public:
  void print(vector<int>& arr)
  {
	const int n = (int)arr.size();
	for (int mask = 0; mask < (1 << n); ++mask)
	{
	  bool first = true;
	  cout << "{";
	  for (int i = 0; i < n; ++i)
	  {
		if (mask & (1 << i))
		{
		  if (!first)
		  {
			cout << ", ";
		  }
		  first = false;
		  cout << arr[i];
		}
	  }
	  cout << "}";
	  cout << endl;
	}
  }
};