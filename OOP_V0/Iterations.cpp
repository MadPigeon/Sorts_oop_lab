#include <vector>
#include <string>
#include <iostream>

#include "Iterations.h"
using namespace std;
IterationsCommand::IterationsCommand(Application *appl) : name("iterations"),
description("Задает количество итераций для теста массива"),app(appl)
{
	app = appl;
}
void IterationsCommand:: execute (vector <string> params)
{
	app->try_get_set(params);
	int i, temp;
	char number[10];
	int iter_size = params[0].length();
	if (iter_size != 0)
	{
		for(i = 0; i < iter_size; i++)// Записываем число в массив Number
			{	
				number[i] = params[0][i];
			}
		temp = atol(number);
		if(temp > 0)
		{
			app->set_iter(temp); 
		}
	}
}
IterationsCommand::~IterationsCommand(void){}
const string & IterationsCommand::get_name() const
{
	return name;
}
const string & IterationsCommand:: get_help() const
{
	return description;
}