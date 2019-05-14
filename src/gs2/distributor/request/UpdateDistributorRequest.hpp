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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ディストリビュータを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateDistributorRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** ディストリビュータの説明 */
        optional<StringHolder> description;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            description(data.description)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
            description(std::move(data.description))
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
    UpdateDistributorRequest() :
        m_pData(nullptr)
    {}

    UpdateDistributorRequest(const UpdateDistributorRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateDistributorRequest(UpdateDistributorRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateDistributorRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateDistributorRequest& operator=(const UpdateDistributorRequest& updateDistributorRequest)
    {
        Gs2BasicRequest::operator=(updateDistributorRequest);
        Gs2Distributor::operator=(updateDistributorRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateDistributorRequest.m_pData);

        return *this;
    }

    UpdateDistributorRequest& operator=(UpdateDistributorRequest&& updateDistributorRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateDistributorRequest));
        Gs2Distributor::operator=(std::move(updateDistributorRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateDistributorRequest.m_pData;
        updateDistributorRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateDistributorRequest* operator->() const
    {
        return this;
    }

    UpdateDistributorRequest* operator->()
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
    UpdateDistributorRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }

    /**
     * ディストリビュータの説明を取得
     *
     * @return ディストリビュータの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ディストリビュータの説明を設定
     *
     * @param description ディストリビュータの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ディストリビュータの説明を設定
     *
     * @param description ディストリビュータの説明
     */
    UpdateDistributorRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateDistributorRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateDistributorRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateDistributorRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateDistributorRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORREQUEST_HPP_