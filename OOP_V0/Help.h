// Команда " Помощь"
#pragma once
#include "ICommand.h"
#include "Application.h"
class HelpCommand : public ICommand
{
	string name, description;
	Application *app;
public:
	HelpCommand(Application *appl);
	
	virtual ~HelpCommand(void);
	virtual void execute (vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};