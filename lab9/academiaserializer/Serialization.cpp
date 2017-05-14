//
// Created by Kuba on 09.05.2017.
//

#include "Serialization.h"

namespace academia
{
    Serializer::Serializer(std::ostream *out) {
    out_=out;
    }

    Room::Room(int id, std::string name, Room::Type type) {
        id_=id;
        name_=name;
        type_=type;

    }

    std::string Room::EnumToString(Room::Type type) const {
        switch(type)
        {
            case CLASSROOM:
                return "CLASSROOM";
            case COMPUTER_LAB:
                return "COMPUTER_LAB";
            case LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        is_end=false;
        serializer->IntegerField("id",id_);
        serializer->StringField("name",name_);
        is_end=true;
        serializer->StringField("type",EnumToString(type_));
        serializer->Footer("room");
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        ;
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"<"<<field_name<<">";
        for(const Serializable &c : value)
        {
           c.Serialize(this);
        }
        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"<<object_name<<">";
    }

    Building::Building(int id, std::string name, std::vector<Room> rooms) {
        id_=id;
        name_=name;
        rooms_=rooms;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id",id_);
        is_end=false;
        serializer->StringField("name",name_);
        is_end=false;
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const auto &n : rooms_)
        {
            tmp.emplace_back(std::cref(n));
        }
        serializer->ArrayField("rooms",tmp);
        serializer->Footer("building");
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_<<"\""<<field_name<<"\": "<<value<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        *out_<<"\""<<field_name<<"\": "<<value<<", ";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
        if(!is_end) *out_<<", ";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
        if(!is_end) *out_<<", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        Serializer::SerializableField(field_name, value);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"\""<<field_name<<"\": [";
        int i=1;
        for(const Serializable &c : value)
        {
            c.Serialize(this);
            if(i<value.size()) *out_<<", ";
            i++;
        }
        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

}