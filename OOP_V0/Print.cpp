#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Print.h"

using namespace std;

PrintCommand::PrintCommand(Application *appl) : name("print"), description("Âûâîäèò ìàññèâ"), app(appl) {}

void PrintCommand::execute (vector <string> params)
{
	vector <int> mass = app->get_arr();
	int i, n = mass.size();
	if(n == 0)
	{
		cout << "Êîëè÷åñòâî èòåğàöèé " << app->get_iter() << endl;
		cout << "À ìàññèâ íàñòîëüêî ïóñò, ÷òî %øóòêà ïğî ïóñòîé ìàññèâ%\n";
	}
	else
	{
		cout << endl << "————————————————————————————————————————————————————————————————————\n";
		for(i = 0; i < n; i++)
		{
			cout << ' ' << mass[i] << ' ';
		}
		cout << endl << "————————————————————————————————————————————————————————————————————\n";
		if (params[0] != "")
		{
			ofstream the_file(params[0]);
			for (i = 0; i < n; i++)
			{
				the_file << mass[i] << " ";
			}
			the_file.close();
			cout << "Òàêæå ïîñëåäîâàòåëüíîñòü ñîõğàíåíà â ôàéë: \"" << params[0] << "\"\n";
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