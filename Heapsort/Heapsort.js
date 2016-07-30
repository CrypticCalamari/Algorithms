#!/usr/bin/node

class Heapsort {
	static heapsort (a) {
		let end = a.length - 1;

		Heapsort.heapify_max(a);
		
		while (end > 0) {
			[a[0], a[end]] = [a[end], a[0]];	// swap
			end--;
			Heapsort.bubble_down(a, 0, end);
		}
	}
	static heapify_max (a) {
		let end = a.length - 1;
		let begin = Math.floor((end-1)/2);

		while (begin >= 0) {
			Heapsort.bubble_down(a, begin, end)
			begin--;
		}
	}
	static bubble_down (a, begin, end) {
		let root = begin;
		let child = 2*root+1;
		let swap = root;

		while (child <= end) {
			if (a[swap] < a[child])
				swap = child;
			if ((child+1 <= end) && (a[swap] < a[child+1]))
				swap = child + 1;

			if (swap == root) {return;}
			
			[a[swap], a[root]] = [a[root], a[swap]];
			root = swap;
			child = 2*root+1;
		}
	}
	static verify_sort(a) {
		let prev = a[0];

		for (let i = 1; i < a.length; i++) {
			if (prev > a[i])
				throw "ERROR: Incorrect Sorting!";

			prev = a[i];
		}
	}
}





let test = [];

for (let i = 0; i < 40; i++) {
	test.push(Math.floor(Math.random()*100));
}

console.log(...test);
Heapsort.heapsort(test);
console.log("");
console.log(...test);
Heapsort.verify_sort(test);


