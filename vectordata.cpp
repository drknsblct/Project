#include "vectordata.h"

void VectorVideoData::populate(string filename) {
    ifstream infile;
    VideoData obj;
    infile.open(filename.c_str());

    while (infile) {
        infile >> obj;
        data.push_back(obj);
    }
}

bool VectorVideoData::exists(string title) {
    for (auto & i : data)
        return (i.getTitle() == title);
}

VideoData &VectorVideoData::findByTitle(string title) {
    for (auto & i : data)
        if (i.getTitle() == title)
            return i;
}

VideoData &VectorVideoData::findByCategory(string title) {
    for (auto & i : data)
        if (i.getCategory() == title)
            return i;
}

ostream &operator<<(ostream &out, VectorVideoData &vector) {
    for (auto & i : vector.data)
        out << i << endl;
    return out;
}




