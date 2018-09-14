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

#ifndef GS2_STAMINA_CONTROL_CREATESTAMINAPOOLREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CREATESTAMINAPOOLREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * @author Game Server Services, Inc.
 */
class CreateStaminaPoolRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "CreateStaminaPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナプールの名前 */
        optional<StringHolder> name;
        /** スタミナプールの説明 */
        optional<StringHolder> description;
        /** スタミナプールのサービスクラス */
        optional<StringHolder> serviceClass;
        /** スタミナの回復速度(秒) */
        optional<Int32> increaseInterval;
        /** スタミナ消費時 に実行されるGS2-Script */
        optional<StringHolder> consumeStaminaTriggerScript;
        /** スタミナ消費完了時 に実行されるGS2-Script */
        optional<StringHolder> consumeStaminaDoneTriggerScript;
        /** スタミナ回復時 に実行されるGS2-Script */
        optional<StringHolder> addStaminaTriggerScript;
        /** スタミナ回復完了時 に実行されるGS2-Script */
        optional<StringHolder> addStaminaDoneTriggerScript;
        /** スタミナの最大値取得 に実行されるGS2-Script */
        optional<StringHolder> getMaxStaminaTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            increaseInterval(data.increaseInterval),
            consumeStaminaTriggerScript(data.consumeStaminaTriggerScript),
            consumeStaminaDoneTriggerScript(data.consumeStaminaDoneTriggerScript),
            addStaminaTriggerScript(data.addStaminaTriggerScript),
            addStaminaDoneTriggerScript(data.addStaminaDoneTriggerScript),
            getMaxStaminaTriggerScript(data.getMaxStaminaTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            increaseInterval(std::move(data.increaseInterval)),
            consumeStaminaTriggerScript(std::move(data.consumeStaminaTriggerScript)),
            consumeStaminaDoneTriggerScript(std::move(data.consumeStaminaDoneTriggerScript)),
            addStaminaTriggerScript(std::move(data.addStaminaTriggerScript)),
            addStaminaDoneTriggerScript(std::move(data.addStaminaDoneTriggerScript)),
            getMaxStaminaTriggerScript(std::move(data.getMaxStaminaTriggerScript))
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
    CreateStaminaPoolRequest() :
        m_pData(nullptr)
    {}

    CreateStaminaPoolRequest(const CreateStaminaPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateStaminaPoolRequest(CreateStaminaPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateStaminaPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateStaminaPoolRequest& operator=(const CreateStaminaPoolRequest& createStaminaPoolRequest)
    {
        Gs2BasicRequest::operator=(createStaminaPoolRequest);
        Gs2Stamina::operator=(createStaminaPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createStaminaPoolRequest.m_pData);

        return *this;
    }

    CreateStaminaPoolRequest& operator=(CreateStaminaPoolRequest&& createStaminaPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(createStaminaPoolRequest));
        Gs2Stamina::operator=(std::move(createStaminaPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createStaminaPoolRequest.m_pData;
        createStaminaPoolRequest.m_pData = nullptr;

        return *this;
    }

    const CreateStaminaPoolRequest* operator->() const
    {
        return this;
    }

    CreateStaminaPoolRequest* operator->()
    {
        return this;
    }

    /**
     * スタミナプールの名前を取得
     *
     * @return スタミナプールの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナプールの名前を設定
     *
     * @param name スタミナプールの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スタミナプールの名前を設定
     *
     * @param name スタミナプールの名前
     */
    CreateStaminaPoolRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * スタミナプールの説明を取得
     *
     * @return スタミナプールの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナプールの説明を設定
     *
     * @param description スタミナプールの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナプールの説明を設定
     *
     * @param description スタミナプールの説明
     */
    CreateStaminaPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * スタミナプールのサービスクラスを取得
     *
     * @return スタミナプールのサービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * スタミナプールのサービスクラスを設定
     *
     * @param serviceClass スタミナプールのサービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * スタミナプールのサービスクラスを設定
     *
     * @param serviceClass スタミナプールのサービスクラス
     */
    CreateStaminaPoolRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * スタミナの回復速度(秒)を取得
     *
     * @return スタミナの回復速度(秒)
     */
    const optional<Int32>& getIncreaseInterval() const
    {
        return ensureData().increaseInterval;
    }

    /**
     * スタミナの回復速度(秒)を設定
     *
     * @param increaseInterval スタミナの回復速度(秒)
     */
    void setIncreaseInterval(Int32 increaseInterval)
    {
        ensureData().increaseInterval.emplace(increaseInterval);
    }

    /**
     * スタミナの回復速度(秒)を設定
     *
     * @param increaseInterval スタミナの回復速度(秒)
     */
    CreateStaminaPoolRequest& withIncreaseInterval(Int32 increaseInterval)
    {
        ensureData().increaseInterval.emplace(increaseInterval);
        return *this;
    }

    /**
     * スタミナ消費時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ消費時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeStaminaTriggerScript() const
    {
        return ensureData().consumeStaminaTriggerScript;
    }

    /**
     * スタミナ消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaTriggerScript スタミナ消費時 に実行されるGS2-Script
     */
    void setConsumeStaminaTriggerScript(const Char* consumeStaminaTriggerScript)
    {
        ensureData().consumeStaminaTriggerScript.emplace(consumeStaminaTriggerScript);
    }

    /**
     * スタミナ消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaTriggerScript スタミナ消費時 に実行されるGS2-Script
     */
    CreateStaminaPoolRequest& withConsumeStaminaTriggerScript(const Char* consumeStaminaTriggerScript)
    {
        ensureData().consumeStaminaTriggerScript.emplace(consumeStaminaTriggerScript);
        return *this;
    }

    /**
     * スタミナ消費完了時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ消費完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeStaminaDoneTriggerScript() const
    {
        return ensureData().consumeStaminaDoneTriggerScript;
    }

    /**
     * スタミナ消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaDoneTriggerScript スタミナ消費完了時 に実行されるGS2-Script
     */
    void setConsumeStaminaDoneTriggerScript(const Char* consumeStaminaDoneTriggerScript)
    {
        ensureData().consumeStaminaDoneTriggerScript.emplace(consumeStaminaDoneTriggerScript);
    }

    /**
     * スタミナ消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaDoneTriggerScript スタミナ消費完了時 に実行されるGS2-Script
     */
    CreateStaminaPoolRequest& withConsumeStaminaDoneTriggerScript(const Char* consumeStaminaDoneTriggerScript)
    {
        ensureData().consumeStaminaDoneTriggerScript.emplace(consumeStaminaDoneTriggerScript);
        return *this;
    }

    /**
     * スタミナ回復時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ回復時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAddStaminaTriggerScript() const
    {
        return ensureData().addStaminaTriggerScript;
    }

    /**
     * スタミナ回復時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaTriggerScript スタミナ回復時 に実行されるGS2-Script
     */
    void setAddStaminaTriggerScript(const Char* addStaminaTriggerScript)
    {
        ensureData().addStaminaTriggerScript.emplace(addStaminaTriggerScript);
    }

    /**
     * スタミナ回復時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaTriggerScript スタミナ回復時 に実行されるGS2-Script
     */
    CreateStaminaPoolRequest& withAddStaminaTriggerScript(const Char* addStaminaTriggerScript)
    {
        ensureData().addStaminaTriggerScript.emplace(addStaminaTriggerScript);
        return *this;
    }

    /**
     * スタミナ回復完了時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ回復完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAddStaminaDoneTriggerScript() const
    {
        return ensureData().addStaminaDoneTriggerScript;
    }

    /**
     * スタミナ回復完了時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaDoneTriggerScript スタミナ回復完了時 に実行されるGS2-Script
     */
    void setAddStaminaDoneTriggerScript(const Char* addStaminaDoneTriggerScript)
    {
        ensureData().addStaminaDoneTriggerScript.emplace(addStaminaDoneTriggerScript);
    }

    /**
     * スタミナ回復完了時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaDoneTriggerScript スタミナ回復完了時 に実行されるGS2-Script
     */
    CreateStaminaPoolRequest& withAddStaminaDoneTriggerScript(const Char* addStaminaDoneTriggerScript)
    {
        ensureData().addStaminaDoneTriggerScript.emplace(addStaminaDoneTriggerScript);
        return *this;
    }

    /**
     * スタミナの最大値取得 に実行されるGS2-Scriptを取得
     *
     * @return スタミナの最大値取得 に実行されるGS2-Script
     */
    const optional<StringHolder>& getGetMaxStaminaTriggerScript() const
    {
        return ensureData().getMaxStaminaTriggerScript;
    }

    /**
     * スタミナの最大値取得 に実行されるGS2-Scriptを設定
     *
     * @param getMaxStaminaTriggerScript スタミナの最大値取得 に実行されるGS2-Script
     */
    void setGetMaxStaminaTriggerScript(const Char* getMaxStaminaTriggerScript)
    {
        ensureData().getMaxStaminaTriggerScript.emplace(getMaxStaminaTriggerScript);
    }

    /**
     * スタミナの最大値取得 に実行されるGS2-Scriptを設定
     *
     * @param getMaxStaminaTriggerScript スタミナの最大値取得 に実行されるGS2-Script
     */
    CreateStaminaPoolRequest& withGetMaxStaminaTriggerScript(const Char* getMaxStaminaTriggerScript)
    {
        ensureData().getMaxStaminaTriggerScript.emplace(getMaxStaminaTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateStaminaPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateStaminaPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateStaminaPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateStaminaPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_CREATESTAMINAPOOLREQUEST_HPP_