#pragma once
#include <string>
#include <vector>
using namespace std;
extern bool start_with(string,const char []);	// ���������, ����������� �� �������� ������� 
extern void comand(string comand, string desk);	// ������� ������� � �� ��������� 
extern void comand_sort(string sort_name, double comand );	// ������� �������� ���������� � ������� ����� ������
extern void help();	// ������� ������ ��������� ������
extern long iteration(int N, string input);	// ������ ���������� ��������
extern void copy_array(int *in,int *out,int n);	// �������� ������
extern void test(long *arr,int n, int iter);	// �������� ������� ����� ���������� ����������
extern void parse_str(string & input, vector<string> & list);	// ��������� ������ � ������ �����
extern void parse_str_int(string & input, vector<string> & list);	// ��������� ������ � ������ �����
extern void show(long *arr, int n);	// ������� ������
extern int arr_size(string input);	// ��������� ������ ������� � ��������� ������������ ������
extern void sequence(long *arr,int n, string input);	// ������ �������� ������������������