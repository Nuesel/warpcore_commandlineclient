#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <string>
#include <getopt.h>

using namespace std;

const struct option long_options[] =
{
    {"ip",             required_argument, 0, 0},
    {"port",           required_argument, 0, 0},
    {"command",        required_argument, 0, 0},
    {0,                0,                 0, 0}
};

typedef struct
{
    std::string ip;
    int port;
    std::string command;
} option_values;

void commandline_options(int argc, char* const argv[], option_values* values);

#endif //COMMANDLINE_H
