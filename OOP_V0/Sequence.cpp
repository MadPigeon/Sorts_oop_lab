#include <vector>
#include <string>
#include <iostream>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(Application *appl) : name("sequence"),
description("������� ������ ������ �� ����������� �����. �������� �������� ������������."), app(appl){}
void Sequence::execute(vector<string> params)
{
	/*��� ����� ����� �����-��.*/	
}
Sequence::~Sequence(void){};
const string & Sequence::get_name() const
{
	return name; 
};
const string & Sequence::get_help() const{return description;};
