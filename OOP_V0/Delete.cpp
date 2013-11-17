#include "Delete.h"
#include "Application.h"

void DeleteCommand::execute(vector <string> params)
{
	bool success = false;
	cout << "���������� ";
	if (params.size() > 0)
	{
		string before = params[0];
		cout << params[0];
		app->try_delete_set(params);
		if (params[0] != before) success = true;
	}
	if (success) cout << " �������.";
	else cout << " �� ����������.";
	cout << endl;
}
const string & DeleteCommand::get_name() const{ return name; }
const string & DeleteCommand::get_help() const{ return description; }
DeleteCommand::DeleteCommand(Application *appl): name("del"), description("�������� ����������"), app(appl){}
DeleteCommand::~DeleteCommand(){}