#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TimeSlot {
public:
    string day;
    string time;

    TimeSlot(const string& day, const string& time)
        : day(day), time(time) {}

    bool operator==(const TimeSlot& other) const {
        return (day == other.day) && (time == other.time);
    }
};

class Course {
public:
    string courseName;
    string instructor;
    TimeSlot timeSlot;

    Course(const string& name, const string& instructor, const TimeSlot& timeSlot)
        : courseName(name), instructor(instructor), timeSlot(timeSlot) {}

    void display() const {
        cout << "Course: " << courseName << "\nInstructor: " << instructor
             << "\nTime Slot: " << timeSlot.day << " " << timeSlot.time << "\n\n";
    }
};

class ClassSchedule {
private:
    vector<Course> courses;
    unordered_map<string, bool> scheduleMap;  

public:
    bool isTimeSlotAvailable(const TimeSlot& timeSlot) const {
        return scheduleMap.find(timeSlot.day + timeSlot.time) == scheduleMap.end();
    }

    void addCourse(const string& name, const string& instructor, const TimeSlot& timeSlot) {
        if (isTimeSlotAvailable(timeSlot)) {
            courses.emplace_back(name, instructor, timeSlot);
            scheduleMap[timeSlot.day + timeSlot.time] = true;
        } else {
            cout << "Conflict detected! Course not added.\n";
        }
    }

    void displaySchedule() const {
        cout << "Class Schedule:\n";
        for (const auto& course : courses) {
            course.display();
        }
    }
};

int main() {
    ClassSchedule schedule;

    schedule.addCourse("Theories of Rigid Boies", "Prof. Costalles", {"Mon", "10:00 AM - 12:00 PM"});
    schedule.addCourse("Physics 2", "Prof. Donato", {"Wed", "2:00 PM - 4:00 PM"});
    schedule.addCourse("History", "Prof. Teguihanon", {"Fri", "1:00 PM - 3:00 PM"});
  
    schedule.addCourse("Differential Equations", "Prof. Dantes", {"Mon", "10:30 AM - 12:30 PM"});

    schedule.displaySchedule();

    return 0;
}
