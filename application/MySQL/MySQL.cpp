#include <drogon/drogon.h>
#include "Model/Student.h"
using namespace drogon;

int main()
{
    app()
    .loadConfigFile("config.json")
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
            orm::DbClientPtr db_client_ptr = drogon::app().getDbClient();
            orm::Mapper<drogon_model::products_db2::Student> mapper(db_client_ptr);

            std::vector<drogon_model::products_db2::Student> vs = mapper.findAll();

            Json::Value root;
            for (size_t i = 0; i < vs.size(); i++)
            {
                root.append(vs[i].toJson());
            }
            
            auto response = HttpResponse::newHttpJsonResponse(root);
            return response;
        }
        return nullptr;
    })
    .run();

    return 0;
}














