// main.cpp - main func header-less source file.
// Copyright (C) 2024 APAMk2
#include "fopro.h"
#include "csv.h"

#include <iostream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]) {
    filesystem::path file = argv[1];

    if (file.extension() == ".fopro") {
        processFOPRO(file);
    }
    else if (file.extension() == ".csv") {
        processCSV(file);
    }

	return 0;
}
