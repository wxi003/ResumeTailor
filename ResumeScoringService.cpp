#include "ResumeScoringService.h"

int ResumeScoringService::scoreResume(const Resume &resume, const JobDescription &jobDescription) {
    int score = 0;

    // Example logic for scoring
    for (const auto &skill : resume.getHardSkills()) {
        if (std::find(jobDescription.getRequiredSkills().begin(), jobDescription.getRequiredSkills().end(), skill) != jobDescription.getRequiredSkills().end()) {
            score += 10; // Add points for each matched skill
        }
    }
    return score;
}
