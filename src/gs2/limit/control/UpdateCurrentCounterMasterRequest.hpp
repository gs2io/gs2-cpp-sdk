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

#ifndef GS2_LIMIT_CONTROL_UPDATECURRENTCOUNTERMASTERREQUEST_HPP_
#define GS2_LIMIT_CONTROL_UPDATECURRENTCOUNTERMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LimitConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateCurrentCounterMasterRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "UpdateCurrentCounterMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** 回数制限の名前を指定します。 */
        optional<StringHolder> limitName;
        /** カウンターマスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            limitName(data.limitName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            limitName(std::move(data.limitName)),
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
    UpdateCurrentCounterMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCurrentCounterMasterRequest(const UpdateCurrentCounterMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Limit(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCurrentCounterMasterRequest(UpdateCurrentCounterMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Limit(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCurrentCounterMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentCounterMasterRequest& operator=(const UpdateCurrentCounterMasterRequest& updateCurrentCounterMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCurrentCounterMasterRequest);
        Gs2Limit::operator=(updateCurrentCounterMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentCounterMasterRequest.m_pData);

        return *this;
    }

    UpdateCurrentCounterMasterRequest& operator=(UpdateCurrentCounterMasterRequest&& updateCurrentCounterMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCurrentCounterMasterRequest));
        Gs2Limit::operator=(std::move(updateCurrentCounterMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentCounterMasterRequest.m_pData;
        updateCurrentCounterMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentCounterMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentCounterMasterRequest* operator->()
    {
        return this;
    }

    /**
     * 回数制限の名前を指定します。を取得
     *
     * @return 回数制限の名前を指定します。
     */
    const optional<StringHolder>& getLimitName() const
    {
        return ensureData().limitName;
    }

    /**
     * 回数制限の名前を指定します。を設定
     *
     * @param limitName 回数制限の名前を指定します。
     */
    void setLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
    }

    /**
     * 回数制限の名前を指定します。を設定
     *
     * @param limitName 回数制限の名前を指定します。
     */
    UpdateCurrentCounterMasterRequest& withLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
        return *this;
    }

    /**
     * カウンターマスターデータを取得
     *
     * @return カウンターマスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * カウンターマスターデータを設定
     *
     * @param settings カウンターマスターデータ
     */
    void setSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
    }

    /**
     * カウンターマスターデータを設定
     *
     * @param settings カウンターマスターデータ
     */
    UpdateCurrentCounterMasterRequest& withSettings(const Char* settings)
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
    UpdateCurrentCounterMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateCurrentCounterMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateCurrentCounterMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentCounterMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LIMIT_CONTROL_UPDATECURRENTCOUNTERMASTERREQUEST_HPP_