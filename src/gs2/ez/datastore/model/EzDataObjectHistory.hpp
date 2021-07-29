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

#ifndef GS2_EZ_DATASTORE_MODEL_EZDATAOBJECTHISTORY_HPP_
#define GS2_EZ_DATASTORE_MODEL_EZDATAOBJECTHISTORY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace datastore {

class DataObjectHistory;

}

namespace ez { namespace datastore {

class EzDataObjectHistory : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** データオブジェクト履歴 */
        StringHolder dataObjectHistoryId;
        /** 世代ID */
        StringHolder generation;
        /** データサイズ */
        Int64 contentLength;
        /** 作成日時 */
        Int64 createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::datastore::DataObjectHistory& dataObjectHistory);
        Data(const gs2::optional<gs2::datastore::DataObjectHistory>& dataObjectHistory);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDataObjectHistory() = default;
    EzDataObjectHistory(const EzDataObjectHistory& ezDataObjectHistory) = default;
    EzDataObjectHistory(EzDataObjectHistory&& ezDataObjectHistory) = default;
    ~EzDataObjectHistory() = default;

    EzDataObjectHistory(gs2::datastore::DataObjectHistory dataObjectHistory);
    EzDataObjectHistory(gs2::optional<gs2::datastore::DataObjectHistory> dataObjectHistory);

    EzDataObjectHistory& operator=(const EzDataObjectHistory& ezDataObjectHistory) = default;
    EzDataObjectHistory& operator=(EzDataObjectHistory&& ezDataObjectHistory) = default;

    EzDataObjectHistory deepCopy() const;

    gs2::datastore::DataObjectHistory ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getDataObjectHistoryId() const
    {
        return ensureData().dataObjectHistoryId;
    }

    const StringHolder& getGeneration() const
    {
        return ensureData().generation;
    }

    Int64 getContentLength() const
    {
        return ensureData().contentLength;
    }

    Int64 getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setDataObjectHistoryId(StringHolder dataObjectHistoryId)
    {
        ensureData().dataObjectHistoryId = std::move(dataObjectHistoryId);
    }

    void setGeneration(StringHolder generation)
    {
        ensureData().generation = std::move(generation);
    }

    void setContentLength(Int64 contentLength)
    {
        ensureData().contentLength = contentLength;
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    EzDataObjectHistory& withDataObjectHistoryId(StringHolder dataObjectHistoryId)
    {
        setDataObjectHistoryId(std::move(dataObjectHistoryId));
        return *this;
    }

    EzDataObjectHistory& withGeneration(StringHolder generation)
    {
        setGeneration(std::move(generation));
        return *this;
    }

    EzDataObjectHistory& withContentLength(Int64 contentLength)
    {
        setContentLength(contentLength);
        return *this;
    }

    EzDataObjectHistory& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_DATASTORE_EZDATAOBJECTHISTORY_HPP_