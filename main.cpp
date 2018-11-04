//To compile this project:
//g++ commandline.cpp jsoncpp.cpp main.cpp -o client

#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include "commandline.h"
#include "json/json.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define STRINGIZER(x)   #x
#define EVALUATOR(x)    STRINGIZER(x)
#define NAME(x)         EVALUATOR(x)

#define COMMANDSIZE 2048
//#define CMD_RUN "RUN=%" NAME(COMMANDSIZE) "s"

void Run_Command(std::string command, Json::Value* Command)
{
	int id = 0;
	
	if (sscanf(command.c_str(), "RUN=%d", &id) > 0)
	{
		(*Command)["commands"]["run_preset"] = id;
	}
	if (command == "GET_CURRENT_PRESET")
	{
		(*Command)["commands"]["get_current_preset"];
	}
	if (command == "GET_PRESET_NAMES")
	{
		(*Command)["commands"]["get_presets"];
	}
	if (command == "GET_PRESET_IDS")
	{
		(*Command)["commands"]["get_presets"];
	}
	if (command == "STOP")
	{
		(*Command)["commands"]["stop_preset"] = true;
	}
        if (command == "NEXT_PRESET")
        {
                (*Command)["commands"]["set_next_preset"] = true;
        }
        if (command == "RELOAD_PRESETS")
        {
                (*Command)["commands"]["reload_presetfile"] = true;
        }
	if (command == "EXIT")
	{
		(*Command)["commands"]["exit"] = true;
	}
	if (command == "SHUTDOWN")
	{
		(*Command)["commands"]["shutdown"] = true;
	}
}

static std::string NumberToString (unsigned int number)
{
 std::ostringstream ss;
 ss << number;
 return ss.str();
}

std::string CreateOutputFromAnswer(std::string command_str, Json::Value command, Json::Value Answer)
{
	unsigned int presetsize = 0;
	std::string preset_id = "";
	std::string output = "";
	
	//if (command["commands"].isMember("get_presets"))
	if (command_str == "GET_PRESET_IDS")
	{
		if (Answer["presets"].isArray())
		{
			presetsize = Answer["presets"].size();
			if (presetsize > 0)
			{
				for (unsigned int i = 0; i < presetsize; i++)
				{
					preset_id = Answer["presets"][i]["id"].asString();
					if (preset_id != "")
					{
						output += preset_id + '\n';
					}
				}
				//preset_id = Answer["presets"][presetsize - 1]["id"].asString();
				//if (preset_id != "")
				//{
				//	output += preset_id;
				//}
			}
		}
	}
	if (command_str == "GET_PRESET_NAMES")
	{
		if (Answer["presets"].isArray())
		{
			presetsize = Answer["presets"].size();
			if (presetsize > 0)
			{
				for (unsigned int i = 0; i < presetsize; i++)
				{
					preset_id = Answer["presets"][i]["name"].asString();
					if (preset_id != "")
					{
						output += preset_id + '\n';
					}
				}
				//preset_id = Answer["presets"][presetsize - 1]["name"].asString();
				//if (preset_id != "")
				//{
				//	output += preset_id;
				//}
			}
		}
	}
	if (Answer["commands"].isMember("get_current_preset"))
	{
		//cout << "get_current_preset: " << Answer["commands"]["get_current_preset"] << endl;
		if (Answer["commands"]["get_current_preset"].isUInt())
		{
			output = "\"get_current_preset\" : " + NumberToString(Answer["commands"].get("get_current_preset", 0).asUInt());
		}
	}
	if (Answer["commands"].isMember("stop_preset"))
	{
		output = "\"stop_preset\" : " + Answer["commands"]["stop_preset"].toStyledString();
	}
	if (Answer["commands"].isMember("exit"))
	{
		output = "\"exit\" : " + Answer["commands"]["exit"].toStyledString();
	}
	if (Answer["commands"].isMember("shutdown"))
	{
		output = "\"shutdown\" : " + Answer["commands"]["shutdown"].toStyledString();
	}
	while (output[output.size() - 1] == '\n')
    	{
        	output.resize(output.size() - 1);
    	}
	//Remove last line feed
	//output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
		
	return output;
}


int main(int argc, char **argv)
{
    const unsigned int AnswerSize = 256;
    char buffer[AnswerSize] = {0};
    int sock = 0;
    int n = 0;
    struct sockaddr_in server;
    std::string cmd ="";
    std::string server_reply = "";
	
    option_values arguments;
	
    Json::Reader reader;
    Json::Value Command;
    Json::Value Answer;
    bool parsingSuccessful = false;
	
    commandline_options(argc, argv, &arguments);

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock < 0)
    {
        cout << "Could not create socket" << endl;
    }
    server.sin_addr.s_addr = inet_addr((arguments.ip).c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(arguments.port);
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        cout << "connect failed. Error" << endl;
        return 1;
    }
	
	//Send data
	Run_Command(arguments.command, &Command);
	cmd = Command.toStyledString() + (char)NULL;
	//cout << "Command:" << endl;
	//cout << cmd << endl;
	if(send(sock, cmd.c_str(), cmd.size(), 0) < 0)
	{
		cout << "Send failed" << endl;
		return 1;
	}
	
	//Receive a reply from the server
	server_reply.clear();
	do
	{
		bzero(buffer, AnswerSize);
		n = recv(sock , buffer, AnswerSize, 0);
		//if n == 0, client has disconnected
		if (n < 0)
		{
		   cout << "ERROR reading from socket" << endl;
		}
		server_reply = server_reply.append(buffer, n);
	}
	while (strlen(buffer) >= AnswerSize);
	
	if(server_reply.length() < 0)
	{
		cout << "recv failed" << endl;
	}
	else
	{
		Answer.clear();
		parsingSuccessful = reader.parse(server_reply, Answer, false);
		if (parsingSuccessful)
		{
			//cout << "Answer: " << endl << Answer.toStyledString() << endl;
			//cout << endl;
			cout << CreateOutputFromAnswer(arguments.command, Command, Answer);
		}
		else
		{
			// report to the user the failure and their locations in the document.
			std::cout  << "Failed to parse JSON presets file." << std::endl << reader.getFormattedErrorMessages() << std::endl;
			return 2;
		}
	}
    close(sock);
	return 0;
}
