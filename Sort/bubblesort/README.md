# bubble 정렬
  - 인접한 두개의 데이터를 비교해가면서, 정렬 순서상 위치변경이 필요한 경우 데이터 위치를 바꾸어 정렬을 진행하는 방식
  - 앞에서부터 순서대로 비교, 교환하는 방식이 마치 버블이 일어나는 것과 비슷하다!

## 1. 코드 구현

```c
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

void AscendingBubbleSort1(int arr[], int n) {

	// n-1 번 반복하고
	for (int i = 0; i < n-1; ++i) {
		// i가 커질수록 각 i번째마다, (n-1)-i로 횟수가 줄어든다. (수가 마지막에 고정되니까!) 
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

}

void DescendingBubbleSort1(int arr[], int n) {

	// n-1 번 반복하고
	for (int i = 0; i < n - 1; ++i) {
		// i가 커질수록 i번째마다, (n-1)-i로 횟수가 줄어든다.
		for (int j = 0; j < (n - 1) - i; ++j) {
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

// 맨 뒤에서 맨 앞으로 순서대로 정렬
void AscendingBubbleSort2(int arr[], int n) {

	// 0 ~ n-1 번 반복
	for (int i = 0; i < n-1; ++i) {
		// 반복이 진행되면 1+i로 범위 줄어듦
		for (int j = n - 1; j >= 1 + i; --j) {
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
		}
	}
}

// 맨 뒤에서 맨 앞으로 순서대로 정렬
void DescendingBubbleSort2(int arr[], int n) {

	// 0 ~ n-1 번 반복
	for (int i = 0; i < n - 1; ++i) {
		// 반복이 진행되면 1+i로 범위 줄어듦
		for (int j = n - 1; j >= 1 + i; --j) {
			if (arr[j] > arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
		}
	}
}

void main(void) {

	int arr[5] = { 2, 3, 1, 5, 4 };

	AscendingBubbleSort1(arr, 5);
	printArr(arr, 5);

	DescendingBubbleSort1(arr, 5);
	printArr(arr, 5);

	AscendingBubbleSort2(arr, 5);
	printArr(arr, 5);

	DescendingBubbleSort2(arr, 5);
	printArr(arr, 5);

	return 0;
}
```

## 2. 시간복잡도 (최악의 경우)
  - 비교 연산의 횟수 : O(N^2)
  - 데이터 이동의 횟수 : O(N^2)
