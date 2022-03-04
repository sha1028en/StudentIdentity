#README.md 

/**************************************/
	
iValue
	액션 ( 플래그 ),
	학생을 얼마나 받을건가 ( 제한 있음! ) 
	학생 별 이름/나이/ID/, C/Java/Kotlin 점수 ( 제한 있음! )

Calc
	isLoop
	학생 이름/나이/ID/, C/Java/Kotlin 점수 ( 난수로! )
	3과목 총점 / 평군/ 등급

Ovalue
	학생 별 이름/나이/ID/, 
	C/Java/Kotlin 점수,
	3과목 총점 / 평군/ 등급

/*********************************************/

학생정보 구조체 원형정의

struct StudentIdentity{

	char personName[임계상수. 4자리];
	int personId;
	int personAge;


	int pointLangC;
	int pointLangJava;
	int pointLangKotlin;
	int pointTotal;
	double pointAvg;
	char pointGrade;

}; struct StudentIdentity Student;

/************************************************/

기능 정의
	
	- 학생 초기화 ( Calc: 난수 )
	- 학생 입력 ( Ivalue )
	- 학생 출력 ( Ovalue )
	- 학생 정렬 ( Calc: ASC/DESC by pointTotal )
	- 학생 삽입 ( Ivalue: by Name )
	- 학생 삭제 ( Ivaule: by Name )
	- 화면 초기화 ( system("cls"); )
	- 프로그램 종료 ( isLoop = 1; )

	- 최대 학생수 입력 / 제한 ( Ivalue )
	- 액션 입력 받기 ( Ivalue )
	

/************************************************/

상세 요구분석

	- personName은 3자리만 사용. 1자리는 null을 위해. 알파벳으로 채우자!
	- personId는 1000 ~ 9999
	- personAge는 20 ~ 40

	- C/Java/Kotlin 언어 점수는 0 ~ 100
	- 등급은 Avg값으로 계산. (A, B, C, D, F)

	- 일단 사용자 ( 액션 ) 정수 입력을 기다리다가
	해당 액션에 알맞는 값을 받으면 해당하는 번호의
	동작을 시행.

	- 프로그램 종료는 isLoop을 1로 바꿔서 종료.
	- 화면 초기화는 system("cls"); 을 사용.

	- 학생 초기화는 StudentIdentity의 값을 전부 임계값이 있는 난수로 저장한다!.

	- 입력은 인덱스 0부터 받을 학생 인원수까지 전부 일일이
	StudentIdentity를 입력받자!

	-정렬은 int( 0/1 )를 입력받아서 ASC/DESC 를 결정하자!
	정렬의 기준은 pointTotal 을 기준으로 전부 정렬한다!

	- 삭제/삽입 은 personName의 값을 기준으로 
	해당하는 인덱스를 찾으면 해당 인덱스의 StudentIdentity의 값을
	모두 입력받자.
	
	- 받을수 있는 학생수의 쵀대치는 19명으로, 이 수치를 초과할 수 없다.

/*******************************************************************/

