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

#ifndef GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 排出確率を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeProbabilitiesRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** グループ名 */
        optional<StringHolder> groupName;
        /** 抽選モデルの種類名 */
        optional<StringHolder> lotteryModelName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            lotteryModelName(data.lotteryModelName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            lotteryModelName(std::move(data.lotteryModelName))
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
    DescribeProbabilitiesRequest() :
        m_pData(nullptr)
    {}

    DescribeProbabilitiesRequest(const DescribeProbabilitiesRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeProbabilitiesRequest(DescribeProbabilitiesRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeProbabilitiesRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeProbabilitiesRequest& operator=(const DescribeProbabilitiesRequest& describeProbabilitiesRequest)
    {
        Gs2BasicRequest::operator=(describeProbabilitiesRequest);
        Gs2Lottery::operator=(describeProbabilitiesRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeProbabilitiesRequest.m_pData);

        return *this;
    }

    DescribeProbabilitiesRequest& operator=(DescribeProbabilitiesRequest&& describeProbabilitiesRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeProbabilitiesRequest));
        Gs2Lottery::operator=(std::move(describeProbabilitiesRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeProbabilitiesRequest.m_pData;
        describeProbabilitiesRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeProbabilitiesRequest* operator->() const
    {
        return this;
    }

    DescribeProbabilitiesRequest* operator->()
    {
        return this;
    }
    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    DescribeProbabilitiesRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * 抽選モデルの種類名を取得
     *
     * @return 抽選モデルの種類名
     */
    const optional<StringHolder>& getLotteryModelName() const
    {
        return ensureData().lotteryModelName;
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param lotteryModelName 抽選モデルの種類名
     */
    void setLotteryModelName(const Char* lotteryModelName)
    {
        ensureData().lotteryModelName.emplace(lotteryModelName);
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param lotteryModelName 抽選モデルの種類名
     */
    DescribeProbabilitiesRequest& withLotteryModelName(const Char* lotteryModelName)
    {
        ensureData().lotteryModelName.emplace(lotteryModelName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeProbabilitiesRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeProbabilitiesRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeProbabilitiesRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeProbabilitiesRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESREQUEST_HPP_