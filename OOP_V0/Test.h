// Команда "Тест"
#pragma once
#include "ICommand.h"
#include "Application.h"
#include "Sorts.h"
class TestCommand : public ICommand
{
    string name, description;
	Application *app;

public:
	TestCommand(Application *appl);
	
	virtual ~TestCommand(void);
	virtual void execute (vector <string> params);
	virtual const string & get_name() const;
	virtual const string & get_help() const;
};