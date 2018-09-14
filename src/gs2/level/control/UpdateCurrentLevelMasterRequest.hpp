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

#ifndef GS2_LEVEL_CONTROL_UPDATECURRENTLEVELMASTERREQUEST_HPP_
#define GS2_LEVEL_CONTROL_UPDATECURRENTLEVELMASTERREQUEST_HPP_

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
class UpdateCurrentLevelMasterRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "UpdateCurrentLevelMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** レベルマスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
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
    UpdateCurrentLevelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCurrentLevelMasterRequest(const UpdateCurrentLevelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCurrentLevelMasterRequest(UpdateCurrentLevelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCurrentLevelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentLevelMasterRequest& operator=(const UpdateCurrentLevelMasterRequest& updateCurrentLevelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCurrentLevelMasterRequest);
        Gs2Level::operator=(updateCurrentLevelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentLevelMasterRequest.m_pData);

        return *this;
    }

    UpdateCurrentLevelMasterRequest& operator=(UpdateCurrentLevelMasterRequest&& updateCurrentLevelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCurrentLevelMasterRequest));
        Gs2Level::operator=(std::move(updateCurrentLevelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentLevelMasterRequest.m_pData;
        updateCurrentLevelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentLevelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentLevelMasterRequest* operator->()
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
    UpdateCurrentLevelMasterRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * レベルマスターデータを取得
     *
     * @return レベルマスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * レベルマスターデータを設定
     *
     * @param settings レベルマスターデータ
     */
    void setSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
    }

    /**
     * レベルマスターデータを設定
     *
     * @param settings レベルマスターデータ
     */
    UpdateCurrentLevelMasterRequest& withSettings(const Char* settings)
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
    UpdateCurrentLevelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateCurrentLevelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateCurrentLevelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentLevelMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_UPDATECURRENTLEVELMASTERREQUEST_HPP_