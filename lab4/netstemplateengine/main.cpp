//
// Created by dawid on 27.03.17.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <map>





int main()
{

    std::unordered_map<std::string, std::string> map = {{"name", "Xavier"}};
    nets::View view{"Hello {{name}}!"};
    std::cout<<view.Render(map);

    return 0;
}
