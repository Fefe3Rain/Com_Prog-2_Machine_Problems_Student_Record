#Rain Sidney G. Alberto
import os

MAX = 5

class StudentRecord:
    def __init__(self, name, q1, q2, q3):
        self.name = name
        self.q1 = q1
        self.q2 = q2
        self.q3 = q3

    def avg(self, q1, q2, q3):
        return (int(q1) + int(q2) + int(q3)) / 3

    def __str__(self):
        ave = self.avg(self.q1, self.q2, self.q3)
        return f"{self.name:10} | {self.q1:6} | {self.q2:6} | {self.q3:6} | {ave:7.2f} | {'Passed' if ave >= 75 else 'Failed'}"

    def to_csv(self):
        return f"{self.name} | {self.q1} | {self.q2} | {self.q3} "

    @staticmethod
    def from_csv(line):
        parts = line.strip().split(',')
        if len(parts) == 4:
            name, q1, q2, q3 = parts
            return StudentRecord(name, q1, q2, q3)
        return None

class RecordList:
    def __init__(self, filename = "records.txt"):
        self.records = []
        self.filename = filename
        self.load_records()

    def find_record(self, name):
        for i, rec in enumerate(self.records):
            if rec.name == name:
                return i
        return -1
    
    def is_full(self):
        return len(self.records) >= MAX
    
    def append_record(self, name, q1, q2, q3):
        if self.is_full():
            print("Record list is full.")
        elif self.find_record(name) != -1:
            print("Student already exist.")
        else:
            self.records.append(StudentRecord(name, q1, q2, q3))
            print("Record added.")
            self.save_records()

    def delete_record(self, name):
        index = self.find_record(name)
        if index == -1:
            print("Record not found.")
        else:
            del self.records[index]
            print("Record deleted.")
            self.save_records()

    def display_records(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("Record List:")
        print("Name      | Quiz 1 | Quiz 2 | Quiz 3 | Average | Remarks")
        print("-" * 56)
        for rec in self.records:
            print(rec)
        input("Press Enter to continue...")

    def save_records(self):
        try:
            with open(self.filename, 'w') as file:
                for rec in self.records:
                    file.write(rec.to_csv() + '\n')
        except IOError:
            print("Error saving records to file.")

    def load_records(self):
        try:
            with open(self.filename, 'r') as file:
                for line in file:
                    rec = StudentRecord.from_csv(line)
                    if rec:
                        self.records.append(rec)
        except FileNotFoundError:
            pass
        except IOError:
            print("Error loading records from file.")

def menu():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("STUDENT RECORD MENU")
    print("1. Add a Record")
    print("2. Delete a Record")
    print("3. Display all Records")
    print("4. exit")
    return input("\nSelect an option (1 - 4): ")

def main():
    record = RecordList()
    while True:
        choice = menu()
        if choice == '1':
            try:
                name = input("Enter Name: ")
                q1 = int(input("Enter Quiz 1: "))
                q2 = int(input("Enter Quiz 2: "))
                q3 = int(input("Enter Quiz 3: "))
                record.append_record(name, q1, q2, q3)
            except ValueError:
                print("Invalid grade input.")
            input("Press Enter to continue...")
        elif choice == '2':
            name = input("Enter name to delete: ")
            record.delete_record(name)
            input("Press Enter to continue...")
        elif choice == '3':
            record.display_records()
        elif choice == '4':
            print("Saving and exiting...")
            record.save_records()
            break
        else:
            print("Invalid input.")
            input("Press Enter to continue...")
                
if __name__ == "__main__":
    main()