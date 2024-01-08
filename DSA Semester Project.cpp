#include "P_List.h"
#include "C_List.h"
#include "F_List.h"

using namespace std;

int main()
{
	char MainChoice;

	P_List Officers;
	stack <int> P_LastEntered;
	int P_Id{ 0 };

	do
	{
		cout << "\nWELCOME TO POLICE MANAGEMENT SYSTEM\n\n";
		cout << "Select one of options from below to proceed\n";
		cout << "(P) to perform actions related to police officers\n";
		cout << "(F) to perform actions related to fir's\n";
		cout << "(C) to perform actions related to criminals\n";
		cout << "(E) to exit\n";
		cout << "Your choice: ";
		cin >> MainChoice;

		MainChoice = toupper(MainChoice);

		switch (MainChoice)
		{
			case 'P':
			{
				char P_Choice;

				do
				{
					//int Id;
					int Rank;
					string Name;

					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new officer\n";
					cout << "(B) to update the record of an existing officer\n";
					cout << "(C) to delete an officer from the list\n";
					cout << "(D) to search for an officer in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					cin >> P_Choice;

					P_Choice = toupper(P_Choice);

					switch (P_Choice)
					{
						case 'A':
						{
							cout << "Enter the rank of the officer that you want to enter: ";
							cin >> Rank;

							cout << "Enter the name of the officer that you want to enter: ";
							cin >> Name;

							if (Officers.P_LimitReached())
							{
								char UpdateChoice;

								cout << "There's no more space to enter more records\n";
								cout << "Would you like to update system to support more entries? (Y/N): ";
								cout << "You choice: ";
								cin >> UpdateChoice;

								if (UpdateChoice == 'Y')
								{
									Officers.P_Update();

									if (Officers.P_IsDeletedEmpty())
									{
										Officers.P_Add(P_Id, Rank, Name);
										P_LastEntered.push(P_Id);

										cout << "\nRecord entered successfully, Id assigned to this officer is: " << P_Id;

										P_Id++;
									}
									else
									{
										Officers.P_Add(Officers.P_GetDeletedId(), Rank, Name);
									}
								}
								else
								{
									cout << "\nRecord not added\n";
									cout << "You need to update the system to add more entires\n";
								}

							}
							else
							{
								if (Officers.P_IsDeletedEmpty())
								{
									Officers.P_Add(P_Id, Rank, Name);
									P_LastEntered.push(P_Id);

									cout << "Record entered successfully, Id assigned to this officer is: " << P_Id;

									P_Id++;
								}
								else
								{
									Officers.P_Add(Officers.P_GetDeletedId(), Rank, Name);
								}
							}

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

				do
				{
					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new Fir\n";
					cout << "(B) to update the record of an existing Fir\n";
					cout << "(C) to delete a fir from the list\n";
					cout << "(D) to search for a fir in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					cin >> F_Choice;

					F_Choice = toupper(F_Choice);

					switch (F_Choice)
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

				do
				{
					cout << "\nSelect one of the options from below to proceed:\n";
					cout << "(A) to add a new criminal\n";
					cout << "(B) to update the record of an existing criminal\n";
					cout << "(C) to delete a criminal from the list\n";
					cout << "(D) to search for a criminal in the list\n";
					cout << "(E) to go back to the main menu\n";
					cout << "Your choice: ";
					cin >> C_Choice;

					C_Choice = toupper(C_Choice);

					switch (C_Choice)
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