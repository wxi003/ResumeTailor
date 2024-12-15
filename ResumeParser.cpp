#include "ResumeParser.h"
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <iostream>

// Parse the resume file to extract structured data (e.g., hard skills and soft skills)
std::vector<std::string> ResumeParser::parse(const std::string &filePath) {
    std::vector<std::string> extractedSkills;

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

    // Extract hard skills
    if (document.HasMember("hardSkills") && document["hardSkills"].IsArray()) {
        for (const auto &skill : document["hardSkills"].GetArray()) {
            if (skill.IsString()) {
                extractedSkills.push_back(skill.GetString());
            }
        }
    }

    // Extract soft skills
    if (document.HasMember("softSkills") && document["softSkills"].IsArray()) {
        for (const auto &skill : document["softSkills"].GetArray()) {
            if (skill.IsString()) {
                extractedSkills.push_back(skill.GetString());
            }
        }
    }

    return extractedSkills;
}
