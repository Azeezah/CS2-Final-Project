#include <string>
#include "User.h"

using namespace std;

User::User(){
	this->username = "Guest";
}

User::User(string username){
	this->username = username;
}

void User::setUsername(string username){
	this->username = username;
}

string User::getUsername(){
	return this->username;
}
