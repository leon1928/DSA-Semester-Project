#include "Node.h"

using namespace std;

class P_List
{
	public:
		int Nodes{ 0 };
		P_Node* List = new P_Node;
		P_Node* Root = List;

		int ArrSize{ 10 };
		int EnteredValues{ 0 };
		P_Node** Arr = new P_Node* [ArrSize];

		stack <int> Deleted;

		P_List();
		void Add(int Id1, int Rank1, string Name1);
		void Delete(int Id1);
		void Size();
};