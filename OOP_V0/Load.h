// Команда "Загрузка последовательности из файла"
#pragma once
#include "ICommand.h"
#include "Application.h"
class LoadCommand : public ICommand
{	

	Application *app;
	string name, description;
public:
	LoadCommand(Application *appl);

	 virtual ~LoadCommand(void);
	 void execute (vector <string> params);
	 const string & get_name() const;
	 const string & get_help() const;
};
