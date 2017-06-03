//
// Created by Kuba on 16.05.2017.
//

#include "Algo.h"

namespace algo
{
    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> w;
        std::transform(m.begin(),m.end(),std::inserter(w,w.begin()),[](const auto &p){return p.first;});
        return w;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> w;
        std::transform(m.begin(),m.end(),std::back_inserter(w),[](const auto &p){return p.second;});
        return w;
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        return std::map<std::string, int>();
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort((*v).begin(),(*v).end());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> w=v;
        std::sort(w.begin(),w.end());
        return w;
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v){

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> result;
        std::transform(v.begin(),v.end(),back_inserter(result),[](double arg){return std::to_string(arg);});
        return result;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {
        if(std::find(v.begin(),v.end(),element)== v.end()) return false;
        else return true;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        if(v.find(key)==v.end()) return false;
        else return true;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> w;
        std::transform(v.begin(),v.end(),std::back_inserter(w),[](const auto &p){return p.second;});
        if(std::find(w.begin(),w.end(),value)==w.end()) return false;
        else return true;
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill((*v).begin(),(*v).end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> v(length);
        InitializeWith(initial_value, &v);
        return v;
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}
