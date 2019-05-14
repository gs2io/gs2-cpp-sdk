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

#ifndef GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 景品の排出確率テーブルを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdatePrizeTableMasterRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** グループ名 */
        optional<StringHolder> groupName;
        /** 景品テーブル名 */
        optional<StringHolder> prizeTableName;
        /** 景品の排出確率テーブルの説明 */
        optional<StringHolder> description;
        /** 景品テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 景品リスト */
        optional<List<PrizeMaster>> prizes;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            prizeTableName(data.prizeTableName),
            description(data.description),
            metadata(data.metadata),
            prizes(data.prizes)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            prizeTableName(std::move(data.prizeTableName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            prizes(std::move(data.prizes))
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
    UpdatePrizeTableMasterRequest() :
        m_pData(nullptr)
    {}

    UpdatePrizeTableMasterRequest(const UpdatePrizeTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdatePrizeTableMasterRequest(UpdatePrizeTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdatePrizeTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdatePrizeTableMasterRequest& operator=(const UpdatePrizeTableMasterRequest& updatePrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(updatePrizeTableMasterRequest);
        Gs2Lottery::operator=(updatePrizeTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updatePrizeTableMasterRequest.m_pData);

        return *this;
    }

    UpdatePrizeTableMasterRequest& operator=(UpdatePrizeTableMasterRequest&& updatePrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updatePrizeTableMasterRequest));
        Gs2Lottery::operator=(std::move(updatePrizeTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updatePrizeTableMasterRequest.m_pData;
        updatePrizeTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdatePrizeTableMasterRequest* operator->() const
    {
        return this;
    }

    UpdatePrizeTableMasterRequest* operator->()
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
    UpdatePrizeTableMasterRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * 景品テーブル名を取得
     *
     * @return 景品テーブル名
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 景品テーブル名を設定
     *
     * @param prizeTableName 景品テーブル名
     */
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 景品テーブル名を設定
     *
     * @param prizeTableName 景品テーブル名
     */
    UpdatePrizeTableMasterRequest& withPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
        return *this;
    }

    /**
     * 景品の排出確率テーブルの説明を取得
     *
     * @return 景品の排出確率テーブルの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 景品の排出確率テーブルの説明を設定
     *
     * @param description 景品の排出確率テーブルの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 景品の排出確率テーブルの説明を設定
     *
     * @param description 景品の排出確率テーブルの説明
     */
    UpdatePrizeTableMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 景品テーブルのメタデータを取得
     *
     * @return 景品テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 景品テーブルのメタデータを設定
     *
     * @param metadata 景品テーブルのメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 景品テーブルのメタデータを設定
     *
     * @param metadata 景品テーブルのメタデータ
     */
    UpdatePrizeTableMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * 景品リストを取得
     *
     * @return 景品リスト
     */
    const optional<List<PrizeMaster>>& getPrizes() const
    {
        return ensureData().prizes;
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    void setPrizes(const List<PrizeMaster>& prizes)
    {
        ensureData().prizes.emplace(prizes);
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    UpdatePrizeTableMasterRequest& withPrizes(const List<PrizeMaster>& prizes)
    {
        ensureData().prizes.emplace(prizes);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdatePrizeTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdatePrizeTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdatePrizeTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdatePrizeTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERREQUEST_HPP_