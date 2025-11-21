// Implementation of utility functions for No Stragglers problem
#include "utils.h"

int total_stragglers(int students, int visitors, int faculty)
{
    // FIXME4: Return the total number of stragglers
    return 0;
}

void update_count(char type, char in_out, int count, int &students, int &visitors, int &faculty)
{
    switch (type)
    {
    case 'S':
        if (in_out == 'I')
            students += count;
        else
            students -= count;
        break;
        // FIXME5: Implement logic for 'V' (visitors)
        // FIXME6: Implement logic for 'F' (faculty)
    }
}