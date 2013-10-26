#include <vector>
#include <string>
#include <iostream>
#include "Help.h"

using namespace std;

HelpCommand::HelpCommand(Application *appl) : name("help"), description("Ёта команда даЄт вам понимание происход€щего как никогда €сное."), app(appl){}
void HelpCommand::execute(const vector<string> params){
	cout<<"================================================================================" << endl;
	cout<<"ƒоступны следующие команды:\n" << endl;
	const vector <ICommand *> & cmdlist = app->get_command_list();

	vector <ICommand *>::const_iterator i = cmdlist.begin();
		for(; i != cmdlist.end(); i++){
			cout << (*i)->get_name() << ": " << (*i)->get_help() << endl;
		}
		cout << "================================================================================" << endl;
}
HelpCommand::~HelpCommand(void){};
const string & HelpCommand::get_name() const
{
	return name; 
};
const string & HelpCommand::get_help() const{return description;};
