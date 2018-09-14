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

#ifndef GS2_GACHA_MODEL_GACHA_HPP_
#define GS2_GACHA_MODEL_GACHA_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * ガチャ
 *
 * @author Game Server Services, Inc.
 *
 */
class Gacha : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 抽選回数 */
        optional<Int32> drawCount;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            meta(data.meta),
            drawCount(data.drawCount)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            drawCount(std::move(data.drawCount))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "drawCount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->drawCount = jsonValue.GetInt();
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
    Gacha() :
        m_pData(nullptr)
    {}

    Gacha(const Gacha& gacha) :
        Gs2Object(gacha),
        m_pData(gacha.m_pData != nullptr ? new Data(*gacha.m_pData) : nullptr)
    {}

    Gacha(Gacha&& gacha) :
        Gs2Object(std::move(gacha)),
        m_pData(gacha.m_pData)
    {
        gacha.m_pData = nullptr;
    }

    ~Gacha()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gacha& operator=(const Gacha& gacha)
    {
        Gs2Object::operator=(gacha);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gacha.m_pData);

        return *this;
    }

    Gacha& operator=(Gacha&& gacha)
    {
        Gs2Object::operator=(std::move(gacha));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gacha.m_pData;
        gacha.m_pData = nullptr;

        return *this;
    }

    const Gacha* operator->() const
    {
        return this;
    }

    Gacha* operator->()
    {
        return this;
    }


    /**
     * ガチャ名を取得
     *
     * @return ガチャ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ガチャ名を設定
     *
     * @param name ガチャ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 抽選回数を取得
     *
     * @return 抽選回数
     */
    const optional<Int32>& getDrawCount() const
    {
        return ensureData().drawCount;
    }

    /**
     * 抽選回数を設定
     *
     * @param drawCount 抽選回数
     */
    void setDrawCount(Int32 drawCount)
    {
        ensureData().drawCount.emplace(drawCount);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_MODEL_GACHA_HPP_