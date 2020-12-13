void insertion_sort(int *array, int len){
	
	int j, key;
	for(int i=1; i<len; ++i){
		j = i-1;
		key = array[i];
		while(j>=0 && array[j]>key){
			array[j+1] = array[j];
			--j;
		}
		array[j+1] = key;
	}
}
