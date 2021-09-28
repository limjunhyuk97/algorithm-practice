#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <array>
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, K;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    int left = 1, right = K, mid = 0;
    while(left <= right){
        mid = left + right >> 1;
        int cnt = 0;
        for(int i=1; i<=N; ++i) cnt += min(mid/i, N);
        if(cnt < K) left = mid + 1;
        else right = mid - 1;
    }
    
    cout << left << endl;
    
    return 0;
}
