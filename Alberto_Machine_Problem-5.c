// Rain Sidney G. Alberto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();
int addition(int items);
int subtraction(int items);
int multiplication(int items);
int division(int items);

int main ()
{   
    int score = 0, n = 5;
    while (1)
    {
        switch (menu())
        {
            case 1:
                system("cls");
                score = addition(n);
                printf("You got %d out of %d.\n", score, n);
                system("pause");
                break;
            case 2:
                system("cls");
                score = subtraction(n);
                printf("You got %d out of %d.\n", score, n);
                system("pause");
                break;
            case 3:
                system("cls");
                score = multiplication(n);
                printf("You got %d out of %d.\n", score, n);
                system("pause");
                break;
            case 4:
                system("cls");
                score = division(n);
                printf("You got %d out of %d.\n", score, n);
                system("pause");
                break;
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
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Select(1-4): ");
    scanf("%d", &op);
    return op;
}
int addition(int items)
{
    int a, b, ans, i, ctr = 0;
    srand(time(NULL));
    for (i = 1; i <= items; i++)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d.) What is %d + %d = ", i, a, b);
        scanf("%d", &ans);
        if (ans == a + b)
        {
            printf("Correct!\n");
            ctr++;
        }
        else
        {
            printf("Wrong! The correct answer is %d.\n", a + b);
        }
    }
    return ctr;
}
int subtraction(int items)
{
    int a, b, ans, i, ctr = 0;
    srand(time(NULL));
    for (i = 1; i <= items; i++)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d.) What is %d - %d = ", i, a, b);
        scanf("%d", &ans);
        if (ans == a - b)
        {
            printf("Correct!\n");
            ctr++;
        }
        else
        {
            printf("Wrong! The correct answer is %d.\n", a - b);
        }
    }
    return ctr;
}
int multiplication(int items)
{
    int a, b, ans, i, ctr = 0;
    srand(time(NULL));
    for (i = 1; i <= items; i++)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d.) What is %d * %d = ", i, a, b);
        scanf("%d", &ans);
        if (ans == a * b)
        {
            printf("Correct!\n");
            ctr++;
        }
        else
        {
            printf("Wrong! The correct answer is %d.\n", a * b);
        }
    }
    return ctr;
}
int division(int items)
{
    int i, ctr = 0;
    float a, b, ans;
    srand(time(NULL));
    for (i = 1; i <= items; i++)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d.) What is %f / %f = ", i, a, b);
        scanf("%f", &ans);
        if (ans == a / b)
        {
            printf("Correct!\n");
            ctr++;
        }
        else
        {
            printf("Wrong! The correct answer is %.2f.\n", a / b);
        }
    }
    return ctr;
}