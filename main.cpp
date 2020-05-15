#include <iostream>
#include "vectordata.h"
#include "videodata.h"

using namespace std;

int main() {
    vector<VideoData> data;

    VideoData sana;
    VideoData lisa;
    cin >> sana;
    cin >> lisa;

    data.push_back(sana);
    data.push_back(lisa);
    cout << endl << data.size() << endl;
    cout << data[0];








    return 0;
}
