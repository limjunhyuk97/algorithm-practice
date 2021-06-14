# Quick Sort

## 1. Quick Sort
  - 분할 정복의 메커니즘 이용
  - pivot을 first, last, middle key 값의 median으로 설정하는 것이 성능을 개선하는 방법.

## 2. 시간 복잡도
 - O(N\*logN)
 - 그러나, 이미 정렬 되어있는 경우 O(N^2).
 
## 3. 놀랍게도,,
 - cpp 에서는 <algorithm> 헤더 파일에서 sort(arr, arr+n)이라는 quicksort 정렬 함수를 제공한다.
 - 사용
```cpp
    #include <algorithm>
    
    int arr[len] = { , , , ,,,};
    sort(arr, arr + n);
    // 정렬 시작할 지점 주소, 종료할 지점 주소 + 1
    
    sort(v.begin(), v.end());
    // vector container를 사용할 경우의 quick sort.
```
    
