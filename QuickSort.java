import java.util.Arrays;

public class QuickSort {
	public static void quickSort(int[] a, int low, int high) {
		if(low>=high)
			return;
		int pivot = a[high];
		int swapIndex = low;
		for(int i=low; i<high; i++) {
			if(a[i] < pivot) {
				swap(a, swapIndex, i);
				swapIndex++;
			}
		}
		swap(a, swapIndex, high);
		quickSort(a, low, swapIndex-1);
		quickSort(a, swapIndex+1, high);
	}

	public static void swap(int[] a, int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	public static void main(String[] args) {
		int[] array = {42,11,23,61,103,2,64};
		System.out.println("Original array: "+Arrays.toString(array));
		quickSort(array, 0, array.length -1);
		System.out.println("Sorted array  : "+Arrays.toString(array));
	}
}
