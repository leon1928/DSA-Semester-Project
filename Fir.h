#pragma once
#include "Node.h"

using namespace std;

class Fir
{
private:
	int Entries{ 0 };

	int ArrSize{ 10 };

	Node<int, string, string>** Arr = new Node<int, string, string>* [ArrSize];

	stack <int> Deleted;

public:
	Fir();
	void Add(string ComplaintDescription, string ComplaintBy);
	void UpdateRecord(int Id, string ComplaintDescription, string ComplaintBy);
	void Delete(int Id);
	void Search(int Id);
	void PrintAll();
	void IncreaseCapacity();
	bool ValidId(int Id);
	bool IdExists(int Id);
};