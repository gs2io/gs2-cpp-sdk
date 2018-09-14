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

#ifndef GS2_SHOWCASE_MODEL_SHOWCASE_HPP_
#define GS2_SHOWCASE_MODEL_SHOWCASE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * ショーケース
 *
 * @author Game Server Services, Inc.
 *
 */
class Showcase : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ショーケースGRN */
        optional<StringHolder> showcaseId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ショーケース名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 公開許可判定 に実行されるGS2-Script */
        optional<StringHolder> releaseConditionTriggerScript;
        /** 購入直前 に実行されるGS2-Script */
        optional<StringHolder> buyTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            showcaseId(data.showcaseId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            releaseConditionTriggerScript(data.releaseConditionTriggerScript),
            buyTriggerScript(data.buyTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            showcaseId(std::move(data.showcaseId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            releaseConditionTriggerScript(std::move(data.releaseConditionTriggerScript)),
            buyTriggerScript(std::move(data.buyTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "showcaseId") == 0) {
                if (jsonValue.IsString())
                {
                    this->showcaseId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "releaseConditionTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->releaseConditionTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "buyTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->buyTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    Showcase() :
        m_pData(nullptr)
    {}

    Showcase(const Showcase& showcase) :
        Gs2Object(showcase),
        m_pData(showcase.m_pData != nullptr ? new Data(*showcase.m_pData) : nullptr)
    {}

    Showcase(Showcase&& showcase) :
        Gs2Object(std::move(showcase)),
        m_pData(showcase.m_pData)
    {
        showcase.m_pData = nullptr;
    }

    ~Showcase()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Showcase& operator=(const Showcase& showcase)
    {
        Gs2Object::operator=(showcase);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*showcase.m_pData);

        return *this;
    }

    Showcase& operator=(Showcase&& showcase)
    {
        Gs2Object::operator=(std::move(showcase));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = showcase.m_pData;
        showcase.m_pData = nullptr;

        return *this;
    }

    const Showcase* operator->() const
    {
        return this;
    }

    Showcase* operator->()
    {
        return this;
    }


    /**
     * ショーケースGRNを取得
     *
     * @return ショーケースGRN
     */
    const optional<StringHolder>& getShowcaseId() const
    {
        return ensureData().showcaseId;
    }

    /**
     * ショーケースGRNを設定
     *
     * @param showcaseId ショーケースGRN
     */
    void setShowcaseId(const Char* showcaseId)
    {
        ensureData().showcaseId.emplace(showcaseId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * ショーケース名を取得
     *
     * @return ショーケース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ショーケース名を設定
     *
     * @param name ショーケース名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 公開許可判定 に実行されるGS2-Scriptを取得
     *
     * @return 公開許可判定 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReleaseConditionTriggerScript() const
    {
        return ensureData().releaseConditionTriggerScript;
    }

    /**
     * 公開許可判定 に実行されるGS2-Scriptを設定
     *
     * @param releaseConditionTriggerScript 公開許可判定 に実行されるGS2-Script
     */
    void setReleaseConditionTriggerScript(const Char* releaseConditionTriggerScript)
    {
        ensureData().releaseConditionTriggerScript.emplace(releaseConditionTriggerScript);
    }

    /**
     * 購入直前 に実行されるGS2-Scriptを取得
     *
     * @return 購入直前 に実行されるGS2-Script
     */
    const optional<StringHolder>& getBuyTriggerScript() const
    {
        return ensureData().buyTriggerScript;
    }

    /**
     * 購入直前 に実行されるGS2-Scriptを設定
     *
     * @param buyTriggerScript 購入直前 に実行されるGS2-Script
     */
    void setBuyTriggerScript(const Char* buyTriggerScript)
    {
        ensureData().buyTriggerScript.emplace(buyTriggerScript);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_MODEL_SHOWCASE_HPP_