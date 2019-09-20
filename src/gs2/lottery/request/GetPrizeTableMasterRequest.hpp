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

#ifndef GS2_LOTTERY_CONTROL_GETPRIZETABLEMASTERREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_GETPRIZETABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/Gs2LotteryConst.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * 排出確率テーブルマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetPrizeTableMasterRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 排出確率テーブル名 */
        optional<StringHolder> prizeTableName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            prizeTableName(data.prizeTableName)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetPrizeTableMasterRequest() = default;
    GetPrizeTableMasterRequest(const GetPrizeTableMasterRequest& getPrizeTableMasterRequest) = default;
    GetPrizeTableMasterRequest(GetPrizeTableMasterRequest&& getPrizeTableMasterRequest) = default;
    ~GetPrizeTableMasterRequest() GS2_OVERRIDE = default;

    GetPrizeTableMasterRequest& operator=(const GetPrizeTableMasterRequest& getPrizeTableMasterRequest) = default;
    GetPrizeTableMasterRequest& operator=(GetPrizeTableMasterRequest&& getPrizeTableMasterRequest) = default;

    GetPrizeTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetPrizeTableMasterRequest);
    }

    const GetPrizeTableMasterRequest* operator->() const
    {
        return this;
    }

    GetPrizeTableMasterRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    GetPrizeTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    GetPrizeTableMasterRequest& withPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetPrizeTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetPrizeTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_GETPRIZETABLEMASTERREQUEST_HPP_