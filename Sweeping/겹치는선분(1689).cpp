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

int N, lp, rp, sum_val;
vector<pair<int, int> > points;

bool operator<(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.first > p2.first;
}

struct compare{
    bool operator()(const int & n1, const int & n2){
        return n1 > n2;
    }
};

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> lp >> rp;
        points.push_back({lp, rp});
    }
    
    sort(points.begin(), points.end());
    
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(points[0].second);
    sum_val = 1;

    for(int i=1; i<points.size(); ++i){
        while(!pq.empty() && (pq.top() <= points[i].first)){
            pq.pop();
        }
        pq.push(points[i].second);
        sum_val = (sum_val > pq.size() ? sum_val : pq.size());
    }
    
    cout << sum_val << endl;
    
    return 0;
}
