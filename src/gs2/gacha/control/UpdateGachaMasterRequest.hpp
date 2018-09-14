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

#ifndef GS2_GACHA_CONTROL_UPDATEGACHAMASTERREQUEST_HPP_
#define GS2_GACHA_CONTROL_UPDATEGACHAMASTERREQUEST_HPP_

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
class UpdateGachaMasterRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "UpdateGachaMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** ガチャの名前を指定します。 */
        optional<StringHolder> gachaName;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 排出確率名リスト */
        optional<List<StringHolder>> prizeTableNames;
        /** 景品の排出処理に使用する GS2-JobQueue */
        optional<StringHolder> prizeJobQueueName;
        /** 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script */
        optional<StringHolder> prizeJobQueueScriptName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            gachaName(data.gachaName),
            meta(data.meta),
            prizeTableNames(data.prizeTableNames),
            prizeJobQueueName(data.prizeJobQueueName),
            prizeJobQueueScriptName(data.prizeJobQueueScriptName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            gachaName(std::move(data.gachaName)),
            meta(std::move(data.meta)),
            prizeTableNames(std::move(data.prizeTableNames)),
            prizeJobQueueName(std::move(data.prizeJobQueueName)),
            prizeJobQueueScriptName(std::move(data.prizeJobQueueScriptName))
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
    UpdateGachaMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateGachaMasterRequest(const UpdateGachaMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGachaMasterRequest(UpdateGachaMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateGachaMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGachaMasterRequest& operator=(const UpdateGachaMasterRequest& updateGachaMasterRequest)
    {
        Gs2BasicRequest::operator=(updateGachaMasterRequest);
        Gs2Gacha::operator=(updateGachaMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGachaMasterRequest.m_pData);

        return *this;
    }

    UpdateGachaMasterRequest& operator=(UpdateGachaMasterRequest&& updateGachaMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateGachaMasterRequest));
        Gs2Gacha::operator=(std::move(updateGachaMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGachaMasterRequest.m_pData;
        updateGachaMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateGachaMasterRequest* operator->() const
    {
        return this;
    }

    UpdateGachaMasterRequest* operator->()
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
    UpdateGachaMasterRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * ガチャの名前を指定します。を取得
     *
     * @return ガチャの名前を指定します。
     */
    const optional<StringHolder>& getGachaName() const
    {
        return ensureData().gachaName;
    }

    /**
     * ガチャの名前を指定します。を設定
     *
     * @param gachaName ガチャの名前を指定します。
     */
    void setGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
    }

    /**
     * ガチャの名前を指定します。を設定
     *
     * @param gachaName ガチャの名前を指定します。
     */
    UpdateGachaMasterRequest& withGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    UpdateGachaMasterRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }

    /**
     * 排出確率名リストを取得
     *
     * @return 排出確率名リスト
     */
    const optional<List<StringHolder>>& getPrizeTableNames() const
    {
        return ensureData().prizeTableNames;
    }

    /**
     * 排出確率名リストを設定
     *
     * @param prizeTableNames 排出確率名リスト
     */
    void setPrizeTableNames(const List<StringHolder>& prizeTableNames)
    {
        ensureData().prizeTableNames.emplace(prizeTableNames);
    }

    /**
     * 排出確率名リストを設定
     *
     * @param prizeTableNames 排出確率名リスト
     */
    UpdateGachaMasterRequest& withPrizeTableNames(const List<StringHolder>& prizeTableNames)
    {
        ensureData().prizeTableNames.emplace(prizeTableNames);
        return *this;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueueを取得
     *
     * @return 景品の排出処理に使用する GS2-JobQueue
     */
    const optional<StringHolder>& getPrizeJobQueueName() const
    {
        return ensureData().prizeJobQueueName;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueueを設定
     *
     * @param prizeJobQueueName 景品の排出処理に使用する GS2-JobQueue
     */
    void setPrizeJobQueueName(const Char* prizeJobQueueName)
    {
        ensureData().prizeJobQueueName.emplace(prizeJobQueueName);
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueueを設定
     *
     * @param prizeJobQueueName 景品の排出処理に使用する GS2-JobQueue
     */
    UpdateGachaMasterRequest& withPrizeJobQueueName(const Char* prizeJobQueueName)
    {
        ensureData().prizeJobQueueName.emplace(prizeJobQueueName);
        return *this;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Scriptを取得
     *
     * @return 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script
     */
    const optional<StringHolder>& getPrizeJobQueueScriptName() const
    {
        return ensureData().prizeJobQueueScriptName;
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Scriptを設定
     *
     * @param prizeJobQueueScriptName 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script
     */
    void setPrizeJobQueueScriptName(const Char* prizeJobQueueScriptName)
    {
        ensureData().prizeJobQueueScriptName.emplace(prizeJobQueueScriptName);
    }

    /**
     * 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Scriptを設定
     *
     * @param prizeJobQueueScriptName 景品の排出処理に使用する GS2-JobQueue に指定する GS2-Script
     */
    UpdateGachaMasterRequest& withPrizeJobQueueScriptName(const Char* prizeJobQueueScriptName)
    {
        ensureData().prizeJobQueueScriptName.emplace(prizeJobQueueScriptName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGachaMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateGachaMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateGachaMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGachaMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_UPDATEGACHAMASTERREQUEST_HPP_