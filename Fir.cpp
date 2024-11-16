#include "Fir.h"

using namespace std;

Fir::Fir()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		Arr[i] = nullptr;
	}
}

void Fir::Add(string ComplaintDescription, string ComplaintBy)
{
TryAgain:
	if (Entries != ArrSize - 1)
	{
		if (Deleted.empty())
		{
			Arr[Entries] = new Node<int, string, string>(Entries, ComplaintDescription, ComplaintBy);
			cout << "\nThe ID assigned to this Fir is: " << Entries << "\n";
		}
		else
		{
			Arr[Deleted.top()] = new Node<int, string, string>(Deleted.top(), ComplaintDescription, ComplaintBy);
			cout << "\nThe ID assigned to this Fir is: " << Deleted.top() << "\n";
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
void Fir::UpdateRecord(int Id, string ComplaintDescription, string ComplaintBy)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			Arr[Id]->Second = ComplaintDescription;
			Arr[Id]->Third = ComplaintBy;
			cout << "\nRecord updated successfully\n";
		}
	}
}
void Fir::Delete(int Id)
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

void Fir::Search(int Id)
{
	if (ValidId(Id))
	{
		if (IdExists(Id))
		{
			cout << "\nThe record against the searched id " << Id << " is as follows:\n";
			cout << "ComplaintBy: " << Arr[Id]->Third << endl;
			cout << "ComplaintDescription: " << Arr[Id]->Second << endl;
		}
	}
}

void Fir::PrintAll()
{
	for (int i{ 0 }; i < ArrSize; i++)
	{
		if (Arr[i] != nullptr)
		{
			cout << "\nId: " << Arr[i]->First << endl;
			cout << "ComplaintBy: " << Arr[i]->Third << endl;
			cout << "ComplaintDescription: " << Arr[i]->Second << endl;
		}
	}
}

void Fir::IncreaseCapacity()
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

bool Fir::ValidId(int Id)
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

bool Fir::IdExists(int Id)
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