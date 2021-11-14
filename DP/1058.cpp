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

int N, friendcnt[53];
char str[53];
bool DP[53][53];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", str);
		for (int j = 0; j < N; ++j) {
			if (str[j] == 'Y') DP[i][j] = true;
			else DP[i][j] = false;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N; ++j) {
			if (DP[i][j]) {
				friendcnt[i] += 1; friendcnt[j] += 1;
				continue;
			}
			for (int k = 0; k < N; ++k) {
				if (DP[i][k] && DP[k][j]) {
					friendcnt[i] += 1; friendcnt[j] += 1;
					break;
				}
			}
		}
	}

	printf("%d\n", *max_element(friendcnt, friendcnt + N));

	return 0;
}
