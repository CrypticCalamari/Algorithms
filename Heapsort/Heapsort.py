#!/usr/bin/python

import random

class Heapsort:
	"""Heapsort"""
	@staticmethod
	def bubble_down(a, begin, end):
		root = begin
		child = root * 2 + 1

		while (child <= end):
			if ((child + 1 <= end) and (a[child] < a[child + 1])):
				child += 1
			if (a[root] < a[child]):
				a[root], a[child] = a[child], a[root]
				root = child
				child = root * 2 + 1
			else:
				return
		
	@staticmethod
	def heapify_max(a):
		end = len(a) - 1
		begin = (end - 1) // 2

		while (begin >= 0):
			Heapsort.bubble_down(a, begin, end)
			begin -= 1

	@staticmethod
	def sort(a):
		end = len(a) - 1

		Heapsort.heapify_max(a)

		while (end > 0):
			a[0], a[end] = a[end], a[0]
			end -= 1
			Heapsort.bubble_down(a, 0, end)

	@staticmethod
	def verify(a):
		prev = a[0]
		for item in range(1, len(a)):
			if prev > a[i]:
				print "FAIL: Array not sorted properly"
		print "--SUCCESS: Sorted!--"

if __name__ == "__main__":
	test = []
	random.seed()
	for i in range(20):
		test.append(random.randint(0, 100))

	print test
	Heapsort.sort(test)
	print test
	Heapsort.verify(test)
