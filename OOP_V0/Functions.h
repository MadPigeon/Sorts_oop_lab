#pragma once
#include <string>
#include <vector>
using namespace std;
extern bool start_with(string,const char []);	// ѕровер€ет, закончилось ли название команды 
extern void comand(string comand, string desk);	// выводит команду с ее описанием 
extern void comand_sort(string sort_name, double comand );	// ¬ыводит название сортировки и среднее врем€ работы
extern void help();	// ¬ыводит список доступных команд
extern long iteration(int N, string input);	// «адает количество итераций
extern void copy_array(int *in,int *out,int n);	//  опирует массив
extern void test(long *arr,int n, int iter);	// «амер€ет среднее врем€ выполнени€ сортировок
extern void parse_str(string & input, vector<string> & list);	// ѕереводит строку в вектор строк
extern void parse_str_int(string & input, vector<string> & list);	// ѕереводит строку в вектор строк
extern void show(long *arr, int n);	// ¬ыводит массив
extern int arr_size(string input);	// ¬ычисл€ет размер массива и провер€ет правильность строки
extern void sequence(long *arr,int n, string input);	// «адает числовую последовательность