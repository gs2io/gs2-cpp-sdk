/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SHOWCASE_MODEL_SHOWCASEITEMMASTER_HPP_
#define GS2_SHOWCASE_MODEL_SHOWCASEITEMMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 陳列商品
 *
 * @author Game Server Services, Inc.
 *
 */
class ShowcaseItemMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品GRN */
        optional<StringHolder> showcaseItemId;
        /** 商品の種類 */
        optional<StringHolder> category;
        /** 商品名 */
        optional<StringHolder> itemName;
        /** グループ名 */
        optional<StringHolder> itemGroupName;
        /** 公開判定の種類 */
        optional<StringHolder> releaseConditionType;
        /** 公開許可判定 に実行されるGS2-Schedule */
        optional<StringHolder> releaseConditionScheduleName;
        /** 公開許可判定 に実行されるGS2-Schedule のイベント名 */
        optional<StringHolder> releaseConditionScheduleEventName;
        /** 応答順序優先度 */
        optional<Int32> priority;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            showcaseItemId(data.showcaseItemId),
            category(data.category),
            itemName(data.itemName),
            itemGroupName(data.itemGroupName),
            releaseConditionType(data.releaseConditionType),
            releaseConditionScheduleName(data.releaseConditionScheduleName),
            releaseConditionScheduleEventName(data.releaseConditionScheduleEventName),
            priority(data.priority),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            showcaseItemId(std::move(data.showcaseItemId)),
            category(std::move(data.category)),
            itemName(std::move(data.itemName)),
            itemGroupName(std::move(data.itemGroupName)),
            releaseConditionType(std::move(data.releaseConditionType)),
            releaseConditionScheduleName(std::move(data.releaseConditionScheduleName)),
            releaseConditionScheduleEventName(std::move(data.releaseConditionScheduleEventName)),
            priority(std::move(data.priority)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "showcaseItemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->showcaseItemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "category") == 0) {
                if (jsonValue.IsString())
                {
                    this->category.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemGroupName") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGroupName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "releaseConditionType") == 0) {
                if (jsonValue.IsString())
                {
                    this->releaseConditionType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "releaseConditionScheduleName") == 0) {
                if (jsonValue.IsString())
                {
                    this->releaseConditionScheduleName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "releaseConditionScheduleEventName") == 0) {
                if (jsonValue.IsString())
                {
                    this->releaseConditionScheduleEventName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "priority") == 0) {
                if (jsonValue.IsInt())
                {
                    this->priority = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
                }
            }
        }
    };
    
    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    ShowcaseItemMaster() :
        m_pData(nullptr)
    {}

    ShowcaseItemMaster(const ShowcaseItemMaster& showcaseItemMaster) :
        Gs2Object(showcaseItemMaster),
        m_pData(showcaseItemMaster.m_pData != nullptr ? new Data(*showcaseItemMaster.m_pData) : nullptr)
    {}

    ShowcaseItemMaster(ShowcaseItemMaster&& showcaseItemMaster) :
        Gs2Object(std::move(showcaseItemMaster)),
        m_pData(showcaseItemMaster.m_pData)
    {
        showcaseItemMaster.m_pData = nullptr;
    }

    ~ShowcaseItemMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ShowcaseItemMaster& operator=(const ShowcaseItemMaster& showcaseItemMaster)
    {
        Gs2Object::operator=(showcaseItemMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*showcaseItemMaster.m_pData);

        return *this;
    }

    ShowcaseItemMaster& operator=(ShowcaseItemMaster&& showcaseItemMaster)
    {
        Gs2Object::operator=(std::move(showcaseItemMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = showcaseItemMaster.m_pData;
        showcaseItemMaster.m_pData = nullptr;

        return *this;
    }

    const ShowcaseItemMaster* operator->() const
    {
        return this;
    }

    ShowcaseItemMaster* operator->()
    {
        return this;
    }


    /**
     * 陳列商品GRNを取得
     *
     * @return 陳列商品GRN
     */
    const optional<StringHolder>& getShowcaseItemId() const
    {
        return ensureData().showcaseItemId;
    }

    /**
     * 陳列商品GRNを設定
     *
     * @param showcaseItemId 陳列商品GRN
     */
    void setShowcaseItemId(const Char* showcaseItemId)
    {
        ensureData().showcaseItemId.emplace(showcaseItemId);
    }

    /**
     * 商品の種類を取得
     *
     * @return 商品の種類
     */
    const optional<StringHolder>& getCategory() const
    {
        return ensureData().category;
    }

    /**
     * 商品の種類を設定
     *
     * @param category 商品の種類
     */
    void setCategory(const Char* category)
    {
        ensureData().category.emplace(category);
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * 商品名を設定
     *
     * @param itemName 商品名
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getItemGroupName() const
    {
        return ensureData().itemGroupName;
    }

    /**
     * グループ名を設定
     *
     * @param itemGroupName グループ名
     */
    void setItemGroupName(const Char* itemGroupName)
    {
        ensureData().itemGroupName.emplace(itemGroupName);
    }

    /**
     * 公開判定の種類を取得
     *
     * @return 公開判定の種類
     */
    const optional<StringHolder>& getReleaseConditionType() const
    {
        return ensureData().releaseConditionType;
    }

    /**
     * 公開判定の種類を設定
     *
     * @param releaseConditionType 公開判定の種類
     */
    void setReleaseConditionType(const Char* releaseConditionType)
    {
        ensureData().releaseConditionType.emplace(releaseConditionType);
    }

    /**
     * 公開許可判定 に実行されるGS2-Scheduleを取得
     *
     * @return 公開許可判定 に実行されるGS2-Schedule
     */
    const optional<StringHolder>& getReleaseConditionScheduleName() const
    {
        return ensureData().releaseConditionScheduleName;
    }

    /**
     * 公開許可判定 に実行されるGS2-Scheduleを設定
     *
     * @param releaseConditionScheduleName 公開許可判定 に実行されるGS2-Schedule
     */
    void setReleaseConditionScheduleName(const Char* releaseConditionScheduleName)
    {
        ensureData().releaseConditionScheduleName.emplace(releaseConditionScheduleName);
    }

    /**
     * 公開許可判定 に実行されるGS2-Schedule のイベント名を取得
     *
     * @return 公開許可判定 に実行されるGS2-Schedule のイベント名
     */
    const optional<StringHolder>& getReleaseConditionScheduleEventName() const
    {
        return ensureData().releaseConditionScheduleEventName;
    }

    /**
     * 公開許可判定 に実行されるGS2-Schedule のイベント名を設定
     *
     * @param releaseConditionScheduleEventName 公開許可判定 に実行されるGS2-Schedule のイベント名
     */
    void setReleaseConditionScheduleEventName(const Char* releaseConditionScheduleEventName)
    {
        ensureData().releaseConditionScheduleEventName.emplace(releaseConditionScheduleEventName);
    }

    /**
     * 応答順序優先度を取得
     *
     * @return 応答順序優先度
     */
    const optional<Int32>& getPriority() const
    {
        return ensureData().priority;
    }

    /**
     * 応答順序優先度を設定
     *
     * @param priority 応答順序優先度
     */
    void setPriority(Int32 priority)
    {
        ensureData().priority.emplace(priority);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_MODEL_SHOWCASEITEMMASTER_HPP_