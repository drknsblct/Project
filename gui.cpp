#include <iostream>
#include "videodata.h"
#include "gui.h"
#include <vector>

using namespace std;


//writeToFile and readFromFile are both methods used for reading and writing files
void Gui::writeToFile(vector<VideoData> data) {
    ofstream file("videos.txt");
    for (auto &i : data) {
        file << i;
    }
}

void Gui::readFromFile() {
    ifstream file("videos.txt");
    string line;
    while (file >> line) {
        getline(file, line);
        cout << line << "\n\n";
    }
}

//Adds videos to memory and in video.txt file
void Gui::addVideos() {
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
void Gui::listVideos() {
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
void Gui::searchListOfVideos() {
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
                    cout << "\n" << i << "\n";
                }
            }

        } else if (choice == 2) {
            cout << "Enter keyword: ";
            getline(cin, keyword);
            for (auto &i : data) {
                if (i.getCategory() == keyword) {
                    cout << i << "\n";
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
            cout << "\n" << data[index] << "\n";

        }
    }
}

//Deletes videos based on last entry, index, all
void Gui::deleteOneOrAll() {
    int choice;
    cout << "0.Exit || 1.Delete Last Video || 2.Delete Index || 3.Delete All\n\n";
    cout << "Enter number: ";
    cin >> choice;
    if (choice == 0) {
        return;
    }
    if (choice == 1) {
        data.pop_back();
        cout << "Deleted last video\n\n";

    } else if (choice == 2) {
        int index;
        cout << "Which index to erase? ";
        cin >> index;
        if (index == data.size() || index > data.size()) {
            cout << "There's no such index\n\n";
        }
        data.erase(data.begin() + index);
        cout << "Deleted index[" << index << "]\n\n";

    } else if (choice == 3) {
        data.clear();
        cout << "Deleted all videos\n\n";
        return;
    } else {
        cout << "Enter a number between 1 - 2 or 0 to exit\n\n";
    }
}

//totalMinutes, totalSize, averageSize, averageDuration, longestVideo, shortestVideo,
// largestVideo, smallestVideo are all used in the showStats method
int Gui::totalMinutes() {
    int total = 0;
    for (VideoData &e : data) {
        total += e.getDuration();
    }
    return total;
}

int Gui::totalSize() {
    int total = 0;
    for (VideoData &e : data) {
        total += e.getSize();
    }
    return total;
}

double Gui::averageSize() {
    double avg = 0;
    for (VideoData &e : data) {
        avg = (double) totalSize() / data.size();
    }
    return avg;

}

double Gui::averageDuration() {
    double avg = 0;
    for (VideoData &e : data) {
        avg = (double) totalMinutes() / data.size();
    }
    return avg;
}

int Gui::longestVideo() {
    int longest = data[0].getDuration();
    for (int i = 1; i < data.size(); i++) {
        if (data[i].getDuration() > longest) {
            longest = data[i].getDuration();
        }
    }
    return longest;
}

int Gui::shortestVideo() {
    int shortest = data[0].getDuration();
    for (int i = 1; i < data.size(); i++) {
        if (data[i].getDuration() < shortest) {
            shortest = data[i].getDuration();
        }
    }
    return shortest;
}

int Gui::largestVideo() {
    int largest = data[0].getSize();
    for (int i = 1; i < data.size(); i++) {
        if (data[i].getSize() > largest) {
            largest = data[i].getSize();
        }
    }
    return largest;
}

int Gui::smallestVideo() {
    int smallest = data[0].getSize();
    for (int i = 1; i < data.size(); i++) {
        if (data[i].getSize() < smallest) {
            smallest = data[i].getSize();
        }
    }
    return smallest;
}

//Shows the stats of all inputed videos
void Gui::showStats() {
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
void Gui::menu() {
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
                cout << "\n";
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
void Gui::nameTemplate() {
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

    cout << name << "\n";


}



