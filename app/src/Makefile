LIBS=-lcppcms -lbooster

all: clean hello

hello: hello.cpp upload_form_view.cpp upload_form.h
	$(CXX) -Wall $(CXXFLAGS) hello.cpp upload_form_view.cpp -o hello $(LIBS)

upload_form_view.cpp: upload_form_view.tmpl upload_form.h
	cppcms_tmpl_cc upload_form_view.tmpl -o upload_form_view.cpp

clean:
	rm -fr *.exe *.so upload_form.cpp cppcms_rundir hello
