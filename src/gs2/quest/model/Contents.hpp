/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_QUEST_MODEL_CONTENTS_HPP_
#define GS2_QUEST_MODEL_CONTENTS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <cstring>

namespace gs2 { namespace quest {

/**
 * コンテンツ
 *
 * @author Game Server Services, Inc.
 *
 */
class Contents : public Gs2Object
{
    friend bool operator!=(const Contents& lhs, const Contents& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストモデルのメタデータ */
        optional<StringHolder> metadata;
        /** クエストクリア時の報酬 */
        optional<List<AcquireAction>> completeAcquireActions;
        /** 抽選する重み */
        optional<Int32> weight;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            metadata(data.metadata),
            completeAcquireActions(data.completeAcquireActions),
            weight(data.weight)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            metadata(std::move(data.metadata)),
            completeAcquireActions(std::move(data.completeAcquireActions)),
            weight(std::move(data.weight))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeAcquireActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->completeAcquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->completeAcquireActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "weight") == 0) {
                if (jsonValue.IsInt())
                {
                    this->weight = jsonValue.GetInt();
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
    Contents() :
        m_pData(nullptr)
    {}

    Contents(const Contents& contents) :
        Gs2Object(contents),
        m_pData(contents.m_pData != nullptr ? new Data(*contents.m_pData) : nullptr)
    {}

    Contents(Contents&& contents) :
        Gs2Object(std::move(contents)),
        m_pData(contents.m_pData)
    {
        contents.m_pData = nullptr;
    }

    ~Contents()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Contents& operator=(const Contents& contents)
    {
        Gs2Object::operator=(contents);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*contents.m_pData);

        return *this;
    }

    Contents& operator=(Contents&& contents)
    {
        Gs2Object::operator=(std::move(contents));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = contents.m_pData;
        contents.m_pData = nullptr;

        return *this;
    }

    const Contents* operator->() const
    {
        return this;
    }

    Contents* operator->()
    {
        return this;
    }
    /**
     * クエストモデルのメタデータを取得
     *
     * @return クエストモデルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    Contents& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * クエストクリア時の報酬を取得
     *
     * @return クエストクリア時の報酬
     */
    const optional<List<AcquireAction>>& getCompleteAcquireActions() const
    {
        return ensureData().completeAcquireActions;
    }

    /**
     * クエストクリア時の報酬を設定
     *
     * @param completeAcquireActions クエストクリア時の報酬
     */
    void setCompleteAcquireActions(const List<AcquireAction>& completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(completeAcquireActions);
    }

    /**
     * クエストクリア時の報酬を設定
     *
     * @param completeAcquireActions クエストクリア時の報酬
     */
    Contents& withCompleteAcquireActions(const List<AcquireAction>& completeAcquireActions)
    {
        setCompleteAcquireActions(completeAcquireActions);
        return *this;
    }

    /**
     * 抽選する重みを取得
     *
     * @return 抽選する重み
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 抽選する重みを設定
     *
     * @param weight 抽選する重み
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
    }

    /**
     * 抽選する重みを設定
     *
     * @param weight 抽選する重み
     */
    Contents& withWeight(Int32 weight)
    {
        setWeight(weight);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Contents& lhs, const Contents& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->completeAcquireActions != lhr.m_pData->completeAcquireActions)
        {
            return true;
        }
        if (lhs.m_pData->weight != lhr.m_pData->weight)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Contents& lhs, const Contents& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_CONTENTS_HPP_