// utils.h - some universal funcs header file.
// Copyright (C) 2024 APAMk2
#pragma once

#include <string>
#include <unordered_map>
#include <filesystem>

void DelimateStr(std::string input, std::string& key, std::string& val);
void LoadListsConfig(std::unordered_map<std::string, std::string>& output, bool reverse);
void WriteFile(std::filesystem::path file, std::string output, std::string extension);