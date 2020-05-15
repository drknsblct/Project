#ifndef PROJECT_GUI_H
#define PROJECT_GUI_H

#include <iostream>
#include "videodata.h"
#include "vectordata.h"

using namespace std;

class Gui {
public:

    vector<VectorVideoData> videos;

    void gui() {
        VectorVideoData data;
        data.populate("data.txt");


        if (data.exists("Epu2345")) {
            cout << data.findByTitle("Epu2345");
        }

        if (data.exists("ccc")) {
            cout << data.findByCategory("ccc");
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
                    cout << "Give a new video\n";
//                    cin >>
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

    void begin(){
        vector<VideoData> data;
        int count = 0;
        cout << "Enter the amount of videos you want to add: ";
        cin >> count;


        string title, category;
        int duration, size;

        for (int i = 0; i < count; i++){
            cout << "\t\t\t\t\tVideo " << i+1 << "\n";
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
        //to e einai unqualified id
        for (VideoData &e : data){
//            cout << "Video: \n";
            cout << "Title: "
                    << e.getTitle() << " || Category: "
                    << e.getCategory() << " || Duration (min): "
                    << e.getDuration() << " || Size (mb): "
                    << e.getSize()
                    << "\n\n";
        }
    }




};






#endif //PROJECT_GUI_H
