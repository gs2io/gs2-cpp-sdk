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

#ifndef GS2_LEVEL_CONTROL_UPDATERESOURCEPOOLREQUEST_HPP_
#define GS2_LEVEL_CONTROL_UPDATERESOURCEPOOLREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateResourcePoolRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "UpdateResourcePool";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** レベルキャップ取得時 に実行されるGS2-Script */
        optional<StringHolder> levelCapScript;
        /** 経験値変化時 に実行されるGS2-Script */
        optional<StringHolder> changeExperienceTriggerScript;
        /** 経験値変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeExperienceDoneTriggerScript;
        /** レベル変化時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelTriggerScript;
        /** レベル変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelDoneTriggerScript;
        /** レベルキャップ変化時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelCapTriggerScript;
        /** レベルキャップ変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelCapDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            description(data.description),
            serviceClass(data.serviceClass),
            levelCapScript(data.levelCapScript),
            changeExperienceTriggerScript(data.changeExperienceTriggerScript),
            changeExperienceDoneTriggerScript(data.changeExperienceDoneTriggerScript),
            changeLevelTriggerScript(data.changeLevelTriggerScript),
            changeLevelDoneTriggerScript(data.changeLevelDoneTriggerScript),
            changeLevelCapTriggerScript(data.changeLevelCapTriggerScript),
            changeLevelCapDoneTriggerScript(data.changeLevelCapDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            levelCapScript(std::move(data.levelCapScript)),
            changeExperienceTriggerScript(std::move(data.changeExperienceTriggerScript)),
            changeExperienceDoneTriggerScript(std::move(data.changeExperienceDoneTriggerScript)),
            changeLevelTriggerScript(std::move(data.changeLevelTriggerScript)),
            changeLevelDoneTriggerScript(std::move(data.changeLevelDoneTriggerScript)),
            changeLevelCapTriggerScript(std::move(data.changeLevelCapTriggerScript)),
            changeLevelCapDoneTriggerScript(std::move(data.changeLevelCapDoneTriggerScript))
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
    UpdateResourcePoolRequest() :
        m_pData(nullptr)
    {}

    UpdateResourcePoolRequest(const UpdateResourcePoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateResourcePoolRequest(UpdateResourcePoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateResourcePoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateResourcePoolRequest& operator=(const UpdateResourcePoolRequest& updateResourcePoolRequest)
    {
        Gs2BasicRequest::operator=(updateResourcePoolRequest);
        Gs2Level::operator=(updateResourcePoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateResourcePoolRequest.m_pData);

        return *this;
    }

    UpdateResourcePoolRequest& operator=(UpdateResourcePoolRequest&& updateResourcePoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateResourcePoolRequest));
        Gs2Level::operator=(std::move(updateResourcePoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateResourcePoolRequest.m_pData;
        updateResourcePoolRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateResourcePoolRequest* operator->() const
    {
        return this;
    }

    UpdateResourcePoolRequest* operator->()
    {
        return this;
    }

    /**
     * リソースプールを取得
     *
     * @return リソースプール
     */
    const optional<StringHolder>& getResourcePoolName() const
    {
        return ensureData().resourcePoolName;
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    void setResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    UpdateResourcePoolRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateResourcePoolRequest& withDescription(const Char* description)
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
    UpdateResourcePoolRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * レベルキャップ取得時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ取得時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getLevelCapScript() const
    {
        return ensureData().levelCapScript;
    }

    /**
     * レベルキャップ取得時 に実行されるGS2-Scriptを設定
     *
     * @param levelCapScript レベルキャップ取得時 に実行されるGS2-Script
     */
    void setLevelCapScript(const Char* levelCapScript)
    {
        ensureData().levelCapScript.emplace(levelCapScript);
    }

    /**
     * レベルキャップ取得時 に実行されるGS2-Scriptを設定
     *
     * @param levelCapScript レベルキャップ取得時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withLevelCapScript(const Char* levelCapScript)
    {
        ensureData().levelCapScript.emplace(levelCapScript);
        return *this;
    }

    /**
     * 経験値変化時 に実行されるGS2-Scriptを取得
     *
     * @return 経験値変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeExperienceTriggerScript() const
    {
        return ensureData().changeExperienceTriggerScript;
    }

    /**
     * 経験値変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceTriggerScript 経験値変化時 に実行されるGS2-Script
     */
    void setChangeExperienceTriggerScript(const Char* changeExperienceTriggerScript)
    {
        ensureData().changeExperienceTriggerScript.emplace(changeExperienceTriggerScript);
    }

    /**
     * 経験値変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceTriggerScript 経験値変化時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeExperienceTriggerScript(const Char* changeExperienceTriggerScript)
    {
        ensureData().changeExperienceTriggerScript.emplace(changeExperienceTriggerScript);
        return *this;
    }

    /**
     * 経験値変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return 経験値変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeExperienceDoneTriggerScript() const
    {
        return ensureData().changeExperienceDoneTriggerScript;
    }

    /**
     * 経験値変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceDoneTriggerScript 経験値変化完了時 に実行されるGS2-Script
     */
    void setChangeExperienceDoneTriggerScript(const Char* changeExperienceDoneTriggerScript)
    {
        ensureData().changeExperienceDoneTriggerScript.emplace(changeExperienceDoneTriggerScript);
    }

    /**
     * 経験値変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceDoneTriggerScript 経験値変化完了時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeExperienceDoneTriggerScript(const Char* changeExperienceDoneTriggerScript)
    {
        ensureData().changeExperienceDoneTriggerScript.emplace(changeExperienceDoneTriggerScript);
        return *this;
    }

    /**
     * レベル変化時 に実行されるGS2-Scriptを取得
     *
     * @return レベル変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelTriggerScript() const
    {
        return ensureData().changeLevelTriggerScript;
    }

    /**
     * レベル変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelTriggerScript レベル変化時 に実行されるGS2-Script
     */
    void setChangeLevelTriggerScript(const Char* changeLevelTriggerScript)
    {
        ensureData().changeLevelTriggerScript.emplace(changeLevelTriggerScript);
    }

    /**
     * レベル変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelTriggerScript レベル変化時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeLevelTriggerScript(const Char* changeLevelTriggerScript)
    {
        ensureData().changeLevelTriggerScript.emplace(changeLevelTriggerScript);
        return *this;
    }

    /**
     * レベル変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return レベル変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelDoneTriggerScript() const
    {
        return ensureData().changeLevelDoneTriggerScript;
    }

    /**
     * レベル変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelDoneTriggerScript レベル変化完了時 に実行されるGS2-Script
     */
    void setChangeLevelDoneTriggerScript(const Char* changeLevelDoneTriggerScript)
    {
        ensureData().changeLevelDoneTriggerScript.emplace(changeLevelDoneTriggerScript);
    }

    /**
     * レベル変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelDoneTriggerScript レベル変化完了時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeLevelDoneTriggerScript(const Char* changeLevelDoneTriggerScript)
    {
        ensureData().changeLevelDoneTriggerScript.emplace(changeLevelDoneTriggerScript);
        return *this;
    }

    /**
     * レベルキャップ変化時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelCapTriggerScript() const
    {
        return ensureData().changeLevelCapTriggerScript;
    }

    /**
     * レベルキャップ変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapTriggerScript レベルキャップ変化時 に実行されるGS2-Script
     */
    void setChangeLevelCapTriggerScript(const Char* changeLevelCapTriggerScript)
    {
        ensureData().changeLevelCapTriggerScript.emplace(changeLevelCapTriggerScript);
    }

    /**
     * レベルキャップ変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapTriggerScript レベルキャップ変化時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeLevelCapTriggerScript(const Char* changeLevelCapTriggerScript)
    {
        ensureData().changeLevelCapTriggerScript.emplace(changeLevelCapTriggerScript);
        return *this;
    }

    /**
     * レベルキャップ変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelCapDoneTriggerScript() const
    {
        return ensureData().changeLevelCapDoneTriggerScript;
    }

    /**
     * レベルキャップ変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapDoneTriggerScript レベルキャップ変化完了時 に実行されるGS2-Script
     */
    void setChangeLevelCapDoneTriggerScript(const Char* changeLevelCapDoneTriggerScript)
    {
        ensureData().changeLevelCapDoneTriggerScript.emplace(changeLevelCapDoneTriggerScript);
    }

    /**
     * レベルキャップ変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapDoneTriggerScript レベルキャップ変化完了時 に実行されるGS2-Script
     */
    UpdateResourcePoolRequest& withChangeLevelCapDoneTriggerScript(const Char* changeLevelCapDoneTriggerScript)
    {
        ensureData().changeLevelCapDoneTriggerScript.emplace(changeLevelCapDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateResourcePoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateResourcePoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateResourcePoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateResourcePoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_UPDATERESOURCEPOOLREQUEST_HPP_