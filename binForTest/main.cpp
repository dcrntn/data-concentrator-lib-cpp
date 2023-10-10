#include "../dconc.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

int main()
{
    dconc::dconcHandler dch("http://127.0.0.1:8000");
    std::cout << dch.readAllDnode();

    std::cout << dch.writeDnode("ayH7nFocwL2urRvOQOfQ", "555");
    std::cout << dch.readDnode("ayH7nFocwL2urRvOQOfQ");

    return 0;
}