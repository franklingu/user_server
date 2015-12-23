#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_file.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <iostream>
#include <stdlib.h>

#include "upload_form.h"

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

        dispatcher().assign("/", &hello::welcome, this);
        mapper().assign("");

        mapper().root("hello");
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
    upload_form::upload c;
    if (request().request_method()=="POST") {
        c.info.load(context());
        if (c.info.validate()) {
            // Create file name
            //
            // Note:
            // NEVER, NEVER, NEVER use user supplied file name!
            //
            // Use it to display or for general information only.
            //
            // If you would try to save the file under user supplied name you
            // may open yourself to multiple security issues like directory
            // traversal and more.
            //
            // So create your own name. If you want to keep the connection with original
            // name you may use sha1 hash and then save it.
            //
            std::string new_name = "latest_image";
            if(c.info.image.value()->mime() == "image/png")
                new_name += ".png";
            else
                new_name += ".jpg"; // we had validated mime-type

            //
            // Note: save_to is more efficient then reading file from
            // c.info.image.value()->data() stream and writing it
            // as save to would try to move the saved file over file-system
            // and it would be more efficient.
            //
            c.info.image.value()->save_to("./uploads/" + new_name);
            c.info.clear();
        }
    }
    render("upload",c);
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
