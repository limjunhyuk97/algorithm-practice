# 삽입정렬

## 1. 코드구현
```cpp

void insertion_sort(int *array, int len){
	
	int j, key;
  
  // index i는 1부터 시작
	for(int i=1; i<len; ++i){
  
    // index j는 i-1 부터 0까지 loop
		j = i-1;
    
    // key는 index i의 value 임시 저장
		key = array[i];
    
    // (오름차순 정렬 기준) index i의 value보다 큰 value는 오른쪽으로 오게끔 한칸씩 오른쪽으로 밀어줌
    // key 말고, array[i]를 비교 기준으로 쓰면 array[i]는 계속 value가 바뀌기에 부정확
		while(j>=0 && array[j]>key){
			array[j+1] = array[j];
			--j;
		}
    
    // 마지막으로 임시저장된 index i값인 key 값을, 큰값들이 오른쪽으로 밀리고 남은 제일 왼쪽 부분에 넣기
		array[j+1] = key;
	}
  
  // 반복
}

```

## 2. 시간복잡도
- 평균적인 경우, 그리고 최악인경우 O(n^2). 이상적인 경우는 O(n) - 모두 정렬이 이미 되있는 상태일때! 
