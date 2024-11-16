#include "Police.h"

using namespace std;

Police::Police()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		Arr[i] = nullptr;
	}
}

void Police::Add(int Rank, string Name)
{
TryAgain:
	if (Entries != ArrSize - 1)
	{
		if (Deleted.empty())
		{
			Arr[Entries] = new Node<int, int, string>(Entries, Rank, Name);
			cout << "\nThe ID assigned to this Police is: " << Entries << "\n";
		}
		else
		{
			Arr[Deleted.top()] = new Node<int, int, string>(Deleted.top(), Rank, Name);
			cout << "\nThe ID assigned to this Police is: " << Deleted.top() << "\n";
		}
		Entries++;
	}
	else
	{
		cout << "\nCapacity reached, hold on while we increase the capacity\n";
		cout << "\nIncreasing capacity...\n";

		IncreaseCapacity();

		cout << "\nCapacity increased successfully\n";

		goto TryAgain;
	}
}
void Police::UpdateRecord(int Id, int Rank, string Name)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			Arr[Id]->Second = Rank;
			Arr[Id]->Third = Name;
			cout << "\nRecord updated successfully\n";
		}
	}
}
void Police::Delete(int Id)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			Node<int, int, string>* Temp = Arr[Id];
			Arr[Id] = nullptr;
			Deleted.push(Id);
			Entries--;
			delete Temp;
			cout << "\nRecord of id " << Id << " has been deleted successfully\n";
		}
	}
}

void Police::Search(int Id)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			cout << "\nThe record against the searched id " << Id << " is as follows:\n";
			cout << "Name: " << Arr[Id]->Third << endl;
			cout << "Rank: " << Arr[Id]->Second << endl;
		}
	}
}

void Police::PrintAll()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		if (Arr[i] != nullptr)
		{
			cout << "\nId: " << Arr[i]->First << endl;
			cout << "Name: " << Arr[i]->Third << endl;
			cout << "Rank: " << Arr[i]->Second << endl;
		}
	}
}

void Police::IncreaseCapacity()
{
	int OldCapacity = ArrSize;
	Node<int, int, string>** Temp = new Node<int, int, string>* [OldCapacity];

	for (int i{ 0 }; i < OldCapacity; i++)
	{
		Temp[i] = Arr[i];
		Arr[i] = nullptr;
	}

	delete[] Arr;

	ArrSize *= 2;

	Node<int, int, string>** Arr = new Node<int, int, string>* [ArrSize];

	for (int i{ 0 }; i < OldCapacity; i++)
	{
		Arr[i] = Temp[i];
		Temp[i] = nullptr;
	}

	delete[] Temp;

	for (int i{ OldCapacity }; i < ArrSize; i++)
	{
		Arr[i] = nullptr;
	}

}

bool Police::ValidId(int Id)
{
	if (Id >= 0 && Id < Entries)
	{
		return true;
	}
	else
	{
		cout << "\nInvalid Id\n";
		return false;
	}
}

bool Police::IdExists(int Id)
{
	if (Arr[Id] != nullptr)
	{
		return true;
	}
	else
	{
		cout << "\nThe record on which you want to perform this operation doesn't exist\n";
		return false;
	}
}