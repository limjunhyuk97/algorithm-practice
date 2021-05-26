#include <stdio.h>

void swap(int* n, int* m) {
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

// 앞의 공간부터 오름차순에 맞는 수를 끼워 넣는다.
void AscendingSelectionSort1(int arr[], int n) {
	
	// 0 ~ n-2 까지 끼워넣기를 반복한다. 
	for (int i = 0; i < n - 1; ++i) {
		int maxIdx = i;
		// i+1 ~ n-1 까지 비교를 반복한다.
		for (int j = i + 1; j < n; ++j) {
			// 제일 작은 값을 갖는 index를 찾아라
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		swap(&arr[i], &arr[maxIdx]);
	}
}

// 앞의 공간부터 내림차순에 맞는 수를 끼워 넣는다.
void DescendingSelectionSort1(int arr[], int n) {
	
	// 0 ~ n-2 까지 끼워넣기를 반복한다.
	for (int i = 0; i < n - 1; ++i) {
		int maxIdx = i;
		// i+1 ~ n-1 까지 비교를 반복한다.
		for (int j = i + 1; j < n; ++j) {
			// 제일 큰 값을 갖는 index를 찾아라
			if (arr[maxIdx] < arr[j])
				maxIdx = j;
		}
		swap(&arr[i], &arr[maxIdx]);
	}
}

// 뒤의 공간부터 내림차순에 맞는 수를 끼워 넣는다.
void AscendingSelectionSort2(int arr[], int n) {

	// n-1 ~ 1 까지 끼워넣기를 반복한다.
	for (int i = n - 1; i > 0; --i) {
		int maxIdx = i;
		// 0 ~ i-1 까지 비교를 반복한다.
		for (int j = 0; j < i; ++j) {
			// 가장 큰 값을 갖는 index를 찾아라
			if (arr[maxIdx] < arr[j])
				maxIdx = j;
		}
		swap(&arr[maxIdx], &arr[i]);
	}
}

// 뒤의 공간부터 내림차순에 맞는 수를 끼워 넣는다.
void DescendingSelectionSort2(int arr[], int n) {

	// n-1 ~ 1 까지 끼워넣기를 반복한다.
	for (int i = n - 1; i > 0; --i) {
		int maxIdx = i;
		// 0 ~ i-1 까지 비교를 반복한다.
		for (int j = 0; j <= i - 1; ++j) {
			// 제일 작은 값을 갖는 index를 찾아라
			if (arr[maxIdx] > arr[j])
				maxIdx = j;
		}
		swap(&arr[i], &arr[maxIdx]);
	}
}

void main(void) {

	int arr[5] = { 2, 3, 1, 5, 4 };
	
	AscendingSelectionSort1(arr, 5);
	printArr(arr, 5);

	DescendingSelectionSort1(arr, 5);
	printArr(arr, 5);

	AscendingSelectionSort2(arr, 5);
	printArr(arr, 5);

	DescendingSelectionSort2(arr, 5);
	printArr(arr, 5);

	return 0;
}
