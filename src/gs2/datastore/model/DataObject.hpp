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

#ifndef GS2_DATASTORE_MODEL_DATAOBJECT_HPP_
#define GS2_DATASTORE_MODEL_DATAOBJECT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace datastore {

/**
 * データオブジェクト
 *
 * @author Game Server Services, Inc.
 *
 */
class DataObject : public Gs2Object
{
    friend bool operator!=(const DataObject& lhs, const DataObject& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** データオブジェクト */
        optional<StringHolder> dataObjectId;
        /** データの名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ファイルのアクセス権 */
        optional<StringHolder> scope;
        /** 公開するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** プラットフォーム */
        optional<StringHolder> platform;
        /** 状態 */
        optional<StringHolder> status;
        /** データの世代 */
        optional<StringHolder> generation;
        /** 以前有効だったデータの世代 */
        optional<StringHolder> previousGeneration;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            dataObjectId(data.dataObjectId),
            name(data.name),
            userId(data.userId),
            scope(data.scope),
            platform(data.platform),
            status(data.status),
            generation(data.generation),
            previousGeneration(data.previousGeneration),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.allowUserIds)
            {
                allowUserIds = data.allowUserIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "dataObjectId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->dataObjectId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scope") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scope.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "allowUserIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->allowUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->allowUserIds += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "platform") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->platform.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "status") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "generation") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->generation.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "previousGeneration") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->previousGeneration.emplace(jsonValue.GetString());
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
    DataObject() = default;
    DataObject(const DataObject& dataObject) = default;
    DataObject(DataObject&& dataObject) = default;
    ~DataObject() = default;

    DataObject& operator=(const DataObject& dataObject) = default;
    DataObject& operator=(DataObject&& dataObject) = default;

    DataObject deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DataObject);
    }

    const DataObject* operator->() const
    {
        return this;
    }

    DataObject* operator->()
    {
        return this;
    }
    /**
     * データオブジェクトを取得
     *
     * @return データオブジェクト
     */
    const optional<StringHolder>& getDataObjectId() const
    {
        return ensureData().dataObjectId;
    }

    /**
     * データオブジェクトを設定
     *
     * @param dataObjectId データオブジェクト
     */
    void setDataObjectId(StringHolder dataObjectId)
    {
        ensureData().dataObjectId.emplace(std::move(dataObjectId));
    }

    /**
     * データオブジェクトを設定
     *
     * @param dataObjectId データオブジェクト
     */
    DataObject& withDataObjectId(StringHolder dataObjectId)
    {
        setDataObjectId(std::move(dataObjectId));
        return *this;
    }

    /**
     * データの名前を取得
     *
     * @return データの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * データの名前を設定
     *
     * @param name データの名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * データの名前を設定
     *
     * @param name データの名前
     */
    DataObject& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DataObject& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * ファイルのアクセス権を取得
     *
     * @return ファイルのアクセス権
     */
    const optional<StringHolder>& getScope() const
    {
        return ensureData().scope;
    }

    /**
     * ファイルのアクセス権を設定
     *
     * @param scope ファイルのアクセス権
     */
    void setScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
    }

    /**
     * ファイルのアクセス権を設定
     *
     * @param scope ファイルのアクセス権
     */
    DataObject& withScope(StringHolder scope)
    {
        setScope(std::move(scope));
        return *this;
    }

    /**
     * 公開するユーザIDリストを取得
     *
     * @return 公開するユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 公開するユーザIDリストを設定
     *
     * @param allowUserIds 公開するユーザIDリスト
     */
    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
    }

    /**
     * 公開するユーザIDリストを設定
     *
     * @param allowUserIds 公開するユーザIDリスト
     */
    DataObject& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        setAllowUserIds(std::move(allowUserIds));
        return *this;
    }

    /**
     * プラットフォームを取得
     *
     * @return プラットフォーム
     */
    const optional<StringHolder>& getPlatform() const
    {
        return ensureData().platform;
    }

    /**
     * プラットフォームを設定
     *
     * @param platform プラットフォーム
     */
    void setPlatform(StringHolder platform)
    {
        ensureData().platform.emplace(std::move(platform));
    }

    /**
     * プラットフォームを設定
     *
     * @param platform プラットフォーム
     */
    DataObject& withPlatform(StringHolder platform)
    {
        setPlatform(std::move(platform));
        return *this;
    }

    /**
     * 状態を取得
     *
     * @return 状態
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * 状態を設定
     *
     * @param status 状態
     */
    void setStatus(StringHolder status)
    {
        ensureData().status.emplace(std::move(status));
    }

    /**
     * 状態を設定
     *
     * @param status 状態
     */
    DataObject& withStatus(StringHolder status)
    {
        setStatus(std::move(status));
        return *this;
    }

    /**
     * データの世代を取得
     *
     * @return データの世代
     */
    const optional<StringHolder>& getGeneration() const
    {
        return ensureData().generation;
    }

    /**
     * データの世代を設定
     *
     * @param generation データの世代
     */
    void setGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
    }

    /**
     * データの世代を設定
     *
     * @param generation データの世代
     */
    DataObject& withGeneration(StringHolder generation)
    {
        setGeneration(std::move(generation));
        return *this;
    }

    /**
     * 以前有効だったデータの世代を取得
     *
     * @return 以前有効だったデータの世代
     */
    const optional<StringHolder>& getPreviousGeneration() const
    {
        return ensureData().previousGeneration;
    }

    /**
     * 以前有効だったデータの世代を設定
     *
     * @param previousGeneration 以前有効だったデータの世代
     */
    void setPreviousGeneration(StringHolder previousGeneration)
    {
        ensureData().previousGeneration.emplace(std::move(previousGeneration));
    }

    /**
     * 以前有効だったデータの世代を設定
     *
     * @param previousGeneration 以前有効だったデータの世代
     */
    DataObject& withPreviousGeneration(StringHolder previousGeneration)
    {
        setPreviousGeneration(std::move(previousGeneration));
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
    DataObject& withCreatedAt(Int64 createdAt)
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
    DataObject& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DataObject& lhs, const DataObject& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->dataObjectId != lhr.m_pData->dataObjectId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->scope != lhr.m_pData->scope)
        {
            return true;
        }
        if (lhs.m_pData->allowUserIds != lhr.m_pData->allowUserIds)
        {
            return true;
        }
        if (lhs.m_pData->platform != lhr.m_pData->platform)
        {
            return true;
        }
        if (lhs.m_pData->status != lhr.m_pData->status)
        {
            return true;
        }
        if (lhs.m_pData->generation != lhr.m_pData->generation)
        {
            return true;
        }
        if (lhs.m_pData->previousGeneration != lhr.m_pData->previousGeneration)
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

inline bool operator==(const DataObject& lhs, const DataObject& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DATASTORE_MODEL_DATAOBJECT_HPP_