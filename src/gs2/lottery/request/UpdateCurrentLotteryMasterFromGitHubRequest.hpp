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

#ifndef GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERFROMGITHUBREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERFROMGITHUBREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 現在有効な現在有効な抽選設定を更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentLotteryMasterFromGitHubRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** GitHubからマスターデータをチェックアウトしてくる設定 */
        optional<GitHubCheckoutSetting> checkoutSetting;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            checkoutSetting(data.checkoutSetting)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            checkoutSetting(std::move(data.checkoutSetting))
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
    UpdateCurrentLotteryMasterFromGitHubRequest() :
        m_pData(nullptr)
    {}

    UpdateCurrentLotteryMasterFromGitHubRequest(const UpdateCurrentLotteryMasterFromGitHubRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCurrentLotteryMasterFromGitHubRequest(UpdateCurrentLotteryMasterFromGitHubRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCurrentLotteryMasterFromGitHubRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentLotteryMasterFromGitHubRequest& operator=(const UpdateCurrentLotteryMasterFromGitHubRequest& updateCurrentLotteryMasterFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(updateCurrentLotteryMasterFromGitHubRequest);
        Gs2Lottery::operator=(updateCurrentLotteryMasterFromGitHubRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentLotteryMasterFromGitHubRequest.m_pData);

        return *this;
    }

    UpdateCurrentLotteryMasterFromGitHubRequest& operator=(UpdateCurrentLotteryMasterFromGitHubRequest&& updateCurrentLotteryMasterFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCurrentLotteryMasterFromGitHubRequest));
        Gs2Lottery::operator=(std::move(updateCurrentLotteryMasterFromGitHubRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentLotteryMasterFromGitHubRequest.m_pData;
        updateCurrentLotteryMasterFromGitHubRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentLotteryMasterFromGitHubRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentLotteryMasterFromGitHubRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateCurrentLotteryMasterFromGitHubRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を取得
     *
     * @return GitHubからマスターデータをチェックアウトしてくる設定
     */
    const optional<GitHubCheckoutSetting>& getCheckoutSetting() const
    {
        return ensureData().checkoutSetting;
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからマスターデータをチェックアウトしてくる設定
     */
    void setCheckoutSetting(const GitHubCheckoutSetting& checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(checkoutSetting);
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからマスターデータをチェックアウトしてくる設定
     */
    UpdateCurrentLotteryMasterFromGitHubRequest& withCheckoutSetting(const GitHubCheckoutSetting& checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(checkoutSetting);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCurrentLotteryMasterFromGitHubRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateCurrentLotteryMasterFromGitHubRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateCurrentLotteryMasterFromGitHubRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentLotteryMasterFromGitHubRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERFROMGITHUBREQUEST_HPP_