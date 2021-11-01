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

int N, M, K;
ll arr[302][302];
ll DP[302][302];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin >> arr[i][j];
            DP[i][j] = DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1] + arr[i][j];
        }
    }
    
    cin >> K;
    while(K--){
        int i, j, x, y; cin >> i >> j >> x >> y;
        cout << DP[x][y] - DP[x][j-1] - DP[i-1][y] + DP[i-1][j-1] << '\n';
    }
    
    return 0;
}
