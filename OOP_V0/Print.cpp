#include <vector>
#include <string>
#include <iostream>

#include "Print.h"
using namespace std;
PrintCommand::PrintCommand(Application *appl) : name("print"),
description("Āūāīäčņ ģąńńčā"),app(appl)
{
	app = appl;
}
void PrintCommand:: execute (vector <string> params)
{	
	int i,n;
	vector <int> mass;
	mass = app -> get_arr();
	n = mass.size();
	if(n == 0)
	{
		cout << "Źīėč÷åńņāī čņåšąöčé "<< app->get_iter() <<endl;
		cout << "Ą ģąńńčā ķąńņīėüźī ļóńņ, ÷ņī %īņėč÷ķą’ ųóņźą ļšī ļóńņīé ģąńńčā%\n";
	}
	else
	{
		cout << endl << "\n";
		for(i = 0; i < n; i++)
		{
			cout << ' ' << mass[i] << ' ';
		}
		cout << endl << "\n";
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