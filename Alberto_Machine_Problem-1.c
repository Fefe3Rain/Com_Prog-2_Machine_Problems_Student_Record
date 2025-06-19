/* Directions: Write a student record program to use User-Defined Functions and Local Variables
    Written by: Rain Sidney G. ALberto
    Date: 02/10/25
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

float getaverage (float q1, float q2, float q3)
{
    return (q1 + q2 + q3) / 3.00;
}

int display (char name[MAX][50], float q1[MAX], float q2[MAX], float q3[MAX])
{
    float ave;
    system("cls");
    printf("   NAME\t\t\tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
    for (int i = 0; i < MAX; i++)
    {
        ave = getaverage(q1[i], q2[i], q3[i]);
        printf("%d.) %s\t\t%.2f\t%.2f\t%.2f\t%6.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave,ave>=75.0? "PASSED\n":"FAILED");
    }
    return 0;
}

void getinfo ()
{
    char name[MAX][50];
    float q1[MAX], q2[MAX], q3[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("Enter name: ");
        scanf("%[^\n]", &name[i]);
        printf("Enter Quiz 1: ");
        scanf("%f", &q1[i]);
        printf("Enter Quiz 2: ");
        scanf("%f", &q2[i]);
        printf("Enter Quiz 3: ");
        scanf("%f", &q3[i]);
        getchar();
    }
    display(name, q1, q2, q3);
}

int main ()
{
    getinfo();
    return 0;
}