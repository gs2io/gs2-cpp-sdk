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

#ifndef GS2_DATASTORE_MODEL_DATAOBJECTHISTORY_HPP_
#define GS2_DATASTORE_MODEL_DATAOBJECTHISTORY_HPP_

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
 * データオブジェクト履歴
 *
 * @author Game Server Services, Inc.
 *
 */
class DataObjectHistory : public Gs2Object
{
    friend bool operator!=(const DataObjectHistory& lhs, const DataObjectHistory& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** データオブジェクト履歴 */
        optional<StringHolder> dataObjectHistoryId;
        /** データオブジェクト名 */
        optional<StringHolder> dataObjectName;
        /** 世代ID */
        optional<StringHolder> generation;
        /** データサイズ */
        optional<Int64> contentLength;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            dataObjectHistoryId(data.dataObjectHistoryId),
            dataObjectName(data.dataObjectName),
            generation(data.generation),
            contentLength(data.contentLength),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "dataObjectHistoryId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->dataObjectHistoryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "dataObjectName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->dataObjectName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "generation") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->generation.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "contentLength") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->contentLength = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DataObjectHistory() = default;
    DataObjectHistory(const DataObjectHistory& dataObjectHistory) = default;
    DataObjectHistory(DataObjectHistory&& dataObjectHistory) = default;
    ~DataObjectHistory() = default;

    DataObjectHistory& operator=(const DataObjectHistory& dataObjectHistory) = default;
    DataObjectHistory& operator=(DataObjectHistory&& dataObjectHistory) = default;

    DataObjectHistory deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DataObjectHistory);
    }

    const DataObjectHistory* operator->() const
    {
        return this;
    }

    DataObjectHistory* operator->()
    {
        return this;
    }
    /**
     * データオブジェクト履歴を取得
     *
     * @return データオブジェクト履歴
     */
    const optional<StringHolder>& getDataObjectHistoryId() const
    {
        return ensureData().dataObjectHistoryId;
    }

    /**
     * データオブジェクト履歴を設定
     *
     * @param dataObjectHistoryId データオブジェクト履歴
     */
    void setDataObjectHistoryId(StringHolder dataObjectHistoryId)
    {
        ensureData().dataObjectHistoryId.emplace(std::move(dataObjectHistoryId));
    }

    /**
     * データオブジェクト履歴を設定
     *
     * @param dataObjectHistoryId データオブジェクト履歴
     */
    DataObjectHistory& withDataObjectHistoryId(StringHolder dataObjectHistoryId)
    {
        setDataObjectHistoryId(std::move(dataObjectHistoryId));
        return *this;
    }

    /**
     * データオブジェクト名を取得
     *
     * @return データオブジェクト名
     */
    const optional<StringHolder>& getDataObjectName() const
    {
        return ensureData().dataObjectName;
    }

    /**
     * データオブジェクト名を設定
     *
     * @param dataObjectName データオブジェクト名
     */
    void setDataObjectName(StringHolder dataObjectName)
    {
        ensureData().dataObjectName.emplace(std::move(dataObjectName));
    }

    /**
     * データオブジェクト名を設定
     *
     * @param dataObjectName データオブジェクト名
     */
    DataObjectHistory& withDataObjectName(StringHolder dataObjectName)
    {
        setDataObjectName(std::move(dataObjectName));
        return *this;
    }

    /**
     * 世代IDを取得
     *
     * @return 世代ID
     */
    const optional<StringHolder>& getGeneration() const
    {
        return ensureData().generation;
    }

    /**
     * 世代IDを設定
     *
     * @param generation 世代ID
     */
    void setGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
    }

    /**
     * 世代IDを設定
     *
     * @param generation 世代ID
     */
    DataObjectHistory& withGeneration(StringHolder generation)
    {
        setGeneration(std::move(generation));
        return *this;
    }

    /**
     * データサイズを取得
     *
     * @return データサイズ
     */
    const optional<Int64>& getContentLength() const
    {
        return ensureData().contentLength;
    }

    /**
     * データサイズを設定
     *
     * @param contentLength データサイズ
     */
    void setContentLength(Int64 contentLength)
    {
        ensureData().contentLength.emplace(contentLength);
    }

    /**
     * データサイズを設定
     *
     * @param contentLength データサイズ
     */
    DataObjectHistory& withContentLength(Int64 contentLength)
    {
        setContentLength(contentLength);
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
    DataObjectHistory& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DataObjectHistory& lhs, const DataObjectHistory& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->dataObjectHistoryId != lhr.m_pData->dataObjectHistoryId)
        {
            return true;
        }
        if (lhs.m_pData->dataObjectName != lhr.m_pData->dataObjectName)
        {
            return true;
        }
        if (lhs.m_pData->generation != lhr.m_pData->generation)
        {
            return true;
        }
        if (lhs.m_pData->contentLength != lhr.m_pData->contentLength)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const DataObjectHistory& lhs, const DataObjectHistory& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DATASTORE_MODEL_DATAOBJECTHISTORY_HPP_