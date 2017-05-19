//
// Created by Kuba on 18.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstdio>
#include <set>

namespace academia
{
    class SchedulingItem
    {
    public:
        SchedulingItem();
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
        void setCourseid(int course_id);
        void setTeacherId(int teacher_id);
        void setRoomId(int room_id);
        void setTimeSlot(int time_slot);
        void setYear(int year);

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule
    {
    private:
        std::vector<SchedulingItem> items_;
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int index) const;
    };

    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
        const std::map<int, std::set<int>> &courses_of_year, int n_time_slots){};
    };

    class GreedyScheduler : public Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };

    class NoViableSolutionFound : public std::runtime_error
    {
    public:
        NoViableSolutionFound(std::string msg) : std::runtime_error(msg){};
        virtual ~NoViableSolutionFound(){};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
