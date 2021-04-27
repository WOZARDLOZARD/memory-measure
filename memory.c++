#include <iostream>
#include <mach/mach.h>
#include <string>
#include <math.h>
#include <sstream>
#include <iomanip>
using namespace std;

int get_memory() {
    struct task_basic_info t_info;
    mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

    if (KERN_SUCCESS != task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count)) {
        return -1;
    }

    return t_info.resident_size;
}

int custom_round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

std::string format(double f, int n)
{
    if (f == 0) {
        return "0";
    }
    int d = (int)::ceil(::log10(f < 0 ? -f : f)); /*digits before decimal point*/
    double order = ::pow(10., n - d);
    std::stringstream ss;
    ss << std::fixed << std::setprecision(std::max(n - d, 0)) << custom_round(f * order) / order;
    return ss.str();
}

int main() {
    double a, b, c;
    long used, heap, total = 0;
    int i;

    cout << "VANILLA\n\n";

    used = 0;
    for (i = 0; i < 15; i++) {
        heap = get_memory();
        used += heap;
        total += used;
        cout << "Iteration " + std::to_string(i + 1) + ": " + format(used / 1e+6, 3) + " MB\n";
    }

    cout << "\n\nLOGIC STATEMENTS\n\n";

    used = 0;
    for (i = 0; i < 15; i++) {
        a = (long)::floor((((double) rand() / (RAND_MAX)) + 1) * 10);
        b = (long)::floor((((double) rand() / (RAND_MAX)) + 1) * 10);
        c = (long)::floor((((double) rand() / (RAND_MAX)) + 1) * 10);

        if (a == b && a == c || a != b || a != c && a == b) {
            heap = get_memory();
        } else {
            heap = get_memory();
        }

        used += heap;
        total += used;
        cout << "Iteration " + std::to_string(i + 1) + ": " + format(used / 1e+6, 3) + " MB\n";
    }

    cout << "\n\nARITHMETIC OPERATIONS\n\n";

    used = 0;
    for (i = 0; i < 15; i++) {
        a = (((floor(random() * 10) + 3) * 8) / 4) - (6 / sin(M_PI / 23));
        b = cos((a * -1) / sin(5 + 2));
        c = sqrt(((b / 3) + (a + 5) - b)) / pow(4, 3 * (2 * 9));

        heap = get_memory();
        used += heap;
        total += used;
        cout << "Iteration " + std::to_string(i + 1) + ": " + format(used / 1e+6, 3) + " MB\n";
    }

    cout << "\n\nTotal usage: " + format(total / 1e+6, 3) + " MB";

    return 0;
}