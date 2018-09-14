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

#ifndef GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMMASTERREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMMASTERREQUEST_HPP_

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
class UpdateItemMasterRequest : public Gs2BasicRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "UpdateItemMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** 消費型アイテムプールの名前 */
        optional<StringHolder> itemPoolName;
        /** 消費型アイテムの名前 */
        optional<StringHolder> itemName;
        /** 最大所持数。 */
        optional<Int32> max;
        /** アイテム入手時 に実行されるGS2-Script */
        optional<StringHolder> acquisitionItemTriggerScript;
        /** アイテム入手完了時 に実行されるGS2-Script */
        optional<StringHolder> acquisitionItemDoneTriggerScript;
        /** アイテム消費時 に実行されるGS2-Script */
        optional<StringHolder> consumeItemTriggerScript;
        /** アイテム消費完了時 に実行されるGS2-Script */
        optional<StringHolder> consumeItemDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            itemPoolName(data.itemPoolName),
            itemName(data.itemName),
            max(data.max),
            acquisitionItemTriggerScript(data.acquisitionItemTriggerScript),
            acquisitionItemDoneTriggerScript(data.acquisitionItemDoneTriggerScript),
            consumeItemTriggerScript(data.consumeItemTriggerScript),
            consumeItemDoneTriggerScript(data.consumeItemDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            itemPoolName(std::move(data.itemPoolName)),
            itemName(std::move(data.itemName)),
            max(std::move(data.max)),
            acquisitionItemTriggerScript(std::move(data.acquisitionItemTriggerScript)),
            acquisitionItemDoneTriggerScript(std::move(data.acquisitionItemDoneTriggerScript)),
            consumeItemTriggerScript(std::move(data.consumeItemTriggerScript)),
            consumeItemDoneTriggerScript(std::move(data.consumeItemDoneTriggerScript))
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
    UpdateItemMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateItemMasterRequest(const UpdateItemMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateItemMasterRequest(UpdateItemMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateItemMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateItemMasterRequest& operator=(const UpdateItemMasterRequest& updateItemMasterRequest)
    {
        Gs2BasicRequest::operator=(updateItemMasterRequest);
        Gs2ConsumableItem::operator=(updateItemMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateItemMasterRequest.m_pData);

        return *this;
    }

    UpdateItemMasterRequest& operator=(UpdateItemMasterRequest&& updateItemMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateItemMasterRequest));
        Gs2ConsumableItem::operator=(std::move(updateItemMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateItemMasterRequest.m_pData;
        updateItemMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateItemMasterRequest* operator->() const
    {
        return this;
    }

    UpdateItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * 消費型アイテムプールの名前を取得
     *
     * @return 消費型アイテムプールの名前
     */
    const optional<StringHolder>& getItemPoolName() const
    {
        return ensureData().itemPoolName;
    }

    /**
     * 消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 消費型アイテムプールの名前
     */
    void setItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
    }

    /**
     * 消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 消費型アイテムプールの名前
     */
    UpdateItemMasterRequest& withItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
        return *this;
    }

    /**
     * 消費型アイテムの名前を取得
     *
     * @return 消費型アイテムの名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * 消費型アイテムの名前を設定
     *
     * @param itemName 消費型アイテムの名前
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * 消費型アイテムの名前を設定
     *
     * @param itemName 消費型アイテムの名前
     */
    UpdateItemMasterRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * 最大所持数。を取得
     *
     * @return 最大所持数。
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * 最大所持数。を設定
     *
     * @param max 最大所持数。
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
    }

    /**
     * 最大所持数。を設定
     *
     * @param max 最大所持数。
     */
    UpdateItemMasterRequest& withMax(Int32 max)
    {
        ensureData().max.emplace(max);
        return *this;
    }

    /**
     * アイテム入手時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム入手時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAcquisitionItemTriggerScript() const
    {
        return ensureData().acquisitionItemTriggerScript;
    }

    /**
     * アイテム入手時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemTriggerScript アイテム入手時 に実行されるGS2-Script
     */
    void setAcquisitionItemTriggerScript(const Char* acquisitionItemTriggerScript)
    {
        ensureData().acquisitionItemTriggerScript.emplace(acquisitionItemTriggerScript);
    }

    /**
     * アイテム入手時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemTriggerScript アイテム入手時 に実行されるGS2-Script
     */
    UpdateItemMasterRequest& withAcquisitionItemTriggerScript(const Char* acquisitionItemTriggerScript)
    {
        ensureData().acquisitionItemTriggerScript.emplace(acquisitionItemTriggerScript);
        return *this;
    }

    /**
     * アイテム入手完了時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム入手完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAcquisitionItemDoneTriggerScript() const
    {
        return ensureData().acquisitionItemDoneTriggerScript;
    }

    /**
     * アイテム入手完了時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemDoneTriggerScript アイテム入手完了時 に実行されるGS2-Script
     */
    void setAcquisitionItemDoneTriggerScript(const Char* acquisitionItemDoneTriggerScript)
    {
        ensureData().acquisitionItemDoneTriggerScript.emplace(acquisitionItemDoneTriggerScript);
    }

    /**
     * アイテム入手完了時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemDoneTriggerScript アイテム入手完了時 に実行されるGS2-Script
     */
    UpdateItemMasterRequest& withAcquisitionItemDoneTriggerScript(const Char* acquisitionItemDoneTriggerScript)
    {
        ensureData().acquisitionItemDoneTriggerScript.emplace(acquisitionItemDoneTriggerScript);
        return *this;
    }

    /**
     * アイテム消費時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム消費時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeItemTriggerScript() const
    {
        return ensureData().consumeItemTriggerScript;
    }

    /**
     * アイテム消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemTriggerScript アイテム消費時 に実行されるGS2-Script
     */
    void setConsumeItemTriggerScript(const Char* consumeItemTriggerScript)
    {
        ensureData().consumeItemTriggerScript.emplace(consumeItemTriggerScript);
    }

    /**
     * アイテム消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemTriggerScript アイテム消費時 に実行されるGS2-Script
     */
    UpdateItemMasterRequest& withConsumeItemTriggerScript(const Char* consumeItemTriggerScript)
    {
        ensureData().consumeItemTriggerScript.emplace(consumeItemTriggerScript);
        return *this;
    }

    /**
     * アイテム消費完了時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム消費完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeItemDoneTriggerScript() const
    {
        return ensureData().consumeItemDoneTriggerScript;
    }

    /**
     * アイテム消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemDoneTriggerScript アイテム消費完了時 に実行されるGS2-Script
     */
    void setConsumeItemDoneTriggerScript(const Char* consumeItemDoneTriggerScript)
    {
        ensureData().consumeItemDoneTriggerScript.emplace(consumeItemDoneTriggerScript);
    }

    /**
     * アイテム消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemDoneTriggerScript アイテム消費完了時 に実行されるGS2-Script
     */
    UpdateItemMasterRequest& withConsumeItemDoneTriggerScript(const Char* consumeItemDoneTriggerScript)
    {
        ensureData().consumeItemDoneTriggerScript.emplace(consumeItemDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateItemMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateItemMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateItemMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateItemMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMMASTERREQUEST_HPP_