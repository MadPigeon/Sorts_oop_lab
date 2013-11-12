//- Команда "Итерации"
#pragma once
#include "ICommand.h"
#include "Application.h"
class IterationsCommand : public ICommand
{	
	Application *app;
	string name, description;

public:
	IterationsCommand(Application *appl);

	 virtual ~IterationsCommand(void);
	 void execute (vector <string> params);
	 const string & get_name() const;
	 const string & get_help() const;
};