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

#ifndef GS2_LEVEL_CONTROL_UPDATERESOURCETYPEMASTERREQUEST_HPP_
#define GS2_LEVEL_CONTROL_UPDATERESOURCETYPEMASTERREQUEST_HPP_

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
class UpdateResourceTypeMasterRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "UpdateResourceTypeMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** リソースタイプ */
        optional<StringHolder> resourceTypeName;
        /** メタデータ */
        optional<StringHolder> meta;
        /** レベルテーブル名 */
        optional<StringHolder> levelTableName;
        /** デフォルト取得済み経験値 */
        optional<Int64> defaultExperience;
        /** デフォルトレベルキャップ */
        optional<Int32> defaultLevelCap;
        /** 最大レベルキャップ */
        optional<Int32> maxLevelCap;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            resourceTypeName(data.resourceTypeName),
            meta(data.meta),
            levelTableName(data.levelTableName),
            defaultExperience(data.defaultExperience),
            defaultLevelCap(data.defaultLevelCap),
            maxLevelCap(data.maxLevelCap)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            resourceTypeName(std::move(data.resourceTypeName)),
            meta(std::move(data.meta)),
            levelTableName(std::move(data.levelTableName)),
            defaultExperience(std::move(data.defaultExperience)),
            defaultLevelCap(std::move(data.defaultLevelCap)),
            maxLevelCap(std::move(data.maxLevelCap))
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
    UpdateResourceTypeMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateResourceTypeMasterRequest(const UpdateResourceTypeMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateResourceTypeMasterRequest(UpdateResourceTypeMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateResourceTypeMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateResourceTypeMasterRequest& operator=(const UpdateResourceTypeMasterRequest& updateResourceTypeMasterRequest)
    {
        Gs2BasicRequest::operator=(updateResourceTypeMasterRequest);
        Gs2Level::operator=(updateResourceTypeMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateResourceTypeMasterRequest.m_pData);

        return *this;
    }

    UpdateResourceTypeMasterRequest& operator=(UpdateResourceTypeMasterRequest&& updateResourceTypeMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateResourceTypeMasterRequest));
        Gs2Level::operator=(std::move(updateResourceTypeMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateResourceTypeMasterRequest.m_pData;
        updateResourceTypeMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateResourceTypeMasterRequest* operator->() const
    {
        return this;
    }

    UpdateResourceTypeMasterRequest* operator->()
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
    UpdateResourceTypeMasterRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * リソースタイプを取得
     *
     * @return リソースタイプ
     */
    const optional<StringHolder>& getResourceTypeName() const
    {
        return ensureData().resourceTypeName;
    }

    /**
     * リソースタイプを設定
     *
     * @param resourceTypeName リソースタイプ
     */
    void setResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
    }

    /**
     * リソースタイプを設定
     *
     * @param resourceTypeName リソースタイプ
     */
    UpdateResourceTypeMasterRequest& withResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
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
    UpdateResourceTypeMasterRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }

    /**
     * レベルテーブル名を取得
     *
     * @return レベルテーブル名
     */
    const optional<StringHolder>& getLevelTableName() const
    {
        return ensureData().levelTableName;
    }

    /**
     * レベルテーブル名を設定
     *
     * @param levelTableName レベルテーブル名
     */
    void setLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
    }

    /**
     * レベルテーブル名を設定
     *
     * @param levelTableName レベルテーブル名
     */
    UpdateResourceTypeMasterRequest& withLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
        return *this;
    }

    /**
     * デフォルト取得済み経験値を取得
     *
     * @return デフォルト取得済み経験値
     */
    const optional<Int64>& getDefaultExperience() const
    {
        return ensureData().defaultExperience;
    }

    /**
     * デフォルト取得済み経験値を設定
     *
     * @param defaultExperience デフォルト取得済み経験値
     */
    void setDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
    }

    /**
     * デフォルト取得済み経験値を設定
     *
     * @param defaultExperience デフォルト取得済み経験値
     */
    UpdateResourceTypeMasterRequest& withDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
        return *this;
    }

    /**
     * デフォルトレベルキャップを取得
     *
     * @return デフォルトレベルキャップ
     */
    const optional<Int32>& getDefaultLevelCap() const
    {
        return ensureData().defaultLevelCap;
    }

    /**
     * デフォルトレベルキャップを設定
     *
     * @param defaultLevelCap デフォルトレベルキャップ
     */
    void setDefaultLevelCap(Int32 defaultLevelCap)
    {
        ensureData().defaultLevelCap.emplace(defaultLevelCap);
    }

    /**
     * デフォルトレベルキャップを設定
     *
     * @param defaultLevelCap デフォルトレベルキャップ
     */
    UpdateResourceTypeMasterRequest& withDefaultLevelCap(Int32 defaultLevelCap)
    {
        ensureData().defaultLevelCap.emplace(defaultLevelCap);
        return *this;
    }

    /**
     * 最大レベルキャップを取得
     *
     * @return 最大レベルキャップ
     */
    const optional<Int32>& getMaxLevelCap() const
    {
        return ensureData().maxLevelCap;
    }

    /**
     * 最大レベルキャップを設定
     *
     * @param maxLevelCap 最大レベルキャップ
     */
    void setMaxLevelCap(Int32 maxLevelCap)
    {
        ensureData().maxLevelCap.emplace(maxLevelCap);
    }

    /**
     * 最大レベルキャップを設定
     *
     * @param maxLevelCap 最大レベルキャップ
     */
    UpdateResourceTypeMasterRequest& withMaxLevelCap(Int32 maxLevelCap)
    {
        ensureData().maxLevelCap.emplace(maxLevelCap);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateResourceTypeMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateResourceTypeMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateResourceTypeMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateResourceTypeMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_UPDATERESOURCETYPEMASTERREQUEST_HPP_