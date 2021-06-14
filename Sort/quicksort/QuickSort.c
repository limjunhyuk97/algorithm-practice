#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MIQ = 0, Q = 0, MQ = 0;

void swap(int* n, int* m) {
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

void QuickSort(int arr[], int left, int right) {

	++Q;

	if (left >= right)
		return;

	int start = left + 1;
	int end = right;
	int pivot = left;

	while (start <= end) {

		// arr[pivot] < arr[start] 찾기
		while (arr[pivot] >= arr[start] && start <= right)
			++start;

		while (arr[pivot] <= arr[end] && end >= (left + 1))
			--end;

		if (start <= end)
			swap(&arr[start], &arr[end]);

	}

	swap(&arr[pivot], &arr[end]);

	QuickSort(arr, left, end - 1);
	QuickSort(arr, end + 1, right);

}

void MiddleIndexQuickSort(int arr[], int left, int right) {

	++MIQ;

	// left == rigt 인것 포함 (1개짜리는 정렬된 것)
	if (left >= right)
		return;

	int start = left;
	int end = right;
	int pivot = (left + right) / 2;

	// start == end 일때도 loop 종료 시켜야 함
	while (start < end) {

		// arr 밖으로 벗어나는 것 방지, arr[pivot] < arr[start] 일 때 loop 종료
		while (arr[pivot] >= arr[start] && (start < right))
			start++;

		// arr 밖으로 벗어나는 것 방지, arr[pivot] > arr[end] 일 때 loop 종료
		while (arr[pivot] <= arr[end] && (end > left))
			--end;

		// start == end일 때도 loop 종료 시켜야 함
		if (start < end)
			swap(&arr[start], &arr[end]);

	}

	// end와 pivot을 바꿔줘야 함
	if (((pivot < end) && (arr[pivot] > arr[end])) || ((pivot > end) && (arr[pivot] < arr[end])))
		swap(&arr[pivot], &arr[end]);

	// end 기준 양 옆이다!
	// end 값이 제 위치가 아닐 수도 있다..!
	// 5 3(end) 6(pivot) 7(start) 6 9 : end가 제 위치에 들어있지 않음
	MiddleIndexQuickSort(arr, left, end);
	MiddleIndexQuickSort(arr, end + 1, right);

}

int FindMedian(int arr[], int left, int right) {

	int tmp[3] = { left, right, (left + right) / 2 };
	
	if (arr[tmp[0]] > arr[tmp[1]])
		swap(&tmp[0], &tmp[1]);

	if (arr[tmp[1]] > arr[tmp[2]])
		swap(&tmp[1], &tmp[2]);

	if (arr[tmp[0]] > arr[tmp[1]])
		swap(&tmp[0], &tmp[1]);

	return tmp[1];
}

void MedianQuickSort(int arr[], int left, int right) {

	++MQ;

	if (left >= right)
		return;

	// 시작부분으로 강제
	swap(&arr[left], &arr[FindMedian(arr, left, right)]);
	int pivotIdx = left;
	int start = left + 1;
	int end = right;

	while (start <= end) {

		while (arr[pivotIdx] >= arr[start] && start <= right)
			++start;

		while (arr[pivotIdx] <= arr[end] && end >= (left + 1))
			--end;

		if (start <= end)
			swap(&arr[start], &arr[end]);

	}

	swap(&arr[end], &arr[pivotIdx]);

	MedianQuickSort(arr, left, end - 1);
	MedianQuickSort(arr, end + 1, right);

}

int main(void) {
	
	int arr1[20], arr2[20], arr3[20];

	srand((unsigned int)time(NULL));

	for (int j = 0; j < 10; ++j) {

		printf("생성 %d. ", j);
		// arr1, arr2 생성
		for (int i = 0; i < 20; ++i) {
			arr1[i] = rand() % 20 + 1;
			arr2[i] = arr1[i];
			arr3[i] = arr1[i];
			printf("%d ", arr1[i]);
		}
		printf("\n");

		Q = 0; MQ = 0; MIQ = 0;
		QuickSort(arr1, 0, 19);
		MiddleIndexQuickSort(arr2, 0, 19);
		MedianQuickSort(arr3, 0, 19);

		printf("QuickSort 정렬 : %d \t\t", Q);
		for (int i = 0; i < 20; ++i) {
			printf("%d ", arr1[i]);
		}
		printf("\n");

		printf("MedianQuickSort 정렬 : %d \t", MQ);
		for (int i = 0; i < 20; ++i) {
			printf("%d ", arr3[i]);
		}
		printf("\n");

		printf("MiddleIndexQuickSort 정렬 : %d \t", MIQ);
		for (int i = 0; i < 20; ++i) {
			printf("%d ", arr2[i]);
		}
		printf("\n\n");
	}

	return 0;
}
