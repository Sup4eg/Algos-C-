#include <vector>
#include <iostream>

using namespace std;

class DynamicProgramming
{
public:
  static void count_staircase()
  {
	int n, k;
	cin >> n >> k;

	vector<int> L; //O(n)
	L.push_back(1);

	for (int i = 0; i <= n; ++i) //O(k * n)
	{
	  int temp = 0;
	  for (int j = 0; j < k; ++j)
	  {
		if (L.size() < 1 + j)
		{
		  break;
		}
		temp += L[L.size() - 1 - j];
	  }
	  L.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
	  cout << L[i] << " ";
	}
  }
};