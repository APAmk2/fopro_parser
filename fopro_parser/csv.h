// csv.h - csv parser header file.
// Copyright (C) 2024 APAMk2
#pragma once

#include <string>
#include <filesystem>
#include <unordered_map>

void LoadCsv(std::filesystem::path file);
void SetupLists();
void GenerateFopro(std::string input);
void processCSV(std::filesystem::path file);