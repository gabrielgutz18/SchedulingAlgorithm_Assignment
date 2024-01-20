#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Meeting {
    std::string title;
    std::string date;
    std::string time;
};

struct Room {
    std::string name;
    bool available;
};

bool compareMeetings(const Meeting &a, const Meeting &b) {
    // Compare meetings based on their date and time
    return a.date + a.time < b.date + b.time;
}

bool allocateRoom(std::vector<Room> &rooms, const Meeting &meeting, std::string &allocatedRoom) {
    // Find the first available room
    auto it = std::find_if(rooms.begin(), rooms.end(), [](const Room &room) { return room.available; });

    if (it != rooms.end()) {
        it->available = false;
        allocatedRoom = it->name;
        return true;
    }

    return false;
}

void scheduleMeetings(std::vector<Meeting> &meetings, std::vector<Room> &rooms) {
    // Sort meetings based on date and time
    std::sort(meetings.begin(), meetings.end(), compareMeetings);

    for (const auto &meeting : meetings) {
        std::string allocatedRoom;
        if (allocateRoom(rooms, meeting, allocatedRoom)) {
            std::cout << "Meeting scheduled - Title: " << meeting.title
                      << ", Date: " << meeting.date
                      << ", Time: " << meeting.time
                      << ", Room: " << allocatedRoom
                      << std::endl;
        } else {
            std::cout << "No available room for meeting - Title: " << meeting.title
                      << ", Date: " << meeting.date
                      << ", Time: " << meeting.time
                      << std::endl;
        }
    }
}

int main() {
    std::vector<Meeting> meetings = {
        {"Film Production", "2024-01-21", "10:00 AM"},
        {"Team Programming Meeting", "2024-01-22", "02:30 PM"},
        {"Game Time/Me time", "2024-01-25", "01:00 PM"}
    };

    std::vector<Room> rooms = {
        {"Room A", true},
        {"Room B", true},
        {"Room C", true}
    };

    scheduleMeetings(meetings, rooms);

    return 0;
}
