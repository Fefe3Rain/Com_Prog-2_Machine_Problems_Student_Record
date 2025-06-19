import os

MAX = 5

class BankList:
    def __init__(self, filename="accounts.txt"):
        self.accounts = []
        self.filename = filename
        self.load_accounts()

    def find_account(self, acc_no):
        for i, acc in enumerate(self.accounts):
            if acc["acc_no"] == acc_no:
                return i
        return -1

    def is_full(self):
        return len(self.accounts) >= MAX

    def append_account(self, acc_no, name, balance):
        if self.is_full():
            print("Account list is full.")
        elif self.find_account(acc_no) != -1:
            print("Account number already exists.")
        else:
            self.accounts.append({
                "acc_no": acc_no,
                "name": name,
                "balance": balance
            })
            print("Account added.")
            self.save_accounts()

    def delete_account(self, acc_no):
        index = self.find_account(acc_no)
        if index == -1:
            print("Account not found.")
        else:
            del self.accounts[index]
            print("Account deleted.")
            self.save_accounts()

    def display_accounts(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("Account List:")
        print("Acc No | Name | Balance")
        print("-" * 30)
        for acc in self.accounts:
            print(f"{acc['acc_no']} | {acc['name']} | Php{acc['balance']:.2f}")
        input("Press Enter to continue...")

    def save_accounts(self):
        try:
            with open(self.filename, 'w') as file:
                for acc in self.accounts:
                    line = f"{acc['acc_no']},{acc['name']},{acc['balance']}"
                    file.write(line + '\n')
        except IOError:
            print("Error saving accounts to file.")

    def load_accounts(self):
        try:
            with open(self.filename, 'r') as file:
                for line in file:
                    parts = line.strip().split(',')
                    if len(parts) == 3:
                        acc_no, name, balance = parts
                        try:
                            balance = float(balance)
                            self.accounts.append({
                                "acc_no": acc_no,
                                "name": name,
                                "balance": balance
                            })
                        except ValueError:
                            print(f"Skipping invalid balance in line: {line}")
        except FileNotFoundError:
            # File will be created on first save
            pass
        except IOError:
            print("Error reading accounts from file.")

def menu():
    print("BANK ACCOUNT MENU")
    print("1. Add Account")
    print("2. Delete Account")
    print("3. Display Accounts")
    print("4. Exit")
    return input("\nSelect (1-4): ")

def main():
    bank = BankList()
    while True:
        choice = menu()
        if choice == '1':
            try:
                acc_no = input("Enter account number: ")
                name = input("Enter name: ")
                balance = float(input("Enter initial balance: "))
                bank.append_account(acc_no, name, balance)
            except ValueError:
                print("Invalid balance input.")
            input("Press Enter to continue...")
        elif choice == '2':
            acc_no = input("Enter account number to delete: ")
            bank.delete_account(acc_no)
            input("Press Enter to continue...")
        elif choice == '3':
            bank.display_accounts()
        elif choice == '4':
            print("Saving and exiting...")
            bank.save_accounts()
            break
        else:
            print("Invalid input.")
            input("Press Enter to continue...")

if __name__ == "__main__":
    main()
