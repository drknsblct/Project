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
    for (int i = 0; i < data.size(); i++)
        if (data[i].get_title() == title)
            return true;
    return false;
}

VideoData &VectorVideoData::findByTitle(string title) {
    for (int i = 0; i < data.size(); i++)
        if (data[i].get_title() == title)
            return data[i];
}

VideoData &VectorVideoData::findByCategory(string title) {
    for (int i = 0; i < data.size(); i++)
        if (data[i].get_category() == title)
            return data[i];
}

ostream &operator<<(ostream &out, VectorVideoData &vector) {
    for (int i = 0; i < vector.data.size(); i++)
        out << vector.data[i] << endl;
    return out;
}




