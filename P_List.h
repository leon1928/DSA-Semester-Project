#pragma once
#include "P_Node.h"

using namespace std;

class P_List
{
	public:
		int Nodes{ 0 };
		P_Node* List = new P_Node;
		P_Node* Root = List;

		int ArrSize{ 10 };
		P_Node** Arr = new P_Node* [ArrSize];

		int EnteredElements{ 0 };

		stack <int> Deleted;

		P_List();
		void P_Add(int Id1, int Rank1, string Name1);
		void P_UpdateRecord(int Id1, int Rank1, string Name1);
		void P_Delete(int Id1);
		void P_PrintAllArr();
		int P_NumberOfEntries();
		int P_CurrentCapacity();
		bool P_LimitReached();
		void P_Update();
		bool P_IdExists(int Id1);
		void P_Search(int Id1);
		void Size();
};