#include "vectordata.h"

void VectorVideos::populate(string filename) {
    ifstream infile;
    VideoData obj;
    infile.open(filename.c_str());

    while (infile) {
        infile >> obj;
        data.push_back(obj);
    }
}

bool VectorVideos::exists(string title) {
    for (auto & i : data)
        return (i.getTitle() == title);
}

VideoData &VectorVideos::findByTitle(string title) {
    for (auto & i : data)
        if (i.getTitle() == title)
            return i;
}

VideoData &VectorVideos::findByCategory(string title) {
    for (auto & i : data)
        if (i.getCategory() == title)
            return i;
}

ostream &operator<<(ostream &out, VectorVideos &vector) {
    for (auto & i : vector.data)
        out << i << endl;
    return out;
}




