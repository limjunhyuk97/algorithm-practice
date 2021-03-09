# Complexity (Time and Space)

## Space complexity
  - **S(p) = c + Sp(I)**
  - **Total space requirement S(p)**
    - **전체 공간**
  - **Fixed space requirement (c)**
    - **고정 공간**
    - instruction space
    - space for simple variable
    - fixed size structured variables and constants
  - **Variable space requirement (Sp(I))**
    - **내가 풀고자 하는 문제의 특정 인스턴스에 의존하는 크기를 가진 구조와 변수를 위해 필요한 공간 (인스턴스에 따른 공간)**
    - structured variables whose size depends on the particular instance of the problem
    - recursive algorithm (**because of implicit stack**)

![space complexity](https://user-images.githubusercontent.com/59442344/110459465-59252b00-8110-11eb-9530-d194fad4199d.png)
![space complexity_2](https://user-images.githubusercontent.com/59442344/110459470-5b878500-8110-11eb-81d4-653fe83d4be3.png)

## Time complexity
  - **Time taken = compile time + run time**
  - **run time ~= number of operations**
    - calculating number of operations : **tabular method**
    - **total steps = (sum of) (frequency * step count)**

![time complexity](https://user-images.githubusercontent.com/59442344/110460634-cd140300-8111-11eb-83f7-3fc941d207ef.png)
