/**
 * @author Ishaan Kumar; 251069961.
 */
#include "Command.h"

using namespace boost::process;
using namespace std;

//Constructor
Command::Command() {
    filename = "/home/pi/Desktop/dial.py";
    command = "python ";
    outputComm = "";
    command += filename;
}


string Command::getOutput() {
    return outputComm;
}
//Execute Method: It takes in an argument in the form of string and runs in through command line and returns the necessary
//outputs
void Command::execute(string command) {


    try {
        child c(command, (std_out) > pipe_stream);

        string line;
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
            outputComm += line;
        c.wait();
    }
    
    catch (const std::exception &e) {
        outputComm = "100";
    }
}
    Command::~Command(){

}



    
