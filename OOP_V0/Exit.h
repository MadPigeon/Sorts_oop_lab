//- Выход из программы
#pragma once
#include "ICommand.h"
#include "Application.h"


class Exit: public ICommand
{
private:
	string name, description;
public:
	Exit (Application *appl);
	virtual ~Exit ( void );

	virtual void execute ( vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};