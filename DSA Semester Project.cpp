#include "P_List.h"
#include "C_List.h"
#include "F_List.h"
#include "SystemAdmin.h"

using namespace std;

int main()
{
	char MainChoice{' '};

	bool IsAdmin{ false };

	string UserPassword{""};

	SystemAdmin* Admins = new SystemAdmin;

	char ch;

	P_List* Officers = new P_List;
	C_List* Criminals = new C_List;
	F_List* Firs = new F_List;

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

							//auto start = std::chrono::high_resolution_clock::now();

							if (Officers->P_LimitReached())
							{
								char UpdateChoice;

								cout << "There's no more space to enter more records\n";
								cout << "Would you like to update system to support more entries? (Y/N): ";
								cout << "You choice: ";
								UpdateChoice = _getch();
								cout << UpdateChoice << endl;

								UpdateChoice = toupper(UpdateChoice);

								if (UpdateChoice == 'Y')
								{
									Officers->P_Update();

									if (Officers->P_IsDeletedEmpty())
									{
										Officers->P_Add(P_Id, Rank, Name);
										P_LastEntered.push(P_Id);

										cout << "\nRecord entered successfully, Id assigned to this officer is: " << P_Id << endl;

										P_Id++;
									}
									else
									{
										Officers->P_Add(Officers->P_GetDeletedId(), Rank, Name);
										P_LastEntered.push(P_Id);
										cout << "\nRecord entered successfully, Id assigned to this officer is: " << Officers->P_GetDeletedId() << endl;
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
								if (Officers->P_IsDeletedEmpty())
								{
									Officers->P_Add(P_Id, Rank, Name);
									P_LastEntered.push(P_Id);

									cout << "Record entered successfully, Id assigned to this officer is: " << P_Id;

									P_Id++;
								}
								else
								{
									Officers->P_Add(Officers->P_GetDeletedId(), Rank, Name);
								}
							}

							/*auto stop = std::chrono::high_resolution_clock::now();

							auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

							std::cout << "\nElapsed time: " << duration.count() << " nanoseconds" << std::endl;*/

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the officer that you want to update: ";
							cin >> Id;

							if (Officers->P_IdExists(Id))
							{
								Officers->P_Search(Id);

								cout << "Enter the new rank of the officer: ";
								cin >> Rank;

								cin.ignore();

								cout << "Enter the updated name of the officer: ";
								getline(cin, Name);

								Officers->P_UpdateRecord(Id, Rank, Name);
							}
							else
							{
								cout << "\nThe id you entered doesn't exist\n";
							}

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the officer that you want to delete: ";
							cin >> Id;

							if (Officers->P_IdExists(Id))
							{
								Officers->P_Delete(Id);
								cout << "\nRecord against the entered id has been successfully deleted\n";
							}
							else
							{
								cout << "\nThe record that you want to delete doesn't exist\n";
							}

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the officer that you want to find: ";
							cin >> Id;

							if (Officers->P_IdExists(Id))
							{
								
								cout << "\nSearching by array:\n";
								//auto start = std::chrono::high_resolution_clock::now();
								Officers->P_Search(Id);

								/*auto stop = std::chrono::high_resolution_clock::now();

								auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

								double seconds = duration.count() * 1e-9;

								std::cout << "\nElapsed time for array: " << seconds << " nanoseconds" << std::endl;*/

								//BST
								//auto start1 = std::chrono::high_resolution_clock::now();

								//Officers->P_SearchBST(Id);

								/*auto stop1 = std::chrono::high_resolution_clock::now();

								auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);

								double seconds1 = duration1.count() * 1e-9;

								std::cout << "\nElapsed time for BST: " << seconds1 << " nanoseconds" << std::endl;*/
							}
							else
							{
								cout << "\nOfficer not found\n";
							}

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

							if (Firs->F_LimitReached())
							{
								char UpdateChoice;

								cout << "There's no more space to enter more records\n";
								cout << "Would you like to update system to support more entries? (Y/N): ";
								cout << "You choice: ";
								UpdateChoice = _getch();
								cout << UpdateChoice << endl;

								UpdateChoice = toupper(UpdateChoice);

								if (UpdateChoice == 'Y')
								{
									Firs->F_Update();

									if (Firs->F_IsDeletedEmpty())
									{
										Firs->F_Add(F_Id, ComplaintDescription, ComplaintBy);
										F_LastEntered.push(F_Id);

										cout << "\nRecord entered successfully, Id assigned to this fir is: " << F_Id << endl;

										F_Id++;
									}
									else
									{
										Firs->F_Add(Firs->F_GetDeletedId(), ComplaintDescription, ComplaintBy);
										F_LastEntered.push(F_Id);
										cout << "\nRecord entered successfully, Id assigned to this fir is: " << Firs->F_GetDeletedId() << endl;
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
								if (Firs->F_IsDeletedEmpty())
								{
									Firs->F_Add(F_Id, ComplaintDescription, ComplaintBy);
									F_LastEntered.push(F_Id);

									cout << "Record entered successfully, Id assigned to this fir is: " << F_Id;

									F_Id++;
								}
								else
								{
									Firs->F_Add(Firs->F_GetDeletedId(), ComplaintDescription, ComplaintBy);
								}
							}

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the fir that you want to update: ";
							cin >> Id;

							if (Firs->F_IdExists(Id))
							{
								Firs->F_Search(Id);

								cin.ignore();

								cout << "Enter the new description of the fir: ";
								getline(cin, ComplaintDescription);

								cout << "Enter the updated name of the person who launched the fir: ";
								getline(cin, ComplaintBy);

								Firs->F_UpdateRecord(Id, ComplaintDescription, ComplaintBy);
							}
							else
							{
								cout << "\nThe id you entered doesn't exist\n";
							}

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the fir that you want to delete: ";
							cin >> Id;

							if (Firs->F_IdExists(Id))
							{
								Firs->F_Delete(Id);
								cout << "\nRecord against the entered id has been successfully deleted\n";
							}
							else
							{
								cout << "\nThe record that you want to delete doesn't exist\n";
							}

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the fir that you want to find: ";
							cin >> Id;

							if (Firs->F_IdExists(Id))
							{
								Firs->F_Search(Id);
							}
							else
							{
								cout << "\nfir not found\n";
							}

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

							if (Criminals->C_LimitReached())
							{
								char UpdateChoice;

								cout << "There's no more space to enter more records\n";
								cout << "Would you like to update system to support more entries? (Y/N): ";
								cout << "You choice: ";
								UpdateChoice = _getch();
								cout << UpdateChoice << endl;

								UpdateChoice = toupper(UpdateChoice);

								if (UpdateChoice == 'Y')
								{
									Criminals->C_Update();

									if (Criminals->C_IsDeletedEmpty())
									{
										Criminals->C_Add(C_Id, Offense, Name);
										C_LastEntered.push(C_Id);

										cout << "\nRecord entered successfully, Id assigned to this criminal is: " << C_Id << endl;

										C_Id++;
									}
									else
									{
										Criminals->C_Add(Criminals->C_GetDeletedId(), Offense, Name);
										C_LastEntered.push(C_Id);
										cout << "\nRecord entered successfully, Id assigned to this criminal is: " << Criminals->C_GetDeletedId() << endl;
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
								if (Criminals->C_IsDeletedEmpty())
								{
									Criminals->C_Add(C_Id, Offense, Name);
									C_LastEntered.push(C_Id);

									cout << "Record entered successfully, Id assigned to this criminal is: " << C_Id;

									C_Id++;
								}
								else
								{
									Criminals->C_Add(Criminals->C_GetDeletedId(), Offense, Name);
								}
							}

							break;
						}
						case 'B':
						{
							int Id;

							cout << "Entet the id of the criminal that you want to update: ";
							cin >> Id;

							if (Criminals->C_IdExists(Id))
							{
								Criminals->C_Search(Id);

								cin.ignore();

								cout << "Enter the new offense of the criminal: ";
								getline(cin, Offense);

								cout << "Enter the updated name of the criminal: ";
								getline(cin, Name);

								Criminals->C_UpdateRecord(Id, Offense, Name);
							}
							else
							{
								cout << "\nThe id you entered doesn't exist\n";
							}

							break;
						}
						case 'C':
						{
							int Id;

							cout << "Enter the id of the criminal that you want to delete: ";
							cin >> Id;

							if (Criminals->C_IdExists(Id))
							{
								Criminals->C_Delete(Id);
								cout << "\nRecord against the entered id has been successfully deleted\n";
							}
							else
							{
								cout << "\nThe record that you want to delete doesn't exist\n";
							}

							break;
						}
						case 'D':
						{
							int Id;

							cout << "Enter the id of the criminal that you want to find: ";
							cin >> Id;

							if (Criminals->C_IdExists(Id))
							{
								Criminals->C_Search(Id);
							}
							else
							{
								cout << "\nOfficer not found\n";
							}

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