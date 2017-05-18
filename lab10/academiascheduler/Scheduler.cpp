//
// Created by Kuba on 18.05.2017.
//

#include "Scheduler.h"

namespace academia
{
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) {
        course_id_=course_id;
        teacher_id_=teacher_id;
        room_id_=room_id;
        time_slot_=time_slot;
        year_=year;
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
            Schedule schedule;
            for(const auto &c : items_)
            {
                if(c.TeacherId()==teacher_id) schedule.items_.emplace_back(c);
            }
            return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
            Schedule schedule;
            for(const auto &c : items_)
            {
                    if(c.RoomId()==room_id) schedule.items_.emplace_back(c);
            }
            return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
            Schedule schedule;
            for(const auto &c : items_)
            {
                    if(c.Year()==year) schedule.items_.emplace_back(c);
            }
            return schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
            std::vector<int> slots;
            for(int i=1;i<=n_time_slots;i++)
            {
                    bool is_free = true;
                    for(const auto &c : items_)
                    {
                            if(c.TimeSlot()==i) {
                                    is_free = false;
                                    break;
                            }
                    }
                    if(is_free) slots.emplace_back(i);
            }
            return slots;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
            items_.emplace_back(item);
    }

    size_t Schedule::Size() const {
            return items_.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
            return items_[index];
    }

    int SchedulingItem::CourseId() const{
            return course_id_;
    }

    int SchedulingItem::TeacherId() const{
            return teacher_id_;
    }

    int SchedulingItem::RoomId() const{
            return room_id_;
    }

    int SchedulingItem::TimeSlot() const{
            return time_slot_;
    }

    int SchedulingItem::Year() const{
            return year_;
    }

    SchedulingItem::SchedulingItem() {
            course_id_=0;
            teacher_id_=0;
            room_id_=0;
            time_slot_=0;
            year_=0;
    }

}

