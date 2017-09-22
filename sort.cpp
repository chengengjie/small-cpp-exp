#include<algorithm>
#include<vector>
#include<cstdio>
#include<ctime>
#include<climits>

using namespace std;

#define ARRAY_SIZE 40000

//****************************************************************************

void InsertionSort(vector<int>& arr)
{
	for (unsigned int i = 1; i < arr.size(); ++i)
	{
		int temp = arr[i];
		unsigned int pos;
		for (pos = 0; pos < i; ++pos)
			if (!(arr[pos] < arr[i])) break;
		for (unsigned int j = i; j > pos; --j) arr[j] = arr[j - 1];
		arr[pos] = temp;
	}
}

//****************************************************************************

void Merge(vector<int>& arr, int p, int q, int r)
{// p <= q < r
	vector<int> L(q - p + 2), R(r - q + 1);
	for (unsigned int i = 0; i < L.size()-1; ++i) L[i] = arr[p + i];
	for (unsigned int j = 0; j < R.size()-1; ++j) R[j] = arr[q + 1 + j];
	*L.rbegin() = INT_MAX;
	*R.rbegin() = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; ++k)
		if (L[i] < R[j]) arr[k] = L[i++];
		else arr[k] = R[j++];
}

//****************************************************************************

void MergeSort(vector<int>& arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

void MergeSort(vector<int>& arr)
{
	MergeSort(arr, 0, arr.size() - 1);
}

//****************************************************************************

void MaxHeapify(vector<int>& arr, int heap_size, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2; // 2*i+2
	int largest;
	if (r<heap_size && arr[r] > arr[i]) largest = r;
	else largest = i;
	if (l<heap_size && arr[l] > arr[largest]) largest = l;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, heap_size, largest);
	}
}

void BuildMaxHeap(vector<int>& arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0; --i) MaxHeapify(arr, arr.size(), i);
}

void HeapSort(vector<int>& arr)
{
	BuildMaxHeap(arr);
	int heap_size = arr.size();
	for (int i = arr.size() - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		MaxHeapify(arr, --heap_size, 0);
	}
}

//****************************************************************************

// [l, r] -> [l, m-1], m, [m+1, r]
int Partition(vector<int>& arr, int l, int r)
{
	int pivot = arr[r], m = l - 1;
	for (int i = l; i < r; ++i)
		if (arr[i] <= pivot)
		{// for index <= m, arr[index] <= pivot; for index > m, arr[index] > m
			m++;
			swap(arr[m], arr[i]);
		}
	swap(arr[m + 1], arr[r]);
	return m + 1;
}

void QuickSort(vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int m = Partition(arr, l, r);
		QuickSort(arr, l, m - 1);
		QuickSort(arr, m + 1, r);
	}
}

void QuickSort(vector<int>& arr)
{
	QuickSort(arr, 0, arr.size() - 1);
}

//****************************************************************************

int main()
{
	srand(0);
	vector<int> a(ARRAY_SIZE), a_init(ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) a_init[i] = rand();
	//for (int i = 0; i < ARRAY_SIZE; i++) printf("%d\n", a[i]);

	a = a_init;
	clock_t start = clock();
	sort(a.begin(), a.end());
	printf("Runtime for std sort is \t %e s\n", double(clock() - start) / CLOCKS_PER_SEC);

	//a = a_init;
	//start = clock();
	//InsertionSort(a);
	//printf("Runtime for insertion sort is \t %e s\n", double(clock() - start) / CLOCKS_PER_SEC);

	a = a_init;
	start = clock();
	MergeSort(a);
	printf("Runtime for merge sort is \t %e s\n", double(clock() - start) / CLOCKS_PER_SEC);

	a = a_init;
	start = clock();
	HeapSort(a);
	printf("Runtime for heap sort is \t %e s\n", double(clock() - start) / CLOCKS_PER_SEC);

	a = a_init;
	start = clock();
	QuickSort(a);
	printf("Runtime for quicksort is \t %e s\n", double(clock() - start) / CLOCKS_PER_SEC);

	//for (int i = 0; i < ARRAY_SIZE; i++) printf("%d\n", a[i]);

	return 0;
}