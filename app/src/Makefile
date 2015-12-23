LIBS=-lcppcms -lbooster
CFLAGS=$(shell mysql_config --cflags) $(shell mysql_config --libs)

all: clean hello

hello: hello.cpp view.cpp upload_form.h login_form.h login_message.h update_nick_form.h db_connection.h
	$(CXX) -Wall $(CXXFLAGS) hello.cpp view.cpp db_connection.cpp -o hello $(LIBS) $(CFLAGS)

view.cpp: upload_form_view.tmpl welcome_view.tmpl login_view.tmpl update_nick.tmpl upload_form.h login_form.h login_message.h update_nick_form.h
	cppcms_tmpl_cc upload_form_view.tmpl welcome_view.tmpl login_view.tmpl update_nick.tmpl -o view.cpp

clean:
	rm -fr *.exe *.so view.cpp cppcms_rundir hello
