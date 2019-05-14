/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * 現在有効なディストリビューターマスターJSONを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentDistributorMasterRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
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
    UpdateCurrentDistributorMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCurrentDistributorMasterRequest(const UpdateCurrentDistributorMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCurrentDistributorMasterRequest(UpdateCurrentDistributorMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCurrentDistributorMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentDistributorMasterRequest& operator=(const UpdateCurrentDistributorMasterRequest& updateCurrentDistributorMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCurrentDistributorMasterRequest);
        Gs2Distributor::operator=(updateCurrentDistributorMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentDistributorMasterRequest.m_pData);

        return *this;
    }

    UpdateCurrentDistributorMasterRequest& operator=(UpdateCurrentDistributorMasterRequest&& updateCurrentDistributorMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCurrentDistributorMasterRequest));
        Gs2Distributor::operator=(std::move(updateCurrentDistributorMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentDistributorMasterRequest.m_pData;
        updateCurrentDistributorMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentDistributorMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentDistributorMasterRequest* operator->()
    {
        return this;
    }
    /**
     * ディストリビュータ名を取得
     *
     * @return ディストリビュータ名
     */
    const optional<StringHolder>& getDistributorName() const
    {
        return ensureData().distributorName;
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    void setDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    UpdateCurrentDistributorMasterRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }

    /**
     * マスターデータを取得
     *
     * @return マスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    void setSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    UpdateCurrentDistributorMasterRequest& withSettings(const Char* settings)
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
    UpdateCurrentDistributorMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateCurrentDistributorMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateCurrentDistributorMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentDistributorMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERREQUEST_HPP_