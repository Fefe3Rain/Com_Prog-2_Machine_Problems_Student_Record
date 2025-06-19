// Rain Sidney G. Alberto
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 3

struct Record {
    string name;
    int q1, q2, q3;
};

Record student[MAX];
int last;

void init();
bool isfull();
bool isempty();
void add(Record x);
int locate(string n);
int updatemenu();
void update(string n);
void del(string n);
void display();
int menu();

int main () {
    Record data;
    init();
    while(true){
        switch(menu()){
            case 1:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                cout << "Input Quiz 1: ";
                cin >> data.q1;
                cout << "Input Quiz 2: ";
                cin >> data.q2;
                cout << "Input Quiz 3: ";
                cin >> data.q3;
                add(data);
                break;
            case 2:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                update(data.name);
                break;
            case 3:
                system("cls");
                cout << "Input name: ";
                cin >> data.name;
                del(data.name);
                break;
            case 4:
                system("cls");
                display();
                break;
            case 5:
                cout << "Thank you for using my program." << endl;
                exit(0);
            default:
                cout << "Invalid input.\n";
                system("pause");
        }
    }
    return 0;
}
void init(){
    last = -1;
}
bool isfull(){
    return last == MAX - 1;
}
bool isempty(){
    return last == -1;
}
void add(Record x){
    if (isfull()){
        cout << "The list is full.\n";
        system("pause");
    }
    else {
        last++;
        student[last] = x;
    }
}
int locate(string n){
    for (int i = 0; i <= last; i++)
        if (n == student[i].name)
            return i;
    return -1;
}
int updatemenu(){
    int op;
    system("cls");
    cout << "Update menu\n";
    cout << "1. Quiz 1\n";
    cout << "2. Quiz 2\n";
    cout << "3. Quiz 3\n";
    cout << "4. Back\n";
    cout << "Select (1-4): ";
    cin >> op;
    return op;
}
void update (string n){
    if (isempty()){
        cout << "The list is empty.\n";
        system("pause");
        return;
    }
    else {
        int p = locate(n);
        if (p < 0){
            cout << "Record of " << n << "not found.\n";
            system("pause");
        }
        else {
            while (true){
                switch (updatemenu()){
                    case 1:
                        system("cls");
                        cout << "Update quiz 1: ";
                        cin >> student[p].q1;
                        break;
                    case 2:
                        system("cls");
                        cout << "Update quiz 2: ";
                        cin >> student[p].q2;
                        break;
                    case 3:
                        system("cls");
                        cout << "Update quiz 3: ";
                        cin >> student[p].q3;
                        break;
                    case 4:
                        system("pause");
                        return;
                    default: 
                        cout << "Invalid input.\n";
                        system("pause");
                }
            }
        }
    }
}
void del(string n){
    if (isempty()){
        cout << "Nothing to delete\n";
        system("pause");
    }
    else {
        int p = locate(n);
        if (p < 0){
            cout << "Record of" << n << "not found\n";
            system("pause");
        }
        else {
            for (int i = p; i < last; i++)
                student[i] = student[i + 1];
        last--;
        }
    }
}
void display(){
    if (isempty()){
        cout << "Nothing to display\n";
        system("pause");
    }
    else{
        system("cls");
        cout << " NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\tREMARKS\n";
        for (int i = 0; i <= last; i++){
            float ave = (student[i].q1 + student[i].q2 + student[i].q3) / 3.0;
            cout << i + 1 << ".) " << fixed << setw(1) << student[i].name << fixed << setw(12)  << student[i].q1 << fixed << setw(7) << student[i].q2 << fixed << setw(7) << student[i].q3 << "      " << fixed << setprecision(2) << ave << "    " << (ave >= 75.0? "PASSED":"FAILED") << endl;
        }
        system("pause");
    }
}
int menu(){
    system("cls");
    int op;
    cout << "MENU\n";
    cout << "1. Add student\n";
    cout << "2. Update Student\n";
    cout << "3. Delete Student\n";
    cout << "4. Display Student\n";
    cout << "5. Exit\n";
    cout << "Select (1-5): ";
    cin >> op;
    return op;
}