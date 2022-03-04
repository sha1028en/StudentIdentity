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



/*************** REQUEST ********************/


#define INIT_LIMIT_REAR 4

#define LIMIT_STUDENT_REAR 19


const double UNIT_TO_SUBJECT_AVG = 3.0;


/**************************

*   INIT_LIMIT_REAR
    personName�� ����,
    NULL�� ���� 3�ڸ��� ����!

*   LIMIT_STUDENT_REAR
    �Է¹��� �ִ� �л� ��.

*   UNIT_TO_SUBJECT_AVG
    pointAvg�� ����ϱ� ���� ����ϴ� ���
    ������ ����� ���ϱ� ���� ����.

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

*   PersonName[4]   �л��� �̸� 3�ڸ�.
*   PersonId        �л��� �й� 1000 ~ 9999
*   PersonGender    �л��� ���� 0 ~ 1

*   pointNation     ���� ����
*   pointEnglish    ���� ����
*   pointMath       ���� ����
*   pointTotal      3������ ����

*   pointAvg        ������ ���.
                    UNIT_TO_SUBJECT_AVG �� ����.
*   pointGrade      ������ ���
                    getGrade(Double Avg)�� ����.

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


    limitStudentRear = getIntRange("ó���� �л���", 0, LIMIT_STUDENT_REAR);


    while(!isLoop){

        printf("\n1. �л� �ʱ�ȭ\n");
        printf("2. �л� ���\n");
        printf("3. �л� ����\n");
        printf("4. �л� ����\n");
        printf("5. �л� ����\n");
        printf("6. �л� ��ȸ\n");
        printf("7. ȭ�� �ʱ�ȭ\n");
        printf("0. ���α׷� ����\n");
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
