#include "JobDescription.h"
#include <iostream>

// Constructor
JobDescription::JobDescription(const std::string &id, const std::string &title, const std::string &description)
    : jobID(id), title(title), description(description) {}

// Upload job description
void JobDescription::uploadJobDescription(const std::string &filePath) {
    std::cout << "Job description uploaded: " << filePath << std::endl;
}

// Extract required skills (placeholder logic)
void JobDescription::extractRequiredSkills() {
    std::cout << "Extracting required skills from job description..." << std::endl;
}
