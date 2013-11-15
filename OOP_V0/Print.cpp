#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Print.h"

using namespace std;

PrintCommand::PrintCommand(Application *appl) : name("print"), description("Āūāīäčņ ģąńńčā"), app(appl) {}

void PrintCommand::execute (vector <string> params)
{
	vector <int> mass = app->get_arr();
	int i, n = mass.size();
	if(n == 0)
	{
		cout << "Źīėč÷åńņāī čņåšąöčé " << app->get_iter() << endl;
		cout << "Ą ģąńńčā ķąńņīėüźī ļóńņ, ÷ņī %ųóņźą ļšī ļóńņīé ģąńńčā%\n";
	}
	else
	{
		cout << endl << "\n";
		for(i = 0; i < n; i++)
		{
			cout << ' ' << mass[i] << ' ';
		}
		cout << endl << "\n";
		if (params[0] != "")
		{
			ofstream the_file(params[0]);
			for (i = 0; i < n; i++)
			{
				the_file << mass[i] << " ";
			}
			the_file.close();
			cout << "Ņąźęå ļīńėåäīāąņåėüķīńņü ńīõšąķåķą ā ōąéė: \"" << params[0] << "\"\n";
		}
	}
}
PrintCommand::~PrintCommand(void){}
const string & PrintCommand::get_name() const
{
	return name;
}
const string & PrintCommand:: get_help() const
{
	return description;
}