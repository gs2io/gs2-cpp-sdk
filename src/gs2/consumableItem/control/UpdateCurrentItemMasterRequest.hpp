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

#ifndef GS2_CONSUMABLEITEM_CONTROL_UPDATECURRENTITEMMASTERREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_UPDATECURRENTITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ConsumableItemConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace consumableItem
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateCurrentItemMasterRequest : public Gs2BasicRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "UpdateCurrentItemMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** アイテムプールの名前を指定します。 */
        optional<StringHolder> itemPoolName;
        /** アイテムマスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            itemPoolName(data.itemPoolName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            itemPoolName(std::move(data.itemPoolName)),
            settings(std::move(data.settings))
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
    UpdateCurrentItemMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCurrentItemMasterRequest(const UpdateCurrentItemMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCurrentItemMasterRequest(UpdateCurrentItemMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCurrentItemMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentItemMasterRequest& operator=(const UpdateCurrentItemMasterRequest& updateCurrentItemMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCurrentItemMasterRequest);
        Gs2ConsumableItem::operator=(updateCurrentItemMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentItemMasterRequest.m_pData);

        return *this;
    }

    UpdateCurrentItemMasterRequest& operator=(UpdateCurrentItemMasterRequest&& updateCurrentItemMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCurrentItemMasterRequest));
        Gs2ConsumableItem::operator=(std::move(updateCurrentItemMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentItemMasterRequest.m_pData;
        updateCurrentItemMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentItemMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * アイテムプールの名前を指定します。を取得
     *
     * @return アイテムプールの名前を指定します。
     */
    const optional<StringHolder>& getItemPoolName() const
    {
        return ensureData().itemPoolName;
    }

    /**
     * アイテムプールの名前を指定します。を設定
     *
     * @param itemPoolName アイテムプールの名前を指定します。
     */
    void setItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
    }

    /**
     * アイテムプールの名前を指定します。を設定
     *
     * @param itemPoolName アイテムプールの名前を指定します。
     */
    UpdateCurrentItemMasterRequest& withItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
        return *this;
    }

    /**
     * アイテムマスターデータを取得
     *
     * @return アイテムマスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * アイテムマスターデータを設定
     *
     * @param settings アイテムマスターデータ
     */
    void setSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
    }

    /**
     * アイテムマスターデータを設定
     *
     * @param settings アイテムマスターデータ
     */
    UpdateCurrentItemMasterRequest& withSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCurrentItemMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateCurrentItemMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateCurrentItemMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentItemMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CONSUMABLEITEM_CONTROL_UPDATECURRENTITEMMASTERREQUEST_HPP_