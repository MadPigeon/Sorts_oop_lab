#pragma once
#include <vector>
#include <string>
#include "ICommand.h"
#include "Application.h"

using namespace std;

class RandomCommand: public ICommand
{
	string name, description;
	Application *app;

public:
	RandomCommand(Application *appl);
	virtual ~RandomCommand(void);

	virtual void execute (vector <string> params);
	virtual const string & get_name () const ;
	virtual const string & get_help () const;
};