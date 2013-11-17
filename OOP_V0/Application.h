#pragma once
#include <vector>
#include <map>
#include <string>
#include <Windows.h>
#include "ICommand.h"
using namespace std;

// ���������� "����������" ��� ��������������� - ����������
// ������, ����������� � ������� � �������� ����������,
// ����������� ��� ����������� ����������
class Application{
	map <string,ICommand*> commandMap;
	vector <ICommand *> commands;
	vector <int> arr;
	long iter;
	vector <string> commands_from_file;

	
public:
	Application(void);
	virtual ~Application(void);
	virtual void parse_str(string & input, vector<string> & list);
	virtual ICommand * get_command(const string & key);	// ���������� ������ "�������" �� �����, ��� ��� - ���������� 0
	virtual const vector<ICommand *> & get_command_list() const;		//  ���������� ������ ��������� ������
	virtual void run(istream & in, ostream &out);	// ��������� ���� ��������� ������
	virtual void add_command(ICommand * cmd);	// ��������� ������� � ������

	Application(int argc, char **argv);
	
	virtual vector <int> & get_arr();
	virtual void add_to_arr(long val);
	virtual void clear_arr();
	virtual void set_iter(long val);
	virtual long get_iter();
	virtual inline long long gettimeus();
    virtual void sorts(vector <int> &copy, int sorts_type,int copy_size);
    virtual void output_average_time(string, double average_time);
};