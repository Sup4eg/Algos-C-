#include <vector>
#include <iostream>

using namespace std;

class DynamicProgramming
{
public:
  static void countStaircase()
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

  static void testSlidingWindowTechnique()
  {
	vector<int> arr{ 1, 7, 5, 3, 2, 3, 8, 9 };
	int k = 4;
	int sum = 0;
	for (int i = 0; i < k; ++i) { // O(k)
	  sum += arr[i];
	}
	cout << sum << " ";
	for (int i = 1; i <= arr.size() - k; ++i) { // O(n)
	  sum = sum - arr[i - 1] + arr[i + k - 1];
	  cout << sum << " ";
	}
  }
};