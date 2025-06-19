#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 5

char name[MAX][31];
int age[MAX];
int last;

int menu();
void init();
int isfull();
void upload();
void download();
void add(char n[], int ag);
int isempty();
void display();
int isMinor(int ag);
int locatePosition(int ag);

int main ()
{
    char nm[31];
    int a;
    init();
    download();
    while (1)
    {
        switch(menu())
        {
        case 1 :
            system("cls");
            printf("Input Name: ");
            scanf(" %[^\n]",nm);
            printf("Input Age: ");
            scanf("%d",&a);
            add(nm,a);
            break;
        case 2 :
            display();
            break;
        case 3 :
            upload();
            printf("Thank you for using my program.\n");
            exit(0);
        default :
            printf("1 to 4 only.\n");
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
    printf("1. Add a Record\n");
    printf("2. Display\n");
    printf("3. Save and Exit\n");
    printf("\nSelect(1-3): ");
    scanf("%d", &op);
    return op;
}
void init()
{
    last = -1;
}
int isfull()
{
    return (last == MAX - 1);
}
void upload()
{
    FILE *fp;
    int i;

    fp = fopen("records.txt", "w+");
    if (fp == NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
    }
    else
    {
        for (i = 0; i <= last; i++)
            fprintf(fp, "%s\n%d\n", name[i], age[i]);
    }
    fclose(fp);
}
void download()
{
    FILE *fp;
    int i;
    char nm[31];
    int ag;
    fp = fopen("records.txt", "r+");
    if (fp == NULL)
    {
        printf("File Error\\Error 404\n");
        system("pause");
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp, " %[^\n]\n%d\n", nm, &ag);
            add(nm, ag);
        }
    }
    fclose(fp);
}
void add(char n[], int ag)
{
    int i, p;
    if (isfull())
    {
        printf("Array is full.\n");
        system("pause");
    }
    else
    {
        p = locatePosition(ag);
        for (i = last; i >= p; i--)
        {
            strcpy(name[i + 1], name[i]);
            age[i + 1] = age[i];
        }
        strcpy(name[p], n);
        age[p] = ag;
        last++;
    }
}
int isempty()
{
    return (last == -1);
}
void display()
{
    int i;
    system("cls");
    printf(" NAME\t\t\tAGE\tREMARKS\n");
    for (i = 0; i <= last; i++)
        printf("%d.) %s\t\t\t%d\t%s\n", i + 1, name[i], age[i], isMinor(age[i])? "MINOR":"ADULT");
    system("pause");
}
int isMinor(int ag)
{
    return (ag < 18);
}
int locatePosition(int ag)
{
    int i;
    for (i = 0; i <= last; i++)
    {
        if (ag > age[i])
            return i;
    }
    return i;
}
