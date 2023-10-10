#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace dconc
{
    class dconcHandler
    {
    public:
        std::string _ip;
        dconcHandler(std::string ip)
        {
            this->_ip = ip;
        };

        json readAllDnode();
        json writeDnode(std::string uid, std::string value);
        json readDnode(std::string uid);
    };
};