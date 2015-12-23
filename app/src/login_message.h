#ifndef LOGIN_MESSAGE_H
#define LOGIN_MESSAGE_H

#include <cppcms/view.h>

#include <iostream>

namespace login_message  {
    struct user_message : public cppcms::base_content {
        std::string username;
    };
}

#endif
