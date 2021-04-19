#include <iostream>
#include <cmath>
using namespace std;

/*Ejercicio 3
Dados los catetos de un triángulo rectángulo, calcular su hipotenusa.*/

float hypo(float cat1, float cat2);

int main(int argc, char *argv[]) {
	float cat1, cat2; 
	
	cout << "Enter leg 1:" << endl;
	cin >> cat1;
	
	cout << "Enter leg 2:" << endl;
	cin >> cat2;
	
	cout << "The hypotenuse is: " << hypo(cat1, cat2);
	return 0;
}

float hypo(float cat1, float cat2){
	float hypov; 
	hypov = sqrt(pow(cat1,2) + pow(cat2,2));
	return hypov;
}
