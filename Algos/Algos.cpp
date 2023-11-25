#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class DataStructures1 {
public:
  bool isOpen(char ch) {
	return ch == '{' || ch == '(' || ch == '[';
  }

  bool isPair(char open, char close) {
	return open == '{' && close == '}'
	  || open == '(' && close == ')'
	  || open == '[' && close == ']';
  }

  bool isBalanced(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i) {
	  if (isOpen(s[i])) {
		st.push(s[i]);
	  }
	  else {
		if (!st.empty() && isPair(st.top(), s[i])) {
		  st.pop();
		}
		else {
		  return false;
		}
	  }
	}
	return st.empty();
  }
};

class BitwiseMask11
{
public:
	void print(vector<int> & arr)
	{
	  const int n = arr.size();
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


class Sortings
{
private:
	static vector<int> merge(vector<int>& left, vector<int>& right)
	{
		vector<int> merged;
		int left_index = 0, right_index = 0;
		while (left_index < left.size() && right_index < right.size())
		{
			if (left[left_index] <= right[right_index])
			{
				merged.push_back(left[left_index++]);
			}
			else
			{
				merged.push_back(right[right_index++]);
			}
		}
		while (left_index < left.size())
		{
			merged.push_back(left[left_index++]);
		}
		while (right_index < right.size())
		{
			merged.push_back(right[right_index++]);
		}
		return merged;
	}

	static int partition(vector<int>& arr, int i, int j)
	{
		int pivot = rand() % (j - i) + i;
		swap(arr[pivot], arr[i]);
		pivot = i;
		int s1_index = i;
		int s2_index = i;
		for (int k = i + 1; k < j; ++k)
		{
			if (arr[k] >= arr[pivot])
			{
				++s2_index;
			}
			else
			{
				++s1_index;
				swap(arr[s1_index], arr[k]);
				++s2_index;
			}
		}
		swap(arr[pivot], arr[s1_index]);
		pivot = s1_index;
		return pivot;
	}

	static void quick_sort(vector<int>& arr, int i, int j)
	{
		if (i == j)
		{
			return;
		}
		int pivot = partition(arr, i, j); //[i, pivot - 1] < pivot // [pivot + 1, j] >= pivot
		quick_sort(arr, i, pivot);
		quick_sort(arr, pivot + 1, j);
	}

public:
	static void radix_sort(vector<int>& arr) // O(d * n)
	{
		vector<vector<int>> buckets(10);
		int power_of_ten = 1;
		int d = 5;
		for (int pow = 0; pow <= d; ++pow)
		{
			for (auto elem : arr)
			{
				buckets[elem / power_of_ten % 10].push_back(elem);
			}
			arr.clear();
			for (int i = 0; i < buckets.size(); ++i)
			{
				for (int j = 0; j < buckets[i].size(); ++j) // O(n)
				{
					arr.push_back(buckets[i][j]);
				}
				buckets[i].clear();
			}
			power_of_ten *= 10;
		}
	}

	static void quick_sort(vector<int>& arr)
	{
		quick_sort(arr, 0, arr.size());
	}

	static void merge_sort(vector<int>& arr)
	{
		if (arr.size() <= 1)
		{
			return;
		}
		vector<int> left, right;
		int n = arr.size() / 2;
		for (int i = 0; i < n; ++i)
			left.push_back(arr[i]);
		for (int i = n; i < arr.size(); ++i)
			right.push_back(arr[i]);

		merge_sort(left);
		merge_sort(right);

		arr = merge(left, right);
	}

	static void counting_sort(vector<int>& arr)
	{
		int minimum = arr[0];
		int maximum = arr[0];
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] > maximum)
			{
				maximum = arr[i];
			}
			if (arr[i] < minimum)
			{
				minimum = arr[i];
			}
		}
		vector<int> bucket(maximum - minimum + 1);
		for (int i = 0; i < arr.size(); ++i)
		{
			bucket[arr[i] - minimum]++;
		}
		arr.clear();
		for (int i = 0; i < bucket.size(); ++i)
		{
			int count = bucket[i]; // i + minimum
			for (int j = 0; j < count; ++j)
			{
				arr.push_back(i + minimum);
			}
		}
	}

	static void insertion_sort(vector<int>& arr)
	{
		for (int i = 1; i < arr.size(); ++i)
		{
			int cur = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > cur)
			{
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = cur;
		}
	}

	static void bubble_sort(vector<int>& arr)
	{
		bool is_sorted = true;
		for (int j = 0; j < arr.size(); ++j)
		{
			for (int i = 1; i < arr.size() - j; ++i)
			{
				if (arr[i] < arr[i - 1])
				{
					is_sorted = false;
					swap(arr[i], arr[i - 1]);
				}
			}
			if (is_sorted)
			{
				return;
			}
		}
	}

	static void selection_sort(vector<int>& arr)
	{
		for (int j = 0; j < arr.size(); ++j)
		{
			int min_ind = j;
			for (int i = j + 1; i < arr.size(); ++i)
			{
				if (arr[min_ind] > arr[i])
				{
					min_ind = i;
				}
			}
			swap(arr[j], arr[min_ind]);
		}
	}
};

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
		int l = 0, r = arr.size() - 1;
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
		int n = A.size();
		int m = A[0].size();
		int k = B[0].size();
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

class Hashing
{
public:
	static long long string_hashing(const string& s) // O(n)
	{
		const int p = 31;
		const int m = 1e9 + 7;
		long long hash = 0;
		long long prime_pow = 1;
		for (char ch : s)
		{
			hash = (hash + (ch - 'a' + 1) * prime_pow) % m;
			prime_pow = (prime_pow * p) % m;
			cout << prime_pow << endl;
		}
		return hash;
	}
};

class BackTracking
{
public:
	static int queens(int row,
	                  std::vector<int>& col,
	                  std::vector<int>& diag1,
	                  std::vector<int>& diag2) //8, 8x8 => n, nxn
	{
		// O(n!) --> 14
		// NP = Non - Polinomial
		// для задачи нет решения, которое бы составляло полиминиальное времяы
		const int n = col.size();
		if (row == n)
		{
			return 1;
		}
		int count = 0;
		for (int column = 0; column < n; ++column)
		{
			if (col[column] == 0 && diag1[column + row] == 0 && diag2[row - column + (n - 1)] == 0)
			{
				col[column] = diag1[column + row] = diag2[row - column + (n - 1)] = 1;
				count += queens(row + 1, col, diag1, diag2);
				col[column] = diag1[column + row] = diag2[row - column + (n - 1)] = 0;
			}
		}
		return count;
	}

	/*
	 * 00000000
	 * 00000000
	 * 00000000
	 * 00000000
	 * 00000000
	 * 00000000
	 * 00000000
	 * 00000000
	 */
};

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

class Graphs
{
};

int main()
{
	// List of edges
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[i] = {a, b};
	}

	for (int i = 0; i < m; ++i)
	{
		std::cout << edges[i].first << " " << edges[i].second << std::endl;
	}


	//Adjacency matrix
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		// 1 <= a, b <= a;
		--a;
		--b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

	//
}
