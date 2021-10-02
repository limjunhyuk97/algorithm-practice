// Divide and Conquer
// divide, conquer, combine 3과정이 필요하다.

#include <stdio.h>
#include <stdlib.h>

// array 복사
void copy_array(int* origin, int* copied, int start, int end) {
	int cnt = 0;
	for (int i = start; i < end; ++i) {
		copied[cnt++] = origin[i];
	}
}

// 오름차순 정렬
void merge_array(int* origin, int* arrL, int* arrR, int left, int mid, int right) {
	int l = 0, r = 0, k = left;
	while (l < (mid - left) && r < (right - mid)) {
		if (arrL[l] <= arrR[r]) origin[k++] = arrL[l++];
		else origin[k++] = arrR[r++];
	}
	if (l == mid - left) for (; r < right - mid; ++r) origin[k++] = arrR[r];
	else for (; l < mid - left; ++l) origin[k++] = arrL[l];
}

void merge_sort(int* arr, int size) {

	// 종료 조건
	if (size == 1) return;

	// divide
	int half = size >> 1;
	int* arrL = (int*)malloc(sizeof(int) * (half));
	int* arrR = (int*)malloc(sizeof(int) * (size - half));
	copy_array(arr, arrL, 0, half);
	copy_array(arr, arrR, half, size);

	// conquer
	merge_sort(arrL, half);
	merge_sort(arrR, size - half);

	// combine
	merge_array(arr, arrL, arrR, 0, half, size);

}

int main(void) {

	int arr[15] = { 3, 5, 10, 32, 5, 6, 9, 2, 13, 24, 66, 29, 132, 22, 1 };

	merge_sort(arr, 15);

	for (int i = 0; i < 15; ++i)
		printf("%d ", arr[i]);

	return 0;
}
