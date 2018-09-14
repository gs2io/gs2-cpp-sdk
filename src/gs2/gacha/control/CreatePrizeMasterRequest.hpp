/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_GACHA_CONTROL_CREATEPRIZEMASTERREQUEST_HPP_
#define GS2_GACHA_CONTROL_CREATEPRIZEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GachaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class CreatePrizeMasterRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "CreatePrizeMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** 排出確率テーブルの名前を指定します。 */
        optional<StringHolder> prizeTableName;
        /** 景品レアリティの名前を指定します。 */
        optional<StringHolder> rarityName;
        /** リソースID */
        optional<StringHolder> resourceId;
        /** 排出重み */
        optional<Int32> weight;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            prizeTableName(data.prizeTableName),
            rarityName(data.rarityName),
            resourceId(data.resourceId),
            weight(data.weight)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            prizeTableName(std::move(data.prizeTableName)),
            rarityName(std::move(data.rarityName)),
            resourceId(std::move(data.resourceId)),
            weight(std::move(data.weight))
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
    CreatePrizeMasterRequest() :
        m_pData(nullptr)
    {}

    CreatePrizeMasterRequest(const CreatePrizeMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreatePrizeMasterRequest(CreatePrizeMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreatePrizeMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreatePrizeMasterRequest& operator=(const CreatePrizeMasterRequest& createPrizeMasterRequest)
    {
        Gs2BasicRequest::operator=(createPrizeMasterRequest);
        Gs2Gacha::operator=(createPrizeMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createPrizeMasterRequest.m_pData);

        return *this;
    }

    CreatePrizeMasterRequest& operator=(CreatePrizeMasterRequest&& createPrizeMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createPrizeMasterRequest));
        Gs2Gacha::operator=(std::move(createPrizeMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createPrizeMasterRequest.m_pData;
        createPrizeMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreatePrizeMasterRequest* operator->() const
    {
        return this;
    }

    CreatePrizeMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ガチャプールの名前を指定します。を取得
     *
     * @return ガチャプールの名前を指定します。
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    CreatePrizeMasterRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * 排出確率テーブルの名前を指定します。を取得
     *
     * @return 排出確率テーブルの名前を指定します。
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 排出確率テーブルの名前を指定します。を設定
     *
     * @param prizeTableName 排出確率テーブルの名前を指定します。
     */
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 排出確率テーブルの名前を指定します。を設定
     *
     * @param prizeTableName 排出確率テーブルの名前を指定します。
     */
    CreatePrizeMasterRequest& withPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
        return *this;
    }

    /**
     * 景品レアリティの名前を指定します。を取得
     *
     * @return 景品レアリティの名前を指定します。
     */
    const optional<StringHolder>& getRarityName() const
    {
        return ensureData().rarityName;
    }

    /**
     * 景品レアリティの名前を指定します。を設定
     *
     * @param rarityName 景品レアリティの名前を指定します。
     */
    void setRarityName(const Char* rarityName)
    {
        ensureData().rarityName.emplace(rarityName);
    }

    /**
     * 景品レアリティの名前を指定します。を設定
     *
     * @param rarityName 景品レアリティの名前を指定します。
     */
    CreatePrizeMasterRequest& withRarityName(const Char* rarityName)
    {
        ensureData().rarityName.emplace(rarityName);
        return *this;
    }

    /**
     * リソースIDを取得
     *
     * @return リソースID
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    CreatePrizeMasterRequest& withResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
        return *this;
    }

    /**
     * 排出重みを取得
     *
     * @return 排出重み
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 排出重みを設定
     *
     * @param weight 排出重み
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
    }

    /**
     * 排出重みを設定
     *
     * @param weight 排出重み
     */
    CreatePrizeMasterRequest& withWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreatePrizeMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreatePrizeMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreatePrizeMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreatePrizeMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_CREATEPRIZEMASTERREQUEST_HPP_