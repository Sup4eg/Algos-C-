#include <iostream>
#include <vector>


using namespace std;

class Heap {
public:

  static void add(vector<int>& heap, int x) {
	heap.push_back(x);
	int ind = (int) heap.size() - 1;
	while (ind != 1 && heap[ind] < heap[ind / 2]) {
	  swap(heap[ind], heap[ind / 2]);
	  ind /= 2;
	}
  }

  static void erase(vector<int>& heap) {
	swap(heap[1], heap[heap.size() - 1]);
	heap.pop_back();
	int ind = 1;
	while (ind * 2 < heap.size() && heap[ind] > heap[ind * 2] || ind * 2 + 1 < heap.size() && heap[ind] > heap[ind * 2 + 1]) {
	  if (ind * 2 + 1 >= heap.size() || heap[ind * 2] < heap[ind * 2 + 1]) {
		swap(heap[ind], heap[ind * 2]);
		ind *= 2;
	  }
	  else {
		swap(heap[ind], heap[ind * 2 + 1]);
		ind *= 2;
		++ind;
	  }
	
	}

  }

  static int top(const vector<int>& heap) {
	//O(1)
	return heap[1];
  }

  static int empty(vector<int>& heap) {
	return heap.size() == 1;
  }

  static void heapSort(vector<int>& arr) {
  	vector<int> heap(1);
	for (int i = 0; i < arr.size(); ++i) {
  	  add(heap, arr[i]);
  	}
	arr.clear();
	while (!empty(heap)) {
	  arr.push_back(top(heap));
	  erase(heap);
	}
  }

};