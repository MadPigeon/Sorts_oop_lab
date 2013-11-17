#include "Exit.h"
#include "Application.h"

void Exit::execute(vector <string> params)
{
	cout << "Âû õîòèòå ÇÀÊÐÛÒÜ ïðîãðàììó?! ÂÎÒ ÝÒÎ ÏÎÂÎÐÎÒ!";
	exit(0);
}
const string & Exit::get_name() const{ return name; }
const string & Exit::get_help() const{ return description; }
Exit::Exit(Application *appl): name("exit"), description("Âûçîä èç ïðîãðàììû"){}
Exit::~Exit(){}