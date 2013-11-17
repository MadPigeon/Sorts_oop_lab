#include <vector>
#include <string>
#include <iostream>

#include "Test.h"


using namespace std;

TestCommand::TestCommand(Application *appl) : name("test"),
    description("��������� ������ ���������� ����������. ������ �������� ��������� ������������������ sequence, iterations ���."
                "������� �� ����� ������� ����� ������ ����������"),app(appl){}
void TestCommand::execute(vector <string> params)
{
    vector <int> arr = app->get_arr();
       vector <int> copy;
    int arr_size = arr.size(),
        iter = app->get_iter(),
        i, sorts_type = 1;
    long long sorts_time[4] = {0,0,0,0},
		      iter_time;
    double average_time [4] = {0,0,0,0};

    if(arr_size == 0)
	{
		cout << endl << "� ������� ��� ���������.\n";	
	}
    else
	{
		cout << "\n���������� �������� " << iter;
		cout << "\n������ ������� " << arr_size;
		cout << "\n������ \n";
		// ���� ������ ������� �� ������� ������ 10 ����� � ������� ��� � ������� ��� N-10 �����
		if( arr_size <= 10 )
        {
		    for( i = 0; i < arr_size; i ++)
		    {
			    cout << arr[i] << " ";
		    }
            cout << endl;
        }
		else
		{
			for( i = 0; i < 10; i ++)	
			{
				cout << arr[i] << " ";
			}
			cout << "... � ������� ��� " << arr_size - 10 << " �����\n";	
		}
		
		for( sorts_type = 1; sorts_type < 5; sorts_type++)
		{
			for(i = 0; i < iter; i++)
			{
				copy = arr;
				iter_time = -app->gettimeus();
				app->sorts(copy, sorts_type, arr_size);
				sorts_time[sorts_type - 1] += app->gettimeus() + iter_time;
			}
		}
		
		for(i = 0; i < 4; i++ )
		{
			average_time[i] = double(sorts_time[i]) / iter;
		}
		app->Output_average_time( "Bubble sort", average_time[0] );
		app->Output_average_time( "Shell sort ", average_time[1] );
		app->Output_average_time( "Quick sort ", average_time[2] );
		app->Output_average_time( "Heap sort  ", average_time[3] );
	}


};
TestCommand::~TestCommand(void){};
const string & TestCommand::get_name() const
{
	return name; 
};
const string & TestCommand::get_help() const{return description;};
