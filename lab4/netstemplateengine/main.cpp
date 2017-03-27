//
// Created by dawid on 27.03.17.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <map>

int main()
{

    std::unordered_map<std::string, std::string> map = {{"test", "888"}};
    nets::View view{"test 888 of {test} but {{test} or {test}} and {888}"};
    std::cout<<view.Render(map);

    return 0;
}
