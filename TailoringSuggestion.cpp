#include "TailoringSuggestion.h"
#include <iostream>

// Constructor
TailoringSuggestion::TailoringSuggestion(const std::string &id, const std::string &skill, const std::string &suggestedText)
    : suggestionID(id), skill(skill), suggestedText(suggestedText) {}

// Generate a tailoring suggestion based on the resume and job description
void TailoringSuggestion::generateSuggestion(const Resume &resume, const JobDescription &jobDescription) {
    // Example logic: Check if the job description requires a skill not present in the resume
    if (std::find(jobDescription.requiredHardSkills.begin(), jobDescription.requiredHardSkills.end(), skill) != jobDescription.requiredHardSkills.end()) {
        if (std::find(resume.hardSkills.begin(), resume.hardSkills.end(), skill) == resume.hardSkills.end()) {
            suggestedText = "Consider adding '" + skill + "' to align with the job description.";
        } else {
            suggestedText = "'" + skill + "' is already highlighted in the resume.";
        }
    } else if (std::find(jobDescription.requiredSoftSkills.begin(), jobDescription.requiredSoftSkills.end(), skill) != jobDescription.requiredSoftSkills.end()) {
        if (std::find(resume.softSkills.begin(), resume.softSkills.end(), skill) == resume.softSkills.end()) {
            suggestedText = "Consider emphasizing your '" + skill + "' skill in the resume.";
        } else {
            suggestedText = "'" + skill + "' is already highlighted in the resume.";
        }
    } else {
        suggestedText = "No specific tailoring required for the skill: '" + skill + "'.";
    }
}

// Apply a tailoring suggestion to the resume
void TailoringSuggestion::applySuggestion() {
    std::cout << "Applying suggestion: " << suggestedText << std::endl;
    // Logic to apply the suggestion to the resume
    // For example, append the suggested text to the corresponding section in the resume.
}

// Withdraw a tailoring suggestion
void TailoringSuggestion::withdrawSuggestion() {
    std::cout << "Withdrawing suggestion: " << suggestedText << std::endl;
    // Logic to undo the applied suggestion
    // For example, remove the text added by `applySuggestion`.
}
