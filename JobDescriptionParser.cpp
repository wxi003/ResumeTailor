#include "JobDescriptionParser.h"
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <iostream>

// Parse the job description file to extract required skills
std::vector<std::string> JobDescriptionParser::parse(const std::string &filePath) {
    std::vector<std::string> requiredSkills;

    // Open the JSON file
    FILE *fp = fopen(filePath.c_str(), "r");
    if (!fp) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    // Use RapidJSON to parse the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    fclose(fp);

    // Check if the document is valid JSON
    if (!document.IsObject()) {
        throw std::runtime_error("Invalid JSON format in file: " + filePath);
    }

    // Extract required hard skills
    if (document.HasMember("requiredHardSkills") && document["requiredHardSkills"].IsArray()) {
        for (const auto &skill : document["requiredHardSkills"].GetArray()) {
            if (skill.IsString()) {
                requiredSkills.push_back(skill.GetString());
            }
        }
    }

    // Extract required soft skills
    if (document.HasMember("requiredSoftSkills") && document["requiredSoftSkills"].IsArray()) {
        for (const auto &skill : document["requiredSoftSkills"].GetArray()) {
            if (skill.IsString()) {
                requiredSkills.push_back(skill.GetString());
            }
        }
    }

    return requiredSkills;
}
