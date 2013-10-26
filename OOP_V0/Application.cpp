#include "Application.h"
#include "ICommand.h"
#include "Help.h"
#include "Exit.h"
#include "Sequence.h"

#include "Functions.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Application::Application()
{
	add_command(new HelpCommand(this));
	add_command(new Exit(this));
	add_command(new Sequence(this));
}
Application::~Application(void)
{
	for (int i = 0; i < commands.size(); i++)
	{
		delete commands[i];
	}
};
ICommand *Application::get_command(const string & key)
{
	if (commandMap.find(key) == commandMap.end())
		return 0;
	return commandMap[key];
};

const vector<ICommand *> & Application::get_command_list() const
{
	return commands;
};
	
void Application::run(istream & in, ostream &out)
{
	ICommand * cmd;
	string input,name;
	vector<string> params;
	while (true)
	{
		out << "|:>";
		in >> name;
		getline(in, input);
		parse_str(input, params);
		if (cmd = get_command(name))
		{
			cmd->execute(params);
		}
		else
		{
			out << "Команда не найдена. Не будем показывать пальцем,"
				<< "но кто-то допустил ошибку.\n";
		}
	}
};
	
void Application::add_command(ICommand * cmd)
{
	commandMap[cmd->get_name()] = cmd;
	commands.push_back(cmd);
};