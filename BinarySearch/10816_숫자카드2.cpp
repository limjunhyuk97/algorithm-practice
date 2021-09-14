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

map<int, int> number_set;
int N, M;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        int tmp; cin >> tmp;
        if(number_set.find(tmp) != number_set.end()) number_set[tmp] += 1;
        else number_set.insert({tmp, 1});
    }
    
    cin >> M;
    for(int i=0; i<M; ++i){
        int tmp; cin >> tmp;
        if(number_set.find(tmp) != number_set.end()) cout << number_set[tmp] << " ";
        else cout << 0 << " ";
    }
    
    return 0;
}
