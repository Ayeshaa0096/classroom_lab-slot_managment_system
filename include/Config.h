/*
 * File: Config.h
 * Author: Samarth kant (Team Lead - Part 1)
 * University Roll No: 2519490 | Student ID: 25101210534
 * Description: Timetable parameters, time lookup arrays, and Purpose enum.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

constexpr int DAYS = 6;       // Monday to Saturday
constexpr int PERIODS = 10;   // 10 periods per day

// Day names (1-indexed)
static const char *DAY_NAME[DAYS + 1] = {
    "", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

// Period Start Times (1-indexed)
static const char *PERIOD_START_TIME[PERIODS + 1] = {
    "", "08:00", "08:55", "10:10", "11:05", "12:00",
    "12:55", "14:10", "15:05", "16:00", "16:55"
};

// Period End Times (1-indexed)
static const char *PERIOD_END_TIME[PERIODS + 1] = {
    "", "08:55", "09:50", "11:05", "12:00", "12:55",
    "13:50", "15:05", "16:00", "16:55", "17:50"
};

enum class Purpose {
    Lecture = 1,
    Tutorial = 2,
    Practical = 3,
    Project = 4
};

inline const char *purposeName(Purpose p) {
    static const char *names[] = {"", "Lecture", "Tutorial", "Practical", "Project"};
    int idx = static_cast<int>(p);
    if (idx >= 1 && idx <= 4) return names[idx];
    return "Unknown";
}

inline Purpose parsePurpose(const std::string &str) {
    if (str == "Lab" || str == "Practical" || str == "3") return Purpose::Practical;
    if (str == "Tutorial" || str == "2") return Purpose::Tutorial;
    if (str == "Project" || str == "4") return Purpose::Project;
    return Purpose::Lecture;
}

#endif // CONFIG_H
