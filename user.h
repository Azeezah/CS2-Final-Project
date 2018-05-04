#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
	User();
	User(string username);
	void setUsername(string username);
	string getUsername();
private:
	string username;
};

#endif
