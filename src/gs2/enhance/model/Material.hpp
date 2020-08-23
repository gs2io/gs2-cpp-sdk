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

#ifndef GS2_ENHANCE_MODEL_MATERIAL_HPP_
#define GS2_ENHANCE_MODEL_MATERIAL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace enhance {

/**
 * 素材
 *
 * @author Game Server Services, Inc.
 *
 */
class Material : public Gs2Object
{
    friend bool operator!=(const Material& lhs, const Material& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化対象の GS2-Inventory アイテムセットGRN */
        optional<StringHolder> materialItemSetId;
        /** 消費数量 */
        optional<Int32> count;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            materialItemSetId(data.materialItemSetId),
            count(data.count)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "materialItemSetId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->materialItemSetId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "count") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Material() = default;
    Material(const Material& material) = default;
    Material(Material&& material) = default;
    ~Material() = default;

    Material& operator=(const Material& material) = default;
    Material& operator=(Material&& material) = default;

    Material deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Material);
    }

    const Material* operator->() const
    {
        return this;
    }

    Material* operator->()
    {
        return this;
    }
    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを取得
     *
     * @return 強化対象の GS2-Inventory アイテムセットGRN
     */
    const optional<StringHolder>& getMaterialItemSetId() const
    {
        return ensureData().materialItemSetId;
    }

    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを設定
     *
     * @param materialItemSetId 強化対象の GS2-Inventory アイテムセットGRN
     */
    void setMaterialItemSetId(StringHolder materialItemSetId)
    {
        ensureData().materialItemSetId.emplace(std::move(materialItemSetId));
    }

    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを設定
     *
     * @param materialItemSetId 強化対象の GS2-Inventory アイテムセットGRN
     */
    Material& withMaterialItemSetId(StringHolder materialItemSetId)
    {
        setMaterialItemSetId(std::move(materialItemSetId));
        return *this;
    }

    /**
     * 消費数量を取得
     *
     * @return 消費数量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 消費数量を設定
     *
     * @param count 消費数量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 消費数量を設定
     *
     * @param count 消費数量
     */
    Material& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Material& lhs, const Material& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->materialItemSetId != lhr.m_pData->materialItemSetId)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Material& lhs, const Material& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ENHANCE_MODEL_MATERIAL_HPP_