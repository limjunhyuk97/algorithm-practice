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
#define INT_INF 2e9
#define LL_INF 9e18
#define MOD 1000000007
using namespace std;

typedef long long int ll;

int N, M, T, t;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while(T--){
        cin >> N;
        
        int DP[10005]; vector<int> coin;
        for(int i=0; i<10005; ++i)
            DP[i] = 0;
        
        for(int i=0; i<N; ++i){
            cin >> t;
            coin.push_back(t);
        }
        cin >> M;
        
        for(int i=0; i<coin.size(); ++i){
            DP[coin[i]] += 1;
            for(int j=coin[i]; j<=M; ++j){
                DP[j] += DP[j-coin[i]];
            }
        }
        
        cout << DP[M] << '\n';
            
    }
    
    return 0;
}
