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

int N, A[52][52], DP1[52][52], DP2[52][52][52][52];
vector< pair<double, double> > Points;
vector<int> area1;
map<int, int> area2;

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin >> A[i][j];
            DP1[i][j] = DP1[i-1][j] + DP1[i][j-1] - DP1[i-1][j-1] + A[i][j];
        }
    }
    
    for(int i=1; i<=N-1; ++i){
        for(int j=1; j<=N-1; ++j){
            Points.push_back({i+0.5, j+0.5});
        }
    }
    
    int ulx, uly, drx, dry;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            for(int x=1; x<=N; ++x){
                for(int y=1; y<=N; ++y){
                    ulx = min(i, x); uly = min(j, y); drx = max(i, x); dry = max(j, y);
                    DP2[i][j][x][y] = DP1[drx][dry] - DP1[drx][uly-1] - DP1[ulx-1][dry] + DP1[ulx-1][uly-1];
                }
            }
        }
    }
    
    int sum = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for(int i=0; i<Points.size(); ++i){
        // 왼쪽 위, 오른쪽 아래
        x1 = Points[i].first - 0.5; y1 = Points[i].second - 0.5; x2 = Points[i].first + 0.5; y2 = Points[i].second + 0.5;
        for(int k=1; k<=x1; ++k){
            for(int l=1; l<=y1; ++l){
                area1.push_back(DP2[k][l][x1][y1]);
            }
        }
        for(int k=x2; k<=N; ++k){
            for(int l=y2; l<=N; ++l){
                area2[DP2[x2][y2][k][l]] += 1;
            }
        }
        for(int k=0; k<area1.size(); ++k){
            if(area2.find(area1[k]) != area2.end()) sum += area2[area1[k]];
        }
        
        area1.clear(); area2.clear();
        
        // 오른쪽 위, 왼쪽 아래
        x1 = Points[i].first - 0.5; y1 = Points[i].second + 0.5; x2 = Points[i].first + 0.5; y2 = Points[i].second - 0.5;
        for(int k=x1; k>=1; --k){
            for(int l=y1; l<=N; ++l){
                area1.push_back(DP2[x1][y1][k][l]);
            }
        }
        for(int k=x2; k<=N; ++k){
            for(int l=y2; l>=1; --l){
                area2[DP2[x2][y2][k][l]] += 1;
            }
        }
        for(int k=0; k<area1.size(); ++k){
            if(area2.find(area1[k]) != area2.end()) sum += area2[area1[k]];
        }
        
        area1.clear(); area2.clear();
    }

    cout << sum << endl;
    
    return 0;
}
