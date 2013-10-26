#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ICommand
{
public:
	virtual void execute (vector <string> params)=0;
	virtual const string & get_name() const = 0;
	virtual const string & get_help() const = 0;
};