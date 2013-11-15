#pragma once
#include <vector>
#include <map>
#include <string>
#include "ICommand.h"
using namespace std;

// Абстракция "приложение" его ответственность - выполнение
// команд, поступающих с консоли и хранение информации,
// специфичной для конкретного приложения
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

	virtual ICommand * get_command(const string & key);	// Возвращает объект "команда" по ключу, его нет - возвращает 0
	virtual const vector<ICommand *> & get_command_list() const;		//  Возвращает список доступных команд
	virtual void run(istream & in, ostream &out);	// Запускает цикл обработки команд
	virtual void add_command(ICommand * cmd);	// Добавляет команду к списку

	Application(int argc, char **argv);
	
	virtual vector <int> & get_arr();
	virtual void add_to_arr(long val);
	virtual void clear_arr();
	virtual void set_iter(long val);
	virtual long get_iter();
};