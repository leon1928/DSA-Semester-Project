#pragma once
#include "Node.h"

using namespace std;

class Criminal
{
private:
	int Entries{ 0 };

	int ArrSize{ 10 };

	Node<int, string, string>** Arr = new Node<int, string, string>* [ArrSize];

	stack <int> Deleted;

public:
	Criminal();
	void Add(string Offense, string Name);
	void UpdateRecord(int Id, string Offense, string Name);
	void Delete(int Id);
	void Search(int Id);
	void PrintAll();
	void IncreaseCapacity();
	bool ValidId(int Id);
	bool IdExists(int Id);
};