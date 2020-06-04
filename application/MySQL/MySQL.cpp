#include <drogon/drogon.h>

using namespace drogon;

int main()
{
    app()
    .setLogPath("./")
    .setLogLevel(trantor::Logger::kWarn)
    .addListener("0.0.0.0", 7770)
    .setThreadNum(0)
    //.registerController(std::make_shared<JsonHelloWorldCtrl>())
    .registerSyncAdvice([](const HttpRequestPtr &req) -> HttpResponsePtr {
        const auto &path = req->path();
        if (path.length() == 1 && path[0] == '/')
        {
            //auto response = HttpResponse::newHttpResponse();
            //response->setBody("<p>MySQL</p>");
            auto response = HttpResponse::newFileResponse("/tmp/hehe.sql","的撒的");
            return response;
        }
        return nullptr;
    })
    .run();

    return 0;
}















