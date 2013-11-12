// Комадна "Вывод последовательности"
#pragma once
#include "ICommand.h"
#include "Application.h"
class PrintCommand : public ICommand
{	

	Application *app;
	string name, description;
public:
	PrintCommand(Application *appl);

	 virtual ~PrintCommand(void);
	 void execute (vector <string> params);
	 const string & get_name() const;
	 const string & get_help() const;
};