#include <vector>
#include <map>
#include <string>
#include "Random.h"

using namespace std;

RandomCommand::RandomCommand(Application *appl):app(appl),name("random"),description("Генерирует случайный массив."){}

RandomCommand::~RandomCommand(void){}

void RandomCommand::execute (vector<string> params)
{	
	app->clear_arr();
	int length = rand()%100+1, i;
	long val;
	for (i = 0; i < length; i++)
	{
		val = rand()%10000-1000;
		app->add_to_arr(val);
	}
}

const string & RandomCommand::get_help() const
{	
	return description;
}

const string & RandomCommand::get_name () const
{
	return name;
}