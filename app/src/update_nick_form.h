#ifndef UPDATE_NICK_FORM_H
#define UPDATE_NICK_FORM_H

#include <cppcms/view.h>
#include <cppcms/form.h>

#include <iostream>


namespace update_nick_form  {
    struct nick_form : public cppcms::form {
        cppcms::widgets::hidden username;
        cppcms::widgets::text nickname;
        cppcms::widgets::submit submit;
        nick_form()
        {
            nickname.message("New nickname");
            submit.value("Upload");
            add(username);
            add(nickname);
            add(submit);
        }
    };

    struct update_nick : public cppcms::base_content {
        nick_form info;
    };

}

#endif
