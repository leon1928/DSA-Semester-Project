#include "P_List.h"
using namespace std;

int main()
{
	P_List Officers;
	char Choice;

	do
	{
		cout << "\nWELCOME TO POLICE MANAGEMENT SYSTEM\n\n";
		cout << "\nSelect one of the options from below to proceed:\n";
		cout << "(A) to add a new officer\n";
		cout << "(B) to update the record of an existing officer\n";
		cout << "(C) to delete an officer from the list\n";
		cout << "(D) to search for an officer in the list\n";
		cout << "(E) to exit\n";
		cout << "Your choice: ";
		cin >> Choice;

		Choice = toupper(Choice);

		switch (Choice)
		{
			case 'A':
			{


				break;
			}
			case 'B':
			{


				break;
			}
			case 'C':
			{


				break;
			}
			case 'D':
			{


				break;
			}
			case 'E':
			{
				cout << "Goodbye\n";

				break;
			}
			default:
			{
				cout << "\nInvalid choice, Try again\n";

				break;
			}
		}
	} while (Choice != 'E');

	return 0;
}