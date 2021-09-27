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

int N, C;
vector<int> point;

bool gap_available(int gap){
    int pivot = point.front();
    int cnt = 1;
    
    for(int i=0; i<point.size(); ++i){
        if (point[i] - pivot >= gap){
            pivot = point[i];
            ++cnt;
        }
    }
    
    if(cnt >= C) return true;
    else return false;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    for(int i=0; i<N; ++i){
        int tmp; cin >> tmp;
        point.push_back(tmp);
    }
    
    sort(point.begin(), point.end());
    
    int s_gap = 1, l_gap = point.back() - point.front();
    int mid = 0;
    
    while(s_gap <= l_gap){
        mid = s_gap + l_gap >> 1;
        
        if(gap_available(mid))
            s_gap = mid + 1;
        else
            l_gap = mid - 1;
    }
    
    cout << l_gap << endl;
     
    return 0;
}
