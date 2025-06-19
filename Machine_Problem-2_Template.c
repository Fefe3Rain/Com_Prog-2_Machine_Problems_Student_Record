#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Global Variables
int a[MAX];
int last;

// User-Defined Function Prototypes
void init();
int isfull();
void add(int x);
void del (int x);
int isempty();
int search(int x);
void display();
int menu();

int main ()
{
    int num;
    init();
    while (1)
    {
        switch (menu())
        {
            case 1:
                system("cls");
                printf("Input a x: ");
                scanf("%d", &num);
                add(num);
                break;
            case 2:
                system("cls");
                printf("Input a x: ");
                scanf("%d", &num);
                del(num);
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
void init()
{
    last = -1;
}
int isfull()
{
    if (last == MAX - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    return (last == -1);
}   
int search(int x)
{
    int i;
    for (i = 0; i <= last; i++)
    {
        if (x == a[i])
            return i;
    }
    return -1;
}
void add (int x)
{
    if (isfull())
    {
        printf("The array is full!\n");
        system("pause");
    }
    else
    {
        last++;
        a[last] = x;
    }
}
void del (int x)
{
    int p, i;
    if (isempty())
    {
        printf("The array is empty!\n");
        system("pause");
    }
    else
    {
        p = search(x);
        if (p < 0)
        {
            printf("Not found!\n");
            system("pause");
        }
        else
        {
            for (i = p; i < last; i++)
                a[i] = a[i + 1];
            last--;
        }
    }
}
void display()
{
    int i;
    system("cls");
    printf("The array contains: \n");
    for (i = 0; i <= last; i++)
        printf("%d.) %d\n", i + 1, a[i]);
    system("pause");
}
int menu()
{
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add x\n");
    printf("2. Delete x\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("\nSelect (1-4): ");
    scanf("%d", &op);
    return op;
}