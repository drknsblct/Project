#include <iostream>
#include "vectordata.h"
#include "videodata.h"
#include "gui.h"

using namespace std;

int main() {
    vector<VideoData> data;

//na to kaneis na grafei se arxeio
    Gui gui;
    gui.menu();
    ifstream infile;
    infile.open("videos.txt");
    for (int i = 0; i < data.size(); i++){
        infile >> data[i];
    }




    return 0;
}
