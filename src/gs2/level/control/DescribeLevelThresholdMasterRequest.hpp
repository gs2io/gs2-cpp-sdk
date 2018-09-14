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

#ifndef GS2_LEVEL_CONTROL_DESCRIBELEVELTHRESHOLDMASTERREQUEST_HPP_
#define GS2_LEVEL_CONTROL_DESCRIBELEVELTHRESHOLDMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeLevelThresholdMasterRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "DescribeLevelThresholdMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** レベルテーブル */
        optional<StringHolder> levelTableName;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int32> limit;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            levelTableName(data.levelTableName),
            pageToken(data.pageToken),
            limit(data.limit)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            levelTableName(std::move(data.levelTableName)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit))
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
    DescribeLevelThresholdMasterRequest() :
        m_pData(nullptr)
    {}

    DescribeLevelThresholdMasterRequest(const DescribeLevelThresholdMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeLevelThresholdMasterRequest(DescribeLevelThresholdMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeLevelThresholdMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeLevelThresholdMasterRequest& operator=(const DescribeLevelThresholdMasterRequest& describeLevelThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(describeLevelThresholdMasterRequest);
        Gs2Level::operator=(describeLevelThresholdMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeLevelThresholdMasterRequest.m_pData);

        return *this;
    }

    DescribeLevelThresholdMasterRequest& operator=(DescribeLevelThresholdMasterRequest&& describeLevelThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeLevelThresholdMasterRequest));
        Gs2Level::operator=(std::move(describeLevelThresholdMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeLevelThresholdMasterRequest.m_pData;
        describeLevelThresholdMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeLevelThresholdMasterRequest* operator->() const
    {
        return this;
    }

    DescribeLevelThresholdMasterRequest* operator->()
    {
        return this;
    }

    /**
     * リソースプールを取得
     *
     * @return リソースプール
     */
    const optional<StringHolder>& getResourcePoolName() const
    {
        return ensureData().resourcePoolName;
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    void setResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    DescribeLevelThresholdMasterRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * レベルテーブルを取得
     *
     * @return レベルテーブル
     */
    const optional<StringHolder>& getLevelTableName() const
    {
        return ensureData().levelTableName;
    }

    /**
     * レベルテーブルを設定
     *
     * @param levelTableName レベルテーブル
     */
    void setLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
    }

    /**
     * レベルテーブルを設定
     *
     * @param levelTableName レベルテーブル
     */
    DescribeLevelThresholdMasterRequest& withLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    DescribeLevelThresholdMasterRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeLevelThresholdMasterRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeLevelThresholdMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeLevelThresholdMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeLevelThresholdMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeLevelThresholdMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_DESCRIBELEVELTHRESHOLDMASTERREQUEST_HPP_