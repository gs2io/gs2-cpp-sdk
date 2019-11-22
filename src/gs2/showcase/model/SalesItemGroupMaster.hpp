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

#ifndef GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace showcase {

/**
 * 商品グループマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItemGroupMaster : public Gs2Object
{
    friend bool operator!=(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループマスター */
        optional<StringHolder> salesItemGroupId;
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品グループマスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 商品グループに含める商品リスト */
        optional<List<StringHolder>> salesItemNames;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SalesItemGroupMaster() = default;
    SalesItemGroupMaster(const SalesItemGroupMaster& salesItemGroupMaster) = default;
    SalesItemGroupMaster(SalesItemGroupMaster&& salesItemGroupMaster) = default;
    ~SalesItemGroupMaster() = default;

    SalesItemGroupMaster& operator=(const SalesItemGroupMaster& salesItemGroupMaster) = default;
    SalesItemGroupMaster& operator=(SalesItemGroupMaster&& salesItemGroupMaster) = default;

    SalesItemGroupMaster deepCopy() const;

    const SalesItemGroupMaster* operator->() const
    {
        return this;
    }

    SalesItemGroupMaster* operator->()
    {
        return this;
    }
    /**
     * 商品グループマスターを取得
     *
     * @return 商品グループマスター
     */
    const optional<StringHolder>& getSalesItemGroupId() const
    {
        return ensureData().salesItemGroupId;
    }

    /**
     * 商品グループマスターを設定
     *
     * @param salesItemGroupId 商品グループマスター
     */
    void setSalesItemGroupId(StringHolder salesItemGroupId)
    {
        ensureData().salesItemGroupId.emplace(std::move(salesItemGroupId));
    }

    /**
     * 商品グループマスターを設定
     *
     * @param salesItemGroupId 商品グループマスター
     */
    SalesItemGroupMaster& withSalesItemGroupId(StringHolder salesItemGroupId)
    {
        setSalesItemGroupId(std::move(salesItemGroupId));
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    SalesItemGroupMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 商品グループマスターの説明を取得
     *
     * @return 商品グループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    SalesItemGroupMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    SalesItemGroupMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 商品グループに含める商品リストを取得
     *
     * @return 商品グループに含める商品リスト
     */
    const optional<List<StringHolder>>& getSalesItemNames() const
    {
        return ensureData().salesItemNames;
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    void setSalesItemNames(List<StringHolder> salesItemNames)
    {
        ensureData().salesItemNames.emplace(std::move(salesItemNames));
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    SalesItemGroupMaster& withSalesItemNames(List<StringHolder> salesItemNames)
    {
        setSalesItemNames(std::move(salesItemNames));
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
    SalesItemGroupMaster& withCreatedAt(Int64 createdAt)
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
    SalesItemGroupMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr);

inline bool operator==(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_