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

#ifndef GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_

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
 * 排出確率テーブルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreatePrizeTableMasterRequest : public Gs2BasicRequest, public Gs2Lottery
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
        optional<StringHolder> name;
        /** 排出確率テーブルマスターの説明 */
        optional<StringHolder> description;
        /** 排出確率テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 景品リスト */
        optional<List<Prize>> prizes;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata)
        {
            if (data.prizes)
            {
                prizes = data.prizes->deepCopy();
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
    CreatePrizeTableMasterRequest() = default;
    CreatePrizeTableMasterRequest(const CreatePrizeTableMasterRequest& createPrizeTableMasterRequest) = default;
    CreatePrizeTableMasterRequest(CreatePrizeTableMasterRequest&& createPrizeTableMasterRequest) = default;
    ~CreatePrizeTableMasterRequest() GS2_OVERRIDE = default;

    CreatePrizeTableMasterRequest& operator=(const CreatePrizeTableMasterRequest& createPrizeTableMasterRequest) = default;
    CreatePrizeTableMasterRequest& operator=(CreatePrizeTableMasterRequest&& createPrizeTableMasterRequest) = default;

    CreatePrizeTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreatePrizeTableMasterRequest);
    }

    const CreatePrizeTableMasterRequest* operator->() const
    {
        return this;
    }

    CreatePrizeTableMasterRequest* operator->()
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
    CreatePrizeTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    CreatePrizeTableMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 排出確率テーブルマスターの説明を取得
     *
     * @return 排出確率テーブルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 排出確率テーブルマスターの説明を設定
     *
     * @param description 排出確率テーブルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 排出確率テーブルマスターの説明を設定
     *
     * @param description 排出確率テーブルマスターの説明
     */
    CreatePrizeTableMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 排出確率テーブルのメタデータを取得
     *
     * @return 排出確率テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 排出確率テーブルのメタデータを設定
     *
     * @param metadata 排出確率テーブルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 排出確率テーブルのメタデータを設定
     *
     * @param metadata 排出確率テーブルのメタデータ
     */
    CreatePrizeTableMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 景品リストを取得
     *
     * @return 景品リスト
     */
    const optional<List<Prize>>& getPrizes() const
    {
        return ensureData().prizes;
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    void setPrizes(List<Prize> prizes)
    {
        ensureData().prizes.emplace(std::move(prizes));
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    CreatePrizeTableMasterRequest& withPrizes(List<Prize> prizes)
    {
        ensureData().prizes.emplace(std::move(prizes));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreatePrizeTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreatePrizeTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERREQUEST_HPP_