#include <iostream>
using namespace std;

/*Ejercicio 10
Un alumno desea saber cual será su calificación final en la materia de Algoritmos. Dicha calificación se compone de los siguientes porcentajes:

55% del promedio de sus tres calificaciones parciales.
30% de la calificación del examen final.
15% de la calificación de un trabajo final.*/


float average_fun(float exam1, float exam2, float exam3);
float final_mark_fun(float average, float examf, float exerf);

int main(int argc, char *argv[]) {
	float exam1, exam2, exam3, examf, exerf;
	float average, final_mark; 
	
	// Data input 
	cout << "Enter the mark of your first test:" << endl; 
	cin >> exam1; 
	cout << "Enter the mark of your second test:" << endl; 
	cin >> exam2; 
	cout << "Enter the mark of your third test:" << endl; 
	cin >> exam3; 
	cout << "Enter the mark of your final test:" << endl; 
	cin >> examf; 
	cout << "Enter the mark of your final project:" << endl; 
	cin >> exerf;
	
	// Operations
	average = average_fun(exam1, exam2, exam3);
	final_mark = final_mark_fun(average, examf, exerf);
	
	// Output
	cout << "\n******************" << endl;
	cout << "Mark first test: " << exam1 << endl;
	cout << "Mark second test: " << exam2 << endl;
	cout << "Mark third test: " << exam3 << endl;
	cout << "Then the average is: " << average << endl; 
	cout << "Your final mark is: 0.55 x " << average << " + 0.3 x " << examf << " + 0.15 x " << exerf << endl;
	cout << "So this is your mark: " << final_mark << endl; 
	
	if (final_mark >= 5){
		cout << "Congrats! You passed the subject" << endl;
	}
	else {
		cout << "Sorry! You failed the subject" << endl; 
	}
	
	
	
	return 0;
}

float average_fun(float exam1, float exam2, float exam3){
	float average; 
	average = (exam1 + exam2 + exam3)/3; 
	return average;
}

float final_mark_fun(float average, float examf, float exerf){
	float mark; 
	
	return 0.55*average + 0.3*examf + 0.15*exerf; 
}
