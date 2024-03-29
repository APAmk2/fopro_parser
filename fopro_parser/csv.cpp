// csv.cpp - csv parser source file.
// Copyright (C) 2024 APAMk2
#include "csv.h"
#include "utils.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> csvDataBlocks;
string csvFileOutput;
vector<string> csvLists;

void LoadCsv(filesystem::path file) {
    string currFileStr;
    string line2Append;
    ifstream input(file.string());
    if (input.is_open()) {
        while (getline(input, currFileStr)) {
            stringstream ss(currFileStr);
            string currStr;
            while (getline(ss, currStr, ',')) {
                line2Append += currStr;
                line2Append += "\n";
            }
            csvDataBlocks.push_back(line2Append);
            line2Append.clear();
        }
    }
    csvDataBlocks.push_back(line2Append);
    input.close();
}

void SetupLists() {
    stringstream ss(csvDataBlocks[0]);
    string currLine;
    unordered_map<string, string> config;
    LoadListsConfig(config, true);
    while (getline(ss, currLine)) {
        if (auto search = config.find(currLine); search != config.end()) {
            csvLists.push_back(search->second);
        }
        else {
            csvLists.push_back(currLine);
        }
    }
}

void GenerateFopro(string input) {
    stringstream ss(input);
    string currLine;
    int counter = 0;
    string localOutput;
    
    localOutput += "[Proto]\n";

    while (getline(ss, currLine)) {
        if (csvLists[counter] == "define") {
            if (currLine != "") {
                localOutput = currLine + "\n" + localOutput;
            }
            counter++;
            continue;
        }
        string line2Append = csvLists[counter] + "=" + currLine + "\n";
        if (currLine != "") {
            localOutput += line2Append;
        }
        counter++;
    }
    localOutput += "\n";
    csvFileOutput += localOutput;
}

void processCSV(filesystem::path file) {
    LoadCsv(file);
    SetupLists();
    for (size_t i = 1; i < csvDataBlocks.size(); i++) {
        GenerateFopro(csvDataBlocks[i]);
    }
    WriteFile(file, csvFileOutput, ".fopro");
}