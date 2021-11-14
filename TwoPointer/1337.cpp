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
#define INF 1234567891
using namespace std;
typedef long long int ll;

int N, idx1 = 0, idx2 = 0, gap = 6;
int arr[55];

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) scanf("%d", arr + i);

	sort(arr, arr + N);

	// 맨 아래에서 같이 증가하면서 올라감
	while (idx2 < N-1) {
		if (abs(arr[idx2 + 1] - arr[idx1]) < 5) idx2 += 1;
		else idx1 += 1;
		gap = min(gap, 4 - (idx2 - idx1));
	}

	if (N == 1) gap = 4;

	printf("%d\n", gap);

	return 0;
}
