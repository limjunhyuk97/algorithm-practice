void BubbleSort(int *arr, int len){
	for(int i = len; i >= 1; --i){
		for(int j = 0; j < i; ++j){
			if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
		}
	}
	
}
inline void swap(int &n, int &m){
	int t;
	t = n;
	n = m;
	m = t;	
}
