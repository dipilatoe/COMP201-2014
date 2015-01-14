#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string argv[1];
	cout << "Enter path to file to be read: ";
	cin >> argv[0];
	ifstream inf; ofstream ouf;
	inf.open(argv[0]); ouf.open("output.txt");
	int num, sum = 0;
	if (inf.fail())
	{
		return -1;
		cout << "The file failed to open.\n";
	}
	else
	{
		ouf << "x\tx^2\tCurrent Sum\n";
		ouf << "=\t===\t===========\n";
		while (inf >> num)
			ouf << num << "\t" << num * 2 << "\t" << sum + num << endl;
	}
	inf.close(); ouf.close();
	return 0;
}