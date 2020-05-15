#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include "vectordata.h"

using namespace std;

class Gui {
public:

    void addVideos() {
        vector<VideoData> data; // kanto global
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
            cout << "Duration: ";
            cin >> duration;
            cout << "Size: ";
            cin >> size;
            cout << "\n";

            data.emplace_back(title, category, duration, size);
        }

        for (VideoData &e : data) {
            cout << "Title: "
                 << e.getTitle() << " || Category: "
                 << e.getCategory() << " || Duration (min): "
                 << e.getDuration() << " || Size (mb): "
                 << e.getSize()
                 << "\n\n";
        }
    }

    void menu() {
        while (true) {
            int choice;
            cout << "1.Add Video || 2.List Videos || 3.Search || 4.Stats || 5.Exit\n\n";
            cout << "Enter number: ";
            cin >> choice;

            if (choice == 0) {
                break;
            }

            switch (choice) {
                case 1:
                    cout << "You chose 1\n";
                    addVideos();
                    break;
                case 2:
                    cout << "You chose 2\n";
                    break;
                case 3:
                    cout << "You chose 3\n";
                    break;
                case 4:
                    cout << "You chose 4\n";
                    break;
                case 5:
                    cout << "You chose 5\n";
                    break;
                default:
                    cout << "Enter a number between 1-6\n";
                    break;
            }
        }

    }


};


#endif //PROJECT_GUI_H
