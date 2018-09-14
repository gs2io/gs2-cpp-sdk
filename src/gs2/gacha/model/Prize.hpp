/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_GACHA_MODEL_PRIZE_HPP_
#define GS2_GACHA_MODEL_PRIZE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * 景品
 *
 * @author Game Server Services, Inc.
 *
 */
class Prize : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャプール名 */
        optional<StringHolder> gachaPoolName;
        /** ガチャ名 */
        optional<StringHolder> gachaName;
        /** 景品リスト */
        optional<List<StringHolder>> resourceIds;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gachaPoolName(data.gachaPoolName),
            gachaName(data.gachaName),
            resourceIds(data.resourceIds)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            gachaName(std::move(data.gachaName)),
            resourceIds(std::move(data.resourceIds))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gachaPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->gachaPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "gachaName") == 0) {
                if (jsonValue.IsString())
                {
                    this->gachaName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->resourceIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->resourceIds += std::move(stringHolder);
                    }
                }
            }
        }
    };
    
    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Prize() :
        m_pData(nullptr)
    {}

    Prize(const Prize& prize) :
        Gs2Object(prize),
        m_pData(prize.m_pData != nullptr ? new Data(*prize.m_pData) : nullptr)
    {}

    Prize(Prize&& prize) :
        Gs2Object(std::move(prize)),
        m_pData(prize.m_pData)
    {
        prize.m_pData = nullptr;
    }

    ~Prize()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Prize& operator=(const Prize& prize)
    {
        Gs2Object::operator=(prize);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*prize.m_pData);

        return *this;
    }

    Prize& operator=(Prize&& prize)
    {
        Gs2Object::operator=(std::move(prize));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = prize.m_pData;
        prize.m_pData = nullptr;

        return *this;
    }

    const Prize* operator->() const
    {
        return this;
    }

    Prize* operator->()
    {
        return this;
    }


    /**
     * ガチャプール名を取得
     *
     * @return ガチャプール名
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプール名を設定
     *
     * @param gachaPoolName ガチャプール名
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャ名を取得
     *
     * @return ガチャ名
     */
    const optional<StringHolder>& getGachaName() const
    {
        return ensureData().gachaName;
    }

    /**
     * ガチャ名を設定
     *
     * @param gachaName ガチャ名
     */
    void setGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
    }

    /**
     * 景品リストを取得
     *
     * @return 景品リスト
     */
    const optional<List<StringHolder>>& getResourceIds() const
    {
        return ensureData().resourceIds;
    }

    /**
     * 景品リストを設定
     *
     * @param resourceIds 景品リスト
     */
    void setResourceIds(const List<StringHolder>& resourceIds)
    {
        ensureData().resourceIds.emplace(resourceIds);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_MODEL_PRIZE_HPP_