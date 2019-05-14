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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 抽選の種類を新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateLotteryModelMasterRequest : public Gs2BasicRequest, public Gs2Lottery
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
        optional<StringHolder> name;
        /** 抽選の種類の説明 */
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
            groupName(data.groupName),
            name(data.name),
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
            groupName(std::move(data.groupName)),
            name(std::move(data.name)),
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
    CreateLotteryModelMasterRequest() :
        m_pData(nullptr)
    {}

    CreateLotteryModelMasterRequest(const CreateLotteryModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateLotteryModelMasterRequest(CreateLotteryModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateLotteryModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateLotteryModelMasterRequest& operator=(const CreateLotteryModelMasterRequest& createLotteryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(createLotteryModelMasterRequest);
        Gs2Lottery::operator=(createLotteryModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createLotteryModelMasterRequest.m_pData);

        return *this;
    }

    CreateLotteryModelMasterRequest& operator=(CreateLotteryModelMasterRequest&& createLotteryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createLotteryModelMasterRequest));
        Gs2Lottery::operator=(std::move(createLotteryModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createLotteryModelMasterRequest.m_pData;
        createLotteryModelMasterRequest.m_pData = nullptr;

        return *this;
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
    CreateLotteryModelMasterRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    CreateLotteryModelMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 抽選の種類の説明を取得
     *
     * @return 抽選の種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 抽選の種類の説明を設定
     *
     * @param description 抽選の種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 抽選の種類の説明を設定
     *
     * @param description 抽選の種類の説明
     */
    CreateLotteryModelMasterRequest& withDescription(const Char* description)
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
    CreateLotteryModelMasterRequest& withMetadata(const Char* metadata)
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
    CreateLotteryModelMasterRequest& withMode(const Char* mode)
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
    CreateLotteryModelMasterRequest& withCount(Int32 count)
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
    CreateLotteryModelMasterRequest& withMethod(const Char* method)
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
    CreateLotteryModelMasterRequest& withPrizeTableName(const Char* prizeTableName)
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
    CreateLotteryModelMasterRequest& withChoicePrizeTableScriptId(const Char* choicePrizeTableScriptId)
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
    CreateLotteryModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateLotteryModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateLotteryModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateLotteryModelMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOTTERY_CONTROL_CREATELOTTERYMODELMASTERREQUEST_HPP_