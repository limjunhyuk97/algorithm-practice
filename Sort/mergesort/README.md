# Merge sort
  - **행렬을 분할하여 정복가능한 크기로까지 분할(분할)**하고, **정복한 뒤(정복)**에, **병합하는 과정을 거쳐 거슬러 올라오는 방식(병합)**

## 1. 코드구현

```c
// Divide and Conquer
// divide , conquer, combine

#include <stdio.h>
#include <stdlib.h>

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
```

## 2. 시간복잡도
  - T(n) = 2(T/2) + f(n)(= O(n-1), worst case) 의 시간복잡도를 갖는다.
  - master theorem에 의해서 간소화 시키면, O(nlogn)의 시간복잡도를 갖는다.
  - 단, 배열을 어딘가에 복사해두는 작업이 필요하기 때문에, 추가적인 공간이 요구된다.
