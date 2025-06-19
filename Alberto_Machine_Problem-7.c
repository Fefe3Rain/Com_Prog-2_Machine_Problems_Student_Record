// Rain Sidney G. Alberto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct person{
    char name[31];
    int q1, q2, q3;
} REC;

REC stude[MAX];
int last;

void init();
int isfull();
int isempty();
int menu();
void upload();
void download();
void add(REC x);
void update();
int updatemenu();
void delete();
void display();

int main ()
{
    REC data;
    init();
    download();
    while (1)
    {
        switch(menu())
        {
            case 1:
                system("cls");
                printf("Input Name: ");
                scanf(" %[^\n]", data.name);
                printf("Input Quiz 1: ");
                scanf("%d", &data.q1);
                printf("Input Quiz 2: ");
                scanf("%d", &data.q2);
                printf("Input Quiz 3: ");
                scanf("%d", &data.q3);
                add(data);
                break;
            case 2:
                system("cls");
                update();
                break;
            case 3:
                system("cls");
                delete();
                break;
            case 4:
                system("cls");
                display();
                break;
            case 5:
                upload();
                printf("Thank you for using my program.\n");
                exit(0);
            default:
                printf("1 to 4 only.\n");
                system("pause");
        }
    }
    return 0;
}
void init()
{
    last = -1;
}
int isfull()
{
    return (last == MAX-1);
}
int isempty()
{
    return (last == -1);
}
int menu()
{
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add a record\n");
    printf("2. Update a record\n");
    printf("3. Delete a record\n");
    printf("4. Display all\n");
    printf("5. Save and Exit\n");
    printf("\nSelect(1-6): ");
    scanf("%d", &op);
    return op;
}
void upload()
{
    FILE *fp;
    fp = fopen("it1a25.txt", "w+");
    if (fp == NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
        return;
    }
    else
    {
        for (int i = 0; i <= last; i++)
            fprintf(fp, "%s\n%d\n%d\n%d\n", stude[i].name, stude[i].q1, stude[i].q2, stude[i].q3);
    }
    fclose(fp);
}
void download()
{
    REC r;
    FILE *fp = fopen("it1a25.txt","r+");
    if (fp==NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
        return;
    }
    else
    {
        while(fscanf(fp, " %[^\n]\n%d\n%d\n%d\n", r.name, &r.q1, &r.q2, &r.q3) != EOF)
            add(r);
    }
    fclose(fp);
}
void add(REC x)
{
    if (isfull())
    {
        printf("Array is full.\n");
        system("pause");
        return;
    }
    last++;
    stude[last] = x;
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
void update()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
        return;
    }
    else
    {
        char id[31];
        printf("Enter a name: ");
        scanf(" %[^\n]", id);
        getchar();
        for (int i = 0; i <= last; i++)
        {
            if (strcmp(stude[i].name, id) == 0)
            {
                while (1)
                {
                    switch (updatemenu())
                    {
                        case 1:
                            system("cls");
                            printf("Input Quiz 1: ");
                            scanf("%d", &stude[i].q1);
                            break;
                        case 2:
                            system("cls");
                            printf("Input Quiz 2: ");
                            scanf("%d", &stude[i].q2);
                            break;
                        case 3:
                            system("cls");
                            printf("Input Quiz 3: ");
                            scanf("%d", &stude[i].q3);
                            break;
                        case 4:
                            system("pause");
                            return;
                        default:
                            printf("1 to 4 only.\n");
                            system("pause");
                    }
                }
            }
        }
    }
}
void delete()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        char id[31];
        printf("Enter a name: ");
        scanf(" %[^\n]", id);
        getchar();
        for (int i = 0; i <= last; i++)
        {
            if (strcmp(stude[i].name, id) == 0)
            {
                for (int j = i; j < last; j++)
                {
                    stude[j] = stude[j + 1];
                }
                last--;
                break;
            }
        }
    }
}
void display ()
{
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
        return;
    }
    else
    {
        float ave;
        printf("   NAME\t\t\tQuiz1\tQuiz2\tQuiz3\tAverage\tRemarks\n");
        for (int i = 0; i <= last; i++)
        {
            ave = (stude[i].q1 + stude[i].q2 + stude[i].q3) / 3;
            printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t%s\n", i+1, stude[i].name, stude[i].q1, stude[i].q2, stude[i].q3, ave, ave >= 75.0 ? "PASSED" : "FAILED");
        }
        system("pause");
    }
}