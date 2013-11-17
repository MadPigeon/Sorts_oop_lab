#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "timer.cpp"
#include "sorts.h"
#include <vector>

using namespace std;
/*bool start_with(string str,const char obraz[])
{
	int i = 0;
	if(str.size() == 0 ) // Отсекаем пустую строку
	{
		return false;
	}
	while(obraz[i] != '\0') // Пока не дошли до конца
	{
		if(obraz[i] != str[i]) // проверяем соответствие введенной строки названию команды(посимвольно)
		{
			return false;
		}
		i++;
	}
	return true;
}*/
/*void comand(string comand, string desk)
{
	cout << comand;
	cout << "   ";
	cout << desk << endl << endl;
}*/
void comand_sort( string desk, double comand )
{
	cout << desk;
	cout << "   ";
	cout << setiosflags (ios::fixed) << comand << " microseconds "<< endl << endl;
}
/*void help()
{
	cout<< "	Введите команду.(Используется только латиница) \n"
				<< "	Список доступных команд : \n\n";
			comand("	help     ","Выводит список всех доступных команд");
			comand("	iteration","Ввести количество итераций");
			comand("	sequence ","Функция ввода числовой последовательности");
			comand("	show     ","Выводит массив");
			comand("	test     ","Выводит среднее время сортировок");
}*/
long iteration(int N, string input)
{// Максимальное число atol 2147483647
	int inp_size = input.size();// замеряем длину строки
	int n, i = 10, j = 10, l;
	char number[10];
	for(; j < inp_size; j++);// Читаем число до конца строки
	for(l = i; l < j; l++)
	{
		number[l-i] = input [l];
	}
	//Записываем число
	n = atol(number);
	// Если не введено новое число итерации, то возвращаем стандартное количество
	if(n == 0)
	{ 
		return N;
	}
	return n;

}
void copy_array(long *in,long *out,int n)
{
	for(int i = 0; i < n ; i++)
	{
		out[i] = in[i];
	}
}
void test(long *arr,int n, int iter)
{
	int i, j;
	long long sorts_time[4] = {0,0,0,0};
	long long iter_time;
	double result [4];
	long *copy = new long [n];
	// Проверяем корректность данных
	if(n == 0)
	{
		cout << "  В массиве нет элементов.\n";	
	}
	else
	{
		cout << "\nКоличество итераций " << iter;
		cout << "\nРазмер массива " << n;
		cout << "\nМассив ";
		// если массив слишком большой то вывести первые 10 чисел и сказать что в массиве еще N-10 чисел
		if(n <= 10)
		for( i = 0; i < n; i ++)
		{
			cout << arr[i] << " ";
		}
		else
		{
			for( i = 0; i < 10; i ++)	// Вывод начала массива
			{
				cout << arr[i] << " ";
			}
			cout << "... в массиве еще " << n - 10 << " чисел";	// При большом размере массива  выводятся только первые 10 элементов и количество оставшихся элементов
		}
		cout << endl << endl;
		for( j = 1; j < 5; j++)
		{
			for(i = 0; i < iter; i++)
			{
				copy_array(arr,copy,n);
				iter_time = - gettimeus();
				//sorts(copy, n, j);
				sorts_time[j-1] += gettimeus() + iter_time;
			}
		}
		
		for(i = 0; i < 4; i++ )
		{
			result[i] = double(sorts_time[i]) / iter;
		}
		comand_sort( "Bubble sort", result[0] );
		comand_sort( "Shell sort ", result[1] );
		comand_sort( "Quick sort ", result[2] );
		comand_sort( "Heap sort  ", result[3] );
	}
}
/*void parse_str(string & input, vector<string> & list)
{
	string temp;	// переменная для копирования и проверки
	stringstream sstream;	// поток строк для разделения
	sstream << input;	// складываем строку в String Builder
	while (!sstream.eof())	// складываем в вектор строки по одной
	{
		sstream >> temp;
		list.push_back(temp);
	}
}*/
void show(long *arr, int n)
{
	int i;
	if(n == 0) // Проверяем массив на наличие в нем элементов
	{
		cout << "  В массиве нет элементов.\n";
	}
	else// если элементы есть то выводим их на экран
	{
		for(i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}
int arr_size(string input)
{
	// под выпел!in future
	int i,n = 0,
	seq_size = input.size();  //Размер вектора input 
	for(i = 8; (i < seq_size) && ((input[i] >= '0' && input[i] <= '9') || ( input[i] == ' ' )); i++)// проверка input-а на числа
	{
		if(input[i] != ' ' && input[i-1] == ' ') n++;// счет размера массива
	}
	if (i == seq_size)// Если нет неправильных символов, то возвращаем кол-во элементов
	{
		return n;
	}
	// В противном случае говорим, что есть неверный символ
	cout<<"Вы ввели недопустимый символ\n";
	return -1;
}
void sequence(long *arr, int n, string input) 
{
	int i, j, l, p = 0,
	seq_size = input.size();  //Размер вектора input 
	long temp;
	char number[10];
	for(i = 8; i < seq_size;) 
	{
		while( i < seq_size && input[i] == ' ' )// Доходим до числа
			i++;
		j = i;
		if (j != seq_size) // Если не зашли за границы
		{
			while( j < seq_size && input[j] >= '0' && input[j] <= '9')// Идем до пробела
				++j;
		}
		for(l = i; l < j; l++)// Записываем число в массив Number
		{	
			number[l - i] = input [l];
		}
		// Заносим число в массив
		temp = atol(number);
		arr[p++] = temp;
		if (p == n) break; // Проверяем считаны ли все числа
		i = j;
		// Очищаем Number от предыдущего числа
		for(l = 0; l < 10; l++){ number[l] = '\0';} 
	} 	
}