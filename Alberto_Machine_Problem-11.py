# Rain Sidney G. Alberto
records = []

def avg(a, b, c):
    return (a + b + c) / 3

def add(name, q1, q2, q3):
    record = {"name": name, "q1": q1, "q2": q2, "q3": q3}
    records.append(record)

def updatemenu():
    print("Update Menu")
    print("1. Update Quiz 1")
    print("2. Update Quiz 2")
    print("3. Update QUiz 3")
    print("4. Back to main menu")
    op = int(input("Enter your choice: "))
    return op

def update(name):
    for record in records:
        if (record["name"] == name):
            while True:
                match(updatemenu()):
                    case 1:
                        record["q1"] = int(input("Enter new Quiz 1: "))
                    case 2:
                        record["q2"] = int(input("Enter new Quiz 2: "))
                    case 3:
                        record["q3"] = int(input("Enter new Quiz 3: "))
                    case 4:
                        break
                    case _:
                        print("Invalid input. Please try again.")
            break

def delete(name):
    for record in records:
        if (record["name"] == name):
            records.remove(record)
            print(f"Record of {name} was successfully deleted.")
            return
    print("Record not found.")

def display():
    print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("Name","Quiz1","Quiz2","Quiz3","Average","Remarks"))
    for rec in records:
        ave = avg( rec["q1"], rec["q2"], rec["q3"])
        print("{:<10} {:<10} {:<10} {:<10} {:<10.2f} {:<10}".format(rec["name"], rec["q1"], rec["q2"], rec["q3"],ave , "passed" if ave>=75 else "failed"))

def menu():
    print("Menu")
    print("1. Add a Record")
    print("2. Update a Record")
    print("3. Delete a Record")
    print("4. Display all Records")
    print("5. Exit")
    op = int(input("Enter your choice: "))
    return op

if  __name__ == "__main__":
    while True:
        match(menu()):
            case 1:
                name = input("Enter Name: ")
                q1 = int(input("Enter Quiz 1: "))
                q2 = int(input("Enter Quiz 2: "))
                q3 = int(input("Enter Quiz 3: "))
                add(name, q1, q2, q3)
            case 2:
                name = input("Enter Name: ")
                update(name)
            case 3:
                name = input("Enter Name: ")
                delete(name)
            case 4:
                display()
            case 5:
                print("Exiting...")
                exit()
            case _:
                print("Invalid input. Please try again.")