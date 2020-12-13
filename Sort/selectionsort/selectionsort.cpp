void swap(int &n, int &m){
	int t;
	t = n;
	n = m;
	m = t;
}

void selection_sort(int *array, int len){
	
	int minIndex;
	
	for(int i = 0 ; i < len ; ++i){
		minIndex = i;
		for(int j=i+1; j<len; ++j){
			if(array[minIndex]>array[j]) minIndex = j;
		}
		swap(array[i], array[minIndex]);
	}	
}
