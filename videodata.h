#ifndef PROJECT_VIDEODATA_H
#define PROJECT_VIDEODATA_H

#include <iostream>

class VideoData {
private:

    std::string title;
    std::string category;
    int duration;
    int size;

public:
    VideoData();

    VideoData(std::string title, std::string category = "None", int duration = 0, int size = 0);

//Getters
    std::string getTitle();

    std::string getCategory();

    int getDuration();

    int getSize();


    friend std::istream &operator>>(std::istream &in, VideoData &data) {
        std::cout << "Title: ";
        in >> data.title;

        std::cout << "Category: ";
        in >> data.category;

        std::cout << "Duration: ";
        in >> data.duration;

        std::cout << "Size: ";
        in >> data.size;

        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, VideoData &data) {
        return out << "Title: "
                   << data.title << " || Category: "
                   << data.category << " || Duration (min): "
                   << data.duration << " || Size (mb): "
                   << data.size
                   << "\n\n";
    }

};


#endif //PROJECT_VIDEODATA_H
