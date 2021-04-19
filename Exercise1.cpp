#include <iostream>
using namespace std;
/* Ejercicio 1
Escribir un programa que pregunte al usuario su nombre, y luego lo salude.*/
int main(int argc, char *argv[]) {
	string name;
	cout << "Hello user! Please, enter your name!" << endl;
	getline(cin, name);
	cout << "Welcome " << name << endl;
	return 0;
}

