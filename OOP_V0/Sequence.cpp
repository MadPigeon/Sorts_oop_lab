#include <vector>
#include <string>
#include <iostream>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(Application *appl) : name("sequence"),
description("Команда создаёт массив из последующих чисел. Неверные значения игнорируются."), app(appl){}
void Sequence::execute(vector<string> params)
{
	/*Тут нужна магия какая-то.*/	
}
Sequence::~Sequence(void){};
const string & Sequence::get_name() const
{
	return name; 
};
const string & Sequence::get_help() const{return description;};
