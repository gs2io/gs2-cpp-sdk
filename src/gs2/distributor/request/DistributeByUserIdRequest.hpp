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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ユーザーIDを指定して所持品を配布する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeByUserIdRequest : public Gs2BasicRequest, public Gs2Distributor
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
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 加算するリソース */
        optional<DistributeResource> distributeResource;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            distributorModelName(data.distributorModelName),
            userId(data.userId),
            distributeResource(data.distributeResource),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
            distributorModelName(std::move(data.distributorModelName)),
            userId(std::move(data.userId)),
            distributeResource(std::move(data.distributeResource)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    DistributeByUserIdRequest() :
        m_pData(nullptr)
    {}

    DistributeByUserIdRequest(const DistributeByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DistributeByUserIdRequest(DistributeByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DistributeByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributeByUserIdRequest& operator=(const DistributeByUserIdRequest& distributeByUserIdRequest)
    {
        Gs2BasicRequest::operator=(distributeByUserIdRequest);
        Gs2Distributor::operator=(distributeByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributeByUserIdRequest.m_pData);

        return *this;
    }

    DistributeByUserIdRequest& operator=(DistributeByUserIdRequest&& distributeByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(distributeByUserIdRequest));
        Gs2Distributor::operator=(std::move(distributeByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributeByUserIdRequest.m_pData;
        distributeByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const DistributeByUserIdRequest* operator->() const
    {
        return this;
    }

    DistributeByUserIdRequest* operator->()
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
    DistributeByUserIdRequest& withDistributorName(const Char* distributorName)
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
    DistributeByUserIdRequest& withDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DistributeByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 加算するリソースを取得
     *
     * @return 加算するリソース
     */
    const optional<DistributeResource>& getDistributeResource() const
    {
        return ensureData().distributeResource;
    }

    /**
     * 加算するリソースを設定
     *
     * @param distributeResource 加算するリソース
     */
    void setDistributeResource(const DistributeResource& distributeResource)
    {
        ensureData().distributeResource.emplace(distributeResource);
    }

    /**
     * 加算するリソースを設定
     *
     * @param distributeResource 加算するリソース
     */
    DistributeByUserIdRequest& withDistributeResource(const DistributeResource& distributeResource)
    {
        ensureData().distributeResource.emplace(distributeResource);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    DistributeByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DistributeByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DistributeByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DistributeByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DistributeByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEBYUSERIDREQUEST_HPP_