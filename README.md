#README.md 

#  학생 인적사항을 간단하게 정리하는 C프로그램.



#### 학생들의 인적사항을 간단하게 관리할 수 있다.
#### 기능은, 학생들 입력 / 정렬 / 수정 / 삭제/ 초기화 가 있다.



```
StudentIdentity Student
      personName 학생의 이름 	범위는 영문3자리
 	    personId   학생의 학번 	범위는 1000 ~ 9999
 	    personGender 학생의 성별, 0은 남성 / 1은 여성으로 취급.


 	    pointNation 국어 점수 	범위는 0 ~ 100	
 	    pointEnglish 영어 점수 	범위는 0 ~ 100
 	    pointMath 수학 점수 	범위는 0 ~ 100
 	    pointSum 3과목 총점.
 	    pointAvg 3과목 평균.
 	    pointGrade 평균 점수와 연계되는 등급. getGrade(double )에 의해 값이 정해진다.
```


# 상수 정의
```
#define INIT_LIMIT_REAR 4 
  personName(학생 이름)의 길이는 4다
  다만, NULL을 위해 3자리만 사용한다.



#define LIMIT_STUDENT_REAR 19 
  관리할 최대 학생 수 제한. 



const double UNIT_TO_SUBJECT_AVG = 3.0
  평균값을 구하는데 사용한다. 과목이 3개니까 3.0
```



# 사용하는 변수
```
int limitStudentRear
   실제로는 얼마나 학생수를 관리할지 결정하는 변수이다. 
   인덱스 관리 시 함수 매개변수명이 "limitRear"거든 이거를 넘겨주면 모든 학생을 대상으로 한다.
```

#함수 기능
```
void showStudentIdentity(Student* student, int index)
  해당 인덱스의 학생 정보를 전부 출력
```

```
void showStudentIdentityAll(Student* student, int limitRear)
  Student의 학생을 인덱스 0부터 limitRear까지 출력...
```

```
void setStudentIdentity(Student* student, int index)
  해당 인덱스의 학생의 맴버 값을 키보드로 입력 받는다.
```

```
void setRandStudentIdentity(Student* student, int limitRear)
  Student의 값들을 인덱스 0부터 limitRear까지 난수화....Student를 모두 난수화 한다.
```

```
void selectStudentIdentityByName(Student* student, char* toTargetName, int limitRear)
  학생의 이름을 입력받아서 인덱스 0부터 limitRear까지 검색한다.
#### 만약 있다면 해당 인덱스의 Student정보를 출력하고 없으면 오류 msg출력.
```

```
void insertStudentIdentityByName(Student* student, char* toTargetName, int limitRear)
  학생의 이름을 입력받아서 인덱스 0부터 limitRear까지 검색한다.
  만약 있다면 해당 인덱스의 Student 값을 키보드로 전부 입력받는다.
```

```
void deleteStudentIdentityByName(Student* student, char* toTargetName, int limitRear)
  학생의 이름을 입력받아서 인덱스 0부터 limitRear까지 검색한다.
  만약 있다면. 해당 인덱스의 Studnet 값을 0으로 밀어버린다.
```

```
void sortStudentIdentityAsc(Student* student, int limitRear)
  학생들의 pointSum( 총점 )을 기준으로 순서를 오름차순으로 정렬한다. 따라서 인댁스도 바뀐다.
```

```
void sortStudentIdentityDesc(Student* student, int limitRear)
  학생들의 pointSum( 총점 )을 기준으로 순서를 내림차순으로 정렬한다. 따라서 인댁스도 바뀐다.
```



```
char getGrade(double avg)
  avg값에 따라 A / B / C / D / F 값을 리턴한다.
  avg 100 ~ 90 이면 A
  avg 89 ~ 80 이면 B
  avg 79 ~ 70 이면 C
  avg 69 ~ 60 이면 D
  그 미만은 F를 리턴한다.
```
