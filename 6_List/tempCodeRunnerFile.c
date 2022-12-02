#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum level { freshman = 1, sophomore, junior, senior };  // 학년
struct student {		// 학생 정보를 저장할 구조체 모양
	char name[20];		// 이름
	enum level year;	// 학년
	int score;			// 점수
	struct student* next;	// 다른 학생을 가리킬 포인터
};

typedef struct student STUDENT;	// 닉네임 정의

STUDENT * buildClass(STUDENT* list)  {

    while(1){
        STUDENT *std = (STUDENT*)malloc(sizeof(STUDENT));
        printf("학생 정보 (이름 학년 점수): ");

        scanf("%s", std->name);
        int x;
        scanf("%d", &x);
        if(x==1){
            std->year = freshman;
        }
        else if(x==2){
            std->year = sophomore;
        }
        else if(x==3){
            std->year = junior;
        }
        else if(x==4){
            std->year = senior;
        }
        scanf("%d", &std->score);
        if(!(strcmp(std->name, "끝") && std->year && std->score))
            break;
        std->next = list;
        list = std;
    }
    return list;

}

void printClass(STUDENT* list) { 
    printf("\n");
    printf("** 학생 리스트 출력 **\n");
    for(STUDENT *p = list; p!=NULL; p=p->next){
        printf("%s : %d학년, %d점\n", p->name, p->year, p->score);
    }
    printf("\n");
  }
	
void printStudent(STUDENT* list, char* p) {
    for(STUDENT *std = list; std!=NULL; std = std->next){
        if(!strcmp(p,std->name)){
            printf("%s : %d학년, %d점\n", std->name, std->year, std->score);
        }
    }
    printf("\n");
}
	
void findStudents(STUDENT* list, int low, int high) {
    printf("*** %d점과 %d점 사이의 학생 정보 ***\n", low, high);
    for(STUDENT *std = list; std!=NULL; std = std->next){
        if(std->score >= low && std->score <= high){
            printf("%s : %d학년, %d점\n", std->name, std->year, std->score);
        }
    }
    printf("\n");
}
	
void printFour(STUDENT* list) {
    printf("*** 4학생들의 이름 ***\n");
    STUDENT* p;
    p=list;
    printf("%s\n", p->name);
    printf("%s\n", p->next->name);
    printf("%s\n", p->next->next->name);
    printf("%s\n", p->next->next->next->name);
    printf("\n");
}	

int main() {
	STUDENT* list = NULL;
	list = buildClass(list);
	printClass(list);
	printStudent(list, "윤이화");
	findStudents(list, 70, 80);
	printFour(list);
	return 0;
}