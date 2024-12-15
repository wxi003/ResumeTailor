#include "SkillMatcher.h"

std::vector<std::string> SkillMatcher::matchSkills(const Resume &resume, const JobDescription &jobDescription) {
    std::vector<std::string> matchedSkills;

    for (const auto &skill : resume.getHardSkills()) {
        if (std::find(jobDescription.getRequiredSkills().begin(), jobDescription.getRequiredSkills().end(), skill) != jobDescription.getRequiredSkills().end()) {
            matchedSkills.push_back(skill);
        }
    }
    return matchedSkills;
}
