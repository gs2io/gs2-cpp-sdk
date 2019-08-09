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

#ifndef GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 抽選の種類マスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateLotteryModelMasterRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 抽選モデルの種類名 */
        optional<StringHolder> lotteryName;
        /** 抽選の種類マスターの説明 */
        optional<StringHolder> description;
        /** 抽選モデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 抽選モード */
        optional<StringHolder> mode;
        /** 抽選回数 */
        optional<Int32> count;
        /** 抽選方法 */
        optional<StringHolder> method;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 抽選テーブルを確定するスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            lotteryName(data.lotteryName),
            description(data.description),
            metadata(data.metadata),
            mode(data.mode),
            count(data.count),
            method(data.method),
            prizeTableName(data.prizeTableName),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            lotteryName(std::move(data.lotteryName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            mode(std::move(data.mode)),
            count(std::move(data.count)),
            method(std::move(data.method)),
            prizeTableName(std::move(data.prizeTableName)),
            choicePrizeTableScriptId(std::move(data.choicePrizeTableScriptId))
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
    UpdateLotteryModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateLotteryModelMasterRequest(const UpdateLotteryModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateLotteryModelMasterRequest(UpdateLotteryModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateLotteryModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateLotteryModelMasterRequest& operator=(const UpdateLotteryModelMasterRequest& updateLotteryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateLotteryModelMasterRequest);
        Gs2Lottery::operator=(updateLotteryModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateLotteryModelMasterRequest.m_pData);

        return *this;
    }

    UpdateLotteryModelMasterRequest& operator=(UpdateLotteryModelMasterRequest&& updateLotteryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateLotteryModelMasterRequest));
        Gs2Lottery::operator=(std::move(updateLotteryModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateLotteryModelMasterRequest.m_pData;
        updateLotteryModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateLotteryModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateLotteryModelMasterRequest* operator->()
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
    UpdateLotteryModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setLotteryName(const Char* lotteryName)
    {
        ensureData().lotteryName.emplace(lotteryName);
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param lotteryName 抽選モデルの種類名
     */
    UpdateLotteryModelMasterRequest& withLotteryName(const Char* lotteryName)
    {
        ensureData().lotteryName.emplace(lotteryName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 抽選の種類マスターの説明を設定
     *
     * @param description 抽選の種類マスターの説明
     */
    UpdateLotteryModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    UpdateLotteryModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setMode(const Char* mode)
    {
        ensureData().mode.emplace(mode);
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    UpdateLotteryModelMasterRequest& withMode(const Char* mode)
    {
        ensureData().mode.emplace(mode);
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
    UpdateLotteryModelMasterRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
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
    void setMethod(const Char* method)
    {
        ensureData().method.emplace(method);
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    UpdateLotteryModelMasterRequest& withMethod(const Char* method)
    {
        ensureData().method.emplace(method);
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
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    UpdateLotteryModelMasterRequest& withPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
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
    void setChoicePrizeTableScriptId(const Char* choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(choicePrizeTableScriptId);
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    UpdateLotteryModelMasterRequest& withChoicePrizeTableScriptId(const Char* choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(choicePrizeTableScriptId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateLotteryModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateLotteryModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateLotteryModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateLotteryModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERREQUEST_HPP_