#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getIntRange(char* StringInformation, int frontLimit, int rearLimimt);
int getInt(char* informationString);
void getStringByAddress(char* informationString, char* inputAddr);
double getDouble(char* informationString);
char getChar(char* informationString);


char getGrade(double inputValue);




/**************465p. Part 03************/

//void swap(int* dest, int* source){
//
//    //int tmp;
//
//    //printf("%d %d\n", *q1,  *q1);
//
//    //tmp = *dest;
//    *dest = *source;
//    //*source = tmp;
//}
//
//
//int main() {
//
//    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//    int toChangeArray[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//
//    int i = 0;
//
//    for(i = 0; i < 7; i++){
//
//        (i < 6) ? (swap((toChangeArray + (i +1)), (array +i))) : (swap((toChangeArray +i), (array +i)));
//    }
//    *(toChangeArray) = *(array +7);
//
//    for(i = 0; i < 7; i++){
//
//        printf("\n%d", *(toChangeArray + i));
//    }
//    return 0;
//}






/***********532p. Part 02*******************/

//struct StudentIdentity{
//
//    int personId;
//    double personSlight;
//    int personWeight;
//    char personBlood;
//
//}; typedef struct StudentIdentity Student;
//
//
//int main(){
//
//    int i = 0, bufferInt = 0;
//    double bufferDouble = 0.0;
//    char bufferChar;
//    Student student[5] = {{0, 0.0, 0, 0}, {}};
//
//
//    for(i = 0; i < 5; i++) {
//
//        puts("Enter ID");
//        scanf("%d", &bufferInt);
//        student[i].personId = bufferInt;
//
//        puts("Enter Weight");
//        scanf("%d", &bufferInt);
//        student[i].personWeight = bufferInt;
//
//        puts("Enter Slight");
//        scanf("%lf", &bufferDouble);
//        student[i].personSlight = bufferDouble;
//
//        puts("Enter Blood type");
//        gets(&bufferChar);
//
//        strcpy(&student[i].personBlood, &bufferChar);
//    }
//
//    for(i = 0; i < 5; i++){
//        printf("%d %c %.2lf %d\n", student[i].personId, student[i].personBlood, student[i].personSlight, student[i].personWeight);
//    }
//
//    return 0;
//}



/******************532p. Part 04********************/


//struct ExampleObject{
//
//    int x;
//    int y
//
//}; typedef struct ExampleObject Object;
//
//
//void showObj(Object* sp){ printf("point -> %d", *sp); }
//
//
//int main(){
//
//    Object s1 = {10, 10};
//
//    showObj(&s1);
//
//    return 0;
//}


/************532p. Part07******************/

//struct Node {
//
//    int data;
//    struct Node* link;
//
//}; typedef struct Node DataNode;
//
//
//
//int main(){
//
//    DataNode node[3] = {{10, NULL}, {}};
//
//
//    int i = 0;
//
//
//
//    node[0].link = (node +1);
//    node[1].link = (node +2);
//    node[2].link = (node);
//
//    node[0].data = 10;
//    node[1].data = 20;
//    node[2].data = 30;
//
//
//
//    for(i = 0; i < 3; i++){
//
//        printf("node[%d] : %d\n", i , node[i].data);
//        printf("node[%d] -> %d\n", i, node[i].link);
//    }
//
//
//    return 0;
//}




/*************** REQUEST ********************/


#define INIT_LIMIT_REAR 4

#define LIMIT_STUDENT_REAR 19


const double UNIT_TO_SUBJECT_AVG = 3.0;


/**************************

*   INIT_LIMIT_REAR
    personName의 길이,
    NULL을 위해 3자리만 쓰자!

*   LIMIT_STUDENT_REAR
    입력받을 최대 학생 수.

*   UNIT_TO_SUBJECT_AVG
    pointAvg를 계산하기 위해 사용하는 상수
    촘점의 평균을 구하기 위한 수식.

**************************/


struct StudentIdentity{

	char personName[INIT_LIMIT_REAR];
	int personId;
	int personGender;

	int pointNation;
	int pointEnglish;
	int pointMath;
	int pointTotal;
	double pointAvg;
	char pointGrade;

}; typedef struct StudentIdentity Student;

/*********************************

    StudentIdentity Student[]

*   PersonName[4]   학생의 이름 3자리.
*   PersonId        학생의 학번 1000 ~ 9999
*   PersonGender    학생의 성별 0 ~ 1

*   pointNation     국어 점수
*   pointEnglish    영어 점수
*   pointMath       수학 점수
*   pointTotal      3과목의 총점

*   pointAvg        촘정의 평균.
                    UNIT_TO_SUBJECT_AVG 와 연계.
*   pointGrade      점수의 등급
                    getGrade(Double Avg)와 연계.

**********************************/


void setStudentIdentity(Student* student, int index);
void setRandStudentIdentity(Student* student, int limitRear);
void showStudentIdentity(Student* student, int index);
void showStudentIdentityAll(Student* student, int limitRear);
void sortStudentIdentityAsc(Student* student, int limitRear);
void sortStudentIdentityDESC(Student* student, int limitRear);
void selectStudentIdentityByName(Student* student, char* toTargetName, int limitRear);
void deleteStudentIdentityByName(Student* student, char* toTargetName, int limitRear);
void insertStudentIdentityByName(Student* student, char* toTargetName, int limitRear);




int main(){

    Student student[LIMIT_STUDENT_REAR] = {{"", 0, 0, 0, 0, 0, 0, 0.0, 0 }, {}};

    int isLoop = 0, action = 0;
    int limitStudentRear = 0;
    char toTargetName[INIT_LIMIT_REAR] = "";

    srand( time( NULL));


    limitStudentRear = getIntRange("처리할 학생수", 0, LIMIT_STUDENT_REAR);


    while(!isLoop){

        printf("\n1. 학생 초기화\n");
        printf("2. 학생 출력\n");
        printf("3. 학생 정렬\n");
        printf("4. 학생 삽입\n");
        printf("5. 학생 삭제\n");
        printf("6. 학생 조회\n");
        printf("7. 화면 초기화\n");
        printf("0. 프로그램 종료\n");
        action = getInt("--> ");

        switch(action){

            case 1: system("cls"); setRandStudentIdentity(student, limitStudentRear);break;
            case 2: system("cls"); showStudentIdentityAll(student, limitStudentRear); break;
            case 3: system("cls"); action = getIntRange("ASC: 1 DESC: 0", 0, 1);
                                    (action) ?
                                    (sortStudentIdentityAsc(student, limitStudentRear)) :
                                    (sortStudentIdentityDESC(student, limitStudentRear));
                                    break;

            case 4: system("cls");  getStringByAddress("Enter name to insert", toTargetName);
                                    insertStudentIdentityByName(student, toTargetName, limitStudentRear);
                                    break;

            case 5: system("cls"); getStringByAddress("Enter name to delete", toTargetName);
                                    deleteStudentIdentityByName(student, toTargetName,limitStudentRear);
                                    break;

            case 6: system("cls"); getStringByAddress("Enter name to search", toTargetName);
                                    selectStudentIdentityByName(student, toTargetName, limitStudentRear);
                                    break;
            case 7: system("cls");  break;
            case 0: isLoop = 1;     break;

        default:    ;
        }
    }

    return 0;
}


/******* Print Student's member By Index ***********/

void showStudentIdentity(Student* student, int index){

    printf("%3s %4d %1c ", student[index].personName, student[index].personId,
            (student[index].personGender) ? ('M') : ('F'));
    printf("%3d %3d %3d ", student[index].pointNation, student[index].pointEnglish, student[index].pointMath);
    printf("%3d %.2lf %c\n", student[index].pointTotal, student[index].pointAvg, student[index].pointGrade);
}


/****** Print Student's member in Range ************/

void showStudentIdentityAll(Student* student, int limitRear){

    int i = 0;

    for(i = 0; i < limitRear; i++){

            showStudentIdentity(student, i);
    }
}


/***** Input Student Member to Index ******/

void setStudentIdentity(Student* student, int index){

        getStringByAddress("Enter Name", student[index].personName);
        student[index].personId = getIntRange("Enter Id", 1000, 9999);
        student[index].personGender = getIntRange("male:0 female: 1", 0, 1);

        student[index].pointNation = getIntRange("Enter Nation point", 0, 100);
        student[index].pointEnglish = getIntRange("Enter English Lang point", 0, 100);
        student[index].pointMath = getIntRange("Enter Math point", 0, 100);

        student[index].pointTotal = student[index].pointNation +
                                    student[index].pointEnglish +
                                    student[index].pointMath;

        student[index].pointAvg = student[index].pointTotal / UNIT_TO_SUBJECT_AVG;
        student[index].pointGrade = getGrade(student[index].pointAvg);
}

/**** _INIT_ student's members ****/

void setRandStudentIdentity(Student* student, int limitRear){

    int i = 0, j = 0;

    for(i = 0; i < limitRear; i++){

        for(j = 0; j < INIT_LIMIT_REAR -1; j++){

            student[i].personName[j] = (rand() % 26) + 'A';
        }

        student[i].personId = (rand() % 9000 - 1000) + 1001;
        student[i].personGender = rand() % 2;

        student[i].pointNation = rand() % 101;
        student[i].pointEnglish = rand() % 101;
        student[i].pointMath = rand() % 101;

        student[i].pointTotal     = student[i].pointNation +
                                    student[i].pointEnglish +
                                    student[i].pointMath;

        student[i].pointAvg = student[i].pointTotal / UNIT_TO_SUBJECT_AVG;
        student[i].pointGrade = getGrade(student[i].pointAvg);
    }
}

/**** Select * From Student WHERE name ****/

void selectStudentIdentityByName(Student* student, char* toTargetName, int limitRear){

    int i = 0;

    for(i = 0; i < limitRear; i++){
        if(stricmp(student[i].personName, toTargetName) == 0){

            showStudentIdentity(student, i);
            return;
        }
    }
    printf("===can not find to go!!!===\n");
    return;
}

/**** Insert * From Student Where name ****/

void insertStudentIdentityByName(Student* student, char* toTargetName, int limitRear){

    int i = 0;

    for(i = 0; i < limitRear; i++){
        if(stricmp(student[i].personName, toTargetName) == 0){

            setStudentIdentity(student, i);
            return;
        }
    }
    printf("===can not find to go!!!===\n");
    return;
}

/**** delete * From Student Where name ****/

void deleteStudentIdentityByName(Student* student, char* toTargetName, int limitRear){

    int i = 0;

    for(i = 0; i < limitRear; i++){
        if(stricmp(student[i].personName, toTargetName) == 0){

            strcpy(student[i].personName, "");
            student[i].personId = 0;
            student[i].personGender = 0;

            student[i].pointNation = 0;
            student[i].pointEnglish = 0;
            student[i].pointMath = 0;

            student[i].pointTotal = 0;
            student[i].pointAvg = 0.0;
            student[i].pointGrade = 0;
            return;
        }

    }

    printf("===can not find to go!!!===\n");
    return;
}

/**** Sort SELECTION ASC Students by member's totalPoint *****/

void sortStudentIdentityAsc(Student* student, int limitRear){

    int i = 0, j = 0;
    Student buffer;


    for(i = 0; i < limitRear -1; i++){
        for(j = i +1; j < limitRear; j++){

            if(student[i].pointTotal < student[j].pointTotal){

                memcpy(&buffer,        &student[i],    sizeof(student[i]));
                memcpy(&student[i],    &student[j],    sizeof(student[i]));
                memcpy(&student[j],    &buffer,        sizeof(student[i]));
            }
        }
    }
}

/**** Sort SELECTION DESC Students by member's totalPoint *****/

void sortStudentIdentityDESC(Student* student, int limitRear){

    int i = 0, j = 0;
    Student buffer;


    for(i = 0; i < limitRear -1; i++){
        for(j = i +1; j < limitRear; j++){


            if(student[i].pointTotal > student[j].pointTotal){

                memcpy(&buffer,        &student[i],    sizeof(student[i]));
                memcpy(&student[i],    &student[j],    sizeof(student[i]));
                memcpy(&student[j],    &buffer,        sizeof(student[i]));
            }
        }
    }
}
