# Jun's Algoritm space

### Hoarding my problem solving techniques

### Daily scrum
  - **Greedy**
    - 각 단계의 최선의 선택이 최적의 선택
    - 1931: 종료지점이 이른 것을 고르는 것이 가장 최선
  - **DP를 언제 도입해야 할까?** 
    - knapsack problem (DP)
    - DP -> 점화식 -> 행렬 표현 -> Divide & Conquer
    - 9251: 최장 공통 문자열, str2 문자 하나씩 str1 문자열에 비교
      - 같은 문자(이전 단계, 이전 문자 비교까지의 '최대치' + 1), 다른 문자(현 단계 이전문자, 이전 단계 현 문자 중 최대치)  
  - **Divide & Conquer를 언제 도입해야 할까?**
    - 거듭 제곱의 mod 연산 (divide&conquer)
    - 곱셈의 mod 연산
    - 나눗셈의 mod 연산 (divide&conquer / 페르마의 소정리)
    - 행렬 거듭제곱의 mod 연산 (divide&conquer)
    - 조합 연산의 방식들 (nCm = n-1Cm-1 + n-1Cm , n!/m!(n-m)!)
    - DP -> 점화식 -> 행렬 표현 -> Divide & Conquer
