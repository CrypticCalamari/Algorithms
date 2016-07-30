#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <exception>
using std::exception;

class Heapsort {
	public:
		static void bubble_down	(int a[], int begin, int end);
		static void heapify_max	(int a[], int size);
		static void sort				(int a[], int size);
		static void verify			(int a[], int size);
};

void Heapsort::bubble_down(int a[], int begin, int end) {
	int root = begin;
	int child = root * 2 + 1;

	while (child <= end) {
		if ((child + 1 <= end) && (a[child] < a[child + 1]))
			child++;
		if (a[root] < a[child]) {
			int temp = a[root];
			a[root] = a[child];
			a[child] = temp;

			root = child;
			child = root * 2 + 1;
		} else {
			return;
		}
	}
}
void Heapsort::heapify_max(int a[], int size) {
	int end = size - 1;
	int begin = (end - 1) / 2;

	while (begin >= 0) {
		Heapsort::bubble_down(a, begin, end);
		begin--;
	}
}
void Heapsort::sort(int a[], int size) {
	int end = size - 1;
	Heapsort::heapify_max(a, size);

	while (end > 0) {
		int temp = a[0]; a[0] = a[end]; a[end] = temp;

		end--;
		Heapsort::bubble_down(a, 0, end);
	}
}
void Heapsort::verify(int a[], int size) {
	try {
		int prev = a[0];
		for (int i = 1; i < size; i++)
			if (prev > a[i])
				throw "Array not sorted properly.";
	} catch (exception& e) {
		cerr << "FAIL: " << e.what() << endl;
	}
}

int main(int argc, char* argv[]) {
	int size = 20;
	int test [size];

	srand(time(0));
	for (int i = 0; i < size; i++)
		test[i] = rand() % 101;

	for (int i = 0; i < size; i++)
		cout << test[i] << " ";
	cout << endl;

	Heapsort::sort(test, size);

	for (int i = 0; i < size; i++)
		cout << test[i] << " ";
	cout << endl;

	Heapsort::verify(test, size);

	return 0;
}








