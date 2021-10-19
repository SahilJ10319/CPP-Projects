/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
// Name : <Sahil Janjua>
// St.# : <301358823>
// Email: <sahil_janjua@sfu.ca>
//
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>   
#include <fstream>
#include <string>
#include <map>
#include <unordered_set>



using namespace std;

int main() {
    int emptyBallot = 0;
    int fullBallot = 0;
    int total = 0;

    // Declare input file stream object / variable
    ifstream inputFile;
    string filename;

    // Prompt User to Enter File Name and Open File
    cout << "What is the name of the ballot file?" << endl;
    cin >> filename;
    cout << endl;
    inputFile.open(filename);

    map<char, int> m;

    string line;
    while (getline(inputFile, line)) {
        unordered_set<char> uset;
        if(line == "none") {
            emptyBallot++;
            total++;
            continue;
        }

        for(int i = 0; i < line.size(); i++) {
            if(line.at(i) == ' ') {
                continue;
            }

            if(uset.count(line.at(i))) {
                continue;
            }
            else {
                uset.insert(line.at(i));
            }

            if(m.count(line.at(i))) {
                m.at(line.at(i)) = m.at(line.at(i)) + 1;
            }
            else {
                m.insert( pair<char, int>(line.at(i), 1) );
            }
        }
        total++;
    }
    inputFile.clear();
    inputFile.seekg(0);
    while (getline(inputFile, line)) {
        int counter = 0;
        unordered_set<char> uset;
        if(line == "none") {
            continue;
        }
        for(int i = 0; i < line.size(); i++) {
            if(line.at(i) == ' ') {
                continue;
            }

            if(uset.count(line.at(i))) {
                continue;
            }
            else {
                uset.insert(line.at(i));
            }
            
            if(m.count(line.at(i))) {
                counter++;
            }
        }
        if(counter == m.size()) {
            fullBallot++;
        }
    }
    cout << "Total # of ballots: " << total << endl;
    for (std::map<char, int>::iterator i = m.begin(); i != m.end(); ++i) {
        cout << i->first << ": "
             << i->second << endl;
    }

    cout << "empty: " << emptyBallot << endl;
    cout << "full: "<< fullBallot;
    inputFile.close();
}
    
