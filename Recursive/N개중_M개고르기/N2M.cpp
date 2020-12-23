#include <iostream>
#include <vector>
#define FOR(index, start, end) for(int (index) = (start); (index) < (end); ++(index))
using namespace std;

void PrintIt(vector <int> arr) {
	FOR(i, 0, arr.size()) cout << arr[i] << " ";
	cout << endl;
}

void Pick(int end, int start, vector <int> arr, int topick) {
	if (topick == 0) { PrintIt(arr); return; }
	int smallest = arr.empty() ? start : arr.back() + 1;
	FOR(i, smallest, end + 1) {
		arr.push_back(i);
		Pick(end, start, arr, topick - 1);
		arr.pop_back();
	}
}

int main(void) {

	int start, end, m;
	cout << "시작점 : ";
	cin >> start;
	cout << "끝점 : ";
	cin >> end;
	cout << "뽑기갯수 :";
	cin >> m;
	vector <int> arr;

	Pick(end, start, arr, m);


	return 0;
}
