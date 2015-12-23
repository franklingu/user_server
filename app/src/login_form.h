#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <cppcms/view.h>
#include <cppcms/form.h>

#include <iostream>

namespace login_form  {
    struct user_form : public cppcms::form {
        cppcms::widgets::text username;
        cppcms::widgets::password pswd;
        cppcms::widgets::submit submit;
        user_form()
        {
            username.message("Your username");
            username.non_empty();
            pswd.message("Your password");
            pswd.non_empty();
            submit.value("Login");
            add(username);
            add(pswd);
            add(submit);
        }
    };

    struct user_login : public cppcms::base_content {
        user_form info;
    };
}

#endif
