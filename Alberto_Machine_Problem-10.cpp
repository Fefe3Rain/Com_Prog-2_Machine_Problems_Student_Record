// Rain Sidney G. Alberto
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define MAX 3

struct Record{
    string name;
    int q1, q2, q3;
};

class Student {
    private:
        Record person[MAX];
        int last;
        bool isfull();
        bool isempty();
        int locate(string n);
    public:
        void init();
        void add(Record x);
        void update(string n);
        void del(string);
        void display();
        void save();
        void retrieve();
};

int menu();
int updatemenu();

int main (){
    Record data;
    Student it;
    it.init();
    it.retrieve();
    while (true){
        switch (menu()){
            case 1:
                system("cls");
                cout << "Input name: ";
                cin.ignore();
                getline(cin, data.name);
                cout << "Input quiz 1: ";
                cin >> data.q1;
                cout << "Input quiz 2: ";
                cin >> data.q2;
                cout << "Input quiz 3: ";
                cin >> data.q3;
                it.add(data);
                break;
            case 2:
                system("cls");
                cout << "Input name: ";
                cin.ignore();
                getline(cin, data.name);
                it.update(data.name);
                break;
            case 3:
                system("cls");
                cout << "Input name: ";
                cin.ignore();
                getline(cin, data.name);
                it.del(data.name);
                break;
            case 4:
                system("cls");
                it.display();
                break;
            case 5:
                it.save();
                exit(0);
            default:
                cout << "Invalid input.\n";
                system("pause");
        }
    }
}

void Student::init(){
    last = -1;
}
void Student::add(Record x){
    if (isfull()){
        cout <<"List is full.\n";
        system("pause");
    } else {
        last++;
        person[last] = x;
    }
}
int updatemenu(){
    system("cls");
    int op;
    cout << "Update menu\n";
    cout << "1. Quiz 1\n";
    cout << "2. Quiz 2\n";
    cout << "3. Quiz 3\n";
    cout << "4. Back\n";
    cout << "Select (1-4): ";
    cin >> op;
    return op;
}
void Student::update(string n){
    if (isempty()){
        cout << "The list is empty.\n";
        system("pause");
    } else {
        int p = locate(n);
        if (p < 0){
            cout << "Record of " << n << "not found.\n";
            system("pause");
        } else {
            while (true){
                switch (updatemenu()) {
                    case 1:
                        system("cls");
                        cout << "Update quiz 1: ";
                        cin >> person[p].q1;
                        break;
                    case 2:
                        system("cls");
                        cout << "Update quiz 2: ";
                        cin >> person[p].q2;
                        break;
                    case 3:
                        system("cls");
                        cout << "Update quiz 3: ";
                        cin >> person[p].q3;
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
void Student::del(string n){
    if (isempty()){
        cout << "Nothing to delete.\n";
        system("pause");
    } else {
        int p = locate(n);
        if (p < 0){
            cout << "Record of " << n << "not found.\n";
            system("pause");
        } else {
            for (int i = p; i < last; i++)
                person[i] = person[i + 1];
            last--;
        }
    }
}
void Student::display(){
    if (isempty()){
        cout << "Nothing to display.\n";
        system("pause");
    } else {
        cout << "   NAME\t\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\tREMARKS\n";
        for (int i = 0; i <= last; i++){
            float ave = (person[i].q1 + person[i].q2 + person[i].q3) / 3.0;
            cout << i + 1 << ".) ";
            cout << fixed << setw(1) << person[i].name;
            cout << fixed << setw(9) << person[i].q1;
            cout << fixed << setw(7) << person[i].q2;
            cout << fixed << setw(7) <<person[i].q3 << "     ";
            cout << fixed << setprecision(2) << ave << "     " << (ave >= 75.0? "PASSED":"FAILED") << endl;
        }
        system("pause");
    }
}
bool Student::isfull(){
    return (last == MAX - 1);
}
bool Student::isempty(){
    return (last == - 1);
}
int Student::locate(string n){
    for (int i = 0; i <=last; i++)
        if (n == person[i].name)
            return i;
    return -1;
}
int menu(){
    system("cls");
    int op;
    cout << "MENU\n";
    cout << "1. Add a Student\n";
    cout << "2. Update Student\n";
    cout << "3. Delete Student\n";
    cout << "4. Display Student\n";
    cout << "5. Exit\n";
    cout << "Select (1 - 5): ";
    cin >> op;
    return op;
}
void Student::save(){
    ofstream fp("itstudent.txt");
    if (!fp){
        cout << "File error.\n";
        system("pause");
    } else {
        for (int i = 0; i <= last; i++)
            fp << person[i].name << endl << person[i].q1 << endl << person[i].q2 << endl << person[i].q3 << endl;
    }
    fp.close();
}
void Student::retrieve(){
    ifstream fp("itstudent.txt");
    if (!fp){
        cout << "File error.\n";
        system("pause");
    } else {
        Record sr;
        while(getline(fp, sr.name) &&  fp >> sr.q1 >> sr.q2 >> sr.q3){
            fp.ignore();
            add(sr);
        }
    }
    fp.close();
}