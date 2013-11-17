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
	if(str.size() == 0 ) // �������� ������ ������
	{
		return false;
	}
	while(obraz[i] != '\0') // ���� �� ����� �� �����
	{
		if(obraz[i] != str[i]) // ��������� ������������ ��������� ������ �������� �������(�����������)
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
	cout<< "	������� �������.(������������ ������ ��������) \n"
				<< "	������ ��������� ������ : \n\n";
			comand("	help     ","������� ������ ���� ��������� ������");
			comand("	iteration","������ ���������� ��������");
			comand("	sequence ","������� ����� �������� ������������������");
			comand("	show     ","������� ������");
			comand("	test     ","������� ������� ����� ����������");
}*/
long iteration(int N, string input)
{// ������������ ����� atol 2147483647
	int inp_size = input.size();// �������� ����� ������
	int n, i = 10, j = 10, l;
	char number[10];
	for(; j < inp_size; j++);// ������ ����� �� ����� ������
	for(l = i; l < j; l++)
	{
		number[l-i] = input [l];
	}
	//���������� �����
	n = atol(number);
	// ���� �� ������� ����� ����� ��������, �� ���������� ����������� ����������
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
	// ��������� ������������ ������
	if(n == 0)
	{
		cout << "  � ������� ��� ���������.\n";	
	}
	else
	{
		cout << "\n���������� �������� " << iter;
		cout << "\n������ ������� " << n;
		cout << "\n������ ";
		// ���� ������ ������� ������� �� ������� ������ 10 ����� � ������� ��� � ������� ��� N-10 �����
		if(n <= 10)
		for( i = 0; i < n; i ++)
		{
			cout << arr[i] << " ";
		}
		else
		{
			for( i = 0; i < 10; i ++)	// ����� ������ �������
			{
				cout << arr[i] << " ";
			}
			cout << "... � ������� ��� " << n - 10 << " �����";	// ��� ������� ������� �������  ��������� ������ ������ 10 ��������� � ���������� ���������� ���������
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
	string temp;	// ���������� ��� ����������� � ��������
	stringstream sstream;	// ����� ����� ��� ����������
	sstream << input;	// ���������� ������ � String Builder
	while (!sstream.eof())	// ���������� � ������ ������ �� �����
	{
		sstream >> temp;
		list.push_back(temp);
	}
}*/
void show(long *arr, int n)
{
	int i;
	if(n == 0) // ��������� ������ �� ������� � ��� ���������
	{
		cout << "  � ������� ��� ���������.\n";
	}
	else// ���� �������� ���� �� ������� �� �� �����
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
	// ��� �����!in future
	int i,n = 0,
	seq_size = input.size();  //������ ������� input 
	for(i = 8; (i < seq_size) && ((input[i] >= '0' && input[i] <= '9') || ( input[i] == ' ' )); i++)// �������� input-� �� �����
	{
		if(input[i] != ' ' && input[i-1] == ' ') n++;// ���� ������� �������
	}
	if (i == seq_size)// ���� ��� ������������ ��������, �� ���������� ���-�� ���������
	{
		return n;
	}
	// � ��������� ������ �������, ��� ���� �������� ������
	cout<<"�� ����� ������������ ������\n";
	return -1;
}
void sequence(long *arr, int n, string input) 
{
	int i, j, l, p = 0,
	seq_size = input.size();  //������ ������� input 
	long temp;
	char number[10];
	for(i = 8; i < seq_size;) 
	{
		while( i < seq_size && input[i] == ' ' )// ������� �� �����
			i++;
		j = i;
		if (j != seq_size) // ���� �� ����� �� �������
		{
			while( j < seq_size && input[j] >= '0' && input[j] <= '9')// ���� �� �������
				++j;
		}
		for(l = i; l < j; l++)// ���������� ����� � ������ Number
		{	
			number[l - i] = input [l];
		}
		// ������� ����� � ������
		temp = atol(number);
		arr[p++] = temp;
		if (p == n) break; // ��������� ������� �� ��� �����
		i = j;
		// ������� Number �� ����������� �����
		for(l = 0; l < 10; l++){ number[l] = '\0';} 
	} 	
}