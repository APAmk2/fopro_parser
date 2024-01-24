// fopro.cpp - fopro parser header file.
// Copyright (C) 2024 APAMk2
#pragma once

#include <string>
#include <filesystem>
#include <unordered_map>

void LoadFopro(std::filesystem::path file);
void GetProtoMap(std::string input, std::unordered_map<std::string, std::string>& output);
std::string pushBack(std::string topush);
void GenerateCSV(std::unordered_map<std::string, std::string> input);
void GenerateLists();
void processFOPRO(std::filesystem::path file);