#include "JsonHelloWorldCtrl.h"
void JsonHelloWorldCtrl::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value ret;
    ret["message"] = "Hello, World!";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}


