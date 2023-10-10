#include "dconc.hpp"
#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json dconc::dconcHandler::readAllDnode()
{
    cpr::Response r = cpr::Get(cpr::Url{this->_ip + "/getall/bucket"});
    json parsedJson = json::parse(r.text);
    return parsedJson;
};

json dconc::dconcHandler::writeDnode(std::string uid, std::string value)
{
    json jsonPayload;
    jsonPayload["node_uid"] = uid;
    jsonPayload["node_val"] = value;

    cpr::Response r = cpr::Post(
        cpr::Url{this->_ip + "/w"},
        cpr::Body{
            jsonPayload.dump()},
        cpr::Header{{"Content-Type", "application/json"}});

    std::cout << r.text << '\n';
    json parsedJson = json::parse(r.text);
    return parsedJson;
};

json dconc::dconcHandler::readDnode(std::string uid)
{
    cpr::Response r = cpr::Get(cpr::Url{this->_ip + "/r/" + uid});
    json parsedJson = json::parse(r.text);
    return parsedJson;
};