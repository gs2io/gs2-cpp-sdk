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

#ifndef GS2_DISTRIBUTOR_CONTROL_DESCRIBEDISTRIBUTORMODELSREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DESCRIBEDISTRIBUTORMODELSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ディストリビュータの種類の一覧を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeDistributorModelsRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName))
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
    DescribeDistributorModelsRequest() :
        m_pData(nullptr)
    {}

    DescribeDistributorModelsRequest(const DescribeDistributorModelsRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeDistributorModelsRequest(DescribeDistributorModelsRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeDistributorModelsRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeDistributorModelsRequest& operator=(const DescribeDistributorModelsRequest& describeDistributorModelsRequest)
    {
        Gs2BasicRequest::operator=(describeDistributorModelsRequest);
        Gs2Distributor::operator=(describeDistributorModelsRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeDistributorModelsRequest.m_pData);

        return *this;
    }

    DescribeDistributorModelsRequest& operator=(DescribeDistributorModelsRequest&& describeDistributorModelsRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeDistributorModelsRequest));
        Gs2Distributor::operator=(std::move(describeDistributorModelsRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeDistributorModelsRequest.m_pData;
        describeDistributorModelsRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeDistributorModelsRequest* operator->() const
    {
        return this;
    }

    DescribeDistributorModelsRequest* operator->()
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
    DescribeDistributorModelsRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeDistributorModelsRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeDistributorModelsRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeDistributorModelsRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeDistributorModelsRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_DESCRIBEDISTRIBUTORMODELSREQUEST_HPP_