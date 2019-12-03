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

#ifndef GS2_DATASTORE_CONTROL_GETDATAOBJECTHISTORYBYUSERIDREQUEST_HPP_
#define GS2_DATASTORE_CONTROL_GETDATAOBJECTHISTORYBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/datastore/Gs2DatastoreConst.hpp>
#include <gs2/datastore/model/model.hpp>
#include <memory>

namespace gs2 { namespace datastore
{

/**
 * ユーザIDを指定してデータオブジェクト履歴を取得する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetDataObjectHistoryByUserIdRequest : public Gs2BasicRequest, public Gs2Datastore
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** データの名前 */
        optional<StringHolder> dataObjectName;
        /** 世代ID */
        optional<StringHolder> generation;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            dataObjectName(data.dataObjectName),
            generation(data.generation),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetDataObjectHistoryByUserIdRequest() = default;
    GetDataObjectHistoryByUserIdRequest(const GetDataObjectHistoryByUserIdRequest& getDataObjectHistoryByUserIdRequest) = default;
    GetDataObjectHistoryByUserIdRequest(GetDataObjectHistoryByUserIdRequest&& getDataObjectHistoryByUserIdRequest) = default;
    ~GetDataObjectHistoryByUserIdRequest() GS2_OVERRIDE = default;

    GetDataObjectHistoryByUserIdRequest& operator=(const GetDataObjectHistoryByUserIdRequest& getDataObjectHistoryByUserIdRequest) = default;
    GetDataObjectHistoryByUserIdRequest& operator=(GetDataObjectHistoryByUserIdRequest&& getDataObjectHistoryByUserIdRequest) = default;

    GetDataObjectHistoryByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetDataObjectHistoryByUserIdRequest);
    }

    const GetDataObjectHistoryByUserIdRequest* operator->() const
    {
        return this;
    }

    GetDataObjectHistoryByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    GetDataObjectHistoryByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    GetDataObjectHistoryByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * データの名前を取得
     *
     * @return データの名前
     */
    const optional<StringHolder>& getDataObjectName() const
    {
        return ensureData().dataObjectName;
    }

    /**
     * データの名前を設定
     *
     * @param dataObjectName データの名前
     */
    void setDataObjectName(StringHolder dataObjectName)
    {
        ensureData().dataObjectName.emplace(std::move(dataObjectName));
    }

    /**
     * データの名前を設定
     *
     * @param dataObjectName データの名前
     */
    GetDataObjectHistoryByUserIdRequest& withDataObjectName(StringHolder dataObjectName)
    {
        ensureData().dataObjectName.emplace(std::move(dataObjectName));
        return *this;
    }

    /**
     * 世代IDを取得
     *
     * @return 世代ID
     */
    const optional<StringHolder>& getGeneration() const
    {
        return ensureData().generation;
    }

    /**
     * 世代IDを設定
     *
     * @param generation 世代ID
     */
    void setGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
    }

    /**
     * 世代IDを設定
     *
     * @param generation 世代ID
     */
    GetDataObjectHistoryByUserIdRequest& withGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    GetDataObjectHistoryByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetDataObjectHistoryByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetDataObjectHistoryByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DATASTORE_CONTROL_GETDATAOBJECTHISTORYBYUSERIDREQUEST_HPP_