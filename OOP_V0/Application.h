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
	map<string,ICommand*> commandMap;
	vector<ICommand *> commands;
public:
	Application(void);
	virtual ~Application(void);

	virtual ICommand * get_command(const string & key);	// ���������� ������ "�������" �� �����, ��� ��� - ���������� 0
	virtual const vector<ICommand *> & get_command_list() const;		//  ���������� ������ ��������� ������
	virtual void run(istream & in, ostream &out);	// ��������� ���� ��������� ������
	virtual void add_command(ICommand * cmd);	// ��������� ������� � ������
};