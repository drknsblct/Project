#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include "vectordata.h"

using namespace std;

class Gui {
public:
    vector<VideoData> data;

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

    void deleteOneOrAll() {
        int choice;
        cout << "0.Exit || 1.Delete Last Video || 2.Delete Index || 3.Delete All\n\n";
        cout << "Enter number: ";
        cin >> choice;
        if (choice == 0) {
            return;
        }
        if (choice == 1) {
            data.pop_back();
            return;
        }
        if (choice == 2) {
            int index;
            cout << "Which index to erase? ";
            cin >> index;
            data.erase(data.begin()+index);
            return;
        }
        if (choice == 3) {
            data.clear();
            return;
        }
        else {
            cout << "Enter a number between 1 - 2 or 0 to exit";
        }
    }

    int totalMinutes(){
        int total = 0;
        for (VideoData &e : data){
            total += e.getDuration();
        }
        return total;
    }

    int totalSize(){
        int total = 0;
        for (VideoData &e : data){
            total += e.getSize();
        }
        return total;
    }

    void showStats(){
        cout << "Videos in the list: " << data.size() << "\n";
        cout << "Total minutes: " << totalMinutes() << "\n";
        cout << "Total size: " << totalSize() << "\n";
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
