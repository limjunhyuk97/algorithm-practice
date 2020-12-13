# Quick sort

## 1. 코드 구현

```cpp

inline void swap(int &a, int &b){
    int t = a; a = b; b = t;
}

void quickSort(int A[], int low, int high) {

    // base condition
    // 길이가 1인 친구는 정지.
    if(low >= high) return;

    // divide process
    // i는 시작점 - 1 부분. j는 시적점 부분.
    int i = low-1, j = low;
    
    // pivot
    // &pivot 참조자로 초기화하는 이유는 main에서 가져온 배열의 주소값을 공유하기 위해서 이다.
    // int pivot으로 선언하면 swap(A[++i], pivot) 계산시에, pivot은 quickSort 안에서 한시적으로 생성된 메모리 이므로 정보가 pivot에서 A[++i]로만 넘어간다.
    int &pivot = A[high];
    
    // 초기화 부분은 이미 되있어서 필요 없다. - 오름차순 정렬
    // pivot 기준 작은 놈을 왼쪽으로 보내주는 작업
    // pivot 기준 작은 놈의 수 만큼 교환이 이루어 지기에,, pivot이 34행에서 제 위치에 들어가게 된다.
    for (; j < high; ++j) {
        if ( A[j] < pivot)
            swap(A[++i], A[j]);
    }
    
    // 마지막으로 ++i, pivot위치 교대로, pivot을 제 위치에 넣어 준다.
    swap(A[++i], pivot);

    // conquer process
    // i 기준 왼쪽, 오른쪽 정렬 다시 시작.
    quickSort(A, low, i-1);
    quickSort(A, i+1, high);
}

```

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
    
