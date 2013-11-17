#include <fstream>
#include <iostream>
#include <string>

#include "Load.h"

using namespace std;

LoadCommand::LoadCommand(Application *appl): name("load"), description("Считывает последовательность из файла"),app(appl){}

void LoadCommand::execute(vector <string> params)
{
	ICommand *cmd = app->get_command("sequence");
	ifstream input_file(params[0]);
	app->clear_arr();
	if(input_file == NULL)
	{
		cout << "Не удалось загрузить последовательность\n";
	}
	else
	{
		while(!input_file.eof())
		{
			getline(input_file, params[0]);                
		}
		app->parse_str(params[0], params);
		cmd->execute(params);
		input_file.close();
		cout << "Последовательность загружена\n";
	}
}

LoadCommand::~LoadCommand(void){}

const string & LoadCommand:: get_name() const 
{
	return name;
}
const string & LoadCommand:: get_help() const
{
	return description;
}