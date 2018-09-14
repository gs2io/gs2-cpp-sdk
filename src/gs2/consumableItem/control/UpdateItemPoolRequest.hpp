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

#ifndef GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMPOOLREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMPOOLREQUEST_HPP_

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
class UpdateItemPoolRequest : public Gs2BasicRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "UpdateItemPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** 更新する消費型アイテムプールの名前 */
        optional<StringHolder> itemPoolName;
        /** 説明文(1024文字以内) */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
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
            description(data.description),
            serviceClass(data.serviceClass),
            acquisitionItemTriggerScript(data.acquisitionItemTriggerScript),
            acquisitionItemDoneTriggerScript(data.acquisitionItemDoneTriggerScript),
            consumeItemTriggerScript(data.consumeItemTriggerScript),
            consumeItemDoneTriggerScript(data.consumeItemDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            itemPoolName(std::move(data.itemPoolName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
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
    UpdateItemPoolRequest() :
        m_pData(nullptr)
    {}

    UpdateItemPoolRequest(const UpdateItemPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateItemPoolRequest(UpdateItemPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateItemPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateItemPoolRequest& operator=(const UpdateItemPoolRequest& updateItemPoolRequest)
    {
        Gs2BasicRequest::operator=(updateItemPoolRequest);
        Gs2ConsumableItem::operator=(updateItemPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateItemPoolRequest.m_pData);

        return *this;
    }

    UpdateItemPoolRequest& operator=(UpdateItemPoolRequest&& updateItemPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateItemPoolRequest));
        Gs2ConsumableItem::operator=(std::move(updateItemPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateItemPoolRequest.m_pData;
        updateItemPoolRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateItemPoolRequest* operator->() const
    {
        return this;
    }

    UpdateItemPoolRequest* operator->()
    {
        return this;
    }

    /**
     * 更新する消費型アイテムプールの名前を取得
     *
     * @return 更新する消費型アイテムプールの名前
     */
    const optional<StringHolder>& getItemPoolName() const
    {
        return ensureData().itemPoolName;
    }

    /**
     * 更新する消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 更新する消費型アイテムプールの名前
     */
    void setItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
    }

    /**
     * 更新する消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 更新する消費型アイテムプールの名前
     */
    UpdateItemPoolRequest& withItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
        return *this;
    }

    /**
     * 説明文(1024文字以内)を取得
     *
     * @return 説明文(1024文字以内)
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文(1024文字以内)を設定
     *
     * @param description 説明文(1024文字以内)
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文(1024文字以内)を設定
     *
     * @param description 説明文(1024文字以内)
     */
    UpdateItemPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    UpdateItemPoolRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
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
    UpdateItemPoolRequest& withAcquisitionItemTriggerScript(const Char* acquisitionItemTriggerScript)
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
    UpdateItemPoolRequest& withAcquisitionItemDoneTriggerScript(const Char* acquisitionItemDoneTriggerScript)
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
    UpdateItemPoolRequest& withConsumeItemTriggerScript(const Char* consumeItemTriggerScript)
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
    UpdateItemPoolRequest& withConsumeItemDoneTriggerScript(const Char* consumeItemDoneTriggerScript)
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
    UpdateItemPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateItemPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateItemPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateItemPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CONSUMABLEITEM_CONTROL_UPDATEITEMPOOLREQUEST_HPP_