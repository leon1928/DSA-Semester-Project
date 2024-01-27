#include "SystemAdmin.h"

using namespace std;

SystemAdmin::SystemAdmin()
{
	Passwords.push_back("BigManIsHere");
}

bool SystemAdmin::PasswordExists(string IncomingPassword)
{
	for (auto i{ 0 }; i < Passwords.size(); i++)
	{
		if (IncomingPassword == Passwords.at(i))
		{
			return true;
		}
	}
	return false;
}
