# warpcore_commandlineclient
To compile, type:
g++ commandline.cpp jsoncpp.cpp main.cpp -o client
Amalgamated source of JsonCpp is needed to compile (https://github.com/open-source-parsers/jsoncpp/wiki/Amalgamated).

To start program, e.g. type:
/usbstick/client/client --ip=127.0.0.1 --port=54321 --command=GET_PRESET_NAMES
The command GET_PRESET_NAMES will print all available preset names to the shell.
