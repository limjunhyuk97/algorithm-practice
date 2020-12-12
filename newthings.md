# 내맘대로 정리! 그날 그날 새로운 것들

## 2020.12.11

- for문이 1억번 돌면 대략 1초

- for(; i<10; ++i) 처럼 초기값이 이미 설정되있다면 생략 가능

- for문 조건값 안에 서로 다른 두개의 조건을 넣을 수도 있다

- <algorithm> 헤더파일에 sort() 함수 이용하면 quicksort를 이용할 수 있다.
  
## 2020.12.12

- <string> 헤더파일 안에
  
  - int형을 string으로 바꿔주는 to_string() 함수가 있다.
  - substring은 배열의 부분을 뜯어서 반환한다.
```cpp
string str = to_string(123);
// 123을 문자열로 바꿈
```
```cpp
substr(str, 0, 5);
// str 문자열에서 index 0 부터 5만큼의 길이만큼 떼서 반환한다.
``` 
