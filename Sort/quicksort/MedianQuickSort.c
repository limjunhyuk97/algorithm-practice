#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* n, int* m) {
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

void QuickSort(int arr[], int left, int right) {

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
	if( ((pivot < end) &&(arr[pivot] > arr[end])) || ((pivot > end) && (arr[pivot] < arr[end])) )
		swap(&arr[pivot], &arr[end]);

	// end 기준 양 옆이다!
	// end 값이 제 위치가 아닐 수도 있다..!
	// 5 3(end) 6(pivot) 7(start) 6 9 : end가 제 위치에 들어있지 않음
	QuickSort(arr, left, end);
	QuickSort(arr, end + 1, right);

}

int main(void) {
	
	int arr1[10], arr2[10];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		arr1[i] = rand() % 10 + 1;
		arr2[i] = rand() % 10 + 1;
		printf("%d ", arr1[i]);
	}
	printf("\n\n");

	QuickSort(arr2, 0, 9);

	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr2[i]);
	}
	printf("\n\n");

	return 0;
}
