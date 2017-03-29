/************************************************
* whatsmypass.cpp
*
* Generate secure password
*
* Deps: sha256.h
*
* (C) 2017 Erick Rettozi 
*
* MIT LICENCE
*************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "include/sha256.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

static const char chars[] = "0123456789"
		            "!@#$%^&*"
		            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		            "abcdefghijklmnopqrstuvwxyz";

static const unsigned int maxbytes = 20;

int main(int argc, char *argv[]) {
    srand(time(0));
    string password;
    int strlen = sizeof(chars) - 1;

    for(unsigned int i = 0; i < maxbytes; ++i) {
	password += chars[rand() % strlen];
    }

    cout << sha256(password).substr((rand() % (maxbytes/2) + 1),maxbytes) << endl;
    return 0;
}
