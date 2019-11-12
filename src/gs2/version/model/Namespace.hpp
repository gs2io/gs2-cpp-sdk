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

#ifndef GS2_VERSION_MODEL_NAMESPACE_HPP_
#define GS2_VERSION_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "LogSetting.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace version {

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
        /** ネームスペース名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRN */
        optional<StringHolder> assumeUserId;
        /** バージョンを承認したときに実行するスクリプト */
        optional<ScriptSetting> acceptVersionScript;
        /** バージョンチェック時 に実行されるスクリプト のGRN */
        optional<StringHolder> checkVersionTriggerScriptId;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            assumeUserId(data.assumeUserId),
            checkVersionTriggerScriptId(data.checkVersionTriggerScriptId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.acceptVersionScript)
            {
                acceptVersionScript = data.acceptVersionScript->deepCopy();
            }
            if (data.logSetting)
            {
                logSetting = data.logSetting->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "assumeUserId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->assumeUserId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acceptVersionScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->acceptVersionScript.emplace();
                    detail::json::JsonParser::parse(&this->acceptVersionScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "checkVersionTriggerScriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->checkVersionTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "logSetting") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->logSetting.emplace();
                    detail::json::JsonParser::parse(&this->logSetting->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
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
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRNを取得
     *
     * @return バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRN
     */
    const optional<StringHolder>& getAssumeUserId() const
    {
        return ensureData().assumeUserId;
    }

    /**
     * バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRN
     */
    void setAssumeUserId(StringHolder assumeUserId)
    {
        ensureData().assumeUserId.emplace(std::move(assumeUserId));
    }

    /**
     * バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId バージョンチェック通過後に改めて発行するプロジェクトトークンの権限判定に使用する ユーザ のGRN
     */
    Namespace& withAssumeUserId(StringHolder assumeUserId)
    {
        setAssumeUserId(std::move(assumeUserId));
        return *this;
    }

    /**
     * バージョンを承認したときに実行するスクリプトを取得
     *
     * @return バージョンを承認したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getAcceptVersionScript() const
    {
        return ensureData().acceptVersionScript;
    }

    /**
     * バージョンを承認したときに実行するスクリプトを設定
     *
     * @param acceptVersionScript バージョンを承認したときに実行するスクリプト
     */
    void setAcceptVersionScript(ScriptSetting acceptVersionScript)
    {
        ensureData().acceptVersionScript.emplace(std::move(acceptVersionScript));
    }

    /**
     * バージョンを承認したときに実行するスクリプトを設定
     *
     * @param acceptVersionScript バージョンを承認したときに実行するスクリプト
     */
    Namespace& withAcceptVersionScript(ScriptSetting acceptVersionScript)
    {
        setAcceptVersionScript(std::move(acceptVersionScript));
        return *this;
    }

    /**
     * バージョンチェック時 に実行されるスクリプト のGRNを取得
     *
     * @return バージョンチェック時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCheckVersionTriggerScriptId() const
    {
        return ensureData().checkVersionTriggerScriptId;
    }

    /**
     * バージョンチェック時 に実行されるスクリプト のGRNを設定
     *
     * @param checkVersionTriggerScriptId バージョンチェック時 に実行されるスクリプト のGRN
     */
    void setCheckVersionTriggerScriptId(StringHolder checkVersionTriggerScriptId)
    {
        ensureData().checkVersionTriggerScriptId.emplace(std::move(checkVersionTriggerScriptId));
    }

    /**
     * バージョンチェック時 に実行されるスクリプト のGRNを設定
     *
     * @param checkVersionTriggerScriptId バージョンチェック時 に実行されるスクリプト のGRN
     */
    Namespace& withCheckVersionTriggerScriptId(StringHolder checkVersionTriggerScriptId)
    {
        setCheckVersionTriggerScriptId(std::move(checkVersionTriggerScriptId));
        return *this;
    }

    /**
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    Namespace& withLogSetting(LogSetting logSetting)
    {
        setLogSetting(std::move(logSetting));
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
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->assumeUserId != lhr.m_pData->assumeUserId)
        {
            return true;
        }
        if (lhs.m_pData->acceptVersionScript != lhr.m_pData->acceptVersionScript)
        {
            return true;
        }
        if (lhs.m_pData->checkVersionTriggerScriptId != lhr.m_pData->checkVersionTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->logSetting != lhr.m_pData->logSetting)
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

#endif //GS2_VERSION_MODEL_NAMESPACE_HPP_