#include <iostream>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;



void PrintHelpMessage();
void PrintVersionMessage();
void PrintAboutMessage();
int ParseArguments(po::variables_map& vm, po::options_description& description);

std::map<std::string, std::string> optionAliases;



int main(int argc, char **argv) {

    po::variables_map vm;
    po::options_description desc("Allowed Options");


    desc.add_options()
            ("name", po::value<std::string>(), "Name to be greeted by");
    desc.add_options()
            ("help,h", "Displays the help message.")
            ("about,A", "Displays an about page.")
            ("special_help,s", "Displays the boost generated help message;")
            ("version,v", "Displays the version information");


    po::store(po::parse_command_line(argc, argv, desc), vm);

    po::notify(vm); //TODO: What does this do

    ParseArguments(vm, desc);
    return 0;
}


int ParseArguments(po::variables_map& vm, po::options_description& description) {
    for (auto const&[key, val] : vm) {
        std::cout << "ParamKey: " << key << std::endl;      //Displays the main name for the parameter if the parameter has multiple
        if (key == "help") {
            PrintHelpMessage();
            return 0;
        } else if (key == "about") {
            PrintAboutMessage();
            return 0;
        } else if (key == "version") {
            PrintVersionMessage();
            return 0;
        }else if (key == "name"){
            std::cout << "Entered name: " << val.as<std::string>() << std::endl;
        } else if (key == "special_help"){
            std::cout << description << std::endl;
        }else {
            std::cout << key << "\n";
            PrintHelpMessage();
            return 1;
        }
    }
    return 0;
}

void PrintHelpMessage() {
    std::string helpMessage{
            u8R"(Program to test "Program_options" Library from boost
    -h, --help:                 Displays this message
    -v, --version:              Displays the version and licence information
    -A, --about                 Displays the about message and acknowledgements
    -s, --special_help          Displays the boost generated help message
    )"};
    std::cout << "\n" << helpMessage << std::endl;
}

void PrintAboutMessage() {
    std::string AboutString{
            u8R"(This program was written by Frederik Hounsvad.
It is only intended as an expiriment in using the program options boost library.
    Libraries used:
        - Boost Program_Options https://www.boost.org/doc/libs/1_75_0/doc/html/program_options.html)"
    };
    std::cout << "\n" << AboutString << std::endl;
}

void PrintVersionMessage(){
    std::string VersionMessage{
        u8R"(You are running version 1.0)"
    };
    std::cout << "\n" << VersionMessage << std::endl;
}