#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Set.h"

using namespace std;

SetCommand::SetCommand(Application *appl) : name("set"), description("Задает значение переменной"), app(appl) {}

void SetCommand::execute (vector <string> params)
{
	string name = params[0];
	params.erase(params.begin());
	if (params[0][0] < '0' || params[0][0] > '9')
	{
		params[0].erase(params[0].begin());
		params[params.size() - 1].erase(params[params.size() - 1].end() - 1);
	}
	app->add_to_set(name, params);
}
SetCommand::~SetCommand(void){}
const string & SetCommand::get_name() const
{
	return name;
}
const string & SetCommand:: get_help() const
{
	return description;
}