#include "P_List.h"

using namespace std;

P_List::P_List()
{
	for (int i{ 0 }; i < 10; i++)
	{
		Arr[i] = nullptr;
	}
}

void P_List::Add(int Id1, int Rank1, string Name1)
{
	if (Nodes == 0)
	{
		Nodes++;

		List->Id = Id1;
		List->Rank = Rank1;
		List->Name = Name1;

		Arr[Id1] = List;
		cout << "Here 1\n";
	}
	else
	{
		a:
		if (Id1 > List->Id && List->Right == nullptr)
		{
			List->Right = new P_Node;
			List->Right->Previous = List;
			cout << List->Right->Previous << endl << endl;
			List = List->Right;

			Nodes++;

			List->Id = Id1;
			List->Rank = Rank1;
			List->Name = Name1;
			cout << Deleted.empty();
			if (Deleted.empty())
			{
				Arr[Id1] = List;
				cout << "\nArray\n";
			}
			else
			{
				cout << "Array 2";
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}

			List = Root;
			cout << "Here 2\n";
		}
		else if (Id1 < List->Id && List->Left == nullptr)
		{
			List->Left = new P_Node;
			List->Left->Previous = List;
			cout << List->Left->Previous << endl << endl;
			List = List->Left;

			Nodes++;

			List->Id = Id1;
			List->Rank = Rank1;
			List->Name = Name1;

			if (Deleted.empty())
			{
				Arr[Id1] = List;
				cout << "\nArray\n";
			}
			else
			{
				cout << "Array 2";
				Arr[Deleted.top()] = List;
				Deleted.pop();
			}

			List = Root;
			cout << "Here 3\n";
		}
		else if (Id1 > List->Id && List->Right != nullptr)
		{
			List = List->Right;
			cout << "Here 4\n";
			goto a;
		}
		else if (Id1 < List->Id && List->Left != nullptr)
		{
			List = List->Left;
			cout << "Here 5\n";
			goto a;
		}
		else
		{
			//This section is reserved for the case when we have duplicate values in id even though no such case should exist due to how the system is coded
			cout << "Something went wrong, Hi from P_List.cpp line 86\n";
		}
	}
}

void P_List::Delete(int Id1)
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
			if (Id1 == List->Right->Id)
			{
				List->Right = nullptr;
				delete Temp;
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
			if (Id1 == List->Right->Id)
			{
				List->Right = Temp->Left;
				Temp->Left->Previous = List;
				Temp->Left = nullptr;
				delete Temp;
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
			if (Id1 == List->Right->Id)
			{
				List->Right = Temp->Right;
				Temp->Right->Previous = List;
				Temp->Right = nullptr;
				delete Temp;
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
				if (Id1 == List->Right->Id)
				{
					List->Right = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
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
				if (Id1 == List->Right->Id)
				{
					List->Right = TempRight;
					TempRight->Previous = List;
					TempRight = nullptr;
					delete TempRight;
					delete Temp;
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
				cout << "\nSomething went wrong, Hi from line 203 in P_List.cpp\n";
			}
		}
		Arr[Id1] = nullptr;
		Deleted.push(Id1);
	}
}

void P_List::Size()
{
	cout << sizeof(Arr);
}