#pragma once
#include <vector>
#include <map>
#include <string>
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

	void parse_str(string & input, vector<string> & list);
public:
	Application(void);
	virtual ~Application(void);

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
};