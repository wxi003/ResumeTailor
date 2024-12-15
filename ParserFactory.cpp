#include "ParserFactory.h"

std::unique_ptr<Parser> ParserFactory::createParser(const std::string &type) {
    if (type == "resume") {
        return std::make_unique<ResumeParser>();
    } else if (type == "job_description") {
        return std::make_unique<JobDescriptionParser>();
    } else {
        throw std::invalid_argument("Unknown parser type: " + type);
    }
}
