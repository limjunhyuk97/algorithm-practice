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

int N, K;
vector<int> LANS;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> N;
    for(int i=0; i<K; ++i){
        int tmp; cin >> tmp;
        LANS.push_back(tmp);
    }
    
    ll left = 1, right = (ll)pow((double)2, (double)31) - 1, mid;
    
    while(left <= right){
        mid = left + right >> 1;
        int sum = 0;
        for(int i=0; i<K; ++i)
            sum += LANS[i] / mid;
        if(sum >= N) left = mid + 1;
        else right = mid - 1;
    }
    
    cout << right << endl;
    
    return 0;
}
