// fopro.h - fopro parser header.
// Copyright (C) 2024 APAMk2
#pragma once

#include <string>
#include <filesystem>
#include <unordered_map>

void DelimateStr(std::string input, std::string& key, std::string& val);
void LoadFopro(std::filesystem::path file);
void GetProtoMap(std::string input, std::unordered_map<std::string, std::string>& output);
std::string pushBack(std::string topush);
void GenerateCSV(std::unordered_map<std::string, std::string> input);
void WriteCSV(std::filesystem::path file);
void GenerateLists();
void processFOPRO(std::filesystem::path file);