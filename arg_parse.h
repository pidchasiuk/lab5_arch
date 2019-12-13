#include <unistd.h>
#include <string>
#include <regex>
#include <iostream>

using namespace std;
static struct program_args {
    bool help;     /*-h --help*/   /*program manual*/
    bool list;     /*-l --list*/   /*list of all args*/
    bool name;     /*-n --name*/   /*input username*/
    char* name_input;               /*name that we put in*/
    bool write;    /*-w --write*/  /*write name into file*/
    int write_input;                /*1 - true, 0 - false*/
} myProgramArgs;

string red_color_start = "\033[1;31m";
string red_color_end = "\033[0m";

void parse_arg(char* arg) {
    const char* long_arg_names[]  = {"help", "list", "name", "write"};
    const char* short_arg_names[] = {"h", "l", "n", "w"};
    std::string str(arg);
    // long arg
    if (str.substr(0, 2) == "--") {
        str.erase(0, 2);
        if (str == long_arg_names[0])
            myProgramArgs.help = true;
        else if (str == long_arg_names[1])
            myProgramArgs.list = true;
        else if (str == long_arg_names[2])
            myProgramArgs.name = true;
        else if (str == long_arg_names[3])
            myProgramArgs.write = true;
        else {
            std::cout << red_color_start << "WARNING unknown long argument is used: " << arg << red_color_end << std::endl;
            return;
        }
    }
    // short arg
    else if (str.substr(0, 1) == "-") {
        str.erase(0, 1);
        if (str.find("h") != std::string::npos)
            myProgramArgs.help = true;
        if (str.find("l") != std::string::npos)
            myProgramArgs.list = true;
        if (str.find("n") != std::string::npos)
            myProgramArgs.name = true;
        if (str.find("w") != std::string::npos)
            myProgramArgs.write = true;
        std::regex regex_pattern1("^[hlnw]+[01]?$");
        std::regex regex_pattern2("w[01]$");
        std::smatch match;
        if (regex_match(str, regex_pattern1) == false) {
            std::cout << red_color_start << "WARNING unknown short arguments are used: " << arg << red_color_end << std::endl;
            return;
        }
        if (regex_search(str, match, regex_pattern2) == true) {
            myProgramArgs.write = true;
            std::string last_symbol(1, str[str.length() - 1]);
            int last_num = std::stoi(last_symbol);
            myProgramArgs.write_input = (bool)last_num;
        }

    }
    else if (str == "0" || str == "1") {
        int write_num = stoi(str);
        myProgramArgs.write_input = (bool)write_num;
    }
    else if (str != "=") {
        if (myProgramArgs.name && myProgramArgs.name_input == NULL)
            myProgramArgs.name_input = arg;
        else
            cout << red_color_start << "WARNING unknown argument " << str << red_color_end << endl;

    }
}
