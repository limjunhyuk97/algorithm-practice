# DFS와 BFS

## DFS와 BFS 언제 써야할까?
  - [참고](https://devuna.tistory.com/32)

### DFS (스택, 재귀)
  - 모든 정점의 방문
  - 각 경로마다 특징이 있는 경우

### BFS (큐)
  - 모든 정점의 방문
  - 목적지까지의 최단경로 찾기 (DFS로 찾는 경우, 처음으로 발견하는 경우가 최단경로가 아닐 수 있고, 같은 정점을 여러번 방문하는 비효율성 발생 가능하다.)
    - 가장 먼저 목적지에 도달하는 경우가 최단 경로이다. (같은 레벨의 노드들을 모두 훑은 다음, 다음 레벨의 노드들을 확인하기 때문에) 

## 1260. DFS와 BFS
  - 단순한 DFS, BFS 구현 문제

## 2178. 미로탐색
  - 목적지까지 도달하는 최단경로를 구하기 위해서 DFS로 꽤나 삽질을 했다.
  - BFS를 사용하는 것이 효율적이다.
    - 서로 다른 경로에 동일하게 존재하는 노드들을 여러번 들여다보는 비효율성을 줄일 수 있다.
    - 출발지점에서 같은 거리만큼 떨어진 요소들을 수평적으로 들여다보기 때문에, BFS를 사용하여 탐색했을 때 가장 먼저 목적지에 도달한 경우가 최단경로이다.  