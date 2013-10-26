#include <iostream>
#include <string>
#include <time.h>
#include "Functions.h"
#include <vector>
#include "Application.h"
using namespace std;


void main()
{
	setlocale (LC_ALL, "Russian");
	/*string input;
	long mass[100];
	mass[0]=10;
	vector <string> vec_str;
	for(int i = 1; i < 100; i++)
	{
		mass[i] = mass[i-1]*10;
	}
	char temp;
	long *arr = new long [4];
	int n = 0, k = 0;
	long iter = 100;*/
	Application App;
	App.run(cin,cout);

	/*do
	{
		cout<<">: ";
		temp = cin.get();
		while(temp != '\n')
		{
			input.push_back(temp);
			temp = cin.get();
		}
		
		if(start_with(input,"help"))
		{
			help();
		}
		else
		{
			if(start_with(input,"sequence"))
			{
				n = arr_size(input);
				if(n != -1)
				{
					if(k >= 0) delete[] arr;	// Очищаем память массива
					k = n;
					arr = new long [k];
					parse_string(input, vec_str);
					sequence(arr,k,input);
				}
			}
			if(start_with(input,"iteration"))
			{
				iter = iteration(iter, input);
			}
			if(start_with(input,"test"))
			{
				test(arr,k,iter);
			}
			if(start_with(input,"show"))
			{
				show(arr,k);
			}
		}
		input.clear();
	} while(!start_with(input,"exit"));

	system("pause");*/
}