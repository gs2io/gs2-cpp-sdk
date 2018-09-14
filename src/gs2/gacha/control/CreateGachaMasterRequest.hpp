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

#ifndef GS2_GACHA_CONTROL_CREATEGACHAMASTERREQUEST_HPP_
#define GS2_GACHA_CONTROL_CREATEGACHAMASTERREQUEST_HPP_

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
class CreateGachaMasterRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "CreateGachaMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** ガチャ名 */
        optional<StringHolder> name;
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
            name(data.name),
            meta(data.meta),
            prizeTableNames(data.prizeTableNames),
            prizeJobQueueName(data.prizeJobQueueName),
            prizeJobQueueScriptName(data.prizeJobQueueScriptName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            name(std::move(data.name)),
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
    CreateGachaMasterRequest() :
        m_pData(nullptr)
    {}

    CreateGachaMasterRequest(const CreateGachaMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGachaMasterRequest(CreateGachaMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGachaMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGachaMasterRequest& operator=(const CreateGachaMasterRequest& createGachaMasterRequest)
    {
        Gs2BasicRequest::operator=(createGachaMasterRequest);
        Gs2Gacha::operator=(createGachaMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGachaMasterRequest.m_pData);

        return *this;
    }

    CreateGachaMasterRequest& operator=(CreateGachaMasterRequest&& createGachaMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGachaMasterRequest));
        Gs2Gacha::operator=(std::move(createGachaMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGachaMasterRequest.m_pData;
        createGachaMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGachaMasterRequest* operator->() const
    {
        return this;
    }

    CreateGachaMasterRequest* operator->()
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
    CreateGachaMasterRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * ガチャ名を取得
     *
     * @return ガチャ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ガチャ名を設定
     *
     * @param name ガチャ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ガチャ名を設定
     *
     * @param name ガチャ名
     */
    CreateGachaMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateGachaMasterRequest& withMeta(const Char* meta)
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
    CreateGachaMasterRequest& withPrizeTableNames(const List<StringHolder>& prizeTableNames)
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
    CreateGachaMasterRequest& withPrizeJobQueueName(const Char* prizeJobQueueName)
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
    CreateGachaMasterRequest& withPrizeJobQueueScriptName(const Char* prizeJobQueueScriptName)
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
    CreateGachaMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGachaMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGachaMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGachaMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_CREATEGACHAMASTERREQUEST_HPP_