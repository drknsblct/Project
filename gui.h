#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include <fstream>
#include <vector>

class Gui {
public:
    std::vector<VideoData> data;

//writeToFile and readFromFile are both methods used for reading and writing files
    void writeToFile(std::vector<VideoData> data);

    void readFromFile();

//Adds videos to memory and in video.txt file
    void addVideos();

//Lists videos
    void listVideos();

//Searches videos in memory
    void searchListOfVideos();

//Deletes videos based on last entry, index, all
    void deleteOneOrAll();

//totalMinutes, totalSize, averageSize, averageDuration, longestVideo, shortestVideo,
// largestVideo, smallestVideo are all used in the showStats method
    int totalMinutes();

    int totalSize();

    double averageSize();

    double averageDuration();

    int longestVideo();

    int shortestVideo();

    int largestVideo();

    int smallestVideo();

//Shows the stats of all inputed videos
    void showStats();

//Home menu with showcasing different functionalities
    void menu();

//Logo
    void nameTemplate();
};


#endif //PROJECT_GUI_H
