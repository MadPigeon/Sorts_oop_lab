#include "Application.h"
#include "ICommand.h"
#include "Help.h"
#include "Exit.h"
#include "Sequence.h"
#include "Print.h"
#include "Random.h"
#include "Iterations.h"

#include "Functions.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

Application::Application() : iter(100)
{
	add_command(new HelpCommand(this));
	add_command(new Exit(this));
	add_command(new Sequence(this));
	add_command(new PrintCommand(this));
	add_command(new RandomCommand(this));
	add_command(new IterationsCommand(this));
}
Application::~Application(void)
{
	for (int i = 0; i < commands.size(); i++)
	{
		delete commands[i];
	}
}
ICommand *Application::get_command(const string & key)
{
	if (commandMap.find(key) == commandMap.end())
		return 0;
	return commandMap[key];
}

const vector<ICommand *> & Application::get_command_list() const
{
	return commands;
}
	
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
		params.clear();
		parse_str(input, params);
		if (cmd = get_command(name))
		{
			cmd->execute(params);
		}
		else
		{
			out << " оманда не найдена. Ќе будем показывать пальцем,"
				<< "но кто-то допустил ошибку.\n";
		}
	}
}
	
void Application::add_command(ICommand * cmd)
{
	commandMap[cmd->get_name()] = cmd;
	commands.push_back(cmd);
}

void Application::parse_str(string & input, vector<string> & list)
{
	string temp;	// переменна€ дл€ копировани€ и проверки
	stringstream sstream;	// поток строк дл€ разделени€
	sstream << input;	// складываем строку в String Builder
	while (!sstream.eof())	// складываем в вектор строки по одной
	{
		sstream >> temp;
		list.push_back(temp);
	}
}
void Application::add_to_arr(long val)
{
	arr.push_back(val);
}
vector <int> & Application::get_arr()
{
	return arr;
}
void Application::clear_arr()
{
	arr.clear();
}
void Application::set_iter(long val)
{
	iter = val;
}
long Application::get_iter()
{
	return iter;
}