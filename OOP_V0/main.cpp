#include <iostream>
#include <string>
#include <time.h>
#include "Functions.h"
#include <vector>
#include "Application.h"
using namespace std;


void main(int argc, char **argv)
{
	cout << "Press <ENTER> key, please.\n";
	cin.get();
	setlocale (LC_ALL, "Russian");
	Application App(argc, argv);
	App.run(cin,cout);
}