#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class HelloWorldCtrl : public drogon::HttpSimpleController<HelloWorldCtrl>
{
  public:
    virtual void asyncHandleHttpRequest(
        const HttpRequestPtr &req,
        std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/HelloWorld", Get);
    PATH_LIST_END
};