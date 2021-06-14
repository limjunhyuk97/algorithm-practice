#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* n, int* m) {
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

// 중복된 값에 대한 정렬까지 고려
void QuickSort(int arr[], int left, int right) {

	if (left >= right)
		return;

	int start = left + 1;
	int end = right;
	int pivot = left;

	while (start < end) {

		while (arr[pivot] >= arr[start] && (start < right))
			start++;

		while (arr[pivot] <= arr[end] && (end > left))
			--end;

		if (start < end)
			swap(&arr[start], &arr[end]);

	}

	swap(&arr[pivot], &arr[end]);

	QuickSort(arr, left, end - 1);
	QuickSort(arr, end + 1, right);

}

int main(void) {
	
	int arr[10];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		arr[i] = rand() % 10 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	QuickSort(arr, 0, 9);

	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	return 0;
}
