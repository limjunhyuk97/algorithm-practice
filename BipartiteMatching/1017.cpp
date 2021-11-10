// 이분 매칭을 이용한 두개씩 짝짓기
// 그래프화 시켜서, 연결된 상태를 일단 전부 구현하고, 이분매칭 알고리즘을 돌린다.

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

// 'A 각 요소들 -> B 배열'로 이분 매칭
int N, arr[55], A[55], B[55];
bool primes[2020];
bool checked[55];
vector<int> edges[55], res;

void find_prime(){
    for(int i=0; i<2020; ++i) primes[i] = true;
    primes[2] = true; primes[3] = true;
    int cnt = 2;
    for(int i=2; i<=2010; ++i){
        if(primes[i]){
            cnt = 2;
            while(cnt * i <= 2020) {
                primes[cnt * i] = false;
                cnt += 1;
            }
        }
    }
}

// DFS를 이용한 이분 매칭 알고리즘
bool dfs(int n){
    checked[n] = true;
    for(int m : edges[n]){
        // 이미 0번째 인덱스와 연결된 선분은 건드리지 않는다.
        if(B[m] == 0) continue;
        // 만약, 상대방에 아무것도 연결이 되어있지 않거나, 상대방이 탐색된적이 없으면서 상대방에 새로운 연결을 설정해 줄 수 있다면 = 연결을 생성한다.
        if(B[m] == -1 || (!checked[B[m]] && dfs(B[m]))){
            A[n] = m;
            B[m] = n;
            return true;
        }
    }
    return false;
}

bool compare(int n, int m){
    return arr[n] < arr[m];
}

int main(void){
    
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", arr + i);
    
    find_prime();
    
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(primes[arr[i]+arr[j]]){
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    bool flag = false;
    for(int i=1; i<N; ++i){
        flag = false;
        // 0번째 인덱스와 i번째 인덱스의 값을 더했을 때 소수라면 이분매칭을 시작한다.
        if(primes[arr[0] + arr[i]]){
            fill(A, A+N, -1);
            fill(B, B+N, -1);
            A[0] = i; B[i] = 0;
            // 0과 엮이지 않은 나머지 노드들(A 배열)에 대해서 이분 매칭을 진행한다.
            for(int j=1; j<N; ++j){
                if(i == j) continue;
                fill(checked, checked+ N, false);
                if(!dfs(j)) {
                    flag = true;
                    break;
                }
            }
            if(!flag) res.push_back(i);
        }
    }
    
    if(res.empty()) printf("-1\n");
    else{
        sort(res.begin(), res.end(), compare);
        for(int i : res) printf("%d ", arr[i]);
        printf("\n");
    }
    
    return 0;
}
