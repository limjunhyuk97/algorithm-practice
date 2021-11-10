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

string S;
int N, leftsum, rightsum, cnt, arr[52];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S;
    
    N = S.size();
    for(int i=1; i<=N; ++i){
        arr[i] += S[i-1] + arr[i-1];
    }
    
    for(int i = N/2; i>=1; --i){
        for(int j=1; j + 2 * (i-1) + 1 <= N; ++j){
            leftsum = arr[j + i - 1] - arr[j - 1];
            rightsum = arr[j + 2*(i-1) + 1] - arr[j + i - 1];
            if(leftsum == rightsum){
                cout << i * 2 << '\n';
                return 0;
            }
        }
    }
    
    cout << 0 << endl;
    
    return 0;
}
