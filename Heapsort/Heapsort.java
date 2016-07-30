import java.util.Arrays;
import java.util.Random;

public class Heapsort {
	public static void main(String... args) {
		Random rand = new Random();
		int[] array = new int[20];
		for (int i = 0; i < 20; i++)
			array[i] = rand.nextInt(100);

		System.out.println(Arrays.toString(array));
		Heapsort.sort(array);
		System.out.println(Arrays.toString(array));
	}
	public static void bubbleDown(int[] array, int begin, int end) {
		int root = begin;
		int child = root * 2 + 1;
		int temp = array[root];

		while (child <= end) {
			if (child + 1 <= end && array[child] < array[child + 1])
				child = child + 1;

			if (array[root] < array[child]) {
				temp = array[root];
				array[root] = array[child];
				array[child] = temp;
				
				root = child;
				child = root * 2 + 1;
			} else {
				return;
			}
		}
	}
	public static void heapifyMax(int[] array) {
		int end = array.length - 1;
		int begin = (end - 1)/2;
System.out.println(begin);
		while (begin >= 0) {
			Heapsort.bubbleDown(array, begin, end);
			begin = begin - 1;
System.out.println(Arrays.toString(array));
		}
	}
	public static void sort(int[] array) {
		int end = array.length - 1;

		Heapsort.heapifyMax(array);
System.out.println(Arrays.toString(array));

		while (end > 0) {
			int temp =	 array[end];
			array[end] = array[0];
			array[0] = temp;
			
			end = end - 1;
			Heapsort.bubbleDown(array, 0, end);
		}
	}
	public static void verify(int[] array) {
		int prev = array[0];
		try {
			for (int i = 1; i < array.length; i++) {
				if (prev > array[i])
					throw new Exception("EXCEPTION: Array not sorted");
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
