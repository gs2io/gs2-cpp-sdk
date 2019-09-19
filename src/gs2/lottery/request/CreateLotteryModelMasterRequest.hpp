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

#ifndef GS2_LOTTERY_CONTROL_CREATELOTTERYMODELMASTERREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_CREATELOTTERYMODELMASTERREQUEST_HPP_

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
 * 抽選の種類マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateLotteryModelMasterRequest : public Gs2BasicRequest, public Gs2Lottery
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
        optional<StringHolder> name;
        /** 抽選の種類マスターの説明 */
        optional<StringHolder> description;
        /** 抽選モデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 抽選モード */
        optional<StringHolder> mode;
        /** 抽選方法 */
        optional<StringHolder> method;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 抽選テーブルを確定するスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            mode(data.mode),
            method(data.method),
            prizeTableName(data.prizeTableName),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId)
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
    CreateLotteryModelMasterRequest() = default;
    CreateLotteryModelMasterRequest(const CreateLotteryModelMasterRequest& createLotteryModelMasterRequest) = default;
    CreateLotteryModelMasterRequest(CreateLotteryModelMasterRequest&& createLotteryModelMasterRequest) = default;
    ~CreateLotteryModelMasterRequest() GS2_OVERRIDE = default;

    CreateLotteryModelMasterRequest& operator=(const CreateLotteryModelMasterRequest& createLotteryModelMasterRequest) = default;
    CreateLotteryModelMasterRequest& operator=(CreateLotteryModelMasterRequest&& createLotteryModelMasterRequest) = default;

    CreateLotteryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateLotteryModelMasterRequest);
    }

    const CreateLotteryModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateLotteryModelMasterRequest* operator->()
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
    CreateLotteryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 抽選モデルの種類名を取得
     *
     * @return 抽選モデルの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    CreateLotteryModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 抽選の種類マスターの説明を取得
     *
     * @return 抽選の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 抽選の種類マスターの説明を設定
     *
     * @param description 抽選の種類マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 抽選の種類マスターの説明を設定
     *
     * @param description 抽選の種類マスターの説明
     */
    CreateLotteryModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 抽選モデルの種類のメタデータを取得
     *
     * @return 抽選モデルの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    CreateLotteryModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 抽選モードを取得
     *
     * @return 抽選モード
     */
    const optional<StringHolder>& getMode() const
    {
        return ensureData().mode;
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    void setMode(StringHolder mode)
    {
        ensureData().mode.emplace(std::move(mode));
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    CreateLotteryModelMasterRequest& withMode(StringHolder mode)
    {
        ensureData().mode.emplace(std::move(mode));
        return *this;
    }

    /**
     * 抽選方法を取得
     *
     * @return 抽選方法
     */
    const optional<StringHolder>& getMethod() const
    {
        return ensureData().method;
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    void setMethod(StringHolder method)
    {
        ensureData().method.emplace(std::move(method));
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    CreateLotteryModelMasterRequest& withMethod(StringHolder method)
    {
        ensureData().method.emplace(std::move(method));
        return *this;
    }

    /**
     * 景品テーブルの名前を取得
     *
     * @return 景品テーブルの名前
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    CreateLotteryModelMasterRequest& withPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
        return *this;
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを取得
     *
     * @return 抽選テーブルを確定するスクリプト のGRN
     */
    const optional<StringHolder>& getChoicePrizeTableScriptId() const
    {
        return ensureData().choicePrizeTableScriptId;
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    void setChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(std::move(choicePrizeTableScriptId));
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    CreateLotteryModelMasterRequest& withChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(std::move(choicePrizeTableScriptId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateLotteryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateLotteryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_CREATELOTTERYMODELMASTERREQUEST_HPP_