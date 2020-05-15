#include "videodata.h"

using namespace std;

VideoData::VideoData(){}

VideoData::VideoData(string title, string category, int duration, int size) {
    this->title = title;
    this->category = category;
    this->duration = duration;
    this-> size = size;
}

string VideoData::get_title() {
    return this->title;
}

string VideoData::get_category() {
    return this->category;
}

int VideoData::get_duration() {
    return this->duration;
}

int VideoData::get_size() {
    return this->size;
}
