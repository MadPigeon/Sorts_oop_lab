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
#include <fstream>

using namespace std;

Application::Application() : iter(100) {}
Application::Application(int argc, char **argv) : iter(100)
{
	add_command(new HelpCommand(this));
	add_command(new Exit(this));
	add_command(new Sequence(this));
	add_command(new PrintCommand(this));
	add_command(new RandomCommand(this));
	add_command(new IterationsCommand(this));

	if (argc > 1)
	{
		ifstream the_file(argv[1]);
		string temp;
		while (getline(the_file, temp))
		{
			commands_from_file.push_back(temp);
		}
		the_file.close();
	}
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
	int i = 0, n = commands_from_file.size();
	while (true)
	{
		params.clear();
		out << "|:>";
		if (i < n)
		{
			// ������ ������ �� �����
			out << commands_from_file[i] << endl;
			parse_str(commands_from_file[i], params);
			name = params[0];
			params.erase(params.begin());
		}
		else
		{
			// ���������� ����
			in >> name;
			getline(in, input);
			parse_str(input, params);
		}

		if (cmd = get_command(name))
		{
			cmd->execute(params);
		}
		else
		{
			out << "������� �� �������. �� ����� ���������� �������,"
				<< "�� ���-�� �������� ������.\n";
		}
		i++;
	}
}
	
void Application::add_command(ICommand * cmd)
{
	commandMap[cmd->get_name()] = cmd;
	commands.push_back(cmd);
}

void Application::parse_str(string & input, vector<string> & list)
{
	string temp;	// ���������� ��� ����������� � ��������
	stringstream sstream;	// ����� ����� ��� ����������
	sstream << input;	// ���������� ������ � String Builder
	while (!sstream.eof())	// ���������� � ������ ������ �� �����
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