#include "Resume.h"
#include <iostream>

// Constructor
Resume::Resume(const std::string &id, const std::string &filePath, const std::string &userID)
    : resumeID(id), filePath(filePath), userID(userID) {}

// Upload resume
void Resume::uploadResume(const std::string &filePath) {
    this->filePath = filePath;
    std::cout << "Resume uploaded: " << filePath << std::endl;
}

// Extract skills (placeholder logic)
void Resume::extractSkills(const std::string &jobDescription) {
    std::cout << "Extracting skills from job description: " << jobDescription << std::endl;
}

// Generate tailored resume (placeholder logic)
std::string Resume::generateTailoredResume(const std::vector<std::string> &skills) {
    std::string tailoredResume = "Tailored Resume:\n";
    for (const auto &skill : skills) {
        tailoredResume += "- " + skill + "\n";
    }
    return tailoredResume;
}
