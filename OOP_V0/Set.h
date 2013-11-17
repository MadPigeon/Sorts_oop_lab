// Комадна "Задание переменной"
#pragma once
#include "ICommand.h"
#include "Application.h"
class SetCommand : public ICommand
{	

	Application *app;
	string name, description;
public:
	SetCommand(Application *appl);

	 virtual ~SetCommand(void);
	 void execute (vector <string> params);
	 const string & get_name() const;
	 const string & get_help() const;
};