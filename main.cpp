#include <iostream>
#include "arg_parse.h"
#include "todo.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "No arguments are passed. Try with --help for more information" << endl;
        return 0;
    }

    myProgramArgs.help = false;
    myProgramArgs.list = false;
    myProgramArgs.name = false;
    myProgramArgs.name_input = NULL;
    myProgramArgs.write = false;
    myProgramArgs.write_input = 0;

    for (int i = 1; i < argc; i++) {
        parse_arg(argv[i]);
    }
    if (myProgramArgs.name && myProgramArgs.name_input == NULL)
        cout << red_color_start << "WARNING No name is defined" << red_color_end << endl;
    if (myProgramArgs.write && myProgramArgs.write_input == NULL)
        cout << red_color_start << "WARNING not defined if the program should write name into file" << red_color_end << endl;
    if (myProgramArgs.help)
        cout << "Arg: Help"<< endl;
    if (myProgramArgs.list)
        cout << "Arg: List" << endl;
    if (myProgramArgs.name) {
        cout << "Arg: Name";
        if (myProgramArgs.name_input == NULL)
            cout << " = NULL" << endl;
        else
            cout << " = " << myProgramArgs.name_input << endl;
    }
    if (myProgramArgs.write) {
        cout << "Arg: Write";
        cout << " = " << myProgramArgs.write_input << endl;
    }
    do_sth myTodo(95, "Yan");
    myTodo.Do();
    return 0;
}
