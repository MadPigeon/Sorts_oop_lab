// - Удаление переменной
#pragma once
#include "ICommand.h"
#include "Application.h"


class DeleteCommand: public ICommand
{
private:
	Application *app;
	string name, description;
public:
	DeleteCommand (Application *appl);
	virtual ~DeleteCommand ( void );

	virtual void execute ( vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};