/* Direction: Write a student record program using parallel arrays with the following menu options:
    1. Add a student record
    2. Delete a student record
    3. Display all student records
    4. Exit
    Written by: Rain Sidney G. ALberto
    Date: 02/12/25
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant
#define MAX 5

// Global Variables
char name[MAX][50];
float q1[MAX], q2[MAX], q3[MAX];
int last = -1;

// User-Defined Function Prototypes
int menu();
int isfull();
void add ();
int isempty();
void del ();
float getaverage (float q1, float q2, float q3);
int display();

int main ()
{
    while (1)
    {
        switch (menu())
        {
            case 1:
                system("cls");
                add ();
                break;
            case 2:
                system("cls");
                del();
                break;
            case 3:
                system("cls");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Try again!\n");
                system("pause");
        }
        
    }
    return 0;
}

// Function Definitions
int menu()
{
    int options;
    system("cls");
    printf("==========Menu=========\n");
    printf("1. Add student info\n");
    printf("2. Delete student info\n");
    printf("3. Display student info\n");
    printf("4. Exit\n");
    printf("\nSelect an option: ");
    scanf("%d", &options);
    return options;
}
int isfull()
{
    if (last == MAX - 1)
        return 1;
    else
        return 0;
}
void add ()
{
    if (isfull())
    {
        printf("The array is full!\n");
        system("pause");
    }
    else
    {
        last++;
        printf("Input a name: ");
        scanf(" %[^\n]", &name[last]);
        printf("Input Quiz 1: ");
        scanf("%f", &q1[last]);
        printf("Input Quiz 2: ");
        scanf("%f", &q2[last]);
        printf("Input Quiz 3: ");
        scanf("%f", &q3[last]);
        getchar();
    }
}
int isempty()
{
    return (last == -1);
}   
void del ()
{
    char ID[50];
    printf("Enter the name of the student to delete: ");
    scanf(" %[^\n]", &ID);
    getchar();

    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        for (int i = 0; i <= last; i++)
        {
            if (strcmp(ID, name[i]) == 0)
            {
                for (int j = i; j < last; j++)
                {
                    strcpy(name[j], name[j + 1]);
                    q1[j] = q1[j + 1];
                    q2[j] = q2[j + 1];
                    q3[j] = q3[j + 1];
                }
                last--;
                break;
            }
        }
    }
}
float getaverage (float q1, float q2, float q3)
{
    return (q1 + q2 + q3) / 3.00;
}
int display()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        float ave;
        printf("   NAME    \tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
        for (int i = 0; i <= last; i++)
        {
            ave = getaverage(q1[i], q2[i], q3[i]);
            printf("%d.) %s    \t%.2f\t%.2f\t%.2f\t%6.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave,ave>=75.0? "PASSED\n":"FAILED");
        }
        system("pause");
        return 0;
    }
}