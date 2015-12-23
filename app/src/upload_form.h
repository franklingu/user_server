#ifndef UPLOAD_FORM_H
#define UPLOAD_FORM_H

#include <cppcms/view.h>
#include <cppcms/form.h>

#include <iostream>


namespace upload_form  {
    struct file_form : public cppcms::form {
        cppcms::widgets::file image;
        cppcms::widgets::submit submit;
        file_form()
        {
            image.message("Image to upload");
            image.help("PNG or JPEG only allowed under 100Kb");
            image.non_empty();

            // Sanity checks on the image

            // size 100k
            image.limits(0, 100*1024);
            // Filename with proper extension (optional)
            image.filename(booster::regex(".*\\.(jpg|jpeg|png)"));
            // Correct mime type (optional)
            image.mime(booster::regex("image/(png|jpeg)"));

            // And the most important (more then two above) the
            // magic numbers for each file and this the most important
            // validation
            //
            // Note: this what really defines the file type, other can be
            // easily changed
            image.add_valid_magic("\x89\x50\x4e\x47\x0D\x0A\x1A\x0A"); // png
            image.add_valid_magic("\xff\xd8"); // jpeg

            submit.value("Upload");

            add(image);
            add(submit);
        }
    };

    struct upload : public cppcms::base_content {
        file_form info;
    };

}

#endif
