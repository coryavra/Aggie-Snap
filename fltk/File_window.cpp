#include "File_window.h"
#include "../input.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

File_window::File_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    file_input  {Point(100,0), x_max()-240, y_max()/2, "File: (images/)"},
    tag_input   {Point(40,y_max()/2), x_max()-180, y_max()/2, "Tags:"},

    button_pushed(false)
{
    attach(file_input);
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool File_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 1
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void File_window::cb_submit(Address, Address pw)
{
    reference_to<File_window>(pw).submit();
}

//------------------------------------------------------------------------------

void File_window::cb_quit(Address, Address pw)
{
    reference_to<File_window>(pw).quit();
}

//------------------------------------------------------------------------------

void File_window::submit()
{
    button_pushed = true;
    open_file(file_input.get_string(), tag_input.get_string());
    wait_for_button();
}

//------------------------------------------------------------------------------

void File_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
