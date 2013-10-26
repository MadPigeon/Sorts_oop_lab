// Команда " Помощь"
#pragma once
#include "ICommand.h"
#include "Application.h"
class Sequence : public ICommand
{
	string name, description;
	Application *app;
public:
	Sequence(Application *appl);
	
	virtual ~Sequence(void);
	virtual void execute (vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};