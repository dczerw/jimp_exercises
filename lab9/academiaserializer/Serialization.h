//
// Created by Kuba on 09.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <experimental/optional>

namespace academia
{

    static bool is_end=false;

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

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(std::ostream *out) : Serializer(out) {};
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(std::ostream *out) : Serializer(out) {};
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class Serializable
    {
    public:
        virtual void Serialize(Serializer *serializer) const {};
    };

    class Room : public Serializable
    {
    public:
        enum Type
        {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id, std::string name, Type type);
        virtual void Serialize(Serializer *serializer) const override;
        std::string EnumToString(Type type) const;

    private:
        int id_;
        std::string name_;
        Type type_;

    };

    class Building : public Serializable
    {
    public:
        Building(int id, std::string name, std::vector<Room> rooms);
        virtual void Serialize(Serializer *serializer) const override;
        int Id();
    private:
        std::string name_;
        int id_;
        std::vector<Room> rooms_;

    };

    class BuildingRepository
    {
    public:
        void StoreAll(Serializer *serializer) const{}
        void Add(Serializable){}
        BuildingRepository(const std::initializer_list<Building> &building);
        std::experimental::optional<Building> operator[](int index) const;
    private:
        std::vector<Building> buildings_;

    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
