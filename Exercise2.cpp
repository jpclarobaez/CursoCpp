#include <iostream>
using namespace std;

/*Ejercicio 2
Calcular el perímetro y área de un rectángulo dada su base y su altura.*/

int main(int argc, char *argv[]) {
	float base;
	float height;
	float perimeter;
	float area; 
	
	cout << "You are in the perimeter and area calculator module\n" << "Please, enter the base value of your rectangle\n";
	cin >> base; 
	cout << "\n The base of your rectangle is " << base << " units. Now enter the height of your rectangle:\n";
	cin >> height; 
	perimeter = 2*base + 2*height;
	area = base * height; 
	
	cout << "Your rectangle: base " << base << " units and height " << height << " units." << endl;
	cout << "Then, the perimeter is: " << perimeter << " units.\nAnd the area is: " << area << " units^2"<< endl;  
	
	
	return 0;
}

