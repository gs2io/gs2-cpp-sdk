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

#ifndef GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class CreateShowcaseItemMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "CreateShowcaseItemMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            category(data.category),
            itemName(data.itemName),
            itemGroupName(data.itemGroupName),
            releaseConditionType(data.releaseConditionType),
            releaseConditionScheduleName(data.releaseConditionScheduleName),
            releaseConditionScheduleEventName(data.releaseConditionScheduleEventName),
            priority(data.priority)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            category(std::move(data.category)),
            itemName(std::move(data.itemName)),
            itemGroupName(std::move(data.itemGroupName)),
            releaseConditionType(std::move(data.releaseConditionType)),
            releaseConditionScheduleName(std::move(data.releaseConditionScheduleName)),
            releaseConditionScheduleEventName(std::move(data.releaseConditionScheduleEventName)),
            priority(std::move(data.priority))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    CreateShowcaseItemMasterRequest() :
        m_pData(nullptr)
    {}

    CreateShowcaseItemMasterRequest(const CreateShowcaseItemMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateShowcaseItemMasterRequest(CreateShowcaseItemMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateShowcaseItemMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateShowcaseItemMasterRequest& operator=(const CreateShowcaseItemMasterRequest& createShowcaseItemMasterRequest)
    {
        Gs2BasicRequest::operator=(createShowcaseItemMasterRequest);
        Gs2Showcase::operator=(createShowcaseItemMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createShowcaseItemMasterRequest.m_pData);

        return *this;
    }

    CreateShowcaseItemMasterRequest& operator=(CreateShowcaseItemMasterRequest&& createShowcaseItemMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createShowcaseItemMasterRequest));
        Gs2Showcase::operator=(std::move(createShowcaseItemMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createShowcaseItemMasterRequest.m_pData;
        createShowcaseItemMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateShowcaseItemMasterRequest* operator->() const
    {
        return this;
    }

    CreateShowcaseItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ショーケースの名前を取得
     *
     * @return ショーケースの名前
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    CreateShowcaseItemMasterRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
        return *this;
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
     * 商品の種類を設定
     *
     * @param category 商品の種類
     */
    CreateShowcaseItemMasterRequest& withCategory(const Char* category)
    {
        ensureData().category.emplace(category);
        return *this;
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
     * 商品名を設定
     *
     * @param itemName 商品名
     */
    CreateShowcaseItemMasterRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
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
     * グループ名を設定
     *
     * @param itemGroupName グループ名
     */
    CreateShowcaseItemMasterRequest& withItemGroupName(const Char* itemGroupName)
    {
        ensureData().itemGroupName.emplace(itemGroupName);
        return *this;
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
     * 公開判定の種類を設定
     *
     * @param releaseConditionType 公開判定の種類
     */
    CreateShowcaseItemMasterRequest& withReleaseConditionType(const Char* releaseConditionType)
    {
        ensureData().releaseConditionType.emplace(releaseConditionType);
        return *this;
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
     * 公開許可判定 に実行されるGS2-Scheduleを設定
     *
     * @param releaseConditionScheduleName 公開許可判定 に実行されるGS2-Schedule
     */
    CreateShowcaseItemMasterRequest& withReleaseConditionScheduleName(const Char* releaseConditionScheduleName)
    {
        ensureData().releaseConditionScheduleName.emplace(releaseConditionScheduleName);
        return *this;
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
     * 公開許可判定 に実行されるGS2-Schedule のイベント名を設定
     *
     * @param releaseConditionScheduleEventName 公開許可判定 に実行されるGS2-Schedule のイベント名
     */
    CreateShowcaseItemMasterRequest& withReleaseConditionScheduleEventName(const Char* releaseConditionScheduleEventName)
    {
        ensureData().releaseConditionScheduleEventName.emplace(releaseConditionScheduleEventName);
        return *this;
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
     * 応答順序優先度を設定
     *
     * @param priority 応答順序優先度
     */
    CreateShowcaseItemMasterRequest& withPriority(Int32 priority)
    {
        ensureData().priority.emplace(priority);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateShowcaseItemMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateShowcaseItemMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateShowcaseItemMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateShowcaseItemMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERREQUEST_HPP_