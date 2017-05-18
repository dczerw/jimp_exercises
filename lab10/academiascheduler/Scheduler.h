//
// Created by Kuba on 18.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstdio>

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
}

#endif //JIMP_EXERCISES_SCHEDULER_H
