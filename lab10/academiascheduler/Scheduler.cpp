//
// Created by Kuba on 18.05.2017.
//

#include <map>
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


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        //check if its possible
        int course_id_check=0;
        int wantedLectures=0;
        for(auto &c : courses_of_year)
        {
            for(auto &d : c.second)
            {
                course_id_check=d;
                for(auto &f : teacher_courses_assignment)
                {
                    for(auto &g : f.second)
                    {
                        if(g==course_id_check) wantedLectures++;
                    }
                }
                if(wantedLectures>n_time_slots) throw NoViableSolutionFound("No solution found");
                wantedLectures=0;
            }
        }
        
        
        
        //
        
        Schedule schedule;
        std::vector<int> rooms_act = rooms;
        int teacher_id=0;
        int course_id=0;
        int year_id=0;
        int room_id=0;
        int n=1;
        bool room_full=false;

        for(auto const &teacher : teacher_courses_assignment)
        {
            teacher_id=teacher.first;
            for(auto const &item : teacher.second)
            {
                course_id=item;
                for(auto const &year : courses_of_year)
                {
                    if(year.second.find(course_id)!=year.second.end())
                    {
                        year_id=year.first;
                        break;
                    }
                }
                for(auto &room : rooms_act)
                {
                    if(n<=n_time_slots)
                    {
                        room_id=room;
                        break;
                    } else if(rooms_act.size()>1){
                        room_full=true;
                        n=1;
                    }
                    else throw NoViableSolutionFound("No solution found");
                }
                if(room_full) rooms_act.erase(rooms_act.begin());
                room_full=false;
                if(n>n_time_slots or rooms_act.size()==0) throw NoViableSolutionFound("No solution found");
                SchedulingItem tmp(course_id,teacher_id,room_id,n,year_id);
                n++;
                year_id=0;
                room_id=0;

                schedule.InsertScheduleItem(tmp);
            }
        }
        teacher_id=0;
        return schedule;
    }

    void SchedulingItem::setCourseid(int course_id) {
        course_id_=course_id;
    }

    void SchedulingItem::setTeacherId(int teacher_id) {
        teacher_id_=teacher_id;
    }

    void SchedulingItem::setRoomId(int room_id) {
        room_id_=room_id;
    }

    void SchedulingItem::setTimeSlot(int time_slot) {
        time_slot_=time_slot;
    }

    void SchedulingItem::setYear(int year) {
        year_=year;
    }
}

