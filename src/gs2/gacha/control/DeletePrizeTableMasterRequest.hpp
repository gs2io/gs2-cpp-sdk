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

#ifndef GS2_GACHA_CONTROL_DELETEPRIZETABLEMASTERREQUEST_HPP_
#define GS2_GACHA_CONTROL_DELETEPRIZETABLEMASTERREQUEST_HPP_

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
class DeletePrizeTableMasterRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "DeletePrizeTableMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** 排出確率テーブルの名前を指定します。 */
        optional<StringHolder> prizeTableName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            prizeTableName(data.prizeTableName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            prizeTableName(std::move(data.prizeTableName))
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
    DeletePrizeTableMasterRequest() :
        m_pData(nullptr)
    {}

    DeletePrizeTableMasterRequest(const DeletePrizeTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeletePrizeTableMasterRequest(DeletePrizeTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeletePrizeTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeletePrizeTableMasterRequest& operator=(const DeletePrizeTableMasterRequest& deletePrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(deletePrizeTableMasterRequest);
        Gs2Gacha::operator=(deletePrizeTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deletePrizeTableMasterRequest.m_pData);

        return *this;
    }

    DeletePrizeTableMasterRequest& operator=(DeletePrizeTableMasterRequest&& deletePrizeTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deletePrizeTableMasterRequest));
        Gs2Gacha::operator=(std::move(deletePrizeTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deletePrizeTableMasterRequest.m_pData;
        deletePrizeTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeletePrizeTableMasterRequest* operator->() const
    {
        return this;
    }

    DeletePrizeTableMasterRequest* operator->()
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
    DeletePrizeTableMasterRequest& withGachaPoolName(const Char* gachaPoolName)
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
    DeletePrizeTableMasterRequest& withPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeletePrizeTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeletePrizeTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeletePrizeTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeletePrizeTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_DELETEPRIZETABLEMASTERREQUEST_HPP_