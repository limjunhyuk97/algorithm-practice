# DP란?
  - optimizing multistage decision process by store and extract solution from table(optimization / non-optimization) 
  - big size problem, overlapping, dependent subproblem + optimization problem 에서 given problem의 optimal solution은 반드시 모든 substructure들의 optimal solution을 포함하고 있어야 한다.
  - use bottom-up approach(+top-down approach)
  - use recurrence relation 
  - get solution using **look-up table** which stores solutions of each stages
  - **steps : establish recurrence relation, solve - store - extract**
  - examples
      - optimal BST, Coin change, binomial coefficient, floyd-warshall 

## 01. DP 와 시간복잡도
  - polynomial time을 걸려서 문제 해결 가능 (다항함수 수준의 시간 복잡도) : optimization technique이다.
  - 다른 방식은 exponential time 걸려서 문제 해결 ( 지수함수 )

## 02. 어떤 문제에 DP를 적용할 수 있을까?

### 1. optimal substructure property
  - optimal : best
  - substructure : sub-problem of main-problem
  - **subproblem들을 optimal 하게 풀면 mainproblem을 optimal하게 풀 수 있다.**
  - **한번의 선택이 다음 선택에는 전혀 무관하며, 매 순간의 최적해가 문제에 대한 최적해인 상태 (Greedy algorithm과 연관)**
  - x1 > x2 > x3 > x4 ... 문제를 분할해서 main problem으로 다가갈 수 있는가..?
## 2. overlapping subproblems property
  - **동일한 연산을 여러번 반복**해야할 경우.

## 03. DP를 어떻게 활용하는가?

### 1. 큰 문제를 작은 문제로 분할한다. (점화식을 세운다.)

### 2. 작은 문제들(sub problems)을 해결하고, Table에 넣는다.

### 3. 동일한 작은 문제(sub problems)에 부딪혔다면, Table에서 꺼내쓴다.

- **memoization : ( top - down )**
  - 결과 값에 먼저 접근하려 시도를 하고, 결과값이 없다면, DP를 이용해서 위에서 아래로 값을 구하려 내려가는 기술이다.
- **tabulation : ( bottom - up )**
  - 도표, 도표의 작성
  - DP를 이용해서 아래서부터 위로, 구해야하는 값까지 거슬러 올라가서, 값을 구하는 방식이다.

```cpp
// Fibonacci 수열 구하기

// memoization 기법 (top - down 방식)
long long DP[100];

long long FiboInMemoization(int x) {

	if (x == 1 || x == 2) {
		return 1;
	}

	if (DP[x] != 0) {
		return DP[x];
	}
	
	return DP[x] = FiboInMemoization(x-1) + FiboInMemoization(x-2);
	
}

// Tabulation 기법 (bottom - up 방식)
long long FactorialInTabulation(int x) {

	for (int i = 1; i <= x; ++i) {
		if (DP[i] == 0)
			DP[i] = DP[i - 1] + DP[i - 2];
		else
			continue;
	}
 
	return DP[x];
 
}

```
