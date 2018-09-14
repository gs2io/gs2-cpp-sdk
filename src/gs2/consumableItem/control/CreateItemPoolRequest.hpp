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

#ifndef GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLREQUEST_HPP_

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
class CreateItemPoolRequest : public Gs2BasicRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "CreateItemPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** 仮想通貨名 */
        optional<StringHolder> name;
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
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            acquisitionItemTriggerScript(data.acquisitionItemTriggerScript),
            acquisitionItemDoneTriggerScript(data.acquisitionItemDoneTriggerScript),
            consumeItemTriggerScript(data.consumeItemTriggerScript),
            consumeItemDoneTriggerScript(data.consumeItemDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
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
    CreateItemPoolRequest() :
        m_pData(nullptr)
    {}

    CreateItemPoolRequest(const CreateItemPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateItemPoolRequest(CreateItemPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateItemPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemPoolRequest& operator=(const CreateItemPoolRequest& createItemPoolRequest)
    {
        Gs2BasicRequest::operator=(createItemPoolRequest);
        Gs2ConsumableItem::operator=(createItemPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemPoolRequest.m_pData);

        return *this;
    }

    CreateItemPoolRequest& operator=(CreateItemPoolRequest&& createItemPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(createItemPoolRequest));
        Gs2ConsumableItem::operator=(std::move(createItemPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemPoolRequest.m_pData;
        createItemPoolRequest.m_pData = nullptr;

        return *this;
    }

    const CreateItemPoolRequest* operator->() const
    {
        return this;
    }

    CreateItemPoolRequest* operator->()
    {
        return this;
    }

    /**
     * 仮想通貨名を取得
     *
     * @return 仮想通貨名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 仮想通貨名を設定
     *
     * @param name 仮想通貨名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 仮想通貨名を設定
     *
     * @param name 仮想通貨名
     */
    CreateItemPoolRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateItemPoolRequest& withDescription(const Char* description)
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
    CreateItemPoolRequest& withServiceClass(const Char* serviceClass)
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
    CreateItemPoolRequest& withAcquisitionItemTriggerScript(const Char* acquisitionItemTriggerScript)
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
    CreateItemPoolRequest& withAcquisitionItemDoneTriggerScript(const Char* acquisitionItemDoneTriggerScript)
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
    CreateItemPoolRequest& withConsumeItemTriggerScript(const Char* consumeItemTriggerScript)
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
    CreateItemPoolRequest& withConsumeItemDoneTriggerScript(const Char* consumeItemDoneTriggerScript)
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
    CreateItemPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateItemPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateItemPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateItemPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLREQUEST_HPP_