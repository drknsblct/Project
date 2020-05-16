#ifndef PROJECT_VECTORDATA_H
#define PROJECT_VECTORDATA_H

#include <iostream>
#include <fstream>
#include <vector>

#include "videodata.h"

using namespace std;

class VectorVideos {

public:
    vector<VideoData> data;

    void populate(string filename);

    bool exists(string title);

    VideoData &findByTitle(string title);

    VideoData &findByCategory(string title);

    friend ostream &operator<<(ostream &out, VectorVideos &vector);
};


#endif //PROJECT_VECTORDATA_H
