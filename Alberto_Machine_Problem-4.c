// Rain Sidney G. Alberto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

char name[MAX][50];
int q1[MAX], q2[MAX], q3[MAX];
int last;

int menu();
void init();
int isfull();
void upload();
void download();
void add();
int isempty();
void del();
float getaverage(int q1, int q2, int q3);
int displayall();

int main ()
{
    init();
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
                del();
                break;
            case 3:
                system("cls");
                displayall();
                break;
            case 4:
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
int menu()
{
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add a record\n");
    printf("2. Delete a record\n");
    printf("3. Display all\n");
    printf("4. Save and Exit\n");
    printf("\nSelect(1-4): ");
    scanf("%d", &op);
    return op;
}
void init()
{
   last = -1;
}
int isfull()
{
    return (last == MAX-1);
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
        int i;
        for (i = 0; i <= last; i++)
        {
            fprintf(fp, "%s\n%d\n%d\n%d\n", name[i], q1[i], q2[i], q3[i]);
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
    init();

    while (fscanf(fp, " %[^\n]\n%d\n%d\n%d\n", name[last + 1], &q1[last + 1], &q2[last + 1], &q3[last + 1]) != EOF) 
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
        scanf("%d", &q1[last]);
        printf("Input Quiz 2: ");
        scanf("%d", &q2[last]);
        printf("Input Quiz 3: ");
        scanf("%d", &q3[last]);
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

        for (int i = 0; i < last; i++) 
        {
            for (int j = i + 1; j <= last; j++) 
            {
                if (strcmp(name[i], name[j]) > 0) 
                {
                    char temp[50];
                    strcpy(temp, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp);

                    int temp1 = q1[i];
                    q1[i] = q1[j];
                    q1[j] = temp1;

                    temp1 = q2[i];
                    q2[i] = q2[j];
                    q2[j] = temp1;

                    temp1 = q3[i];
                    q3[i] = q3[j];
                    q3[j] = temp1;
                }
            }
        }
    }
}
int isempty()
{
    return (last == -1);
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

        int i;
        for (i = 0; i <= last; i++)
        {
            if (strcmp(ID, name[i]) == 0)
            {
                int j;
                for (j = i; j < last; j++)
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
float getaverage(int q1, int q2, int q3)
{
    return ((float)q1 + (float)q2 + (float)q3) / 3;
}
int displayall() 
{
    if (isempty()) 
    {
        printf("The array is empty!\n");
        system("pause");
        return 0;
    } 
    else 
    {
        float ave;
        printf("   NAME\t\tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
        int i;
        for (i = 0; i <= last; i++) 
        {
            ave = getaverage(q1[i], q2[i], q3[i]);
            printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t%s\n", i + 1, name[i], q1[i], q2[i], q3[i], ave, ave >= 75.0 ? "PASSED" : "FAILED");
        }
        system("pause");
        return 0;
    }
}