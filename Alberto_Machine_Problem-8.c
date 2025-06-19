// Rain Sidney G. Alberto
#include <stdio.h>
#include <string.h>

int ipalin(int n);
int recpalin(int n, int rev);
void irev(char str[]);
void rrev(char str[], int i, int len);
int ibin(int decimal);
int recbin(int decimal);
int isearch(int arr[], int size, int target);
int recsearch(int arr[], int size, int target, int index);

int main() {
    int n, decimal;
    int rev, len;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (ipalin(n)) {
        printf("Iterative: # %d is a palindrome\n", n);
    } else {
        printf("Iterative: # %d is not a palindrome\n", n);
    }

    if (recpalin(n, rev) == n) {
        printf("Recursive: # %d is a palindrome\n", n);
    } else {
        printf("Recursive: # %d is not a palindrome\n", n);
    }

    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    irev(str);
    printf("The reversed string in Iterative is : %s", str);
    len = strlen(str);
    rrev(str, 0, len);
    printf("\nThe reversed string in Recursion is : %s", str);

    printf("\nThe Iterative Binary of the decimal number %d is: %d\n", n, ibin(decimal));
    printf("The Recursive Binary of the decimal number %d is: %d\n", n, recbin(decimal));

    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("\nEnter an element to search in the array: ");
    scanf("%d", &target);

    int iterResult = isearch(arr, size, target);
    if (iterResult != -1) {
        printf("In Iterative, %d is found at index %d.\n", target, iterResult);
    } else {
        printf("In Iterative, %d is not found in the array.\n", target);
    }

    int recResult = recsearch(arr, size, target, 0);
    if (recResult != -1) {
        printf("In Recursion, %d is found at index %d.\n", target, recResult);
    } else {
        printf("In Recursion, %d is not found in the array.\n", target);
    }

    return 0;
}

int ipalin(int n) {
    if (n < 0) return 0;

    int original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return original == rev;
}

int recpalin(int n, int rev) {
    if (n == 0)
        return rev;
    return recpalin(n / 10, rev * 10 + (n % 10));
}

void irev(char str[]) {
    int len = strlen(str);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void rrev(char str[], int i, int len) {
    if (i >= len / 2)
        return;

    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;

    rrev(str, i + 1, len);
}

int ibin(int decimal) {
    int binary = 0;
    int place = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * place;
        decimal /= 2;
        place *= 10;
    }
    return binary;
}

int recbin(int decimal) {
    if (decimal == 0)
        return 0;
    return (decimal % 2) + 10 * recbin(decimal / 2);
}

int isearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int recsearch(int arr[], int size, int target, int index) {
    if (index >= size) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return recsearch(arr, size, target, index + 1);
}