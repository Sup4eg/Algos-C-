#include <vector>

using namespace std;

class Mathematics
{
public:
  static int bin_pow(int a, int n)
  {
	if (n == 0)
	{
	  return 1;
	}
	if (n & 1)
	{
	  return bin_pow(a, n - 1) * a;
	}
	const int b = bin_pow(a, n / 2);
	return b * b;
  }

  static int bin_pow2(int a, int n)
  {
	int result = 1;
	while (n != 0)
	{
	  if (n & 1)
	  {
		result *= a;
	  }
	  n >>= 1;
	  a *= a;
	  // a, a^2, a^4, a^8
	}
	return result;
  }

  static bool binary_search(const vector<int>& arr, int x)
  {
	int l = 0, r = (int)arr.size() - 1;
	while (l <= r)
	{
	  int m = (l + r) / 2;
	  if (arr[m] == x)
	  {
		return true;
	  }
	  if (arr[m] < x)
	  {
		l = m + 1;
	  }
	  else if (arr[m] > x)
	  {
		r = m - 1;
	  }
	}
	return false;
  }

  static int gcd(int a, int b)
  {
	return b ? gcd(b, a % b) : a;
  }

  static int lcm(int a, int b)
  {
	return a / gcd(a, b) * b;
  }

  static vector<int> sieve(int n)
  {
	vector<bool> mark(n, true);
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i * i <= n; i += 2)
	{
	  if (mark[i])
	  {
		for (int j = i * i; j < n; j += i)
		{
		  mark[j] = false;
		}
	  }
	}
	for (int i = 3; i < n; i += 2)
	{
	  if (mark[i])
	  {
		primes.push_back(i);
	  }
	}
	return primes;
  }

  static vector<vector<int>> matrix_mul(const vector<vector<int>>& A, const vector<vector<int>>& B)
  {
	int n = (int)A.size();
	int m = (int)A[0].size();
	int k = (int)B[0].size();
	vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
	for (int i = 0; i < n; ++i)
	{
	  for (int j = 0; j < k; ++j)
	  {
		for (int k = 0; k < m; ++k)
		{
		  C[i][j] += A[i][k] * B[k][j];
		}
	  }
	}
	return C;
  }

  static int euler(int n)
  {
	int count = 0;
	for (int i = 1; i < n; ++i)
	{
	  if (gcd(i, n) == 1)
	  {
		count++;
	  }
	}
	return count;
  }

  static int euler_fast(int n)
  {
	int result = n;
	int prime = 2;
	while (n >= prime * prime)
	{
	  if (n % prime == 0)
	  {
		result = result / prime * (prime - 1);
		while (n % prime == 0)
		{
		  n /= prime;
		}
	  }
	  ++prime;
	}
	if (n != 1)
	{
	  result = result / n * (n - 1);
	}
	return result;
  }
};