#include "ResumeEditor.h"
#include "Resume.h"
#include "TailoringSuggestion.h"
#include <string>
#include <vector>
#include <sstream>

// Generate a live preview of the resume
std::string ResumeEditor::getLivePreview(const Resume &resume, const std::vector<TailoringSuggestion> &suggestions) {
    std::stringstream preview;

    // Start with the base resume content
    preview << "Live Preview of Resume\n";
    preview << "========================\n";
    preview << "Hard Skills:\n";
    for (const auto &skill : resume.hardSkills) {
        preview << "- " << skill << "\n";
    }
    preview << "\nSoft Skills:\n";
    for (const auto &skill : resume.softSkills) {
        preview << "- " << skill << "\n";
    }

    // Apply tailoring suggestions
    preview << "\nTailored Suggestions:\n";
    for (const auto &suggestion : suggestions) {
        preview << "- " << suggestion.getSuggestedText() << "\n";
    }

    return preview.str();
}
