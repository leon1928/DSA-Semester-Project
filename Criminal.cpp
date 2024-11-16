#include "Criminal.h"

using namespace std;

Criminal::Criminal()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		Arr[i] = nullptr;
	}
}

void Criminal::Add(string Offense, string Name)
{
	TryAgain:
	if (Entries != ArrSize - 1)
	{
		if (Deleted.empty())
		{
			Arr[Entries] = new Node<int, string, string>(Entries, Offense, Name);
			cout << "\nThe ID assigned to this criminal is: " << Entries << "\n";
		}
		else
		{
			Arr[Deleted.top()] = new Node<int, string, string>(Deleted.top(), Offense, Name);
			cout << "\nThe ID assigned to this criminal is: " << Deleted.top() << "\n";
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
void Criminal::UpdateRecord(int Id, string Offense, string Name)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			Arr[Id]->Second = Offense;
			Arr[Id]->Third = Name;
			cout << "\nRecord updated successfully\n";
		}
	}
}
void Criminal::Delete(int Id)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			Node<int, string, string>* Temp = Arr[Id];
			Arr[Id] = nullptr;
			Deleted.push(Id);
			Entries--;
			delete Temp;
			cout << "\nRecord of id " << Id << " has been deleted successfully\n";
		}
	}
}

void Criminal::Search(int Id)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			cout << "\nThe record against the searched id " << Id << " is as follows:\n";
			cout << "Name: " << Arr[Id]->Third << endl;
			cout << "Offense: " << Arr[Id]->Second << endl;
		}
	}
}

void Criminal::PrintAll()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		if (Arr[i] != nullptr)
		{
			cout << "\nId: " << Arr[i]->First << endl;
			cout << "Name: " << Arr[i]->Third << endl;
			cout << "Offense: " << Arr[i]->Second << endl;
		}
	}
}

void Criminal::IncreaseCapacity()
{
	int OldCapacity = ArrSize;
	Node<int, string, string>** Temp = new Node<int, string, string>* [OldCapacity];

	for (int i{ 0 }; i < OldCapacity; i++)
	{
		Temp[i] = Arr[i];
		Arr[i] = nullptr;
	}

	delete[] Arr;

	ArrSize *= 2;

	Node<int, string, string>** Arr = new Node<int, string, string>* [ArrSize];

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

bool Criminal::ValidId(int Id)
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

bool Criminal::IdExists(int Id)
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