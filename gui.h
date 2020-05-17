#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include <fstream>
#include <vector>

using namespace std;

class Gui {
public:
    vector<VideoData> data;
//writeToFile and readFromFile are both methods used for reading and writing files
    void writeToFile(vector<VideoData> data) {
        ofstream file("videos.txt");
        for (auto &i : data) {
            file << i;
        }
    }

    void readFromFile() {
        ifstream file("videos.txt");
        string line;
        while (file >> line) {
            getline(file, line);
            cout << line << "\n\n";
        }
    }

//Adds videos to memory and in video.txt file
    void addVideos() {
        int count = 0;
        cout << "Enter the amount of videos you want to add: ";
        cin >> count;
        cin.ignore();


        string title, category;
        int duration, size;

        for (int i = 0; i < count; i++) {
            cout << "\nVideo " << i + 1 << "\n";
            cout << "Title: ";
            getline(cin, title);

            cout << "Category: ";
            getline(cin, category);

            cout << "Duration (min): ";
            cin >> duration;

            cout << "Size (mb): ";
            cin >> size;
            cin.ignore();
            cout << "\n";

            data.emplace_back(title, category, duration, size);
            writeToFile(data);
        }

    }
//Lists videos
    void listVideos() {
        for (VideoData &e : data) {
            cout << "Title: "
                 << e.getTitle() << " || Category: "
                 << e.getCategory() << " || Duration (min): "
                 << e.getDuration() << " || Size (mb): "
                 << e.getSize()
                 << "\n\n";
        }
    }
//Searches videos in memory
    void searchListOfVideos() {
        int choice;
        string keyword;
        while (true) {
            cout << "0.Exit || 1.Search by Title || 2. Search by Category || 3. Search by Index\n\n";
            cout << "Enter number: ";
            cin >> choice;
            cin.ignore();
            if (choice == 0) {
                return;
            }
            if (choice == 1) {
                cout << "Enter keyword: ";
                getline(cin, keyword);
                for (auto &i : data) {
                    if (i.getTitle() == keyword) {
                        cout << "\n" << i << endl;
                    }
                }

            } else if (choice == 2) {
                cout << "Enter keyword: ";
                getline(cin, keyword);
                for (auto &i : data) {
                    if (i.getCategory() == keyword) {
                        cout << "\n" << i << endl;
                    }
                }
            } else if (choice == 3) {
                int index;
                cout << "Find by which index? ";
                cin >> index;
                cin.ignore();
                if (index == data.size() || index > data.size()) {
                    cout << "\n" << "There's no such index\n\n";
                    return;
                }
                cout << "\n" << data[index] << endl;

            }
        }
    }
//Deletes videos based on last entry, index, all
    void deleteOneOrAll() { //dokimase na vgaleis ta return apo to 1 kai meta
        int choice;
        cout << "0.Exit || 1.Delete Last Video || 2.Delete Index || 3.Delete All\n\n";
        cout << "Enter number: ";
        cin >> choice;
        if (choice == 0) {
            return;
        }
        if (choice == 1) {
            data.pop_back();
            cout << "Deleted last video\n";
            return;
        }
        if (choice == 2) {
            int index;
            cout << "Which index to erase? ";
            cin >> index;
            data.erase(data.begin() + index);
            cout << "Deleted index[" << index << "]\n";
            //den 3erw an einai xrhsimo to return
            return;
        }
        if (choice == 3) {
            data.clear();
            return;
        } else {
            cout << "Enter a number between 1 - 2 or 0 to exit";
        }
    }
//totalMinutes, totalSize, averageSize, averageDuration, longestVideo, shortestVideo,
// largestVideo, smallestVideo are all used in the showStats method
    int totalMinutes() {
        int total = 0;
        for (VideoData &e : data) {
            total += e.getDuration();
        }
        return total;
    }

    int totalSize() {
        int total = 0;
        for (VideoData &e : data) {
            total += e.getSize();
        }
        return total;
    }

    double averageSize() {
        double avg = 0;
        for (VideoData &e : data) {
            avg = (double) totalSize() / data.size();
        }
        return avg;

    }

    double averageDuration() {
        double avg = 0;
        for (VideoData &e : data) {
            avg = (double) totalMinutes() / data.size();
        }
        return avg;
    }

    int longestVideo() {
        int longest = data[0].getDuration();
        for (int i = 1; i < data.size(); i++) {
            if (data[i].getDuration() > longest) {
                longest = data[i].getDuration();
            }
        }
        return longest;
    }

    int shortestVideo() {
        int shortest = data[0].getDuration();
        for (int i = 1; i < data.size(); i++) {
            if (data[i].getDuration() < shortest) {
                shortest = data[i].getDuration();
            }
        }
        return shortest;
    }

    int largestVideo() {
        int largest = data[0].getSize();
        for (int i = 1; i < data.size(); i++) {
            if (data[i].getSize() > largest) {
                largest = data[i].getSize();
            }
        }
        return largest;
    }

    int smallestVideo() {
        int smallest = data[0].getSize();
        for (int i = 1; i < data.size(); i++) {
            if (data[i].getSize() < smallest) {
                smallest = data[i].getSize();
            }
        }
        return smallest;
    }

//Shows the stats of all inputed videos
    void showStats() {
        cout << "Videos in the list: " << data.size() << "\n";
        cout << "Total minutes: " << totalMinutes() << "\n";
        cout << "Total size: " << totalSize() << "\n\n";
        cout << "Average duration: " << averageDuration() << "\n";
        cout << "Average size: " << averageSize() << "\n\n";

        cout << "Longest video duration: " << longestVideo() << "\n";
        cout << "Shortest video duration: " << shortestVideo() << "\n\n";
        cout << "Largest video size: " << largestVideo() << "\n";
        cout << "Smallest video size: " << smallestVideo() << "\n\n";
    }

//Home menu with showcasing different functionalities
    void menu() {
        while (true) {
            int choice;
            cout
                    << "0.Exit || 1.Add Videos || 2.List Videos || 3.Search || 4.Stats || 5.Delete Video || 6.Read from File\n\n";
            cout << "Enter number: ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Add Videos: \n\n";
                    addVideos();
                    break;
                case 2:
                    cout << "List Videos: \n\n";
                    listVideos();
                    cout << "\n\n";
                    break;
                case 3:
                    cout << "Search: \n\n";
                    searchListOfVideos();
                    break;
                case 4:
                    cout << "Stats: \n\n";
                    showStats();
                    break;
                case 5:
                    cout << "Delete Video: \n\n";
                    deleteOneOrAll();
                    break;
                case 6:
                    cout << "Read from File: \n\n";
                    readFromFile();
                    break;
                default:
                    cout << "Enter a number between 1 - 6\n\n";
                    break;
            }
        }

    }
//Logo
    void nameTemplate() {
        string name = R"(




 /$$$$$$$            /$$                           /$$       /$$             /$$
| $$__  $$          | $$                          | $$      | $$            | $$
| $$  \ $$  /$$$$$$ | $$   /$$ /$$$$$$$   /$$$$$$$| $$$$$$$ | $$  /$$$$$$$ /$$$$$$
| $$  | $$ /$$__  $$| $$  /$$/| $$__  $$ /$$_____/| $$__  $$| $$ /$$_____/|_  $$_/
| $$  | $$| $$  \__/| $$$$$$/ | $$  \ $$|  $$$$$$ | $$  \ $$| $$| $$        | $$
| $$  | $$| $$      | $$_  $$ | $$  | $$ \____  $$| $$  | $$| $$| $$        | $$ /$$
| $$$$$$$/| $$      | $$ \  $$| $$  | $$ /$$$$$$$/| $$$$$$$/| $$|  $$$$$$$  |  $$$$/
|_______/ |__/      |__/  \__/|__/  |__/|_______/ |_______/ |__/ \_______/   \___/



        )";

        cout << name << endl;

    }
};


#endif //PROJECT_GUI_H
