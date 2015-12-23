#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_file.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <iostream>
#include <stdlib.h>

#include "login_form.h"
#include "upload_form.h"
#include "update_nick_form.h"
#include "login_message.h"

class hello : public cppcms::application {
public:
    hello(cppcms::service &srv) :
        cppcms::application(srv)
    {
        dispatcher().assign("/login", &hello::login, this);
        mapper().assign("login","/login");

        dispatcher().assign("/update_nick", &hello::update_nickname, this);
        mapper().assign("update_nick","/update_nick");

        dispatcher().assign("/update_pic", &hello::update_pic, this);
        mapper().assign("update_pic","/update_pic");

        dispatcher().assign("/welcome", &hello::welcome, this);
        mapper().assign("welcome", "/welcome");

        mapper().root("/hello");
    }
    void login();
    void update_nickname();
    void update_pic();
    void welcome();
};

void hello::login()
{
    login_message::user_message m;
    m.username = "1";
    render("login", m);
}

void hello::update_nickname()
{
    update_nick_form::update_nick n;
    if (request().request_method() == "POST") {
        n.info.load(context());
        if (n.info.validate())
        {
            // processing
        }
    }
    render("update_nick", n);
}

void hello::update_pic()
{
    upload_form::upload c;
    if (request().request_method() == "POST")
    {
        c.info.load(context());
        if (c.info.validate())
        {
            std::string new_name = "latest_image";
            if(c.info.image.value()->mime() == "image/png")
            {
                new_name += ".png";
            }
            else
            {
                new_name += ".jpg"; // we had validated mime-type
            }
            c.info.image.value()->save_to("./uploads/" + new_name);
            c.info.clear();
        }
    }
    render("upload", c);
}

void hello::welcome()
{
    login_form::user_login u;
    render("welcome", u);
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
