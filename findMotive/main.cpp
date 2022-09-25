#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string word;
    int occurence = 0;
    fstream file;
    //Donner le chemin relatif
    
    
    file.open(argv[1], ios::in);

    if(!file.is_open()){
        cout << "The file " << argv[1] << " could not be opened";
        return 1;
    }


    while(file >> word){
        if(word.find(argv[2]) != string::npos)
            occurence++;
    }

    cout << "The file " << argv[1] << " contains " << occurence << " words containing the motive " << argv[2] <<"\n";

    return 0;
}