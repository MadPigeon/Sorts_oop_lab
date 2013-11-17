#include "Dump.h"
#include "Application.h"

void DumpCommand::execute(vector <string> params)
{
	bool success = false;
	cout << "Переменная ";
	if (params.size() > 0)
	{
		string before = params[0];
		cout << params[0];
		app->try_get_set(params);
		if (params[0] != before) success = true;
	}
	if (success) cout << " = " << params[0];
	else cout << "не существует.";
	cout << endl;
}
const string & DumpCommand::get_name() const{ return name; }
const string & DumpCommand::get_help() const{ return description; }
DumpCommand::DumpCommand(Application *appl): name("dump"), description("Вывод переменной"), app(appl){}
DumpCommand::~DumpCommand(){}