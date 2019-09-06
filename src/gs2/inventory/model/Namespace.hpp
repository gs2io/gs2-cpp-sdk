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

#ifndef GS2_INVENTORY_MODEL_NAMESPACE_HPP_
#define GS2_INVENTORY_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** カテゴリー名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** アイテム入手したときに実行するスクリプト */
        optional<ScriptSetting> acquireScript;
        /** 入手上限に当たって入手できなかったときに実行するスクリプト */
        optional<ScriptSetting> overflowScript;
        /** アイテム消費するときに実行するスクリプト */
        optional<ScriptSetting> consumeScript;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            acquireScript(data.acquireScript),
            overflowScript(data.overflowScript),
            consumeScript(data.consumeScript),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            acquireScript(std::move(data.acquireScript)),
            overflowScript(std::move(data.overflowScript)),
            consumeScript(std::move(data.consumeScript)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->acquireScript.emplace();
                    detail::json::JsonParser::parse(&this->acquireScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "overflowScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->overflowScript.emplace();
                    detail::json::JsonParser::parse(&this->overflowScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "consumeScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->consumeScript.emplace();
                    detail::json::JsonParser::parse(&this->consumeScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
        return *this;
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
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * アイテム入手したときに実行するスクリプトを取得
     *
     * @return アイテム入手したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getAcquireScript() const
    {
        return ensureData().acquireScript;
    }

    /**
     * アイテム入手したときに実行するスクリプトを設定
     *
     * @param acquireScript アイテム入手したときに実行するスクリプト
     */
    void setAcquireScript(const ScriptSetting& acquireScript)
    {
        ensureData().acquireScript.emplace(acquireScript);
    }

    /**
     * アイテム入手したときに実行するスクリプトを設定
     *
     * @param acquireScript アイテム入手したときに実行するスクリプト
     */
    Namespace& withAcquireScript(const ScriptSetting& acquireScript)
    {
        setAcquireScript(acquireScript);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを取得
     *
     * @return 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    const optional<ScriptSetting>& getOverflowScript() const
    {
        return ensureData().overflowScript;
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを設定
     *
     * @param overflowScript 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    void setOverflowScript(const ScriptSetting& overflowScript)
    {
        ensureData().overflowScript.emplace(overflowScript);
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを設定
     *
     * @param overflowScript 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    Namespace& withOverflowScript(const ScriptSetting& overflowScript)
    {
        setOverflowScript(overflowScript);
        return *this;
    }

    /**
     * アイテム消費するときに実行するスクリプトを取得
     *
     * @return アイテム消費するときに実行するスクリプト
     */
    const optional<ScriptSetting>& getConsumeScript() const
    {
        return ensureData().consumeScript;
    }

    /**
     * アイテム消費するときに実行するスクリプトを設定
     *
     * @param consumeScript アイテム消費するときに実行するスクリプト
     */
    void setConsumeScript(const ScriptSetting& consumeScript)
    {
        ensureData().consumeScript.emplace(consumeScript);
    }

    /**
     * アイテム消費するときに実行するスクリプトを設定
     *
     * @param consumeScript アイテム消費するときに実行するスクリプト
     */
    Namespace& withConsumeScript(const ScriptSetting& consumeScript)
    {
        setConsumeScript(consumeScript);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->acquireScript != lhr.m_pData->acquireScript)
        {
            return true;
        }
        if (lhs.m_pData->overflowScript != lhr.m_pData->overflowScript)
        {
            return true;
        }
        if (lhs.m_pData->consumeScript != lhr.m_pData->consumeScript)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_NAMESPACE_HPP_