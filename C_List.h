#pragma once
#include "C_Node.h"

using namespace std;

class C_List
{
public:
	int Nodes{ 0 };
	C_Node* List = new C_Node;
	C_Node* Root = List;

	int ArrSize{ 10 };
	C_Node** Arr = new C_Node * [ArrSize];

	int EnteredElements{ 0 };

	stack <int> Deleted;

	C_List();
	void C_Add(int Id1, string Offense1, string Name1);
	void C_UpdateRecord(int Id1, string Offense1, string Name1);
	void C_Delete(int Id1);
	void C_PrintAllArr();
	int C_NumberOfEntries();
	int C_CurrentCapacity();
	bool C_LimitReached();
	void C_Update();
	bool C_IdExists(int Id1);
	bool C_IsDeletedEmpty();
	void C_Search(int Id1);
	int C_GetDeletedId();
};