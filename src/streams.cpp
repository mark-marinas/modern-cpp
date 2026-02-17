/*
streams converts objects to streams of bytes, and vice versa.
The arrow goes from the direction of the stream to the object, or vice-versa. The stream is always on the left.
fs >> s; from file stream to buffer
fs << s; from s to file stream


1. file streams
    are by default input file streams.
    to make it output file streams (that is, write to a file), use std::ios::out, std::ios::app to append

2. string streams
    use <sstream>
    istringstream for input streams, ostringstream for output streams, stringstreams for both.
    ss << "string" - to insert to a stream.
    ss >> to extract from a string. It stops extracting when it encounters a white space.
        or use getline(ss, buffer, delim)

*/

#include <iostream>
#include <fstream> /*file stream.  ifstream - input file stream, ofstream - output file stream. fstream - input + output*/
#include <sstream>

using namespace std;

int main() {
    fstream fs {"streams.cpp"};
    string buffer;
    while ( getline(fs, buffer)) {
        cout << buffer << endl;
    }

    cout << "======================" << endl;
    fstream fs2 {"streams.cpp"};
    char c;
    while ( fs2 >> noskipws >> c) {
        cout << c;
    }
    cout << endl;

    fstream outfile{ "sample.txt", ios::out };
    outfile << "hello mark" << endl;
    outfile << "hello marla";
    outfile << endl;
    
    //fstream config {"config.ini"};

    stringstream config;
    config << "name = mark marinas" << endl;
    config << "age = 45" << endl;
    config << "sex = male" << endl;

    while ( getline(config, buffer) ) {
        stringstream ss {buffer};
        string key, value , dummy;
        int idx = 0;
        
        /*
        while ( ss >> dummy ) {
            if (idx == 0 ) { key = dummy; }
            else if(idx == 2) { value = dummy; }
            idx++; 
        }
        */
        
        
        while ( getline(ss, dummy, '=') ) {
            if (idx == 0) { key = dummy; }
            else { value = dummy;}
            idx++;
        }
        

        cout << key << ":" << value << endl;
    }




    return 0;
}