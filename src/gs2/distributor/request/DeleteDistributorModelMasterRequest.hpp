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

#ifndef GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORMODELMASTERREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ディストリビュータの種類を削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteDistributorModelMasterRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** ディストリビューターの種類名 */
        optional<StringHolder> distributorModelName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            distributorModelName(data.distributorModelName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
            distributorModelName(std::move(data.distributorModelName))
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
    DeleteDistributorModelMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteDistributorModelMasterRequest(const DeleteDistributorModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteDistributorModelMasterRequest(DeleteDistributorModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteDistributorModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteDistributorModelMasterRequest& operator=(const DeleteDistributorModelMasterRequest& deleteDistributorModelMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteDistributorModelMasterRequest);
        Gs2Distributor::operator=(deleteDistributorModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteDistributorModelMasterRequest.m_pData);

        return *this;
    }

    DeleteDistributorModelMasterRequest& operator=(DeleteDistributorModelMasterRequest&& deleteDistributorModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteDistributorModelMasterRequest));
        Gs2Distributor::operator=(std::move(deleteDistributorModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteDistributorModelMasterRequest.m_pData;
        deleteDistributorModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteDistributorModelMasterRequest* operator->() const
    {
        return this;
    }

    DeleteDistributorModelMasterRequest* operator->()
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
    DeleteDistributorModelMasterRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }

    /**
     * ディストリビューターの種類名を取得
     *
     * @return ディストリビューターの種類名
     */
    const optional<StringHolder>& getDistributorModelName() const
    {
        return ensureData().distributorModelName;
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    void setDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    DeleteDistributorModelMasterRequest& withDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteDistributorModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteDistributorModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteDistributorModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteDistributorModelMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORMODELMASTERREQUEST_HPP_