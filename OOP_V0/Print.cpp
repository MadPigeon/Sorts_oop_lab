#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Print.h"

using namespace std;

PrintCommand::PrintCommand(Application *appl) : name("print"), description("������� ������"), app(appl) {}

void PrintCommand::execute (vector <string> params)
{
	vector <int> mass = app->get_arr();
	int i, n = mass.size();
	if(n == 0)
	{
		cout << endl << "���������� �������� "<< app->get_iter() <<endl;
		cout << "� ������ ��������� ����, ��� %����� ��� ������ ������%\n";
		cout << "���������� �������� " << app->get_iter() << endl;
		cout << "� ������ ��������� ����, ��� %����� ��� ������ ������%\n";
	}
	else
	{
        cout << endl << "���������� �������� "<< app->get_iter() <<endl;
		cout << endl << "��������������������������������������������������������������������\n";
		for(i = 0; i < n; i++)
		{
			cout << ' ' << mass[i] << ' ';
		}
		cout << endl << "��������������������������������������������������������������������\n";
		if (params[0] != "")
		{
			ofstream output_file(params[0]);
			for (i = 0; i < n; i++)
			{
				output_file << mass[i] << " ";
			}
			output_file.close();
			cout << "����� ������������������ ��������� � ����: \"" << params[0] << "\"\n";
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