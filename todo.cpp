#include <iostream>
#include "todo.h"

do_sth::do_sth(int mark, char* name) {
	this->mark = mark;
	this->name = name;
}

do_sth::~do_sth() {
	//delete name;
}

void do_sth::Do() {
	std::cout << "Student " << name << " has mark " << mark << std::endl;
}

