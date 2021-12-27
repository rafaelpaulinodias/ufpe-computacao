#include <stdio.h>

typedef struct t_student
{
    char name[20];
    double grade;
    int age;
} Student;

Student Students[5];

void Swap(double *n1, double *n2) {
    double aux= *n1;
    *n1 = *n2;
    *n2 = aux;
}

void SortGrades(Student v[], int n) {
    int min, p1, p2;
    for (p1=0; p1<n; p1++) {
        min = p1;
        for (p2=p1+1; p2<=n-1; p2++)
            if (v[p2].grade < v[min].grade) min = p2;
        Swap(&v[min].grade, &v[p1].grade);
    }
}

void ReadStudentList() {
    for(int i = 0; i < 5; i++) 
    scanf("%s %lf %d", Students[i].name, &Students[i].grade, &Students[i].age);
}

void PrintStudentsList() {
    for(int i = 0; i < 5; i++) 
    printf("%s %.2lf %d\n", Students[i].name, Students[i].grade, Students[i].age); 
}

int main() {
    ReadStudentList();
    SortGrades(Students, 5);
    PrintStudentsList();
    return 0;
}