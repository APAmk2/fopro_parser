// utils.h - some universal funcs source file.
// Copyright (C) 2024 APAMk2
#include "utils.h"

#include <fstream>

using namespace std;

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

void LoadListsConfig(unordered_map<string, string>& output, bool reverse) {
    ifstream config("userconfig.cfg");
    string currStr;

    if (config.is_open()) {
        while (getline(config, currStr, '\n')) {
            string key, val;
            DelimateStr(currStr, key, val);
            if (key != "" && val != "") {
                if (!reverse) {
                    output[key] = val;
                }
                else {
                    output[val] = key;
                }
            }
        }
    }

    config.close();
}

void WriteFile(filesystem::path file, string output, string extension) {
    ofstream out;
    out.open(file.filename() += extension);
    if (out.is_open())
    {
        out << output << endl;
    }
    out.close();
}