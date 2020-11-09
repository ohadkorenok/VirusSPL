#include <iostream>
#include <fstream>
//#include "include/Session.h"
#include "include/json.hpp"

using namespace std;
using json = nlohmann::json;
json j;


class Session;

std::string get_name_from_json(json &json_object){
    std::string name ;
    // verify that "info" attribute exists in j
    if (j.find("info") != j.end()) {
        json info = j["info"];

        // verify that "name" attribute exists in info
        if (info.find("name") != info.end()) {
            cout << info["name"] << endl;;
            name = info["name"];
        }

    }
    return name;
}

int main(int argc, char **argv) {
    std::ifstream ifs("json_file/config.json");
    if (!ifs.is_open()) {
        cout << "json is not opened! " << endl;
    }

    ifs >> j;
    ifs.close();
    cout << get_name_from_json(j) <<endl;

    if (argc != 2) {
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }
    Session sess(argv[1]);
    sess.simulate();
    return 0;
}

