#include <vector>
#include <string>
#include <iostream>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(Application *appl) : name("sequence"),
	description("Команда создаёт массив из последующих чисел. Неверные значения игнорируются."),app(appl){}
void Sequence::execute(vector<string> input)
{
	app->clear_arr();
	// Максимальное число atol 2147483647
	int str_numb,string_size, i, p = 0,
	seq_size = input.size();  //Количество аргументов в вектрое
	long temp;
	char number[10];
	for(str_numb = 0; str_numb < seq_size; str_numb++) 
	{
		string_size = input[str_numb].size();
		if(string_size <= 10)
		{
			for(i = 0; i < string_size; i++)// Записываем число в массив Number
			{	
				number[i] = input[str_numb][i];
			}
			temp = atol(number);
			// Продолжаем фильтровать элементы вектора
			if(temp == 2147483647)
			{
				// Значение отсеяно;
			}
			else
			{
				app->add_to_arr(temp);
			}
		}
		else
		{
			// Значение отсеяно;
		}
	} 	
}
Sequence::~Sequence(void){};
const string & Sequence::get_name() const
{
	return name; 
};
const string & Sequence::get_help() const{return description;};
