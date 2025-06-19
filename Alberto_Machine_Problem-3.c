/* Direction: Write the Student Record Program using Parallel arrays with the following menu:
    1. ADD A RECORD
    2. UPDATE A RECORD
    3. DELETE A RECORD
    4. DISPLAY ALL
    5. DISPLAY A RECORD 
    6. EXIT

    UPDATE FUNCTION
    Update Menu

        1. Quiz 1
        2. Quiz 2
        3. Quiz 3
        4. Exit
    
    Select (1-4):

    NOTE: DUPLICATE NAME ARE NOT ALLOWED

    Written by: Rain Sidney G. Alberto
    Date: 02/17/25
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
void upload();
void download();
void add();
int isempty();
int updatemenu();
int update();
void del();
float getaverage(float q1, float q2, float q3);
int displayall();
int display();

// Main Function
int main ()
{
    download();
    while (1)
    {
        switch (menu())
        {
            case 1: 
                system("cls"); 
                add(); 
                break;
            case 2:
                system("cls");
                update();
                break;
            case 3:
                system("cls");
                del();
                break;
            case 4:
                system("cls");
                displayall();
                break;
            case 5:
                system("cls");
                display();
                break;
            case 6:
                upload();
                printf("Record saved successfully!\n");
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
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add a record\n");
    printf("2. Update a record\n");
    printf("3. Delete a record\n");
    printf("4. Display all\n");
    printf("5. Display a record\n");
    printf("6. Save and Exit\n");
    printf("\nSelect(1-6): ");
    scanf("%d", &op);
    return op;
}
int isfull()
{
    if (last == MAX - 1)
        return 1;
    else
        return 0;
}
void upload()
{
    FILE *fp;
    fp = fopen("record.txt", "w");
    if (fp == NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
    }
    else
    {
        for (int i = 0; i <= last; i++)
        {
            fprintf(fp, "%s\n%.2f\n%.2f\n%.2f\n", name[i], q1[i], q2[i], q3[i]);
        }
    }
    fclose(fp);
}
void download()
{
    FILE *fp;
    fp = fopen("record.txt", "r");

    if (fp == NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
    }
    last = -1;

    while (fscanf(fp, " %[^\n]\n%f\n%f\n%f\n", &name[last + 1], &q1[last + 1], &q2[last + 1], &q3[last + 1]) != EOF)
    {
        last++;
    }

    fclose(fp);
}
void add()
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

        for (int i = 0; i < last; i++)
        {
            if (strcmp(name[last], name[i]) == 0)
            {
                printf("Duplicate name is not allowed!\n");
                last--;
                system("pause");
                break;
            }
        }
    }
}
int isempty()
{
    return (last == -1);
}
int updatemenu()
{
    int op;
    system("cls");
    printf("Update Menu\n");
    printf("1. Quiz 1\n");
    printf("2. Quiz 2\n");
    printf("3. Quiz 3\n");
    printf("4. Exit\n");
    printf("\nSelect(1-4): ");
    scanf("%d", &op);
    return op;
}
int update()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        char ID[50];
        printf("Enter a name: ");
        scanf(" %[^\n]", &ID);
        getchar();

        for (int i = 0; i <= last; i++)
        {
            if (strcmp(ID, name[i]) == 0)
            {
                while (1)
                {
                    switch (updatemenu())
                    {
                        case 1:
                            system("cls");
                            printf("Input Quiz 1: ");
                            scanf("%f", &q1[i]);
                            break;
                        case 2:
                            system("cls");
                            printf("Input Quiz 2: ");
                            scanf("%f", &q2[i]);
                            break;
                        case 3:
                            system("cls");
                            printf("Input Quiz 3: ");
                            scanf("%f", &q3[i]);
                            break;
                        case 4:
                            system("pause");
                            return 0;
                        default:
                            printf("Try again!\n");
                            system("pause");
                    }
                }
            }
        }
    }
}
void del()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        char ID[50];
        printf("Enter a name: ");
        scanf(" %[^\n]", &ID);
        getchar();

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
float getaverage(float q1, float q2, float q3)
{
    return (q1 + q2 + q3) / 3;
}
int displayall()
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
int display()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        char ID[50];
        printf("Enter a name: ");
        scanf(" %[^\n]", &ID);
        getchar();

        for (int i = 0; i <= last; i++)
        {
            if (strcmp(ID, name[i]) == 0)
            {
                float ave = getaverage(q1[i], q2[i], q3[i]);
                printf("   NAME    \tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
                printf("%d.) %s    \t%.2f\t%.2f\t%.2f\t%6.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],ave,ave>=75.0? "PASSED\n":"FAILED");
                system("pause");
                break;
            }
        }
    }
    return 0;
}