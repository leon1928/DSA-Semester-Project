#include "F_List.h"

using namespace std;

F_List::F_List()
{
	for (int i{ 0 }; i < 10; i++)
	{
		Arr[i] = nullptr;
	}
}

void F_List::F_Add(int Id1, string ComplaintDescription1, string ComplaintBy1)
{
	if (Nodes == 0)
	{
		Nodes++;

		List->Id = Id1;
		List->ComplaintDescription = ComplaintDescription1;
		List->ComplaintBy = ComplaintBy1;

		Arr[Id1] = List;
	}
	else
	{
	a:
		if (Id1 > List->Id && List->Right == nullptr)
		{
			List->Right = new F_Node;
			List->Right->Previous = List;
			List = List->Right;

			//Nodes++;

			List->Id = Id1;
			List->ComplaintDescription = ComplaintDescription1;
			List->ComplaintBy = ComplaintBy1;

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
			List->Left = new F_Node;
			List->Left->Previous = List;
			List = List->Left;

			//Nodes++;

			List->Id = Id1;
			List->ComplaintDescription = ComplaintDescription1;
			List->ComplaintBy = ComplaintBy1;

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
			cout << "Something went wrong, Hi from F_List.cpp line 89\n";
		}
	}
	EnteredElements++;
}

void F_List::F_Delete(int Id1)
{
	if (Id1 >= ArrSize || Id1 < 0)
	{
		cout << "\nInvalid Id entered\n";
	}
	else
	{
		List = Arr[Id1];

		F_Node* Temp = List;

		if (List != Root)
		{
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
					cout << "Something went wrong, Hi from line 124 of F_List.cpp\n";
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
					cout << "Something went wrong, Hi from line 145 of F_List.cpp\n";
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
					cout << "Something went wrong, Hi from line 166 of F_List.cpp\n";
				}
			}
			else //case where the node that is to be deleted has a both left and right
			{
				F_Node* TempLeft = Temp->Left;
				F_Node* TempRight = Temp->Right;
				F_Node* TraverseRight = Temp->Right;

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
						cout << "Something went wrong, Hi from line 212 of F_List.cpp\n";
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
						cout << "Something went wrong, Hi from line 242 of F_List.cpp\n";
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
						cout << "\nSomething went wrong, Hi from line 311 of F_List.cpp\n";
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
					cout << "\nSomething went wrong, Hi from line 282 in F_List.cpp\n";
				}
				TraverseRight = nullptr;
				delete TraverseRight;
			}
		}
		else
		{
			cout << "\nCan't do it chief, my developer is too lazy to implement the case the root element is to be deleted\n";
		}

		Arr[Id1] = nullptr;
		Deleted.push(Id1);
		EnteredElements--;
	}
}

void F_List::F_PrintAllArr()
{
	if (Nodes != 0)
	{
		cout << "\nAll the entries are:\n";
		for (int i{ 0 }; i < ArrSize; i++)
		{
			if (Arr[i] != nullptr)
			{
				cout << "Id: " << Arr[i]->Id << endl;
				cout << "Complaint By: " << Arr[i]->ComplaintBy << endl;
				cout << "Complaint Description: " << Arr[i]->ComplaintDescription << endl << endl;
			}
		}
	}
	else
	{
		cout << "\nThere are no entries to display\n";
	}

}

int F_List::F_NumberOfEntries()
{
	return EnteredElements;
}

int F_List::F_CurrentCapacity()
{
	return ArrSize;
}

bool F_List::F_LimitReached()
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

void F_List::F_Update()
{
	int TempSize = ArrSize;
	F_Node** TempArr = new F_Node * [TempSize];

	for (int i{ 0 }; i < ArrSize; i++)
	{
		TempArr[i] = Arr[i];
		Arr[i] = nullptr;
	}

	delete[] Arr;

	ArrSize *= 2;

	F_Node** Arr = new F_Node * [ArrSize];

	for (int i{ 0 }; i < TempSize; i++)
	{
		Arr[i] = TempArr[i];
		TempArr[i] = nullptr;
	}

	delete[] TempArr;

	cout << "\n Officers list update successful\n";
}

bool F_List::F_IdExists(int Id1)
{
	if (Id1 < ArrSize && Id1 >= 0 && Arr[Id1] != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void F_List::F_UpdateRecord(int Id1, string ComplaintDescription1, string ComplaintBy1)
{
	Arr[Id1]->ComplaintDescription = ComplaintDescription1;
	Arr[Id1]->ComplaintBy = ComplaintBy1;
	cout << "\nRecord updated successfully\n";
}

void F_List::F_Search(int Id1)
{
	cout << "\nRecord found:\n";
	cout << "ID: " << Arr[Id1]->Id << endl;
	cout << "Complaint Description:" << Arr[Id1]->ComplaintDescription << endl;
	cout << "Complaint By: " << Arr[Id1]->ComplaintBy << endl;
}

bool F_List::F_IsDeletedEmpty()
{
	return Deleted.empty();
}

int F_List::F_GetDeletedId()
{
	int Temp = Deleted.top();
	Deleted.pop();
	return Temp;
}