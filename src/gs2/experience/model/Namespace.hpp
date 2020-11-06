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

#ifndef GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_
#define GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "LogSetting.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace experience {

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
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ランクキャップ取得時 に実行されるスクリプト のGRN */
        optional<StringHolder> experienceCapScriptId;
        /** 経験値変化したときに実行するスクリプト */
        optional<ScriptSetting> changeExperienceScript;
        /** ランク変化したときに実行するスクリプト */
        optional<ScriptSetting> changeRankScript;
        /** ランクキャップ変化したときに実行するスクリプト */
        optional<ScriptSetting> changeRankCapScript;
        /** 経験値あふれしたときに実行するスクリプト */
        optional<ScriptSetting> overflowExperienceScript;
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
            experienceCapScriptId(data.experienceCapScriptId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.changeExperienceScript)
            {
                changeExperienceScript = data.changeExperienceScript->deepCopy();
            }
            if (data.changeRankScript)
            {
                changeRankScript = data.changeRankScript->deepCopy();
            }
            if (data.changeRankCapScript)
            {
                changeRankCapScript = data.changeRankCapScript->deepCopy();
            }
            if (data.overflowExperienceScript)
            {
                overflowExperienceScript = data.overflowExperienceScript->deepCopy();
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
            else if (std::strcmp(name_, "experienceCapScriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->experienceCapScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeExperienceScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->changeExperienceScript.emplace();
                    detail::json::JsonParser::parse(&this->changeExperienceScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "changeRankScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->changeRankScript.emplace();
                    detail::json::JsonParser::parse(&this->changeRankScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "changeRankCapScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->changeRankCapScript.emplace();
                    detail::json::JsonParser::parse(&this->changeRankCapScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "overflowExperienceScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->overflowExperienceScript.emplace();
                    detail::json::JsonParser::parse(&this->overflowExperienceScript->getModel(), jsonObject);
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを取得
     *
     * @return ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getExperienceCapScriptId() const
    {
        return ensureData().experienceCapScriptId;
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    void setExperienceCapScriptId(StringHolder experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(std::move(experienceCapScriptId));
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    Namespace& withExperienceCapScriptId(StringHolder experienceCapScriptId)
    {
        setExperienceCapScriptId(std::move(experienceCapScriptId));
        return *this;
    }

    /**
     * 経験値変化したときに実行するスクリプトを取得
     *
     * @return 経験値変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeExperienceScript() const
    {
        return ensureData().changeExperienceScript;
    }

    /**
     * 経験値変化したときに実行するスクリプトを設定
     *
     * @param changeExperienceScript 経験値変化したときに実行するスクリプト
     */
    void setChangeExperienceScript(ScriptSetting changeExperienceScript)
    {
        ensureData().changeExperienceScript.emplace(std::move(changeExperienceScript));
    }

    /**
     * 経験値変化したときに実行するスクリプトを設定
     *
     * @param changeExperienceScript 経験値変化したときに実行するスクリプト
     */
    Namespace& withChangeExperienceScript(ScriptSetting changeExperienceScript)
    {
        setChangeExperienceScript(std::move(changeExperienceScript));
        return *this;
    }

    /**
     * ランク変化したときに実行するスクリプトを取得
     *
     * @return ランク変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeRankScript() const
    {
        return ensureData().changeRankScript;
    }

    /**
     * ランク変化したときに実行するスクリプトを設定
     *
     * @param changeRankScript ランク変化したときに実行するスクリプト
     */
    void setChangeRankScript(ScriptSetting changeRankScript)
    {
        ensureData().changeRankScript.emplace(std::move(changeRankScript));
    }

    /**
     * ランク変化したときに実行するスクリプトを設定
     *
     * @param changeRankScript ランク変化したときに実行するスクリプト
     */
    Namespace& withChangeRankScript(ScriptSetting changeRankScript)
    {
        setChangeRankScript(std::move(changeRankScript));
        return *this;
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを取得
     *
     * @return ランクキャップ変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeRankCapScript() const
    {
        return ensureData().changeRankCapScript;
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを設定
     *
     * @param changeRankCapScript ランクキャップ変化したときに実行するスクリプト
     */
    void setChangeRankCapScript(ScriptSetting changeRankCapScript)
    {
        ensureData().changeRankCapScript.emplace(std::move(changeRankCapScript));
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを設定
     *
     * @param changeRankCapScript ランクキャップ変化したときに実行するスクリプト
     */
    Namespace& withChangeRankCapScript(ScriptSetting changeRankCapScript)
    {
        setChangeRankCapScript(std::move(changeRankCapScript));
        return *this;
    }

    /**
     * 経験値あふれしたときに実行するスクリプトを取得
     *
     * @return 経験値あふれしたときに実行するスクリプト
     */
    const optional<ScriptSetting>& getOverflowExperienceScript() const
    {
        return ensureData().overflowExperienceScript;
    }

    /**
     * 経験値あふれしたときに実行するスクリプトを設定
     *
     * @param overflowExperienceScript 経験値あふれしたときに実行するスクリプト
     */
    void setOverflowExperienceScript(ScriptSetting overflowExperienceScript)
    {
        ensureData().overflowExperienceScript.emplace(std::move(overflowExperienceScript));
    }

    /**
     * 経験値あふれしたときに実行するスクリプトを設定
     *
     * @param overflowExperienceScript 経験値あふれしたときに実行するスクリプト
     */
    Namespace& withOverflowExperienceScript(ScriptSetting overflowExperienceScript)
    {
        setOverflowExperienceScript(std::move(overflowExperienceScript));
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
        if (lhs.m_pData->experienceCapScriptId != lhr.m_pData->experienceCapScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeExperienceScript != lhr.m_pData->changeExperienceScript)
        {
            return true;
        }
        if (lhs.m_pData->changeRankScript != lhr.m_pData->changeRankScript)
        {
            return true;
        }
        if (lhs.m_pData->changeRankCapScript != lhr.m_pData->changeRankCapScript)
        {
            return true;
        }
        if (lhs.m_pData->overflowExperienceScript != lhr.m_pData->overflowExperienceScript)
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

#endif //GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_