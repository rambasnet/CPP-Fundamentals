#include <string>
#include "util.h"
using namespace std;

// given width of the column and the string, function returns centered string within the column
string center_text(int width, const string &str)
{
    int len = str.length();
    if (width < len)
        return str;
    int diff = width - len;
    int pad1 = diff / 2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' ');
}