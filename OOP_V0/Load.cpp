#include <fstream>
#include <iostream>
#include <string>

#include "Load.h"

using namespace std;

LoadCommand::LoadCommand(Application *appl): name("load"), description("Считывает последовательность из файла"),app(appl){}

void LoadCommand::execute(vector <string> params)
{
	ICommand *cmd =app-> get_command("sequence");
    app ->clear_arr();
	vector <string> seq;
    string temp;
    ifstream myfile ("Sequence_for_load.txt");
    if(myfile == NULL )
    {
        cout << "Не удалось загрузить последовательность\n";
    }
    else
    {
        while(!myfile.eof())
        {
            getline(myfile,temp);                
        }
		app ->parse_str(temp,seq); 
        myfile.close();
		cmd -> execute(seq);
        cout << "Последовательность загружена\n";
    }
}

LoadCommand::~LoadCommand(void){}

const string & LoadCommand:: get_name() const 
{
	return name;
}
const string & LoadCommand:: get_help() const
{
	return description;
}