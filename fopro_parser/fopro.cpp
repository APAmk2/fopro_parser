// fopro.cpp - fopro parser source file.
// Copyright (C) 2024 APAMk2

#include "fopro.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> protoDataBlocks;
string foproFileOutput;

vector<string> foproLists;

void DelimateStr(string input, string& key, string& val) {
    bool isKeyParsed = false;
    if (input.find("=") != input.npos) {
        for (char c : input) {
            if (c == '=') {
                isKeyParsed = true;
                continue;
            }
            if (!isKeyParsed) {
                key += c;
            }
            else {
                val += c;
            }
        }
    }
}

void LoadFopro(filesystem::path file) {
    string currString;
    string line2Append;
    ifstream input(file.string());
    if (input.is_open()) {
        while (getline(input, currString)) {
            if (currString == "") {
                protoDataBlocks.push_back(line2Append);
                line2Append.clear();
                continue;
            }
            line2Append +=currString;
            line2Append += "\n";
        }
    }
    protoDataBlocks.push_back(line2Append);
    input.close();
}

void GetProtoMap(string input, unordered_map<string, string>& output) {
    stringstream ss(input);
    string currStr;

    while (getline(ss, currStr, '\n')) {
        string key, val;
        DelimateStr(currStr, key, val);
        if (key != "") {
            output[key] = val;
        }
    }
}

string pushBack(string topush) {
    string result;

    result += topush += ",";
    return result;
}

void GenerateCSV(unordered_map<string, string> input) {
    for (size_t i = 0; i < foproLists.size(); i++) {
        foproFileOutput += pushBack(input[foproLists[i]]);
    }
    foproFileOutput += "\n";
}

void WriteCSV(filesystem::path file) {
    ofstream out;
    out.open(file.filename() += ".csv");
    if (out.is_open())
    {
        out << foproFileOutput << endl;
    }
    out.close();
}

void GenerateLists() {
    for (size_t i = 0; i < protoDataBlocks.size(); i++) {
        unordered_map<string, string> data;
        GetProtoMap(protoDataBlocks[i], data);
        ofstream goy("goy.txt");
        for (const auto& [key, value] : data) {
           
            goy << key << " " << value << endl;
        }
        goy.close();
        for (const auto& [key, value] : data) {
            if (find(foproLists.begin(), foproLists.end(), key) == foproLists.end()) {
                foproLists.push_back(key);
            }
        }
    }
    for (size_t i = 0; i < foproLists.size(); i++) {
        foproFileOutput += pushBack(foproLists[i]);
    }
    foproFileOutput += "\n";
}

void processFOPRO(filesystem::path file) {
    LoadFopro(file);
    GenerateLists();

    for (size_t i = 0; i < protoDataBlocks.size(); i++) {
        unordered_map<string, string> data;
        GetProtoMap(protoDataBlocks[i], data);
        GenerateCSV(data);
    }
    WriteCSV(file);
}