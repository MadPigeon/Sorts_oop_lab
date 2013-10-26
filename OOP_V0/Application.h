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
	map<string,ICommand*> commandMap;
	vector<ICommand *> commands;
public:
	Application(void);
	virtual ~Application(void);

	virtual ICommand * get_command(const string & key);	// Возвращает объект "команда" по ключу, его нет - возвращает 0
	virtual const vector<ICommand *> & get_command_list() const;		//  Возвращает список доступных команд
	virtual void run(istream & in, ostream &out);	// Запускает цикл обработки команд
	virtual void add_command(ICommand * cmd);	// Добавляет команду к списку
};