#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#define INF 1234567891
using namespace std;
typedef long long int ll;

int N, M, cnt;
vector<int> arr;

int main() {

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; ++i) {
		int tmp; scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	// 앞 뒤에서 조여가면서 찾아감
	int i1 = 0, i2 = N-1;
	while (i1 < i2) {
		int sum = arr[i1] + arr[i2];
		if (sum == M) {
			cnt += 1; i1 += 1; i2 -= 1;
		}
		else if (sum < M) i1 += 1;
		else i2 -= 1;
	}

	printf("%d\n", cnt);

	return 0;
}
