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

#ifndef GS2_LOTTERY_CONTROL_DRAWBYUSERIDREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_DRAWBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * ユーザIDを指定して抽選を実行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DrawByUserIdRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 抽選モデルの種類名 */
        optional<StringHolder> lotteryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 抽選回数 */
        optional<Int32> count;
        /** スタンプシートのプレースホルダの適用する設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            lotteryName(data.lotteryName),
            userId(data.userId),
            count(data.count),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.config)
            {
                config = data.config->deepCopy();
            }
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
    DrawByUserIdRequest() = default;
    DrawByUserIdRequest(const DrawByUserIdRequest& drawByUserIdRequest) = default;
    DrawByUserIdRequest(DrawByUserIdRequest&& drawByUserIdRequest) = default;
    ~DrawByUserIdRequest() GS2_OVERRIDE = default;

    DrawByUserIdRequest& operator=(const DrawByUserIdRequest& drawByUserIdRequest) = default;
    DrawByUserIdRequest& operator=(DrawByUserIdRequest&& drawByUserIdRequest) = default;

    DrawByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DrawByUserIdRequest);
    }

    const DrawByUserIdRequest* operator->() const
    {
        return this;
    }

    DrawByUserIdRequest* operator->()
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
    DrawByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 抽選モデルの種類名を取得
     *
     * @return 抽選モデルの種類名
     */
    const optional<StringHolder>& getLotteryName() const
    {
        return ensureData().lotteryName;
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param lotteryName 抽選モデルの種類名
     */
    void setLotteryName(StringHolder lotteryName)
    {
        ensureData().lotteryName.emplace(std::move(lotteryName));
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param lotteryName 抽選モデルの種類名
     */
    DrawByUserIdRequest& withLotteryName(StringHolder lotteryName)
    {
        ensureData().lotteryName.emplace(std::move(lotteryName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DrawByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 抽選回数を取得
     *
     * @return 抽選回数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 抽選回数を設定
     *
     * @param count 抽選回数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 抽選回数を設定
     *
     * @param count 抽選回数
     */
    DrawByUserIdRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
        return *this;
    }

    /**
     * スタンプシートのプレースホルダの適用する設定値を取得
     *
     * @return スタンプシートのプレースホルダの適用する設定値
     */
    const optional<List<Config>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * スタンプシートのプレースホルダの適用する設定値を設定
     *
     * @param config スタンプシートのプレースホルダの適用する設定値
     */
    void setConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * スタンプシートのプレースホルダの適用する設定値を設定
     *
     * @param config スタンプシートのプレースホルダの適用する設定値
     */
    DrawByUserIdRequest& withConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    DrawByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DrawByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DrawByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_DRAWBYUSERIDREQUEST_HPP_