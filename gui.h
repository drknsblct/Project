#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include "vectordata.h"
#include <fstream>

using namespace std;

class Gui {
public:
    vector<VideoData> data;
//    ifstream  infile;
//    infile.open(videos.txt);


    void addVideos() {
        int count = 0;
        cout << "Enter the amount of videos you want to add: ";
        cin >> count;


        string title, category;
        int duration, size;

        for (int i = 0; i < count; i++) {
            cout << "\t\t\t\t\t\t\t\tVideo " << i + 1 << "\n";
            cout << "Title: ";
            cin >> title;
            cout << "Category: ";
            cin >> category;
            cout << "Duration (min): ";
            cin >> duration;
            cout << "Size (mb): ";
            cin >> size;
            cout << "\n";

            data.emplace_back(title, category, duration, size);
        }

    }

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

    void searchListOfVideos() {
        //vale while gia na deixnei sunexeia th lista panw
        int choice;
        string keyword;
        while (true) {
            cout << "0.Exit || 1.Search by Title || 2. Search by Category\n\n";
            cout << "Enter number: ";
            cin >> choice;
            if (choice == 0) {
                return;
            }
            if (choice == 1) {
                cout << "Enter keyword: ";
                cin >> keyword;
                for (int i = 0; i < data.size(); i++) {
                    if (data[i].getTitle() == keyword) {
                        cout << data[i] << endl;
                    }
                }

            } else if (choice == 2) {
                cout << "Enter keyword: ";
                cin >> keyword;
                for (int i = 0; i < data.size(); i++) {
                    if (data[i].getCategory() == keyword) {
                        cout << data[i] << endl;
                    }
                }


            }
        }
    }

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

    void showStats() {
        cout << "Videos in the list: " << data.size() << "\n";
        cout << "Total minutes: " << totalMinutes() << "\n";
        cout << "Total size: " << totalSize() << "\n";
        cout << "Average duration: " << averageDuration() << "\n";
        cout << "Average size: " << averageSize() << "\n";
    }


    void menu() {
        while (true) {
            int choice;
            cout << "0.Exit || 1.Add Videos || 2.List Videos || 3.Search || 4.Stats || 5.Delete Video\n\n";
            cout << "Enter number: ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            switch (choice) {
                case 1:
                    cout << "Add Videos: \n";
                    addVideos();
                    break;
                case 2:
                    cout << "List Videos: \n\n\n";
                    listVideos();
                    //Nea grammh h apo katw
                    cout << "\n\n";
                    break;
                case 3:
                    cout << "Search: \n";
                    searchListOfVideos();
                    break;
                case 4:
                    cout << "Stats: \n";
                    showStats();
                    break;
                case 5:
                    cout << "Delete Video: \n";
                    deleteOneOrAll();
                    break;
                default:
                    cout << "Enter a number between 1 - 6\n";
                    break;
            }
        }

    }
};


#endif //PROJECT_GUI_H
