#include <iostream>
using namespace std;

/*Ejercicio 17
Un ciclista parte de una ciudad A a las HH horas, MM minutos y SS segundos. 
El tiempo de viaje hasta llegar a otra ciudad B es de T segundos. 
Escribir un algoritmo que determine la hora de llegada a la ciudad B. */

#define DELIMITER ':'

struct hh_mm_ss {
	int hh;
	int mm;
	float ss;
	float total_time; 
};

int delim_counter(string time, char delimiter);
hh_mm_ss extract_time(string time);
hh_mm_ss delta_time(hh_mm_ss hora_ini, float delta); 

int main(int argc, char *argv[]) {
	string time_ini; 
	int hh_ini, mm_ini, hh_end, mm_end, counter;
	float ss_ini, ss_end, travel_time; 
	bool correct_time = false;
	hh_mm_ss hora_ini, hora_end;
	
	while(not correct_time){
		cout << "Enter the initial time in format hh:mm:ss" << endl; 
		getline(cin, time_ini);
		counter = delim_counter(time_ini, DELIMITER);
		
		if (counter != 2){
			cout << "Sorry! The init time is not valid. Use format hh:mm:ss or hh:mm:ss.ddd" << endl << endl;
		}
		else{
			hora_ini = extract_time(time_ini);
			if (hora_ini.hh>23 || hora_ini.mm>59 || hora_ini.ss>=60){
				cout << "Sorry! The init time is not valid. Use format hh:mm:ss or hh:mm:ss.ddd" << endl;
				cout << "Where hh must be lower than 24, and mm and ss must be lower than 60!" << endl << endl; 
			}
			else{
				correct_time = true;
			}
		}
	}
	
	cout << "Enter travel time in seconds, please" << endl;
	cin >> travel_time; 
	hora_end = delta_time(hora_ini, travel_time);
	cout << hora_end.hh << ":"<<hora_end.mm << ":" << hora_end.ss << endl;
	return 0;
}

int delim_counter(string time, char delimiter){
	int len, counter=0;
	len = time.length();
	
	for (int i=0; i<len; i++){
		if (time[i] == delimiter){
			counter+=1;
		}
	}
	return counter; 
}

hh_mm_ss extract_time(string time){
	int hh, mm, i;
	float ss; 
	string hh_s, mm_s, ss_s;
	hh_mm_ss hora_ini; 
	
	for (i=0; i<time.find(DELIMITER); i++){
		if (isdigit(time[i])){
			hh_s = hh_s + time[i];
		};
	};
	
	for (i+1; i<time.find_last_of(DELIMITER); i++){
		if (isdigit(time[i])||time[i]=='.'){
			mm_s = mm_s + time[i];
		}
	};

	for (i+1; i<time.length(); i++){
		if (isdigit(time[i])||time[i]=='.'){
			ss_s = ss_s + time[i];
		}
	};

	hora_ini.hh = stoi(hh_s);
	hora_ini.mm = stoi(mm_s);
	hora_ini.ss = stoi(ss_s);
	hora_ini.total_time = hora_ini.hh*3600 + hora_ini.mm*60 + hora_ini.ss;
	return hora_ini;
}


hh_mm_ss delta_time(hh_mm_ss hora_ini, float delta){
	hh_mm_ss hora_end;
	int hh, mm;
	float ss; 
	float final_time_seconds;
	final_time_seconds = delta + hora_ini.total_time; 
	
	hh = int(final_time_seconds/3600);
	mm = (final_time_seconds - int((final_time_seconds/3600))*3600)/60;
	ss = (final_time_seconds - (int(final_time_seconds/3600))*3600) - mm*60;
	if (hh>23){
		hh = hh%24;
	}
	hora_end.hh = hh; 
	hora_end.mm = mm;
	hora_end.ss = ss; 
	return hora_end;
}	
