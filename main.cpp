#include <pistache/endpoint.h>
#include <pistache/router.h>
#include "Resume.h"
#include "Admin.h"
#include "FileUploader.h"

using namespace Pistache;

// Functionality: Upload Resume
void uploadResume(const Rest::Request &request, Http::ResponseWriter response) {
    FileUploader uploader;
    auto filePath = request.body();
    if (uploader.validateFile(filePath)) {
        uploader.uploadFile(filePath);
        response.send(Http::Code::Ok, "Resume uploaded successfully.");
    } else {
        response.send(Http::Code::Bad_Request, "Invalid file type.");
    }
}

// Functionality: Manage Content (Admin only)
void manageContent(const Rest::Request &request, Http::ResponseWriter response) {
    Admin admin("1", "Admin User", "admin123");
    admin.manageContent();  // Example function call
    response.send(Http::Code::Ok, "Content managed successfully.");
}

int main() {
    // Initialize Pistache HTTP server
    Http::Endpoint server(Address("localhost", Port(8080)));

    // Create the router
    Rest::Router router;

    // Define routes
    Routes::Post(router, "/uploadResume", Routes::bind(uploadResume));
    Routes::Post(router, "/manageContent", Routes::bind(manageContent));

    // Start the server
    server.init(Http::Endpoint::options().threads(1));
    server.setHandler(router.handler());
    server.serve();

    return 0;
}
