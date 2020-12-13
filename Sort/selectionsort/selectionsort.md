# Selection sort

## 1. 코드구현
```cpp
// swap 함수 편의 상 구현
void swap(int &n, int &m){
	int t;
	t = n;
	n = m;
	m = t;
}

// 선택정렬 함수
void selection_sort(int *array, int len){
	
  // i+1 부터, 끝 사이의 value 중 제일 작은 것의 index를 가리키는 변수.
	int minIndex;
	
  // i 변수가 0부터, 끝까지 돌아가면서 자리를 고정적으로 맡는다.
	for(int i = 0 ; i < len ; ++i){
  
		minIndex = i;
    
		for(int j=i+1; j<len; ++j){
      
      // 고정된 i 자리에, index i 부터 끝 사이의 value 중 제일 작은 값을 갖는 index를 minIndex에 넣어준다.
			if(array[minIndex]>array[j]) minIndex = j;
      
		}
    
    // 그 minIndex의 value를 i 자리와 swap 해준다.
		swap(array[i], array[minIndex]);
    
	}	
}
```

## 2. 시간 복잡도
- O(n^2)
