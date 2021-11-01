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
typedef pair<int, int> point_1d;

ll N, sum;
vector<point_1d> points;

bool compare(const point_1d &p1, const point_1d &p2){
    return p1.first < p2.first;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        ll lp, rp; cin >> lp >> rp;
        points.push_back({lp, rp});
    }
    
    sort(points.begin(), points.end(), compare);
    
    point_1d tmp = points[0];
    sum += points[0].second - points[0].first;
    for(int i = 1; i< N; ++i){
        if((points[i].first <= tmp.second) && (tmp.second < points[i].second)) {
            sum += points[i].second - tmp.second;
            tmp.second = points[i].second;
        }
        if(points[i].first > tmp.second) {
            tmp = points[i];
            sum += points[i].second - points[i].first;
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}
