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

#ifndef GS2_EZ_DATASTORE_MODEL_EZDATAOBJECT_HPP_
#define GS2_EZ_DATASTORE_MODEL_EZDATAOBJECT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace datastore {

class DataObject;

}

namespace ez { namespace datastore {

class EzDataObject : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** データオブジェクト */
        StringHolder dataObjectId;
        /** データの名前 */
        StringHolder name;
        /** ユーザーID */
        StringHolder userId;
        /** ファイルのアクセス権 */
        StringHolder scope;
        /** 公開するユーザIDリスト */
        List<StringHolder> allowUserIds;
        /** 状態 */
        StringHolder status;
        /** データの世代 */
        StringHolder generation;
        /** 作成日時 */
        Int64 createdAt;
        /** 最終更新日時 */
        Int64 updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::datastore::DataObject& dataObject);
        Data(const gs2::optional<gs2::datastore::DataObject>& dataObject);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDataObject() = default;
    EzDataObject(const EzDataObject& ezDataObject) = default;
    EzDataObject(EzDataObject&& ezDataObject) = default;
    ~EzDataObject() = default;

    EzDataObject(gs2::datastore::DataObject dataObject);
    EzDataObject(gs2::optional<gs2::datastore::DataObject> dataObject);

    EzDataObject& operator=(const EzDataObject& ezDataObject) = default;
    EzDataObject& operator=(EzDataObject&& ezDataObject) = default;

    EzDataObject deepCopy() const;

    gs2::datastore::DataObject ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getDataObjectId() const
    {
        return ensureData().dataObjectId;
    }

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    const StringHolder& getScope() const
    {
        return ensureData().scope;
    }

    const List<StringHolder>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    const StringHolder& getStatus() const
    {
        return ensureData().status;
    }

    const StringHolder& getGeneration() const
    {
        return ensureData().generation;
    }

    Int64 getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    Int64 getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setDataObjectId(StringHolder dataObjectId)
    {
        ensureData().dataObjectId = std::move(dataObjectId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setScope(StringHolder scope)
    {
        ensureData().scope = std::move(scope);
    }

    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds = std::move(allowUserIds);
    }

    void setStatus(StringHolder status)
    {
        ensureData().status = std::move(status);
    }

    void setGeneration(StringHolder generation)
    {
        ensureData().generation = std::move(generation);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt = updatedAt;
    }

    EzDataObject& withDataObjectId(StringHolder dataObjectId)
    {
        setDataObjectId(std::move(dataObjectId));
        return *this;
    }

    EzDataObject& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzDataObject& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzDataObject& withScope(StringHolder scope)
    {
        setScope(std::move(scope));
        return *this;
    }

    EzDataObject& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        setAllowUserIds(std::move(allowUserIds));
        return *this;
    }

    EzDataObject& withStatus(StringHolder status)
    {
        setStatus(std::move(status));
        return *this;
    }

    EzDataObject& withGeneration(StringHolder generation)
    {
        setGeneration(std::move(generation));
        return *this;
    }

    EzDataObject& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzDataObject& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_DATASTORE_EZDATAOBJECT_HPP_