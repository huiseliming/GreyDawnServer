/**
 *
 *  Products.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Products.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::products_db2;

const std::string Products::Cols::_id = "id";
const std::string Products::Cols::_name = "name";
const std::string Products::Cols::_price = "price";
const std::string Products::Cols::_add_date = "add_date";
const std::string Products::Cols::_image = "image";
const std::string Products::primaryKeyName = "id";
const bool Products::hasPrimaryKey = true;
const std::string Products::tableName = "products";

const std::vector<typename Products::MetaData> Products::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"name","std::string","varchar(200)",200,0,0,0},
{"price","float","float",4,0,0,0},
{"add_date","std::string","varchar(20)",20,0,0,0},
{"image","std::vector<char>","longblob",0,0,0,0}
};
const std::string &Products::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Products::Products(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["price"].isNull())
        {
            price_=std::make_shared<float>(r["price"].as<float>());
        }
        if(!r["add_date"].isNull())
        {
            addDate_=std::make_shared<std::string>(r["add_date"].as<std::string>());
        }
        if(!r["image"].isNull())
        {
            image_=std::make_shared<std::vector<char>>(r["image"].as<std::vector<char>>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 5 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            price_=std::make_shared<float>(r[index].as<float>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            addDate_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            image_=std::make_shared<std::vector<char>>(r[index].as<std::vector<char>>());
        }
    }

}

Products::Products(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            price_=std::make_shared<float>(pJson[pMasqueradingVector[2]].asFloat());
        }
     }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            addDate_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto str = pJson[pMasqueradingVector[4]].asString();
            image_=std::make_shared<std::vector<char>>(drogon::utils::base64DecodeToVector(str));
        }
    }
}

Products::Products(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("price"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["price"].isNull())
        {
            price_=std::make_shared<float>(pJson["price"].asFloat());
        }
     }
    if(pJson.isMember("add_date"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["add_date"].isNull())
        {
            addDate_=std::make_shared<std::string>(pJson["add_date"].asString());
        }
    }
    if(pJson.isMember("image"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["image"].isNull())
        {
            auto str = pJson["image"].asString();
            image_=std::make_shared<std::vector<char>>(drogon::utils::base64DecodeToVector(str));
        }
    }
}

void Products::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            price_=std::make_shared<float>(pJson[pMasqueradingVector[2]].asFloat());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            addDate_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto str = pJson[pMasqueradingVector[4]].asString();
            image_=std::make_shared<std::vector<char>>(drogon::utils::base64DecodeToVector(str));
        }
    }
}
                                                                    
void Products::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("price"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["price"].isNull())
        {
            price_=std::make_shared<float>(pJson["price"].asFloat());
        }
    }
    if(pJson.isMember("add_date"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["add_date"].isNull())
        {
            addDate_=std::make_shared<std::string>(pJson["add_date"].asString());
        }
    }
    if(pJson.isMember("image"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["image"].isNull())
        {
            auto str = pJson["image"].asString();
            image_=std::make_shared<std::vector<char>>(drogon::utils::base64DecodeToVector(str));
        }
    }
}

const int32_t &Products::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Products::getId() const noexcept
{
    return id_;
}
const typename Products::PrimaryKeyType & Products::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Products::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Products::getName() const noexcept
{
    return name_;
}
void Products::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Products::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}


void Products::setNameToNull() noexcept
{
    name_.reset();
    dirtyFlag_[1] = true;
}

const float &Products::getValueOfPrice() const noexcept
{
    const static float defaultValue = float();
    if(price_)
        return *price_;
    return defaultValue;
}
const std::shared_ptr<float> &Products::getPrice() const noexcept
{
    return price_;
}
void Products::setPrice(const float &pPrice) noexcept
{
    price_ = std::make_shared<float>(pPrice);
    dirtyFlag_[2] = true;
}


void Products::setPriceToNull() noexcept
{
    price_.reset();
    dirtyFlag_[2] = true;
}

const std::string &Products::getValueOfAddDate() const noexcept
{
    const static std::string defaultValue = std::string();
    if(addDate_)
        return *addDate_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Products::getAddDate() const noexcept
{
    return addDate_;
}
void Products::setAddDate(const std::string &pAddDate) noexcept
{
    addDate_ = std::make_shared<std::string>(pAddDate);
    dirtyFlag_[3] = true;
}
void Products::setAddDate(std::string &&pAddDate) noexcept
{
    addDate_ = std::make_shared<std::string>(std::move(pAddDate));
    dirtyFlag_[3] = true;
}


void Products::setAddDateToNull() noexcept
{
    addDate_.reset();
    dirtyFlag_[3] = true;
}

const std::vector<char> &Products::getValueOfImage() const noexcept
{
    const static std::vector<char> defaultValue = std::vector<char>();
    if(image_)
        return *image_;
    return defaultValue;
}
std::string Products::getValueOfImageAsString() const noexcept
{
    const static std::string defaultValue = std::string();
    if(image_)
        return std::string(image_->data(),image_->size());
    return defaultValue;
}
const std::shared_ptr<std::vector<char>> &Products::getImage() const noexcept
{
    return image_;
}
void Products::setImage(const std::vector<char> &pImage) noexcept
{
    image_ = std::make_shared<std::vector<char>>(pImage);
    dirtyFlag_[4] = true;
}

void Products::setImage(const std::string &pImage) noexcept
{
    image_ = std::make_shared<std::vector<char>>(pImage.c_str(),pImage.c_str()+pImage.length());
    dirtyFlag_[4] = true;
}

void Products::setImageToNull() noexcept
{
    image_.reset();
    dirtyFlag_[4] = true;
}

void Products::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Products::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "name",
        "price",
        "add_date",
        "image"
    };
    return inCols;
}

void Products::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPrice())
        {
            binder << getValueOfPrice();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getAddDate())
        {
            binder << getValueOfAddDate();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getImage())
        {
            binder << getValueOfImage();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Products::updateColumns() const
{
    std::vector<std::string> ret;
    for(size_t i=0;i<sizeof(dirtyFlag_);i++)
    {
        if(dirtyFlag_[i])
        {
            ret.push_back(getColumnName(i));
        }
    }
    return ret;
}

void Products::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPrice())
        {
            binder << getValueOfPrice();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getAddDate())
        {
            binder << getValueOfAddDate();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getImage())
        {
            binder << getValueOfImage();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Products::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getPrice())
    {
        ret["price"]=getValueOfPrice();
    }
    else
    {
        ret["price"]=Json::Value();
    }
    if(getAddDate())
    {
        ret["add_date"]=getValueOfAddDate();
    }
    else
    {
        ret["add_date"]=Json::Value();
    }
    if(getImage())
    {
        ret["image"]=drogon::utils::base64Encode((const unsigned char *)getImage()->data(),getImage()->size());
    }
    else
    {
        ret["image"]=Json::Value();
    }
    return ret;
}

Json::Value Products::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 5)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getPrice())
            {
                ret[pMasqueradingVector[2]]=getValueOfPrice();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getAddDate())
            {
                ret[pMasqueradingVector[3]]=getValueOfAddDate();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getImage())
            {
                ret[pMasqueradingVector[4]]=drogon::utils::base64Encode((const unsigned char *)getImage()->data(),getImage()->size());
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getPrice())
    {
        ret["price"]=getValueOfPrice();
    }
    else
    {
        ret["price"]=Json::Value();
    }
    if(getAddDate())
    {
        ret["add_date"]=getValueOfAddDate();
    }
    else
    {
        ret["add_date"]=Json::Value();
    }
    if(getImage())
    {
        ret["image"]=drogon::utils::base64Encode((const unsigned char *)getImage()->data(),getImage()->size());
    }
    else
    {
        ret["image"]=Json::Value();
    }
    return ret;
}

bool Products::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, true))
            return false;
    }
    if(pJson.isMember("price"))
    {
        if(!validJsonOfField(2, "price", pJson["price"], err, true))
            return false;
    }
    if(pJson.isMember("add_date"))
    {
        if(!validJsonOfField(3, "add_date", pJson["add_date"], err, true))
            return false;
    }
    if(pJson.isMember("image"))
    {
        if(!validJsonOfField(4, "image", pJson["image"], err, true))
            return false;
    }
    return true;
}
bool Products::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 5)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty())
    {
        if(pJson.isMember(pMasqueradingVector[0]))
        {
            if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[1].empty())
    {
        if(pJson.isMember(pMasqueradingVector[1]))
        {
            if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[2].empty())
    {
        if(pJson.isMember(pMasqueradingVector[2]))
        {
            if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[3].empty())
    {
        if(pJson.isMember(pMasqueradingVector[3]))
        {
            if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[4].empty())
    {
        if(pJson.isMember(pMasqueradingVector[4]))
        {
            if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                return false;
        }
    }
    return true;
}
bool Products::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, false))
            return false;
    }
    if(pJson.isMember("price"))
    {
        if(!validJsonOfField(2, "price", pJson["price"], err, false))
            return false;
    }
    if(pJson.isMember("add_date"))
    {
        if(!validJsonOfField(3, "add_date", pJson["add_date"], err, false))
            return false;
    }
    if(pJson.isMember("image"))
    {
        if(!validJsonOfField(4, "image", pJson["image"], err, false))
            return false;
    }
    return true;
}
bool Products::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 5)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
            return false;
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
            return false;
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
            return false;
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
            return false;
    }
    return true;
}
bool Products::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson, 
                                std::string &err, 
                                bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }        
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 200)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 200)";
                return false;               
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isNumeric())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 20)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 20)";
                return false;               
            }

            break;
        case 4:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
     
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}