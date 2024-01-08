#pragma once
#include "Libraries.h"

using namespace std;

class F_Node
{
	public:
		int Id;
		string ComplaintDescription;
		string ComplaintBy;
		F_Node* Left;
		F_Node* Right;
		F_Node* Previous;

		F_Node();
};