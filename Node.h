#pragma once
#include "Libraries.h"

using namespace std;

class P_Node
{
	public:
		int Id;
		int Rank;
		string Name;
		P_Node* Left;
		P_Node* Right;
		P_Node* Previous;

		P_Node();
};