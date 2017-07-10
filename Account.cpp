#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class BaseAccount {
protected:
	string name, account;
	float balance;
public:
	BaseAccount(string n, string a, float b) :name(n), account(a), balance(b) {
	}
	virtual void deposit(float m) {
		balance += m;
	}
	virtual bool withdraw(float m) {
		if (balance >= m) {
			balance -= m;
			return true;
		}
		return false;
	}
	virtual void display() {
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};
class BasePlus :public BaseAccount {
protected:
	float limit;
public:
	BasePlus(string n, string a, float b) :BaseAccount(n, a, b) {
		limit = 5000;
	}
	virtual void deposit(float m) {
		balance += m;
	}
	virtual bool withdraw(float m) {
		if ((balance + limit) >= m) {
			balance -= m;
			if (balance<0) {
				limit = 5000 + balance;
			}
			else {
				limit = 5000;
			}
			return true;
		}
		return false;
	}
	virtual void display() {
		if (balance < 0) {
			balance = 0;
		}
		cout << name << " " << account << " Balance:" << balance << " limit:" << limit << endl;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string name, account;
		float balance, m1, m2, m3, m4;
		cin >> name >> account >> balance;
		if (account.substr(0, 2) == "BA") {
			BaseAccount A(name, account, balance);
			cin >> m1 >> m2 >> m3 >> m4;
			A.deposit(m1);
			A.withdraw(m2);
			A.deposit(m3);
			if (!A.withdraw(m4)) {
				cout << "insufficient" << endl;
			}
			A.display();
		}
		else {
			BaseAccount *A;
			A = new BasePlus(name, account, balance);
			cin >> m1 >> m2 >> m3 >> m4;
			A->deposit(m1);
			A->withdraw(m2);
			A->deposit(m3);
			if (!A->withdraw(m4)) {
				cout << "insufficient" << endl;
			}
			A->display();

		}


	}
	return 0;
}
