#include "videodata.h"

using namespace std;

VideoData::VideoData(){}

VideoData::VideoData(string title, string category, int duration, int size) {
    this->title = title;
    this->category = category;
    this->duration = duration;
    this-> size = size;
}

//Getters
string VideoData::getTitle() {
    return this->title;
}

string VideoData::getCategory() {
    return this->category;
}

int VideoData::getDuration() {
    return this->duration;
}

int VideoData::getSize() {
    return this->size;
}


