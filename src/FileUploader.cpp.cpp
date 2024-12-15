#include "FileUploader.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <filesystem>

#define MAX_FILE_SIZE 10 * 1024 * 1024  // 10 MB

// Ensure the uploads directory exists
void FileUploader::ensureUploadsDirectoryExists() {
    if (!std::filesystem::exists("./uploads")) {
        std::filesystem::create_directory("./uploads");
    }
}

// Save the uploaded file to the server
std::string FileUploader::saveFile(const std::string &fileData, const std::string &fileName) {
    ensureUploadsDirectoryExists();
    std::string filePath = "./uploads/" + fileName;

    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Failed to save file");
    }
    outFile << fileData;
    outFile.close();

    return filePath;
}

// Validate file type
bool FileUploader::validateFileType(const std::string &fileName) {
    std::regex fileTypeRegex(".*\\.(pdf|docx)$", std::regex::icase);
    return std::regex_match(fileName, fileTypeRegex);
}

// Handle resume upload
void FileUploader::uploadResume(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {
        auto fileName = request.query().get("filename").getOrElse("resume.pdf");
        auto fileData = request.body();

        if (fileName.find("..") != std::string::npos) {
            response.send(Pistache::Http::Code::Bad_Request, "Invalid file name.");
            return;
        }

        if (fileData.size() > MAX_FILE_SIZE) {
            response.send(Pistache::Http::Code::Payload_Too_Large, "File size exceeds limit.");
            return;
        }

        if (!validateFileType(fileName)) {
            response.send(Pistache::Http::Code::Bad_Request, "Invalid file type. Only PDF and DOCX are allowed.");
            return;
        }

        std::string savedPath = saveFile(fileData, fileName);
        response.send(Pistache::Http::Code::Ok, R"({"status": "success", "path": ")" + savedPath + R"("})");
    } catch (const std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}

// Handle job description upload
void FileUploader::uploadJobDescription(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {
        auto fileName = request.query().get("filename").getOrElse("job_description.pdf");
        auto fileData = request.body();

        if (fileName.find("..") != std::string::npos) {
            response.send(Pistache::Http::Code::Bad_Request, "Invalid file name.");
            return;
        }

        if (fileData.size() > MAX_FILE_SIZE) {
            response.send(Pistache::Http::Code::Payload_Too_Large, "File size exceeds limit.");
            return;
        }

        if (!validateFileType(fileName)) {
            response.send(Pistache::Http::Code::Bad_Request, "Invalid file type. Only PDF and DOCX are allowed.");
            return;
        }

        std::string savedPath = saveFile(fileData, fileName);
        response.send(Pistache::Http::Code::Ok, R"({"status": "success", "path": ")" + savedPath + R"("})");
    } catch (const std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}
