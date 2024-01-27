#pragma once
#include "Libraries.h"

using namespace std;

class SystemAdmin
{
	public:
		//vector<int> Ids;
		vector<string>Passwords;

		SystemAdmin();
		bool PasswordExists(string IncomingPassword);
};

