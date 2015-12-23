#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <iostream>
#include <stdlib.h>

class hello : public cppcms::application {
public:
    hello(cppcms::service &srv) :
        cppcms::application(srv)
    {
        dispatcher().assign("/login", &hello::login, this);
        mapper().assign("login","/login");

        dispatcher().assign("/updatenick", &hello::update_nickname, this);
        mapper().assign("updatenick","/updatenick");

        dispatcher().assign("/updatepic", &hello::update_pic, this);
        mapper().assign("updatepic","/updatepic");

        dispatcher().assign("/index", &hello::welcome, this);
        mapper().assign("index", "/index");

        mapper().root("");
    }
    void login();
    void update_nickname();
    void update_pic();
    void welcome();
};

void hello::login()
{
    response().out() <<
        "<html><head><title>Welcome to user sys</title></head>"
        "<body><h1>Login!</h1></body></html>";
}

void hello::update_nickname()
{
    response().out() <<
        "<html><head><title>Welcome to user sys</title></head>"
        "<body><h1>Update nickname!</h1></body></html>";
}

void hello::update_pic()
{
    response().out() <<
        "<html><head><title>Welcome to user sys</title></head>"
        "<body><h1>Update Pic!</h1></body></html>";
}

void hello::welcome()
{
    response().out() <<
        "<html><head><title>Welcome to user sys</title></head>"
        "<body><h1>Welcome!</h1></body></html>";
}

int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(
            cppcms::applications_factory<hello>()
        );
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
