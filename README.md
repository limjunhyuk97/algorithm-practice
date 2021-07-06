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
  -  데이터가 정렬되어 있는 배열에서 특정한 값을 찾아낼 때 사용하는데, O(N)을 O(logN)으로 단축시킬 수 있다.

### 6. Divide & Conquer / Greedy / DP
  - Divide & Conquer는 non-overlapping subproblem들을 해결할 때 사용한다.
  - DP는 Divide & Conquer의 특수한 경우로, overlapping subproblem들을 해결할 때 사용한다.
  - Greedy는 매 단계의 결정을 재고려하지 않으며, 짧은 시간 간격의 good/fair한 solution을 제공하지만, DP는 가장 optimal한 해결방식을 제공한다.



