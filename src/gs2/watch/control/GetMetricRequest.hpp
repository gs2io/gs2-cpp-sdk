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

#ifndef GS2_WATCH_CONTROL_GETMETRICREQUEST_HPP_
#define GS2_WATCH_CONTROL_GETMETRICREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2WatchConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace watch
{

/**
 * @author Game Server Services, Inc.
 */
class GetMetricRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "GetMetric";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースGRN */
        optional<StringHolder> serviceId;
        /** 操作名 */
        optional<StringHolder> operation;
        /** データの取得開始日時 */
        optional<Int32> begin;
        /** データの取得終了日時 */
        optional<Int32> end;
        /** 長期間のデータ取得を許可するか */
        optional<Bool> allowLongTerm;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            serviceId(data.serviceId),
            operation(data.operation),
            begin(data.begin),
            end(data.end),
            allowLongTerm(data.allowLongTerm)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            serviceId(std::move(data.serviceId)),
            operation(std::move(data.operation)),
            begin(std::move(data.begin)),
            end(std::move(data.end)),
            allowLongTerm(std::move(data.allowLongTerm))
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
    GetMetricRequest() :
        m_pData(nullptr)
    {}

    GetMetricRequest(const GetMetricRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Watch(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetMetricRequest(GetMetricRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Watch(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetMetricRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMetricRequest& operator=(const GetMetricRequest& getMetricRequest)
    {
        Gs2BasicRequest::operator=(getMetricRequest);
        Gs2Watch::operator=(getMetricRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMetricRequest.m_pData);

        return *this;
    }

    GetMetricRequest& operator=(GetMetricRequest&& getMetricRequest)
    {
        Gs2BasicRequest::operator=(std::move(getMetricRequest));
        Gs2Watch::operator=(std::move(getMetricRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMetricRequest.m_pData;
        getMetricRequest.m_pData = nullptr;

        return *this;
    }

    const GetMetricRequest* operator->() const
    {
        return this;
    }

    GetMetricRequest* operator->()
    {
        return this;
    }

    /**
     * リソースGRNを取得
     *
     * @return リソースGRN
     */
    const optional<StringHolder>& getServiceId() const
    {
        return ensureData().serviceId;
    }

    /**
     * リソースGRNを設定
     *
     * @param serviceId リソースGRN
     */
    void setServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
    }

    /**
     * リソースGRNを設定
     *
     * @param serviceId リソースGRN
     */
    GetMetricRequest& withServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
        return *this;
    }

    /**
     * 操作名を取得
     *
     * @return 操作名
     */
    const optional<StringHolder>& getOperation() const
    {
        return ensureData().operation;
    }

    /**
     * 操作名を設定
     *
     * @param operation 操作名
     */
    void setOperation(const Char* operation)
    {
        ensureData().operation.emplace(operation);
    }

    /**
     * 操作名を設定
     *
     * @param operation 操作名
     */
    GetMetricRequest& withOperation(const Char* operation)
    {
        ensureData().operation.emplace(operation);
        return *this;
    }

    /**
     * データの取得開始日時を取得
     *
     * @return データの取得開始日時
     */
    const optional<Int32>& getBegin() const
    {
        return ensureData().begin;
    }

    /**
     * データの取得開始日時を設定
     *
     * @param begin データの取得開始日時
     */
    void setBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
    }

    /**
     * データの取得開始日時を設定
     *
     * @param begin データの取得開始日時
     */
    GetMetricRequest& withBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
        return *this;
    }

    /**
     * データの取得終了日時を取得
     *
     * @return データの取得終了日時
     */
    const optional<Int32>& getEnd() const
    {
        return ensureData().end;
    }

    /**
     * データの取得終了日時を設定
     *
     * @param end データの取得終了日時
     */
    void setEnd(Int32 end)
    {
        ensureData().end.emplace(end);
    }

    /**
     * データの取得終了日時を設定
     *
     * @param end データの取得終了日時
     */
    GetMetricRequest& withEnd(Int32 end)
    {
        ensureData().end.emplace(end);
        return *this;
    }

    /**
     * 長期間のデータ取得を許可するかを取得
     *
     * @return 長期間のデータ取得を許可するか
     */
    const optional<Bool>& getAllowLongTerm() const
    {
        return ensureData().allowLongTerm;
    }

    /**
     * 長期間のデータ取得を許可するかを設定
     *
     * @param allowLongTerm 長期間のデータ取得を許可するか
     */
    void setAllowLongTerm(Bool allowLongTerm)
    {
        ensureData().allowLongTerm.emplace(allowLongTerm);
    }

    /**
     * 長期間のデータ取得を許可するかを設定
     *
     * @param allowLongTerm 長期間のデータ取得を許可するか
     */
    GetMetricRequest& withAllowLongTerm(Bool allowLongTerm)
    {
        ensureData().allowLongTerm.emplace(allowLongTerm);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetMetricRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetMetricRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetMetricRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMetricRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_WATCH_CONTROL_GETMETRICREQUEST_HPP_