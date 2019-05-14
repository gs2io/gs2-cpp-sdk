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

#ifndef GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * 所持品を配布する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class RunStampSheetRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** ディストリビューターの種類名 */
        optional<StringHolder> distributorModelName;
        /** 実行するスタンプタスク */
        optional<StringHolder> stampSheet;
        /** スタンプシートの暗号化に使用した暗号鍵GRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            distributorModelName(data.distributorModelName),
            stampSheet(data.stampSheet),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
            distributorModelName(std::move(data.distributorModelName)),
            stampSheet(std::move(data.stampSheet)),
            keyId(std::move(data.keyId)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    RunStampSheetRequest() :
        m_pData(nullptr)
    {}

    RunStampSheetRequest(const RunStampSheetRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    RunStampSheetRequest(RunStampSheetRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~RunStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunStampSheetRequest& operator=(const RunStampSheetRequest& runStampSheetRequest)
    {
        Gs2BasicRequest::operator=(runStampSheetRequest);
        Gs2Distributor::operator=(runStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runStampSheetRequest.m_pData);

        return *this;
    }

    RunStampSheetRequest& operator=(RunStampSheetRequest&& runStampSheetRequest)
    {
        Gs2BasicRequest::operator=(std::move(runStampSheetRequest));
        Gs2Distributor::operator=(std::move(runStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runStampSheetRequest.m_pData;
        runStampSheetRequest.m_pData = nullptr;

        return *this;
    }

    const RunStampSheetRequest* operator->() const
    {
        return this;
    }

    RunStampSheetRequest* operator->()
    {
        return this;
    }
    /**
     * ディストリビュータ名を取得
     *
     * @return ディストリビュータ名
     */
    const optional<StringHolder>& getDistributorName() const
    {
        return ensureData().distributorName;
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    void setDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    RunStampSheetRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }

    /**
     * ディストリビューターの種類名を取得
     *
     * @return ディストリビューターの種類名
     */
    const optional<StringHolder>& getDistributorModelName() const
    {
        return ensureData().distributorModelName;
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    void setDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    RunStampSheetRequest& withDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
        return *this;
    }

    /**
     * 実行するスタンプタスクを取得
     *
     * @return 実行するスタンプタスク
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 実行するスタンプタスクを設定
     *
     * @param stampSheet 実行するスタンプタスク
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }

    /**
     * 実行するスタンプタスクを設定
     *
     * @param stampSheet 実行するスタンプタスク
     */
    RunStampSheetRequest& withStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
        return *this;
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを取得
     *
     * @return スタンプシートの暗号化に使用した暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを設定
     *
     * @param keyId スタンプシートの暗号化に使用した暗号鍵GRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを設定
     *
     * @param keyId スタンプシートの暗号化に使用した暗号鍵GRN
     */
    RunStampSheetRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    RunStampSheetRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    RunStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    RunStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    RunStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RunStampSheetRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETREQUEST_HPP_