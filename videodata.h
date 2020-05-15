#ifndef PROJECT_VIDEODATA_H
#define PROJECT_VIDEODATA_H

#include <iostream>
#include <fstream>

using namespace std;

class VideoData {
private:

    string title;
    string category;
    int duration;
    int size;

public:
    VideoData();

    explicit VideoData(string title, string category = "None", int duration = 0, int size = 0);


    string get_title();

    string get_category();

    int get_duration();

    int get_size();

    friend istream &operator>>(istream &in, VideoData &data) {
        cout << "Title: ";
        in >> data.title;

        cout << "Category: ";
        in >> data.category;

        cout << "Duration: ";
        in >> data.duration;

        cout << "Size: ";
        in >> data.size;

        return in;
    }

    friend ostream &operator<<(ostream &out, VideoData &data) {
        return out << "Title: "
                   << data.title << " || Category: "
                   << data.category << " || Duration: "
                   << data.duration << " || Size: "
                   << data.size
                   << "\n";
    }

};


#endif //PROJECT_VIDEODATA_H
