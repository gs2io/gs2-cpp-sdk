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

#ifndef GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "SalesItem.hpp"
#include <memory>

namespace gs2 { namespace showcase {

/**
 * 商品グループ
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItemGroup : public Gs2Object
{
    friend bool operator!=(const SalesItemGroup& lhs, const SalesItemGroup& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 商品リスト */
        optional<List<SalesItem>> salesItems;

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
    SalesItemGroup() = default;
    SalesItemGroup(const SalesItemGroup& salesItemGroup) = default;
    SalesItemGroup(SalesItemGroup&& salesItemGroup) = default;
    ~SalesItemGroup() = default;

    SalesItemGroup& operator=(const SalesItemGroup& salesItemGroup) = default;
    SalesItemGroup& operator=(SalesItemGroup&& salesItemGroup) = default;

    SalesItemGroup deepCopy() const;

    const SalesItemGroup* operator->() const
    {
        return this;
    }

    SalesItemGroup* operator->()
    {
        return this;
    }
    /**
     * 商品グループ名を取得
     *
     * @return 商品グループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品グループ名を設定
     *
     * @param name 商品グループ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 商品グループ名を設定
     *
     * @param name 商品グループ名
     */
    SalesItemGroup& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    SalesItemGroup& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 商品リストを取得
     *
     * @return 商品リスト
     */
    const optional<List<SalesItem>>& getSalesItems() const
    {
        return ensureData().salesItems;
    }

    /**
     * 商品リストを設定
     *
     * @param salesItems 商品リスト
     */
    void setSalesItems(List<SalesItem> salesItems)
    {
        ensureData().salesItems.emplace(std::move(salesItems));
    }

    /**
     * 商品リストを設定
     *
     * @param salesItems 商品リスト
     */
    SalesItemGroup& withSalesItems(List<SalesItem> salesItems)
    {
        setSalesItems(std::move(salesItems));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const SalesItemGroup& lhs, const SalesItemGroup& lhr);

inline bool operator==(const SalesItemGroup& lhs, const SalesItemGroup& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_