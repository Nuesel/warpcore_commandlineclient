#include "commandline.h"

#include <ctype.h>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include <string.h>
#include <iostream>

const int cIP = 1;
const int cPort = 2;
const int cCommand = 4;

extern char *optarg;

void CheckChar(int option_index, char optarg[])
{
    if (!isdigit(optarg[0]))
    {
        cout << "No valid argument \"" << optarg << "\" for option \"" << long_options[option_index].name << "\"" << endl;
        exit(EXIT_FAILURE);
    }
}

void commandline_options(int argc, char* const argv[], option_values* values)
{
    int option_index = 0;
    int args_found = 0;
    
    values->ip = "";
    values->port = 0;
    values->command = "";
    
    while (getopt_long_only(argc, argv, "", long_options, &option_index) != -1)
    {
        switch (option_index)
        {
            case 0:
                values->ip = optarg;
                args_found |= cIP;
                break;
            case 1:
			    CheckChar(option_index, optarg);
                values->port = atoi (optarg);
                args_found |= cPort;
                break;
            case 2:
                values->command = optarg;
                args_found |= cCommand;
                break;
            default:
                cout << "Invalid option index " << option_index << " with arg "<< optarg << endl;
                exit(EXIT_FAILURE);
                break;
        }
    }
    if (args_found != (cIP | cPort | cCommand))
    {
        cout << "usage: " << argv[0] << " --ip=x --port=x --command=x" << endl;
        args_found = ~args_found & 7;
        if ((args_found & cIP) > 0)
        {
            cout << "ip address missed" << endl;
        }
        if ((args_found & cPort) > 0)
        {
            cout << "port missed" << endl;
        }
        if ((args_found & cCommand) > 0)
        {
            cout << "command missed" << endl;
        }
        exit(EXIT_FAILURE);
    }
}