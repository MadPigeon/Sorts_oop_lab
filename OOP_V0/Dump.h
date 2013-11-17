// - Вывод переменной
#pragma once
#include "ICommand.h"
#include "Application.h"


class DumpCommand: public ICommand
{
private:
	Application *app;
	string name, description;
public:
	DumpCommand (Application *appl);
	virtual ~DumpCommand ( void );

	virtual void execute ( vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};