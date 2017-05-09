//
// Created by Kuba on 09.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>

namespace academia
{


   class Serializable;

    class Serializer
    {
    public:
        std::ostream *out_;
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value){};
        virtual void DoubleField(const std::string &field_name, double value){};
        virtual void StringField(const std::string &field_name, const std::string &value){};
        virtual void BooleanField(const std::string &field_name, bool value){};
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value){}
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value){};
        virtual void Header(const std::string &object_name){};
        virtual void Footer(const std::string &object_name){};
    };

    class Serializable
    {
    public:
        virtual void Serialize(Serializer *serializer)=0;
    };

    class Room : public Serializable
    {
    public:
        enum Type
        {
            COMPUTER_LAB
        };
        Room(int id, std::string name, Type type);
        virtual void Serialize(Serializer *serializer) override;
        std::string EnumToString(Type type);

    private:
        int id_;
        std::string name_;
        Type type_;

    };

    class Building : public Room
    {
    public:

    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
