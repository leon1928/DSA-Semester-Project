#include "C_List.h"

using namespace std;

C_List::C_List()
{
	for (int i{ 0 }; i < 10; i++)
	{
		Arr[i] = nullptr;
	}
}

void C_List::C_Add(int Id1, string Offense1, string Name1)
{
	if (Nodes == 0)
	{
		Nodes++;

		List->Id = Id1;
		List->Offense = Offense1;
		List->Name = Name1;

		Arr[Id1] = List;
	}
	else
	{
	a:
		if (Id1 > List->Id && List->Right == nullptr)
		{
			List->Right = new C_Node;
			List->Right->Previous = List;
			List = List->Right;

			//Nodes++;

			List->Id = Id1;
			List->Offense = Offense1;
			List->Name = Name1;

			/*if (Deleted.empty())
			{
				Arr[Id1] = List;
			}
			else
			{
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}*/

			Arr[Id1] = List;	//Remove this and make the commented part above part of the code again if things start acting up

			List = Root;
		}
		else if (Id1 < List->Id && List->Left == nullptr)
		{
			List->Left = new C_Node;
			List->Left->Previous = List;
			List = List->Left;

			//Nodes++;

			List->Id = Id1;
			List->Offense = Offense1;
			List->Name = Name1;

			/*if (Deleted.empty())
			{
				Arr[Id1] = List;
			}
			else
			{
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}*/

			Arr[Id1] = List;	//Remove this and make the commented part above part of the code again if things start acting up

			List = Root;
		}
		else if (Id1 > List->Id && List->Right != nullptr)
		{
			List = List->Right;
			goto a;
		}
		else if (Id1 < List->Id && List->Left != nullptr)
		{
			List = List->Left;
			goto a;
		}
		else
		{
			//This section is reserved for the case when we have duplicate values in id even though no such case should exist due to how the system is coded
			cout << "Something went wrong, Hi from C_List.cpp line 89\n";
		}
	}
	EnteredElements++;
}

void C_List::C_Delete(int Id1)
{
	if (Id1 >= ArrSize || Id1 < 0)
	{
		cout << "\nInvalid Id entered\n";
	}
	else
	{
		List = Arr[Id1];

		C_Node* Temp = List;
		//cout << List->Previous << endl;
		List = List->Previous;
		Temp->Previous = nullptr; //Just to make sure the delete keyword doesn't delete everything in the previous as well

		if (Temp->Left == nullptr && Temp->Right == nullptr)	//case where the nodes both left and right are null
		{
			if (List->Left != nullptr)
			{
				if (Id1 == List->Left->Id)	//error to be resolved (crashes code as the condition tries to check left id even if it doesn't exist)
				{
					List->Left = nullptr;
					delete Temp;
				}
			}
			else if (List->Right != nullptr)
			{
				if (Id1 == List->Right->Id)
				{
					List->Right = nullptr;
					delete Temp;
				}
			}
			else
			{
				cout << "Something went wrong, Hi from line 124 of C_List.cpp\n";
			}
		}
		else if (Temp->Left != nullptr && Temp->Right == nullptr)	//case where the node has a left and the right is null
		{
			if (List->Left != nullptr)
			{
				if (Id1 == List->Left->Id)
				{
					List->Left = Temp->Left;
					Temp->Left->Previous = List;
					Temp->Left = nullptr;
					delete Temp;
				}
			}
			else if (List->Right != nullptr)
			{
				if (Id1 == List->Right->Id)
				{
					List->Right = Temp->Left;
					Temp->Left->Previous = List;
					Temp->Left = nullptr;
					delete Temp;
				}
			}
			else
			{
				cout << "Something went wrong, Hi from line 145 of C_List.cpp\n";
			}
		}
		else if (Temp->Right != nullptr && Temp->Left == nullptr)	//case where the node has a right and left is null
		{
			if (List->Left != nullptr)
			{
				if (Id1 == List->Left->Id)
				{
					List->Left = Temp->Right;
					Temp->Right->Previous = List;
					Temp->Right = nullptr;
					delete Temp;
				}
			}
			else if (List->Right != nullptr)
			{
				if (Id1 == List->Right->Id)
				{
					List->Right = Temp->Right;
					Temp->Right->Previous = List;
					Temp->Right = nullptr;
					delete Temp;
				}
			}
			else
			{
				cout << "Something went wrong, Hi from line 166 of C_List.cpp\n";
			}
		}
		else //case where the node that is to be deleted has a both left and right
		{
			C_Node* TempLeft = Temp->Left;
			C_Node* TempRight = Temp->Right;
			C_Node* TraverseRight = Temp->Right;

			Temp->Left = nullptr;
			Temp->Right = nullptr;

			TempLeft->Previous = nullptr;
			TempRight->Previous = nullptr;

			TempRight->Previous = List;

		b:
			if (TempRight->Left == nullptr)
			{
				TempRight->Left = TempLeft;
				TempLeft->Previous = TempRight;

				TempLeft = nullptr;
				delete TempLeft;

				//TempRight->Previous = List;

				if (List->Left != nullptr)
				{
					if (Id1 == List->Left->Id)
					{
						List->Left = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else if (List->Right != nullptr)
				{
					if (Id1 == List->Right->Id)
					{
						List->Right = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else
				{
					cout << "Something went wrong, Hi from line 212 of C_List.cpp\n";
				}

			}
			else if (TempLeft->Id < TraverseRight->Left->Id && TempRight->Left->Left == nullptr)
			{
				TempRight->Left->Left = TempLeft;
				TempLeft->Previous = TempRight->Left;

				TempLeft = nullptr;
				delete TempLeft;

				if (List->Left != nullptr)
				{
					if (Id1 == List->Left->Id)
					{
						List->Left = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else if (List->Right != nullptr)
				{
					if (Id1 == List->Right->Id)
					{
						List->Right = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else
				{
					cout << "Something went wrong, Hi from line 242 of C_List.cpp\n";
				}
			}
			else if (TempLeft->Id > TraverseRight->Left->Id && TempRight->Left->Right == nullptr)
			{
				TempRight->Left->Right = TempLeft;
				TempLeft->Previous = TempRight->Right;

				TempLeft = nullptr;
				delete TempLeft;

				if (List->Left != nullptr)
				{
					if (Id1 == List->Left->Id)
					{
						List->Left = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else if (List->Right != nullptr)
				{
					if (Id1 == List->Right->Id)
					{
						List->Right = TempRight;
						TempRight->Previous = List;
						TempRight = nullptr;
						delete TempRight;
						delete Temp;
					}
				}
				else
				{
					cout << "\nSomething went wrong, Hi from line 311 of C_List.cpp\n";
				}
			}
			else if (TempLeft->Id < TraverseRight->Left->Id && TempRight->Left->Left != nullptr)
			{
				TraverseRight = TraverseRight->Left->Left;
				goto b;
			}
			else if (TempLeft->Id > TraverseRight->Left->Id && TempRight->Left->Right != nullptr)
			{
				TraverseRight = TraverseRight->Left->Right;
				goto b;
			}
			else
			{
				cout << "\nSomething went wrong, Hi from line 282 in C_List.cpp\n";
			}
			TraverseRight = nullptr;
			delete TraverseRight;
		}
		Arr[Id1] = nullptr;
		Deleted.push(Id1);
		EnteredElements--;
	}
}

void C_List::C_PrintAllArr()
{
	if (Nodes != 0)
	{
		cout << "\nAll the entries are:\n";
		for (int i{ 0 }; i < ArrSize; i++)
		{
			if (Arr[i] != nullptr)
			{
				cout << "Id: " << Arr[i]->Id << endl;
				cout << "Name: " << Arr[i]->Name << endl;
				cout << "Offense: " << Arr[i]->Offense << endl << endl;
			}
		}
	}
	else
	{
		cout << "\nThere are no entries to display\n";
	}

}

int C_List::C_NumberOfEntries()
{
	return EnteredElements;
}

int C_List::C_CurrentCapacity()
{
	return ArrSize;
}

bool C_List::C_LimitReached()
{
	if (EnteredElements == ArrSize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void C_List::C_Update()
{
	int TempSize = ArrSize;
	C_Node** TempArr = new C_Node * [TempSize];

	for (int i{ 0 }; i < ArrSize; i++)
	{
		TempArr[i] = Arr[i];
		Arr[i] = nullptr;
	}

	delete[] Arr;

	ArrSize *= 2;

	C_Node** Arr = new C_Node * [ArrSize];

	for (int i{ 0 }; i < TempSize; i++)
	{
		Arr[i] = TempArr[i];
		TempArr[i] = nullptr;
	}

	delete[] TempArr;

	cout << "\n Officers list update successful\n";
}

bool C_List::C_IdExists(int Id1)
{
	if (Id1 < ArrSize && Id1 > 0 && Arr[Id1] != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void C_List::C_UpdateRecord(int Id1, string Offense1, string Name1)
{
	Arr[Id1]->Offense = Offense1;
	Arr[Id1]->Name = Name1;
	cout << "\nRecord updated successfully\n";
}

void C_List::C_Search(int Id1)
{
	cout << "\nRecord found:\n";
	cout << "ID: " << Arr[Id1] << endl;
	cout << "Offense:" << Arr[Id1] << endl;
	cout << "Name: " << Arr[Id1] << endl;
}

bool C_List::C_IsDeletedEmpty()
{
	return Deleted.empty();
}

int C_List::C_GetDeletedId()
{
	int Temp = Deleted.top();
	Deleted.pop();
	return Temp;
}