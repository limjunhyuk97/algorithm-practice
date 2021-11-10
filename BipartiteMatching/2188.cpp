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

int N, M, A[202], B[202], cnt;
bool checked[202];
vector<int> graph[202];

bool DFS(int n){
    checked[n] = true;
    for(int i : graph[n]){
        // i 번 축사가 선택되기 전이거나, i번 축사에 넣어진 소에 대한 DFS가 아직 돌기 전이면서 i번 축사에 다른 값을 넣을 수 있는 경우!
        if(B[i] == -1 || (!checked[B[i]] && DFS(B[i]))){
            A[n] = i;
            B[i] = n;
            return true;
        }
    }
    return false;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        int tmp; scanf("%d", &tmp);
        for(int j=0; j<tmp; ++j){
            int room; scanf("%d", &room);
            graph[i].push_back(room);
        }
    }
    
    fill(A, A+202, -1);
    fill(B, B+202, -1);
    for(int i=0; i<N; ++i){
        fill(checked, checked + N, false);
        if(DFS(i)) cnt += 1;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
