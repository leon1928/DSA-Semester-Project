#pragma once
#include "Node.h"

using namespace std;

class Police
{
private:
	int Entries{ 0 };

	int ArrSize{ 10 };

	Node<int, int, string>** Arr = new Node<int, int, string>* [ArrSize];

	stack <int> Deleted;

public:
	Police();
	void Add(int Rank, string Name);
	void UpdateRecord(int Id, int Rank, string Name);
	void Delete(int Id);
	void Search(int Id);
	void PrintAll();
	void IncreaseCapacity();
	bool ValidId(int Id);
	bool IdExists(int Id);
};