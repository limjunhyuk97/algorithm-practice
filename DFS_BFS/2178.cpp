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
typedef pair<int, int> coordinate;
typedef pair<coordinate, int> path;

bool grid[103][103];
bool grid_picked[103][103];
int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// DFS로 푼다면 시간초과가 나올 가능성이 높아진다.
// DFS : 모든 정점의 방문, 각 경로마다 특징이 있는 경우
//     : 스택, 재귀 함수를 통해서 구현할 수 있다.
// BFS : 모든 정점의 방문, 최단 경로 찾기(DFS로 찾는 경우, 처음으로 발견되는 해답이 최단거리가 아닐 수도 있다.)
//     : 큐를 통해서 구현할 수 있다.

// 이 문제의 경우, 탐색 시 파고 들어갈 경로를 생각해봤을 떄, DFS를 통해서 파고들어간다면, 중복하여 고려되는 경우가 굉장히 많을 것이다.

int BFS(int n, int m){
    queue<path> picked;
    picked.push({{n, m}, 1});
    
    int x = 0, y = 0 , w = 0;
    grid_picked[0][0] = true;
    while(!picked.empty()){
        path cur = picked.front();
        picked.pop();
        
        x = cur.first.first; y = cur.first.second; w = cur.second;
        if(x == N-1 && y == M-1) return w;
        for(int i=0; i<4; ++i){
            if(x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M) continue;
            if(!grid_picked[x + dx[i]][y+dy[i]] && grid[x + dx[i]][y+dy[i]]){
                picked.push({{x+dx[i], y+dy[i]}, w + 1});
                grid_picked[x+dx[i]][y+dy[i]] = true;
            }
        }
    }
    return w;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0 ; i<N; ++i){
        string tmp; cin >> tmp;
        for(int j=0; j<M; ++j)
            if(tmp[j]=='1') grid[i][j] = true;
            else grid[i][j] = false;
    }
    
    cout << BFS(0, 0) << endl;
    
    return 0;
}
