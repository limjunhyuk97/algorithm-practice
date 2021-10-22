# Jun's Algoritm space

## Hoarding my problem solving techniques

## Daily scrum

### 1. Greedy
  - 각 단계의 최선의 선택이 최적의 선택
  - 1931: 종료지점이 이른 것을 고르는 것이 가장 최선
### 2. DP를 언제 도입해야 할까?
  - knapsack problem (DP)
  - DP -> 점화식 -> 행렬 표현 -> Divide & Conquer
  - 9251: 최장 공통 문자열, str2 문자 하나씩 str1 문자열에 비교
    - 같은 문자(이전 단계, 이전 문자 비교까지의 '최대치' + 1), 다른 문자(현 단계 이전문자, 이전 단계 현 문자 중 최대치)  
### 3. Divide & Conquer를 언제 도입해야 할까?
  - 거듭 제곱의 mod 연산 (divide&conquer)
  - 곱셈의 mod 연산
  - 나눗셈의 mod 연산 (divide&conquer / 페르마의 소정리)
  - 행렬 거듭제곱의 mod 연산 (divide&conquer)
  - 조합 연산의 방식들 (nCm = n-1Cm-1 + n-1Cm , n!/m!(n-m)!)
  - DP -> 점화식 -> 행렬 표현 -> Divide & Conquer
    - 11444: n 번째 피보나치 수까지, 행렬의 거듭제곱의 연산으로 나타낼 수 있다.  
  - 트리의 구조파악
    - 2263: 다른 방식의 순회를 수행, root 기준(연산과 트리의 정의 기준) divide + conquer 
### 4. **Brute Force(완전 탐색)를 언제 사용해야 할까?**
  - 보통 시간복잡도가 매우 높아서 입력값이 작을 때에만 가능하다.
  - **입력값이 작고, 시간 제한이 널널하고, 효율적인 공통성을 발견하기 어려운 경우** : 브루트포스를 염두.
### 5. **이진탐색을 언제 활용해야할까?**
  - N 개의 수가 크기 순으로 배열되어 있을 때, 그 중 수 **K의 위치를 빠르게 찾는 방법**이다.
  - N 개의 수가 크기 순으로 배열되어 있을 때, **K 이상의 값을 갖는 위치중 가장 작은 위치를 빠르게 찾는 방법**이다.
  - **어떤 조건을 만족하는 위치 중 가장 작은 위치가 어디인가?** 를 빠르게 찾을 수 있다.
  - 최적화 문제(여러 해답 중 기준에 따라 최적의 값을 구하는 문제 : 최대, 최소)를 결정 문제(예, 아니오를 결정하는 문제)로 바꿀 수 있다.
    - 최적화 문제 : f(i)가 1이 되는 i의 최소값을 구해라
    - 결정 문제 : f(i)가 1인가? 
<img src="https://user-images.githubusercontent.com/59442344/124707461-d1232680-df33-11eb-88a8-cd9633acddd8.png" width=60% height=60%>
 
 - **이진탐색의 종료조건**
    - 정확히 떨어지는 값을 찾는 것이 아닌 경우
```cpp
if(...) right = mid - 1
else left = mid + 1
// 이런 구조로 짠다면, left 왼쪽에 찾고자하는 값을 고정시킬 수 있게 되고, right가 답을 가리키게 된다.
```
  - [2805](https://github.com/limjunhyuk97/BOJ/tree/main/SILVER/2805_%EC%9D%B4%EB%B6%84%ED%83%90%EC%83%89%20%EB%82%98%EB%AC%B4%EC%9E%90%EB%A5%B4%EA%B8%B0): 나무자르기

### 6. Divide & Conquer / Greedy / DP
- optimization / non-optimization ?
- overlapping problem ?
- 

- **Basic principle**
  - **Divide and Conquer**
    - divide into smaller instances until they can be solved, conquer, and merge the solutions (optimization / non-optimization)
    - non-overlapping, big size problem
    - use top-down approach
    - use recursive algorithm
    - get solution using **call stack**
    - **steps : divide - conquer - merge**
    - examples
      - BS, merge sort, quick sort 
  - **Dynamic Programming**
    - optimizing multistage decision process by store and extract solution from table(optimization / non-optimization) 
    - big size problem, overlapping, dependent subproblem + only problem with optimal substructure (optimal subproblem)
    - use bottom-up approach(+top-down approach)
    - use recurrence relation 
    - get solution using **look-up table** which stores solutions of each stages
    - **steps : establish recurrence relation, solve - store - extract**
    - examples
      - optimal BST, Coin change, binomial coefficient, floyd-warshall 
  - **Greedy**
    - arrives at solution by constructing solution set through a sequence of optimal choices (optimization)
    - sequence of local optimal choices produce global optimal solution.
    - use iteration
    - get solution using **solution set**, adding items into it, until solution set represents a solution to instance
    - **steps : selection, feasibility check, solution check**
    - examples
     - constructing MST(Kruskal, Prim), Shortest Path(Dijkstra)  



