//Written by Mikael Thorvaldsen from SatX technologies
//Last edited: 13.09.2021

#include <iostream>
using namespace std;

//Declaring input variables
int humidity                 =   {};
double temp                  =   {};
double rainfall_last_week    =   {};

//Variables carrying points for each parameter
int humidity_points {};
int temp_points {};
int rainfall_last_week_points {};

//Other variables
char repeat_question_answer {};
int case_number {};

int main() {
    
    //Startdisplay 
    cout << "====================================" << endl;
    cout << "\t     SatX fire" << endl;
    
    //Collect user input data
    do {
    cout << endl;
    cout << endl;
    case_number++;
    
    cout << "\t\tNr." << case_number << endl;
    cout << "====================================" << endl;
    cout << "Temperature (C) \t   : ";
    cin >> temp;
    cout << "Humidity (relative) \t   : ";
    cin >> humidity;
    cout << "Rainfall last 7 days (mm)  : ";
    cin >> rainfall_last_week;
    cout << "------------------------------------" << endl;
    cout << "Danger level \t: ";
    
    //Calculating the points for each parameter
    
    //Rainfall last week
    if (rainfall_last_week <= 3) {
        rainfall_last_week_points = 12;
    } else if (rainfall_last_week <= 15 && rainfall_last_week > 3) {
        rainfall_last_week_points = 9;
    } else if (rainfall_last_week < 50 && rainfall_last_week > 15) {
        rainfall_last_week_points = 6;
    } else if (rainfall_last_week >= 50) {
        rainfall_last_week_points = -2;
    }
    
    //Humidity
    if (humidity <= 20) {
        humidity_points = 3;
    } else if (humidity <= 40 && humidity > 20) {
        humidity_points = 2;
    } else if (humidity <= 100 && humidity > 40) {
        humidity_points = 1;
    }
    
    //Temperature
    if (temp >= 20) {
        temp_points = 9;
    } else if (temp < 20 && temp >= 10) {
        temp_points = 6;
    } else if (temp < 10 && temp >= 0) {
        temp_points = 3;
    }
    
    //Calculating combined sum
    int sum = {temp_points + humidity_points + rainfall_last_week_points};
    
    //Determining risk level
    int category = {};
    if (rainfall_last_week_points == 0 or sum < 15) {
        category = 1;  
    } else if (sum >= 15 && sum < 19) {
        category = 2;
    } else if (sum >= 19 && sum < 22) {
        category = 3;
    } else if (sum >= 22) {
        category = 4;
    }
    

    //Display of the risk level
    if (category == 1) {
        cout << "No risk" << endl;
    } else if (category == 2) {
        cout << "Low risk" << endl;
    } else if (category == 3) {
        cout << "Medium risk" << endl;
    } else if (category == 4) {
        cout << "High risk" << endl;
    }
    
    //Asking the user whether they want to repeat
    cout << "Again (Y/N) \t: ";
    cin >> repeat_question_answer;
    cout << "====================================" << endl;
    } while (repeat_question_answer != 'N' and repeat_question_answer != 'n');
    
    
    return 0;
}
