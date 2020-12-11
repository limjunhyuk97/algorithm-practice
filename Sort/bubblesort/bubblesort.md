# bubble 정렬

```cpp

// 받는 인자는 배열.
void BubbleSort(int *arr, int len){
  
  // 오름차순 정렬
  // 1 ~ len 까지 큰놈 오른쪽으로 밀고,, 1 ~ len-1 까지 또 큰놈 오른쪽으로 밀고 반복.
	for(int i=len-1; i>=1; --i){
		for(int j=0; j<i;++j){
			if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
		}
	}
	
}

// 편의를 위해서 swap 함수 지정
inline void swap(int &n, int &m){
	int t;
	t = n;
	n = m;
	m = t;	
}
```
