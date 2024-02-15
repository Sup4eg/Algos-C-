#include <vector>

using namespace std;

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
	quick_sort(arr, 0, (int)arr.size());
  }

  static void merge_sort(vector<int>& arr)
  {
	if ((int)arr.size() <= 1)
	{
	  return;
	}
	vector<int> left, right;
	int n = (int)arr.size() / 2;
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