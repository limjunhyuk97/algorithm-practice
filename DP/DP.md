## 0. DP란?
 - Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and storing the results of subproblems to avoid computing the same results again.

## 1. DP 와 시간복잡도
 - polynomial time을 걸려서 문제 해결 가능 (다항함수 수준의 시간 복잡도) : optimization technique이다.
 - 다른 방식은 exponential time 걸려서 문제 해결 ( 지수함수 )

## 2. 어떤 문제에 DP를 적용할 수 있을까?
  - optimal substructure property을 갖어야 함.
    - optimal : best
    - substructure : sub-problem of main-problem
    - subproblem들을 optimal 하게 풀면 mainproblem을 optimal하게 풀 수 있대요.
    - x1 > x2 > x3 > x4 ... 문제를 분할해서 main problem으로 다가갈 수 있는가..?
  - overlapping subproblems property을 갖어야 함.
    - 동일한 연산을 여러번 반복해야할 경우.

## 3. DP를 어떻게 활용하는가?
 - memoization : 이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여 실행속도를 높이는 기술 ( top - down )
 - tabulation : ( bottom - up )

## 4. DP와 Divide and conquer
 - overlapping property -> DP O, Divide and Conquer X
 - solving subproblems -> DP O, Divide ans Conquer X
