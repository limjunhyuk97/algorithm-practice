# Divide and Conquer

## 분할 정복법이란?

### 1. 엄청나게 크고 방대한 문제를 작은 문제로 '분할'하고, 분할된 문제들을 '조합'하면서 정복하는 방법이다.

### 2. 분할 / 정복/ 조합 의 단계로 구성된다.
  - **분할** : 문제를 동일 유형의 여러 하위 문제로 나눈다. D(n)
  - **정복** : 가장 작은 하위 문제를 해결하여 정복한다. S(n)
  - **조합(필요하다면)** : 정복된 하위 단계를 원래 문제에 대한 결과로 조합한다. C(n)
    - (예) binary search - 조합과정 필요없음, merge sort - 조합과정 요구된다.

### 3. 시간 복잡도
  - **T(n) = aT(n/b) + f(n)(= D(n)+C(n))**
  - **master theorem**에 의해서 단순화 시킬 수 있다.
 
## 예시

### 1. Merge sort
  - 시간 복잡도는 O(nlogn)이지만, 다른 정렬방식에 비해 메모리를 더 사용한다.

```cpp
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
```

### 2. a^b 구하기
  - O(b)의 시간복잡도를 O(logb)의 시간복잡도로 단축시킬 수 있다.

```cpp
int powAB(int a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else if (b % 2 == 0) {
		int t = powAB(a, b / 2);
		return t * t;
	}
	else {
		return a * powAB(a, b - 1);
	}
}
```

### 3. 대수 연산과 분할 정복
  - **거듭 제곱 연산에 대한 mod 연산** : 분할 정복의 방법 (O(logN)의 복잡도로 구현 가능)
  - **곱셈 연산에 대한 mod 연산** : (a * b) % n == ( (a % n) * (b % n) ) % n
  - **나눗셈 연산에 대한 mod 연산** : 페르마의 소정리를 통한 연산 구현
