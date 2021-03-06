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

#ifndef GS2_SCRIPT_MODEL_SCRIPT_HPP_
#define GS2_SCRIPT_MODEL_SCRIPT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace script {

/**
 * スクリプト
 *
 * @author Game Server Services, Inc.
 *
 */
class Script : public Gs2Object
{
    friend bool operator!=(const Script& lhs, const Script& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スクリプト */
        optional<StringHolder> scriptId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** スクリプト名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** Luaスクリプト */
        optional<StringHolder> script;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            scriptId(data.scriptId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            script(data.script),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "scriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scriptId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "script") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->script.emplace(jsonValue.GetString());
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
    Script() = default;
    Script(const Script& script) = default;
    Script(Script&& script) = default;
    ~Script() = default;

    Script& operator=(const Script& script) = default;
    Script& operator=(Script&& script) = default;

    Script deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Script);
    }

    const Script* operator->() const
    {
        return this;
    }

    Script* operator->()
    {
        return this;
    }
    /**
     * スクリプトを取得
     *
     * @return スクリプト
     */
    const optional<StringHolder>& getScriptId() const
    {
        return ensureData().scriptId;
    }

    /**
     * スクリプトを設定
     *
     * @param scriptId スクリプト
     */
    void setScriptId(StringHolder scriptId)
    {
        ensureData().scriptId.emplace(std::move(scriptId));
    }

    /**
     * スクリプトを設定
     *
     * @param scriptId スクリプト
     */
    Script& withScriptId(StringHolder scriptId)
    {
        setScriptId(std::move(scriptId));
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
    Script& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * スクリプト名を取得
     *
     * @return スクリプト名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スクリプト名を設定
     *
     * @param name スクリプト名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スクリプト名を設定
     *
     * @param name スクリプト名
     */
    Script& withName(StringHolder name)
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
    Script& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * Luaスクリプトを取得
     *
     * @return Luaスクリプト
     */
    const optional<StringHolder>& getScript() const
    {
        return ensureData().script;
    }

    /**
     * Luaスクリプトを設定
     *
     * @param script Luaスクリプト
     */
    void setScript(StringHolder script)
    {
        ensureData().script.emplace(std::move(script));
    }

    /**
     * Luaスクリプトを設定
     *
     * @param script Luaスクリプト
     */
    Script& withScript(StringHolder script)
    {
        setScript(std::move(script));
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
    Script& withCreatedAt(Int64 createdAt)
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
    Script& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Script& lhs, const Script& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->scriptId != lhr.m_pData->scriptId)
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
        if (lhs.m_pData->script != lhr.m_pData->script)
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

inline bool operator==(const Script& lhs, const Script& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SCRIPT_MODEL_SCRIPT_HPP_