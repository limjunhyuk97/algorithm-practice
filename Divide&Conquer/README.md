# Divide and Conquer

## 1. a^b 구하기
  - O(b)의 시간복잡도를 O(logb)의 시간복잡도로 단축시킬 수 있다.

```cpp
int powAB(int a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else if (b % 2 == 0) {
		int t = powAB(a, b / 2);
		return t * t;
	}
	else {
		return a * powAB(a, b - 1);
	}
}
```
