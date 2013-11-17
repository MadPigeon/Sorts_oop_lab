#include "Dump.h"
#include "Application.h"

void DumpCommand::execute(vector <string> params)
{
	unsigned int i, n;
	bool success = false;
	cout << "Переменная ";
	if (params.size() > 0)
	{
		string before = params[0];
		cout << params[0];
		app->try_get_set(params);
		if (params[0] != before)
		{
			success = true;
			n = params.size();
			cout << " = ";
			if (n > 1)
			{
				cout << '[';
				for(i = 0; i < n - 1; i++)
				{
					cout << params[i] << ' ';
				}
				cout << params[ n - 1 ] << "]";
			}
			else if(params[0][0] >= '0' && params[0][0] <= '9')
			{
				cout << params[0];
			}
			else
			{
				cout << '"' << params[0] << '"';
			}
		}

	}
	if (!success) cout << " не существует.";
	cout << endl;
}
const string & DumpCommand::get_name() const{ return name; }
const string & DumpCommand::get_help() const{ return description; }
DumpCommand::DumpCommand(Application *appl): name("dump"), description("Вывод переменной"), app(appl){}
DumpCommand::~DumpCommand(){}