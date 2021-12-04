# Branch and Bound

- Breadth First Search + fixed traversal + pruning
- Best First Search + flexible traversal + pruning

## 1. For optimization problem

- **optimizaiton problem을 해결하기 위해** 사용된다.
- **state-space-tree를 사용**하지만, **traversal order가 미리 정해져있지 않다.**
  - running time에 다음으로 방문할 노드가 결정된다.
  - 이를 통해서 backtracking 보다 time complexity가 좋은 이유가 여기서 발생한다.
- **BFS(Best First Search) + Pruning 을 사용한다.**
- **promising function이 numerical value를 내놓는다.**
  - backtracking 은 DFS 로 타고 들어가서 + 여지껏 찾은 max value 와 bound를 비교한 boolean return
  - branch&bound 는 BFS 로 타고 들어가서 + bound의 의미를 갖는 numeric return 하면, max value와 비교함
    - bound value < max value 라면 non-promising
    - bound value > max value 라면 promising

## 2. Backtracking vs Branch And Bound (Best/Breadth)

 |Backtracking|Branch and Bound|
 |:---:|:---:|
 |use state-space-tree|use state-space-tree|
 |optimization, non-optimization|optimization|
 |DFS + Pruning|BFS(Best / Breadth First Search) + Pruning|
 |fixed traversal|flexible / fixed traversal|
 |predetermined traversal에서 오는 비효율성| runtime에 결정, child 방문 최소화 / predetermined traversal, child 방문의 비효율성|
 |promising function return Boolean|promising function return numeric|

## 3. 0-1Knapsack and Branch And Bound

### 3.1 breadth first search + branch and bound pruning

- fixed order traversal
  - child를 방문할 때 비효율성이 발생한다.
  - predetermined traversal order가 비효율성을 발생시킨다.

- general pseudo code

```cpp
// T 로 root 건넴, best 로 initialize 된 best solution 받음
void BAB(state_space_tree T, number & best){
    queue Q;
    node c, p = root of T;
    Q.enqueue(p);
    visit p;
    while(!Q.isempty()){
        p = Q.dequeue();
        for (child c under p){
            // c까지 고려했을 때 도출할 수 있는 solution 이 현재 있는 것 보다 낫다
            if (value(c) better than best) best = value(c);
            // 현재 있는 solution 보다 더 멀리까지 고려할 수 있다면 enqueue
            if (bound(c) better than best) Q.enqueue(c);
        }
    }
}
```

- 0-1 knapsack pseudo code

```cpp
struct node{
    int level;
    int profit;
    int weight;
};

// p[]와 w[]는 p/w 내림차순(단위무게당 가치 내림차순)으로 각각 정렬된 상태
void knapsack2(int n, const int p[], const int w[], int w, int &maxprofit){
    queue Q;
    node c, p;
    p.level = 0; p.profit = 0; p.weight = 0;
    Q.enqueue(p);
    // bound를 통해서 queue에 넣을지 말지
    while(!Q.isempty()){
        // p 를 queue에서 뽑아내고, p 의 자식인 c를 새로 생성한다.
        p = Q.dequeue();
        c.level = p.level + 1; 
        c.profit = p.profit + p[c.level]; 
        c.weight = w.weight + w[c.level];
        // if (value(c) better than best + under w constraint)
        if (c.value > maxprofit && c.weight <= W>) maxprofit = c.profit;
        // if (bound(c) better than best) - c를 고른경우
        if (bound(c) > maxprofit) Q.enqueue(c);
        // if (bound(c) better than best) - c를 안골라서 level은 올라가는데, weight, profit이 안변한 경우
        c.weight = p.weight;
        c.profit = p.profit;
        if (bound(c) > maxprofit) Q.enqueue(c);
    }
}

```

### 3.2 Best First Search + branch and bound pruning

- flexible order traversal
  - checking children 하면서 낭비되는 시간을 줄일 수 있다.
  - 가장 좋은 bound value 갖는 node를 선택하여 확장함으로써 Best First Search가 가능해진다.

- general pseudo code

```cpp
void BAB(tree T, number &best){
    priority_queue pq;
    node c, p = T.root;
    pq.enqueue(p);
    best = value(p);
    while(!pq.isempty()){
        // 가장 좋은 bound value 갖는 node를 뽑아 낸다.
        p = pq.dequeue();
        // p node가 promising 하다면 확인, 그렇지 않다면 넘어감
        if(bound(p) is better than best){
            for(child c under p){
                if(value(c) is better than best) best = value(c);
                if(bound(c) is better than best) pq.enqueue(c);
            }
        }
    }
}
```

- 0-1 knapsack pseudo code

```cpp
struct node{
    int level;
    int profit;
    int weight;
    int bound;
};

// p[]와 w[]는 p/w 내림차순(단위무게당 가치 내림차순)으로 각각 정렬된 상태
void knapsack3(int n, int p[], int w[], int W, int &maxprofit){
    priority_queue pq;
    node c, p;
    maxprofit = 0;
    p.level = 0; p.profit = 0; p.weight = 0; p.bound = bound(p);
    // bound를 통해서 deque에서 꺼냈을 때 고려할 지 말지
    while(!pq.isempty()){
        // 가장 큰 bound value 갖는 node를 뽑아낸다.
        p = pq.dequeue();
        if (maxprofit < p.bound){
            c.level = p.level + 1;
            c.weight = p.weight + w[c.level];
            c.profit = p.profit + p[c.level];
            // if(value(c) is better than best) - c 를 고른 경우
            if (c.profit > maxprofit && W >= c.weight) maxprofit = c.profit;
            c.bound = bound(c);
            // if(value(c) is better than best) - c 를 고른 경우
            if (c.bound > best) pq.enqueue(c);
            // if(bound(c) is better than best) - c를 안골라서 level은 올라가는데, weight, profit 그대로
            p.level += 1;
            p.bound = bound(p);
            if (p.bound > best) pq.enqueue(p);
        }
    }
}
```

## 4. Dijkstra and Branch And Bound

```cpp

vector<edge> Edges[805];

// Dijkstra : 갱신된 edge들 기준으로 다시 갱신
ll Dijkstra(int s, int e) {

    ll path[803];
    priority_queue<edge> nextE;
    
    for (int i = 0; i < 803; ++i) path[i] = INF;
    path[s] = 0;
    nextE.push({ 0, s });
    
    while (!nextE.empty()) {
        
        edge e = nextE.top(); nextE.pop();
        if (path[e.second] < -e.first) continue;
        for (int i = 0; i < Edges[e.second].size(); ++i) {
            if (path[Edges[e.second][i].second] > path[e.second] - Edges[e.second][i].first) {
            path[Edges[e.second][i].second] = path[e.second] - Edges[e.second][i].first;
            nextE.push({ -path[Edges[e.second][i].second], Edges[e.second][i].second });
            }
        }
    }

    return path[e];

}
```