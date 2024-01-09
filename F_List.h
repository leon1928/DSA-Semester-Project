#pragma once
#include "F_Node.h"

using namespace std;

class F_List
{
public:
	int Nodes{ 0 };
	F_Node* List = new F_Node;
	F_Node* Root = List;

	int ArrSize{ 10 };
	F_Node** Arr = new F_Node * [ArrSize];

	int EnteredElements{ 0 };

	stack <int> Deleted;

	F_List();
	void F_Add(int Id1, string ComplaintDescription1, string Name1);
	void F_UpdateRecord(int Id1, string ComplaintDescription1, string Name1);
	void F_Delete(int Id1);
	void F_PrintAllArr();
	int F_NumberOfEntries();
	int F_CurrentCapacity();
	bool F_LimitReached();
	void F_Update();
	bool F_IdExists(int Id1);
	bool F_IsDeletedEmpty();
	void F_Search(int Id1);
	int F_GetDeletedId();
};