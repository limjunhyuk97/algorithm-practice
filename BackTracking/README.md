# Backtracking (백 트래킹)

## 1. non-optimization Backtracking

- **어떤 object 집합에서 criteria를 만족하는 object의 sequence나, object의 combination을 구할 때 사용**한다.
- **state space tree**라는 implicit한 자료구조를 사용한다.
  - state space tree는 object를 선택하는 모든 가능한 방법들을 담고 있는 의미론적인 트리구조이다.
  - 각 노드들을 state space라고 한다.
- **state space tree를 DFS(깊이 우선 탐색) 기법으로 preorder하게 순회**한다.
- **promising하는 node들에 대해서는 순회를 계속**하고, **non-promising하는 node들에서는 다시 부모노드로 돌아가는 방식으로 그 하위 subtree를 prune(가지치기)** 한다.
  - promising node : solution으로 진행될 수 있는 잠재력을 가진 노드. (constraint에 아직까지 부합하는 노드)
  - non-promising node : solution으로 진행될 수 있는 잠재력이 없는 노드. (constraint에 의해 걸러진 노드)
  - pruned state space tree : 이미 방문되어서 더 이상 볼필요 없이 제거된 branch
- **Backtracking의 진행 순서**
  - tree model에서 DFS 수행하는 함수 생성
  - constraint 조건 갖는 promising 함수 생성
    - constraint 조건 고려를 위한 자료구조도 고려

## 2. optimization Backtracking

- 최적의 답안을 구해낼 때에도 Backtracking을 사용할 수 있다.

## 3. General Skeleton

```cpp
///////////////////////////// non-optimization Backtracking /////////////////////////////

// DFS 수행
void checknode (node P){
  node C; 
  if(promising(C)){
    if(solution at P){
      write the solution
    }
    else{
      for(each child C of P)
        checknode(C);
    }
  }
}

// promising 함수
bool promising(index i){
  // 문제 조건에 따라 내용이 달라진다.
}

///////////////////////////// optimization Backtracking /////////////////////////////

// DFS 수행
void checknode (node Parent){
  if(value(Parent) > BestValue){
    BestValue = value(Parent)
  }
  if(promising(Parent)){
    for(each child C of Parent)
      checknode(C);
  }
}

// promising 함수

// value 함수
```

## Backtracking vs Greedy

||Backtracking|Greedy|
|:---:|:---:|:---:|
|공통점|constraint에 부합하는 solution을 단계마다 선택한다|constraint에 부합하는 solution을 단계마다 선택한다|
|차이점|이전 step으로 돌아갈 수 있다|이전 step으로 돌아갈 수 없다|
||이전 step들을 고려한다|현재 step만을 고려한다|

## Backtracking vs DFS

- Backtracking은 DFS + constraint이다.
- 즉, DFS로 그래프(엄밀히 말하면 state space tree)를 탐색하는데, promising한 노드의 경우에만 더 깊게 파고들어간다.

## 문제

### 1062.가르침

- DFS를 통해서 가르칠 수 있는 범위 내의 문자들을 싹다 고른다. -> 그 후 해당 문자들을 바탕으로 읽어낼 수 있는 단어가 몇개인지 파악한다.
- promising한 부분만을 골라내어 prune 하는 과정이 존재하지 않는다. (DFS에 더 가깝다고 생각.)

### 1133.반복되지 않는 단어

- **State Space Tree / DFS** : 알파벳 트리 / 알파벳 트리를 깊이 우선 탐색하면서 만들 수 있는 모든 문자열의 경우
- **Pruning(constraint) / Promising** : 문자열에서 K번 중복된 부분이 등장하는 경우
