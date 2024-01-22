// fopro_parser.cpp - main source file.
// Copyright (C) 2024 APAMk2

#include "fopro_parser.h"
#include "fopro.h"
#include "csv.h"

using namespace std;

int main(int argc, char* argv[]) {
	file = argv[1];

    if (file.extension() == ".fopro") {
        processFOPRO(file);
    }
    else if (file.extension() == ".csv") {
        processCSV(file);
    }

	return 0;
}
