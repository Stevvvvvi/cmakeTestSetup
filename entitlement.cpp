#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <iostream>
#include <vector>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;


const std::string criteriaSimpleMaxChannelsString(
    "{\
        \"label\": \"Audinate Remote Monitor\",\
        \"criteria\":[\
        {\
            \"manfId\":\"417564696e617465\",\
            \"modelId\":\"444f445f52454d4f\",\
            \"minRxChannels\":0,\
            \"maxRxChannels\":64,\
            \"minTxChannels\":0,\
            \"maxTxChannels\":64\
        }\
        ],\
        \"limit\":1\
    }");
const std::string resultSimpleMaxChannelsString(
    "{\
        \"label\" : \"Audinate Remote Monitor\",\
        \"manfId\":\"417564696e617465\",\
        \"modelId\":\"444f445f52454d4f\",\
        \"limit\":1,\
        \"maxRxChannels\":64,\
        \"maxTxChannels\":64\
    }");

const std::string criteriaComplexOrString(
    "{\
        \"label\" : \"Audinate Dante Virtual Soundcard (256 Channels)\",\
        \"criteria\":[\
            {\
                \"manfId\":\"417564696e617465\",\
                \"modelId\":\"444f445f44565300\"\
            },\
            {\
                \"$or\":[\
                    {\
                        \"minRxChannels\":65,\
                        \"maxRxChannels\":256\
                    },\
                    {\
                        \"minTxChannels\":65,\
                        \"maxTxChannels\":256\
                    }\
                ]\
            }\
        ],\
        \"limit\":1\
    }");
const std::string resultComplexOrString(
    "{\
        \"label\" : \"Audinate Dante Virtual Soundcard (256 Channels)\",\
        \"manfId\":\"417564696e617465\",\
        \"modelId\":\"444f445f44565300\",\
        \"limit\":1,\
        \"maxRxChannels\":256,\
        \"maxTxChannels\":256\
    }");


const std::string mutltiModelInSingleEntitlement(
    "{\
        \"label\" : \"DVS 64x64 -Support\",\
        \"matchCriteria\":[\
            {\
                \"label\":\"OEM A DVS 64x64\",\
                \"manfId\":\"417564696e617411\",\
                \"modelId\":\"445653574b363411\"\
            },\
            {\
                \"label\":\"OEM B DVS 64x64\",\
                \"manfId\":\"417564696e617412\",\
                \"modelId\":\"445653574b363412\"\
            },\
            {\
                \"label\":\"OEM A DVS 64x64\",\
                \"manfId\":\"417564696e617411\",\
                \"modelId\":\"445653574b363413\"\
            },\
            {\
                \"label\":\"Audinate Dante Virtual Soundcard for Dante Connect (64 Channels)\",\
                \"manfId\":\"417564696e617465\",\
                \"modelId\":\"445653574b363400\"\
            }\
        ],\
        \"limit\":1000\
    }");


void extractDeviceEntitlements(Json::Value entitlement, Json::Value& deviceEntitlementsObject)
{
	if (entitlement.isObject())
	{
		if (entitlement.isMember("label"))
		{
			deviceEntitlementsObject["label"] = entitlement["label"];
		}
		if (entitlement.isMember("limit"))
		{
			deviceEntitlementsObject["limit"] = entitlement["limit"];
		}
		if (entitlement.isMember("manfId"))
		{
			deviceEntitlementsObject["manfId"] = entitlement["manfId"];
		}
		if (entitlement.isMember("modelId"))
		{
			deviceEntitlementsObject["modelId"] = entitlement["modelId"];
		}
		if (entitlement.isMember("maxRxChannels"))
		{
			deviceEntitlementsObject["maxRxChannels"] = entitlement["maxRxChannels"];
		}
		if (entitlement.isMember("maxTxChannels"))
		{
			deviceEntitlementsObject["maxTxChannels"] = entitlement["maxTxChannels"];
		}
        if (entitlement.isMember("criteria") && entitlement["criteria"].isArray())
        {
           deviceEntitlementsObject["matchCriteria"] = Json::Value(Json::arrayValue);
           for (Json::Value::ArrayIndex i = 0; i < entitlement["criteria"].size(); i++) {
                Json::Value deviceCriteria;
                extractDeviceEntitlements(entitlement["criteria"][i], deviceCriteria);
                if (!deviceCriteria.isObject()){
                    continue;
                }
                deviceEntitlementsObject["matchCriteria"].append(deviceCriteria);
           }
           
        }
        if (entitlement.isMember("matchCriteria") && entitlement["matchCriteria"].isArray())
        {
            deviceEntitlementsObject["matchCriteria"] = Json::Value(Json::arrayValue);
            for (Json::Value::ArrayIndex i = 0; i < entitlement["matchCriteria"].size(); i++) {
                Json::Value deviceCriteria;
                extractDeviceEntitlements(entitlement["matchCriteria"][i], deviceCriteria);
                if (!deviceCriteria.isObject()){
                    continue;
                }
                deviceEntitlementsObject["matchCriteria"].append(deviceCriteria);
            }
        }
	}
}

int main() 
{
    // Json::Value criteria;
    // Json::Value expectedResult;
    // Json::Value simpleMax;
    
    // std::stringstream(mutltiModelInSingleEntitlement) >> criteria;
    // std::stringstream(criteriaComplexOrString) >> expectedResult;
    // std::stringstream(criteriaSimpleMaxChannelsString) >> simpleMax;
	// Json::Value deviceEntitlementsObject;
    // Json::Value deviceEntitlementsObjectComplex;
    // Json::Value deviceEntitlementsObjectSimpleMax;
    
	// extractDeviceEntitlements(criteria, deviceEntitlementsObject);
    // extractDeviceEntitlements(simpleMax, deviceEntitlementsObjectSimpleMax);
    // extractDeviceEntitlements(expectedResult, deviceEntitlementsObjectComplex);
    // std::cout << "deviceEntitlementsObject.toStyledString()" << std::endl;
    // std::cout << deviceEntitlementsObject.toStyledString() << std::endl;
    // std::cout << "deviceEntitlementsObjectSimpleMax.toStyledString()" << std::endl;
    // std::cout << deviceEntitlementsObjectSimpleMax.toStyledString() << std::endl;
    // std::cout << "deviceEntitlementsObjectComplex.toStyledString()" << std::endl;
    // std::cout << deviceEntitlementsObjectComplex.toStyledString() << std::endl;

    mongocxx::instance instance{}; // This should be done only once.
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    auto db = client["meteor"];
    auto collection = db["deviceEntitlements"];
    auto insert_one_result = collection.insert_one(make_document(kvp("i", 0)));
    assert(insert_one_result);
    auto doc_id = insert_one_result->inserted_id();
    assert(doc_id.type() == bsoncxx::type::k_oid);
    auto cursor_all = collection.find({});
    std::cout << "collection " << collection.name() << " contains these documents:" << std::endl;
    for (auto doc : cursor_all) {
        std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}