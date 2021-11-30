#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/process.hpp>



class Command {
private:
    std::string filename;
    std::string command;
    boost::process::ipstream pipe_stream;
    std::string outputComm;

public :
    Command();

    

    std::string getOutput();

    void execute(std::string in);

    ~Command();
};

#endif //COMMAND_H
