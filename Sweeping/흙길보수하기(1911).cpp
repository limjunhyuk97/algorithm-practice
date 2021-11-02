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
typedef pair<int, int> dump;

int N, L;
vector<dump> dumps;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    
    int s, e;
    for(int i=0; i<N; ++i){
        cin >> s >> e;
        dumps.push_back({s, e});
    }
    
    sort(dumps.begin(), dumps.end());
    
    s = 0;
    int count = 0;
    
    for(int i=0; i<dumps.size(); ++i){
        dump tmp = dumps[i];
        if(tmp.first > s) s = tmp.first;
        if(tmp.second < s) continue;
        while(tmp.second > s){
            s += L; count += 1;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
