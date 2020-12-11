// QuickSort 코드 구현. <- 인자는 array(배열) 포인터, 시작점, 끝점.
void Qsort(int * array, int start, int end){
	
  // 길이가 1인 경우를 제외하는 부분. 
	if(start>=end) return;
	
  // pivot이 기준점. i는 왼쪽, j는 오른쪽.
	int pivot = start, i = start + 1, j = end - 1;
	
  // i와 j가 뒤집힐때까지 반복
	while(i<=j){
  
    // pivot 보다 작아야하는데, 큰놈 발견하면 알박기 
		while(i <= end && array[pivot] >= array[i]){
			++i;
		}
    
    // pivot 보다 커야되는데, 작은놈 발견하면 알박기
		while(j > start && array[pivot] <= array[j] ){
			--j;
		}
    
    // i, j 순서 안뒤집힘 : i, j 위치 바꿈 
    // 결과적으로 pivot 기준, 작은 놈들, 큰 놈들이 정위치로 들어가게됨
		if(i<=j) swap(array[i], array[j]);
    
    // i, j 순서 뒤집힘 : j, pivot 위치 바꿈
    // pivot보다 작은 j를 발견했기에, 이제 pivot이 정위치에 들어감. (pivot 기준 왼쪽 다 pivot보다 작고, pivot 기준 오른쪽 다 pivot보다 큼)
		else swap(array[j], array[pivot]);
	} 
	
  // 정해진 j 위치를 기준으로 왼쪽 재정렬 반복 수행.
	Qsort(array, start, j-1);
  
  // 정해진 j 위치를 기준으로 오른쪽 재정렬 반복 수행.
	Qsort(array, j+1, end);
	
}

// 편의를 위해서 swap 함수를 참조자 매개변수로 별도 지정. (포인터로 지정할 수도 있지.)
inline void swap(int &n, int &m){
	int tmp;
	tmp = n;
	n = m;
	m= tmp;
}
