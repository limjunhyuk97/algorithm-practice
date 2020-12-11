void Qsort(int * array, int start, int end){
	
	if(start>=end) return;
	
	int pivot = start, i = start + 1, j = end - 1;
	
	while(i<=j){
		while(i <= end && array[pivot] >= array[i]){
			++i;
		}
		while(j > start && array[pivot] <= array[j] ){
			--j;
		}
		if(i<j) swap(array[i], array[j]);
		else swap(array[j], array[pivot]);
	} 
	
	Qsort(array, start, j-1);
	Qsort(array, j+1, end);
	
}
inline void swap(int &n, int &m){
	int tmp;
	tmp = n;
	n = m;
	m= tmp;
}
