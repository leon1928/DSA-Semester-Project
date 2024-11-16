#include "Police.h"
#include "Criminal.h"
#include "Fir.h"
#include "SystemAdmin.h"

using namespace std;

int main()
{
	char MainChoice{' '};

	bool IsAdmin{ false };

	string UserPassword{""};

	SystemAdmin* Admins = new SystemAdmin;

	char ch;

	Police* Officers = new Police;
	Criminal* Criminals = new Criminal;
	Fir* Firs = new Fir;

	stack <int> P_LastEntered;
	stack <int> C_LastEntered;
	stack <int> F_LastEntered;

	int P_Id{ 0 };
	int C_Id{ 0 };
	int F_Id{ 0 };

	do
	{
		cout << "********************************************************\n";
		cout << "\tWELCOME TO POLICE MANAGEMENT SYSTEM\n";
		cout << "********************************************************\n\n";

		cout << "Are you an admin? (Y/N):";
		cout << "\nYour choice: ";

		MainChoice = _getch();

		cout << MainChoice << endl;

		MainChoice = toupper(MainChoice);

		if (MainChoice == 'Y')
		{
			int TotalCharacters{ 0 };
			cout << "\nEnter the admin password: ";
			// 13 is the ASCII code for Enter
			while ((ch = _getch()) != 13) 
			{
				if (ch == 8)	//ASCII code for backspace
				{
					UserPassword.erase();	//removes the last entered character
					cout << "\b" << " " << "\b";
				}
				else
				{
					// Display '*' for each character
					cout << '*';
					UserPassword = UserPassword + ch;
					TotalCharacters++;
				}
			}

			if (Admins->PasswordExists(UserPassword))
			{
				IsAdmin = true;
				cout << "\nAdmin login detected\n";
			}
			else
			{
				cout << "\nIncorrect password, logged in as guest\n";
			}

		}

		cout << "\nSelect one of options from below to proceed\n";
		cout << "(P) to perform actions related to police officers\n";
		cout << "(F) to perform actions related to fir's\n";
		cout << "(C) to perform actions related to criminals\n";
		cout << "(E) to exit\n";
		cout << "Your choice: ";
		MainChoice = _getch();
		cout << MainChoice << endl;

		MainChoice = toupper(MainChoice);

		switch (MainChoice)
		{
			case 'P':
			{
				char P_Choice;
				int Rank;
				string Name;

				do
				{
					P:
					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new officer\n";
					cout << "(B) to update the record of an existing officer\n";
					cout << "(C) to delete an officer from the list\n";
					cout << "(D) to search for an officer in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					P_Choice = _getch();
					cout << P_Choice << endl;

					P_Choice = toupper(P_Choice);

					if ((P_Choice == 'A' || P_Choice == 'B' || P_Choice == 'C') && !IsAdmin)
					{
						char Again{ ' ' };
						cout << "\nOnly admins can perform this function\n";
						cout << "Would you like to try again? (Y/N)\n";
						cout << "Your choice: ";
						Again = _getch();

						Again = toupper(Again);

						if (Again == 'Y')
						{
							goto P;
						}
						else
						{
							P_Choice = 'E';
						}
					}

					switch (P_Choice)
					{
						case 'A':
						{
							cout << "\nEnter the rank of the officer that you want to enter: ";
							cin >> Rank;

							cin.ignore();

							cout << "\nEnter the name of the officer that you want to enter: ";
							getline(cin, Name);

							Officers->Add(Rank, Name);

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the officer that you want to update: ";
							cin >> Id;

							cout << "\nEnter the rank of the officer that you want to update to: ";
							cin >> Rank;

							cin.ignore();

							cout << "\nEnter the name of the officer that you want to update to: ";
							getline(cin, Name);

							Officers->UpdateRecord(Id, Rank, Name);

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the officer that you want to delete: ";
							cin >> Id;

							Officers->Delete(Id);

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the officer that you want to find: ";
							cin >> Id;

							Officers->Search(Id);

							break;
						}
						case 'E':
						{
							cout << "\nGoodbye from the department of officer management\n";

							break;
						}
						default:
						{
							cout << "\nInvalid choice, Try again\n";

							break;
						}
					}
				} while (P_Choice != 'E');

				break;
			}
			case 'F':
			{
				char F_Choice;
				string ComplaintDescription;
				string ComplaintBy;

				do
				{
					F:
					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new Fir\n";
					cout << "(B) to update the record of an existing Fir\n";
					cout << "(C) to delete a fir from the list\n";
					cout << "(D) to search for a fir in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					F_Choice = _getch();
					cout << F_Choice << endl;

					F_Choice = toupper(F_Choice);

					if ((F_Choice == 'A' || F_Choice == 'B' || F_Choice == 'C') && !IsAdmin)
					{
						char Again{ ' ' };
						cout << "\nOnly admins can perform this function\n";
						cout << "Would you like to try again? (Y/N)\n";
						cout << "Your choice: ";
						Again = _getch();

						Again = toupper(Again);

						if (Again == 'Y')
						{
							goto F;
						}
						else
						{
							F_Choice = 'E';
						}
					}

					switch (F_Choice)
					{
						case 'A':
						{
							cin.ignore();

							cout << "Enter the description of the fir that you want to enter: ";
							getline(cin, ComplaintDescription);

							cout << "Enter the name of the person who has launched the fir: ";
							getline(cin, ComplaintBy);

							Firs->Add(ComplaintDescription, ComplaintBy);

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the fir that you want to update: ";
							cin >> Id;

							cout << "Enter the description of the fir that you want to update to: ";
							getline(cin, ComplaintDescription);

							cout << "Enter the name of the person to which you want to update the fir to: ";
							getline(cin, ComplaintBy);

							Firs->UpdateRecord(Id, ComplaintDescription, ComplaintBy);

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the fir that you want to delete: ";
							cin >> Id;

							Firs->Delete(Id);

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the fir that you want to find: ";
							cin >> Id;

							Firs->Search(Id);

							break;
						}
						case 'E':
						{
							cout << "\nGoodbye from the department of fir management\n";

							break;
						}
						default:
						{
							cout << "\nInvalid choice, Try again\n";

							break;
						}
					}

				} while (F_Choice != 'E');

				break;
			}
			case 'C':
			{
				char C_Choice;
				string Offense;
				string Name;

				do
				{
					C:
					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new criminal\n";
					cout << "(B) to update the record of an existing criminal\n";
					cout << "(C) to delete a criminal from the list\n";
					cout << "(D) to search for a criminal in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					C_Choice = _getch();
					cout << C_Choice << endl;

					C_Choice = toupper(C_Choice);

					if ((C_Choice == 'A' || C_Choice == 'B' || C_Choice == 'C') && !IsAdmin)
					{
						char Again{ ' ' };
						cout << "\nOnly admins can perform this function\n";
						cout << "Would you like to try again? (Y/N)\n";
						cout << "Your choice: ";
						Again = _getch();

						Again = toupper(Again);

						if (Again == 'Y')
						{
							goto C;
						}
						else
						{
							C_Choice = 'E';
						}
					}

					switch (C_Choice)
					{
						case 'A':
						{
							cin.ignore();

							cout << "Enter the offense of the criminal that you want to enter: ";
							getline(cin, Offense);

							cout << "Enter the name of the criminal that you want to enter: ";
							getline(cin, Name);

							Criminals->Add(Offense, Name);

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the criminal that you want to update: ";
							cin >> Id;

							cout << "Enter the offense of the criminal that you want to update to: ";
							getline(cin, Offense);

							cout << "Enter the name of the criminal that you want to update to: ";
							getline(cin, Name);

							Criminals->UpdateRecord(Id, Offense, Name);

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the criminal that you want to delete: ";
							cin >> Id;

							Criminals->Delete(Id);

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the criminal that you want to find: ";
							cin >> Id;

							Criminals->Search(Id);

							break;
						}
						case 'E':
						{
							cout << "\nGoodbye from the department of criminal management\n";

							break;
						}
						default:
						{
							cout << "\nInvalid choice, Try again\n";

							break;
						}
					}

				} while (C_Choice != 'E');

				break;
			}
			case 'E':
			{
				cout << "\nGoodbye\n";

				break;
			}
			default:
			{
				cout << "\nInvalid choice, Try again\n";

				break;
			}
		}


	} while (MainChoice != 'E');

	return 0;
}