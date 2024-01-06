#include "P_List.h"
using namespace std;

int main()
{
	P_List a;
	//a.Size();
	cout << "\nEntering 5:\n";
	a.Add(5, 0, "a");
	cout << "\nEntering 7:\n";
	a.Add(7, 0, "b");
	cout << "\nEntering 2:\n";
	a.Add(2, 0, "c");
	cout << "\nEntering 3:\n";
	a.Add(3, 0, "d");
	cout << "\nEntering 1:\n";
	a.Add(1, 0, "e");
	cout << "\nEntering 6:\n";
	a.Add(6, 0, "f");
	cout << "\nEntering 8:\n";
	a.Add(8, 0, "g");
	cout << a.Arr[5] << endl;
	cout << a.Arr[7] << endl;
	cout << a.Arr[2] << endl;
	cout << a.Arr[3] << endl;
	cout << a.Arr[1] << endl;
	cout << a.Arr[6] << endl;
	cout << a.Arr[8] << endl;
	a.Delete(7);

	return 0;
}