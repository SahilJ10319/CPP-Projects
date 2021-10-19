//
//  main.cpp
//  tokimonGame
//
//  Created by Sahil Janjua on 2019-11-25.
//  Copyright © 2019 Sahil Janjua. All rights reserved.
//
/* This is a program that will be used to track a variety of
 tokimon that exist in the world and track their abilities */

#include <iostream>
#include <string>
#include <iomanip>

// declares total number of abilities I will use
const int NUM_ABILITIES = 5;
// measure = height and weight which is used in same array therefore 2 is used
const int measure = 2;
// all the possible toki the user may encounter = 300
const int toki = 300;

// This function will be used to display the main menu
void displayMainMenu() {
    std::cout << " ******************************************** " << std::endl;
    std::cout << " * Tokimon Tracker by Sahil J  sn 301358823 * " << std::endl;
    std::cout << " ******************************************** " << std::endl;
    std::cout << std::endl;
    std::cout << " ************* " << std::endl;
    std::cout << " * Main Menu * " << std::endl;
    std::cout << " ************* " << std::endl;
    std::cout << " 1. List Tokimons " << std::endl;
    std::cout << " 2. Add a New Tokimon " << std::endl;
    std::cout << " 3. Remove a Tokimon " << std::endl;
    std::cout << " 4. Change Tokimon Ability " << std::endl;
    std::cout << " 5. Change Tokimon Height " << std::endl;
    std::cout << " 6. Change Tokimon Weight " << std::endl;
    std::cout << " 7. Exit " << std::endl;
    std::cout << " 8. Rest and Heal " << std::endl;
    std::cout << ">";
}

// All known Tokimon will be displayed (user inputted)

void displayAllTokis(int k, std::string names [toki], double measurements [toki][measure],
double abilities [toki][NUM_ABILITIES]) {
    std::cout << "* Documented Tokimons *" << std::endl;
    
    for(int n = 0; n < k; n++ ) {
        std::cout << n + 1 << "." << std::setw(10) << names[n] << "," << std::setw(5);
        std::cout << measurements[n][1] << "cm," << std::setw(5) << measurements[n][2];
        std::cout << "kg," << " Abilities: fly=" << std::setw(2) << abilities[n][0];
        std::cout << ", fire=" << std::setw(2) << abilities[n][1] << ", water=";
        std::cout << std::setw(2) << abilities[n][2] << ", electrify=" << std::setw(2);
        std::cout << abilities[n][3] << ", freeze=" << std::setw(2) << abilities[n][4];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function used to add new tokimon by user command and input

void addNewToki(std::string names [toki], double measurements [toki][measure],
double abilities [toki][NUM_ABILITIES], double height, double weight,
std::string nameInsert, int n) {
    names[n] = nameInsert;
    measurements[n][1] = height;
    measurements[n][2] = weight;
    std::cout << names[n] << " added successfully." << std::endl;
    std::cout << std::endl;
}

// Function used to delete Tokimon by user's will

void deleteToki(int numDelete, int cycle, std::string names [toki],
double measurements [toki][measure], double abilities [toki][NUM_ABILITIES]) {
    
    for (int k = 0; k < cycle; k++) {
        
        if (names [numDelete] == names[k]) {
            
            for (int l = 0; l < cycle; l++)
            names[l] = names [l+1];
            
            for (int l = 0; l < cycle; l++)
            measurements[l][1] = measurements[l+1][1];
            for (int l = 0; l < cycle; l++)
            measurements[l][2] = measurements[l+1][2];
            
            for (int l = 0; l < cycle; l++)
            abilities[l][0] = measurements[l+1][0];
            for (int l = 0; l < cycle; l++)
            abilities[l][1] = measurements[l+1][1];
            for (int l = 0; l < cycle; l++)
            abilities[l][2] = measurements[l+1][2];
            for (int l = 0; l < cycle; l++)
            abilities[l][3] = measurements[l+1][3];
            for (int l = 0; l < cycle; l++)
            abilities[l][4] = measurements[l+1][4];
        }
    }
    
}

// Function used to alter Tokimon's stats

void alterTokiAbility(std::string abilSelect [5], std::string selectAbil,
int newAbility, int numToki, std::string names [toki],
double abilities [toki][NUM_ABILITIES] ) {

    abilSelect[0] = "fly";
    abilSelect[1] = "fire";
    abilSelect[2] = "water";
    abilSelect[3] = "electrify";
    abilSelect[4] = "freeze";
    
    for (int k = 0; k <= 4; k++){
        if (selectAbil == abilSelect[k]){
            
            abilities[numToki][k] = newAbility;
        }
    }

}

// Function used to alter Tokimon height

void alterTokiHeight(int selectHeight, int valueOfHeight,
double measurements [toki][measure], std::string names [toki] ) {
    
    std::cout << names[selectHeight] << " now has the height of" << valueOfHeight;
    std::cout << "cm" << std::endl;
    std::cout << std::endl;
    
    measurements[selectHeight][1] = valueOfHeight;

}

// Function used to alter Tokimon's Weight

void alterTokiWeight(int selectWeight, int valueOfWeight, double measurements [toki][measure],
std::string names [toki] ) {
    
    std::cout << names[selectWeight] << " now has the weight of" << valueOfWeight;
    std::cout << "kg" << std::endl;
    std::cout << std::endl;
    
    measurements[selectWeight][2] = valueOfWeight;
    
}

int main() {
    std::string names [toki];
    double measurements [toki] [measure];
    double abilities [toki] [NUM_ABILITIES];
    int cycle = 0;
    int input;
    // Main Menu Input for user
    while (true) {
        displayMainMenu();
        std::cin >> input;
        
        while (input <= 0 || input >= 9) {
            std::cout << "Please Enter Value from 1 to 8" << std::endl;
            std::cin >> input;
            
        }
        // To end function
        if (input == 7) {
            std::cout << "BYE!";
            break;
            
        }
        // To display Tokimon's
        if (input == 1) {
            displayAllTokis(cycle,names,measurements,abilities);
            
        }
        // For user to enter Tokimon ID and Stats
        if (input == 2) {
            std::string fullName;
            double weight, height;

            std::cout << "Enter Tokimon's name:      ";
            std::cin.ignore();
            getline(std::cin, fullName);
            
            std::cout << "Enter Tokimon's height:    ";
            std::cin >> height;
            
            while (height < 10 || height > 99) {
                std::cout << "Please Enter a Value Inbetween 10-99: ";
                std::cin >> height;
            }
            std::cout << "Enter Tokimon's weight:     ";
            std::cin >> weight;
            
            while (weight < 4 || weight > 30) {
                std::cout << "Please Enter a Value Inbetween 4-30: ";
                std::cin >> weight;
                
            }
            std::cout << "Enter abilities (fly, fire, water, electrify, freeze): ";
            for (int k = 0; k < 5; k++){
                std::cin >> abilities [cycle][k];
                while (abilities[cycle][k] < 0 || abilities[cycle][k] > 99) {
                    std::cout << "Please Enter a Value Inbetween 1-99: ";
                    std::cin >> abilities[cycle][k];
                    
                }
                
            }
            addNewToki(names,measurements, abilities, height, weight, fullName, cycle);
            cycle ++;
            
        }
        if (input == 3) {
            // Delete Tokimon Call
            int deleteNum;
            displayAllTokis(cycle,names,measurements, abilities);
            
            std::cout <<  "(Enter 0 to cancel)" << std::endl;
            std::cout << ">";
            std::cin >> deleteNum;
            
            while (deleteNum < 0||deleteNum > cycle+1){
                std::cout << "Please enter a number between 0-" << cycle+1;
                std::cin >> deleteNum;
                
            }
            if (deleteNum == 0){
                continue;
                
            }
            deleteNum = deleteNum - 1;
            std::cout << names[deleteNum] << " has been removed!" << std::endl << std::endl;
            deleteToki(deleteNum,cycle,names,measurements, abilities);
            cycle --;
            
        }
        if (input == 4) {
            // New ability Call
            int TokiNum, newAbility;
            std::string selectAbility;
            std::string abilityName[5];
            
            displayAllTokis(cycle,names,measurements,abilities);
            
            std::cout << "(Enter 0 to cancel)" << std::endl;
            std::cout << "> ";
            std::cin >> TokiNum;
            
            TokiNum = TokiNum - 1;
            
            if (TokiNum == -1) {
                continue;
                
            }
            std::cout << "Which ability (0 to cancel)? ";
            std::cin >> selectAbility;
            
            if (selectAbility == "0") {
                continue;
                
            }
            std::cout << "New value?                   ";
            std::cin >> newAbility;
            
            if (newAbility == 0) {
                continue;
                
            }
            if (newAbility < 0 || newAbility > 99) {
                std::cout << "Please enter a number between 1-99 (press 0 to cancel): ";
                std::cin >> newAbility;
                
            }
            if (newAbility == 0) {
                continue;
                
            }
            while (newAbility < 0 || newAbility > 99) {
                std::cout << "Please enter a number between 1-99 (press 0 to cancel: ";
                std::cin >> newAbility;
                
                if (newAbility == 0) {
                    continue;
                    
                }
                
            }
            std::cout << names[TokiNum] << " now has " << selectAbility << " ability " << newAbility << "!";
            std::cout << std::endl << std::endl;
            
            alterTokiAbility(abilityName, selectAbility, newAbility, TokiNum, names, abilities);
            
        }
        if (input == 5) {
            // New Height Call
            int selectHeight;
            int valueOfHeight;
            
            displayAllTokis(cycle,names,measurements, abilities);
            
            std::cout << "(Enter 0 to cancel)" << std::endl;
            std::cout << "> ";
            std::cin >> selectHeight;
            
            if (selectHeight == 0) {
                continue;
                
            }
            selectHeight = selectHeight - 1;
            std::cout << "What is your new height value? ";
            std::cin >> valueOfHeight;

            while (valueOfHeight < 10 || valueOfHeight > 99) {
                std::cout << "Please enter a value inbetween 10-99";
                std::cin >> valueOfHeight;
                
            }
            alterTokiHeight(selectHeight, valueOfHeight, measurements, names);
            
        }
        if (input == 6) {
            // New Weight Call
            int selectWeight;
            int valueOfWeight;
            
            displayAllTokis(cycle,names,measurements, abilities);
            
            std::cout << "(Enter 0 to cancel)" << std::endl;
            std::cout << "> ";
            std::cin >> selectWeight;
            
            if (selectWeight == 0) {
                continue;
                
            }
            selectWeight = selectWeight - 1;
            std::cout << "What is your new weight value? ";
            std::cin >> valueOfWeight;
          
            while (valueOfWeight < 4 || valueOfWeight > 30) {
                std::cout << "Please enter a value inbetween 4-30: ";
                std::cin >> valueOfWeight;
                
            }
            alterTokiWeight(valueOfWeight, selectWeight, measurements, names);
            
        }
        if (input == 8) {
            std::cout << "Your Tokimon are fully rested and Healed!" << std::endl;
            std::cout << std::endl;
        }
    }
return 0;
}
