#include "P_List.h"

using namespace std;

P_List::P_List()
{
	for (int i{ 0 }; i < 10; i++)
	{
		Arr[i] = nullptr;
	}
}

void P_List::P_Add(int Id1, int Rank1, string Name1)
{
	if (Nodes == 0)
	{
		Nodes++;

		List->Id = Id1;
		List->Rank = Rank1;
		List->Name = Name1;

		Arr[Id1] = List;
	}
	else
	{
		a:
		if (Id1 > List->Id && List->Right == nullptr)
		{
			List->Right = new P_Node;
			List->Right->Previous = List;
			List = List->Right;

			Nodes++;

			List->Id = Id1;
			List->Rank = Rank1;
			List->Name = Name1;

			if (Deleted.empty())
			{
				Arr[Id1] = List;
			}
			else
			{
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}

			List = Root;
		}
		else if (Id1 < List->Id && List->Left == nullptr)
		{
			List->Left = new P_Node;
			List->Left->Previous = List;
			List = List->Left;

			Nodes++;

			List->Id = Id1;
			List->Rank = Rank1;
			List->Name = Name1;

			if (Deleted.empty())
			{
				Arr[Id1] = List;
			}
			else
			{
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}

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
			cout << "Something went wrong, Hi from P_List.cpp line 89\n";
		}
	}
	EnteredElements++;
}

void P_List::P_Delete(int Id1)
{
	if (Id1 >= ArrSize || Id1 < 0)
	{
		cout << "\nInvalid Id entered\n";
	}
	else
	{
		List = Arr[Id1];

		P_Node* Temp = List;
		//cout << List->Previous << endl;
		List = List->Previous;
		Temp->Previous = nullptr; //Just to make sure the delete keyword doesn't delete everything in the previous as well

		if (Temp->Left == nullptr && Temp->Right == nullptr)	//case where the nodes both left and right are null
		{
			if (Id1 == List->Left->Id)
			{
				List->Left = nullptr;
				delete Temp;
			}
			else if (Id1 == List->Right->Id)
			{
				List->Right = nullptr;
				delete Temp;
			}
			else
			{
				cout << "Something went wrong, Hi from line 124 of P_List.cpp\n";
			}
		}
		else if (Temp->Left != nullptr && Temp->Right == nullptr)	//case where the node has a left and the right is null
		{
			if (Id1 == List->Left->Id)
			{
				List->Left = Temp->Left;
				Temp->Left->Previous = List;
				Temp->Left = nullptr;
				delete Temp;
			}
			else if (Id1 == List->Right->Id)
			{
				List->Right = Temp->Left;
				Temp->Left->Previous = List;
				Temp->Left = nullptr;
				delete Temp;
			}
			else
			{
				cout << "Something went wrong, Hi from line 145 of P_List.cpp\n";
			}
		}
		else if (Temp->Right != nullptr && Temp->Left == nullptr)	//case where the node has a right and left is null
		{
			if (Id1 == List->Left->Id)
			{
				List->Left = Temp->Right;
				Temp->Right->Previous = List;
				Temp->Right = nullptr;
				delete Temp;
			}
			else if (Id1 == List->Right->Id)
			{
				List->Right = Temp->Right;
				Temp->Right->Previous = List;
				Temp->Right = nullptr;
				delete Temp;
			}
			else
			{
				cout << "Something went wrong, Hi from line 166 of P_List.cpp\n";
			}
		}
		else //case where the node that is to be deleted has a both left and right
		{
			P_Node* TempLeft = Temp->Left;
			P_Node* TempRight = Temp->Right;
			P_Node* TraverseRight = Temp->Right;

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

				if (Id1 == List->Left->Id)
				{
					List->Left = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
				}
				else if (Id1 == List->Right->Id)
				{
					List->Right = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
				}
				else
				{
					cout << "Something went wrong, Hi from line 212 of P_List.cpp\n";
				}
				
			}
			else if (TempLeft->Id < TraverseRight->Left->Id && TempRight->Left->Left == nullptr)
			{
				TempRight->Left->Left = TempLeft;
				TempLeft->Previous = TempRight->Left;

				TempLeft = nullptr;
				delete TempLeft;

				if (Id1 == List->Left->Id)
				{
					List->Left = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
				}
				else if (Id1 == List->Right->Id)
				{
					List->Right = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
				}
				else
				{
					cout << "Something went wrong, Hi from line 242 of P_List.cpp\n";
				}
			}
			else if (TempLeft->Id > TraverseRight->Left->Id && TempRight->Left->Right == nullptr)
			{
				TempRight->Left->Right = TempLeft;
				TempLeft->Previous = TempRight->Right;

				TempLeft = nullptr;
				delete TempLeft;

				if (Id1 == List->Left->Id)
				{
					List->Left = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
				}
				if (Id1 == List->Right->Id)
				{
					List->Right = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
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
				cout << "\nSomething went wrong, Hi from line 282 in P_List.cpp\n";
			}
			TraverseRight = nullptr;
			delete TraverseRight;
		}
		Arr[Id1] = nullptr;
		Deleted.push(Id1);
		EnteredElements--;
	}
}

void P_List::P_PrintAllArr()
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
				cout << "Rank: " << Arr[i]->Rank << endl << endl;
			}
		}
	}
	else
	{
		cout << "\nThere are no entries to display\n";
	}
	
}

int P_List::P_NumberOfEntries()
{
	return EnteredElements;
}

int P_List::P_CurrentCapacity()
{
	return ArrSize;
}

bool P_List::P_LimitReached()
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

void P_List::P_Update()
{
	int TempSize = ArrSize;
	P_Node** TempArr = new P_Node * [TempSize];

	for (int i{ 0 }; i < ArrSize; i++)
	{
		TempArr[i] = Arr[i];
		Arr[i] = nullptr;
	}

	delete[] Arr;

	ArrSize *= 2;

	P_Node** Arr = new P_Node * [ArrSize];

	for (int i{ 0 }; i < TempSize; i++)
	{
		Arr[i] = TempArr[i];
		TempArr[i] = nullptr;
	}

	delete[] TempArr;

	cout << "\n Officers list update successful\n";
}

bool P_List::P_IdExists(int Id1)
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

void P_List::P_UpdateRecord(int Id1, int Rank1, string Name1)
{
	Arr[Id1]->Rank = Rank1;
	Arr[Id1]->Name = Name1;
	cout << "\nRecord updated successfully\n";
}

void P_List::P_Search(int Id1)
{
	cout << "\nRecord found:\n";
	cout << "ID: " << Arr[Id1] << endl;
	cout << "Rank:" << Arr[Id1] << endl;
	cout << "Name: " << Arr[Id1] << endl;
}

void P_List::Size()
{
	cout << sizeof(Arr);
}