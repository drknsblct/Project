#ifndef PROJECT_VIDEODATA_H
#define PROJECT_VIDEODATA_H

#include <iostream>

using namespace std;

class VideoData {
private:

    string title;
    string category;
    int duration;
    int size;

public:
    VideoData();

    VideoData(string title, string category = "None", int duration = 0, int size = 0);

//Getters
    string getTitle();

    string getCategory();

    int getDuration();

    int getSize();


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
                   << data.category << " || Duration (min): "
                   << data.duration << " || Size (mb): "
                   << data.size
                   << "\n\n";
    }

};


#endif //PROJECT_VIDEODATA_H
