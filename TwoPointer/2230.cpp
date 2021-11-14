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
#include <cmath>
#define INF 2100000000
using namespace std;
typedef long long int ll;

int N, M, gap;
vector<int> arr;

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		int tmp; scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	gap = INF;
	sort(arr.begin(), arr.end());

	int l = 0, r = 0;
	while (r < N) {
		if (abs(arr[r] - arr[l]) < M) r += 1;
		else {
			gap = min(gap, arr[r] - arr[l]);
			l += 1;
			if (l > r) r = l;
		}
	}

	printf("%d\n", gap);

	return 0;
}
