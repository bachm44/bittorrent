#include "utils.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string utils::readFile(const string& fileName)
{
    ifstream t(fileName);
    if (t.fail())
    {
        throw runtime_error("Could not find file: " + fileName);
    }

    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void utils::saveFile(const string& content, const string& fileName)
{
    ofstream file;
    file.open(fileName);
    file << content;
    if (file.fail())
    {
        throw runtime_error("Could not save file: " + fileName);
    }

    file.close();
}