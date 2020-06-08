/*
Зробити обєкт Користувач (Ім'я, пошта, пароль, телефон, баласн з коштами)

В користувача має бути функціонал:
	Реєстрація (Користувач вводить всі значення, пароль двічі з перевіркою)
	Логін (Вводить пошту і пароль, якщо правильна то його відкривається меню користувача)
	Поповнення балансу (Використовувати інкапсуляцію)
	Покупка товарів (Користувач може бачити список товарів які він може купити і за яку ціну) <---- перевірки чи хватає грошей та чи є продукт в наявності

Також у вас є бути файл який буде названий config.txt в якому буде збережений логін і пароль для адміна

Приклад:
Admin
1111

Зробити обєкт Продукт (Назва, Ціна, Опис, Кількість)

Якщо при логіні був введений такий пароль як у файлі, відкривається меню адміна де є керування
всіма продуктами (Додавання, Пошук, Видалення, *Редуагування) <---- всі продукти мають бути збережені у файлі
Також адмін може змінювати собі пароль)
*/

#include <iostream>
#include <Windows.h>

using namespace std;

class User
{
private:
	string email;
	string name;
	string pass;
	string numberPhone;
	int balance;

public:

	/*User()
	{
		this->balance = 0;
		this->email = "NO_EMAIL";
		this->name = "NO_NAME";
		this->numberPhone = "NO_NUMBER_PHONE";
		this->pass = "NO_PASS";
	}*/

	User(string t_email = "NO_EMAIL", string t_name = "NO_NAME", string t_pass = "NO_PASS", string t_numberPhone = "NO_NUMBER_PHONE", int t_balance = 0)
	{
		this->balance = t_balance;
		this->email = t_email;
		this->name = t_name;
		this->numberPhone = t_numberPhone;
		this->pass = t_pass;
	}

	void Show()
	{
		cout << "Your email: " << GetEmail() << endl;
		cout << "Your name: " << GetName() << endl;
		cout << "Your number phone: " << GetNumberPhone() << endl;
		cout << "Your password: " << GetPass() << endl;
		cout << "Balance :" << GetBalance() << endl;

	}

	void EnterDataUser()
	{
		string tempEmail;
		string tempName;
		//string tempPass;
		string tempNumberPhone;

		cout << "Enter email: ";
		cin >> tempEmail;
		SetEmail(tempEmail);

		cout << "Enter name: ";
		cin >> tempName;
		SetName(tempName);

		cout << "Enter number phone: ";
		cin >> tempNumberPhone;
		SetNumberPhone(tempNumberPhone);

		cout << "Create a password\n";
		cout << "Enter GOOD password. LIKE (\tHell0_w0rlD\tBig3st_b00b\tS@nFr@nC1sC0)\n";
		SetPass(GoodPass());
	}

	string GoodPass()
	{
		string goodPassFirst;
		string goodPassSecond;

		//char yes='n';

		do
		{
			cout << "Enter password: ";
			cin >> goodPassFirst;
			cout << "And once again ";
			cin >> goodPassSecond;

			if (goodPassFirst == goodPassSecond)
			{
				//do
				//{

				cout << "\tYour password: ";
				cout << goodPassSecond << endl;
				/*cout << "Do you confirm password ? y or n\n";
				cin >> yes;*/


				//} while (!(yes == 'y' || yes == 'Y'));

				return goodPassSecond;
			}
			else
			{
				cout << "Passwords do not match\n";
			}

		} while (true);

	}

	void SetEmail(string& t_email)				// SET EMAIL
	{
		this->email = t_email;
	}
	string GetEmail()							// GET EMAIL
	{
		return this->email;
	}

	void SetName(string& t_name)				// SET NAME
	{
		this->name = t_name;
	}
	string GetName()							// GET NAME
	{
		return this->name;
	}

	void SetPass(string t_pass)					// SET PASS
	{
		this->pass = t_pass;
	}
	string GetPass()							// GET PASS
	{
		return this->pass;
	}

	void SetNumberPhone(string t_numberPhone)	// SET NUMBER PHONE
	{
		this->numberPhone = t_numberPhone;
	}
	string GetNumberPhone()						// GET NUMBER PHONE
	{
		return this->numberPhone;
	}

	void SetBalance(int t_balance)				// SET BALANCE
	{
		this->balance = t_balance;
	}
	int GetBalance()							// GET BALANCE
	{
		return this->balance;
	}

	bool CheckDate()
	{
		string checkEmail;
		string checkPass;
		int count = 5;
		system("cls");
		do
		{
			cout << "Enter login details (EMAIL and PASSWORD)\n";
			cout << "Enter email: ";
			cin >> checkEmail;

			cout << "Enter password: ";
			cin >> checkPass;

			if (checkEmail == this->email && checkPass == this->pass)
				return true;
			else
			{
				cout << "Incorect data\n";
				count--;
			}
		} while (count > 0);
		return false;
	}

};

int main()
{
	char yes;

	User ShopUser1;

	//int tempBalance;
	cout << "Welcome to the store. Will we register ? Enter y or n\n";
	cin >> yes;
	if (yes == 'y' || yes == 'Y')
	{
		do
		{
			ShopUser1.EnterDataUser();

			cout << "\nYour data:\n";
			ShopUser1.Show();

			cout << "Do you confirm the data? Enter y or n: ";
			cin >> yes;

		} while (!(yes == 'y' || yes == 'Y'));

	}
	else
	{
		cout << "\tGoodbye";
		return 0;
		//cout << "You have account ? Enter y or n: ";
		//cin >> yes;
		//if (yes == 'y' || yes == 'Y')
		//{
		//	//cout<<"Enter you pass"
		//}
		//else
		//{

		//}
		//return 0;
	}

	//cout << "\tWeLcOmE iN tHe ShOp\n";

	if (ShopUser1.CheckDate())
	{
		system("cls");
		cout << "WeLcOmE To tHe ShOp\n";
	}
	else
	{
		cout << "\nGOODBYE";
		return 0;
	}

	cout << "\tMENU\n";







	return 0;
}