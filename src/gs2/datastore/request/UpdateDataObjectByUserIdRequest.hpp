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

#ifndef GS2_DATASTORE_CONTROL_UPDATEDATAOBJECTBYUSERIDREQUEST_HPP_
#define GS2_DATASTORE_CONTROL_UPDATEDATAOBJECTBYUSERIDREQUEST_HPP_

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
 * ユーザIDを指定してデータオブジェクトを更新する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateDataObjectByUserIdRequest : public Gs2BasicRequest, public Gs2Datastore
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** データの名前 */
        optional<StringHolder> dataObjectName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ファイルのアクセス権 */
        optional<StringHolder> scope;
        /** 公開するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            dataObjectName(data.dataObjectName),
            userId(data.userId),
            scope(data.scope),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.allowUserIds)
            {
                allowUserIds = data.allowUserIds->deepCopy();
            }
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
    UpdateDataObjectByUserIdRequest() = default;
    UpdateDataObjectByUserIdRequest(const UpdateDataObjectByUserIdRequest& updateDataObjectByUserIdRequest) = default;
    UpdateDataObjectByUserIdRequest(UpdateDataObjectByUserIdRequest&& updateDataObjectByUserIdRequest) = default;
    ~UpdateDataObjectByUserIdRequest() GS2_OVERRIDE = default;

    UpdateDataObjectByUserIdRequest& operator=(const UpdateDataObjectByUserIdRequest& updateDataObjectByUserIdRequest) = default;
    UpdateDataObjectByUserIdRequest& operator=(UpdateDataObjectByUserIdRequest&& updateDataObjectByUserIdRequest) = default;

    UpdateDataObjectByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateDataObjectByUserIdRequest);
    }

    const UpdateDataObjectByUserIdRequest* operator->() const
    {
        return this;
    }

    UpdateDataObjectByUserIdRequest* operator->()
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
    UpdateDataObjectByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    UpdateDataObjectByUserIdRequest& withDataObjectName(StringHolder dataObjectName)
    {
        ensureData().dataObjectName.emplace(std::move(dataObjectName));
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
    UpdateDataObjectByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * ファイルのアクセス権を取得
     *
     * @return ファイルのアクセス権
     */
    const optional<StringHolder>& getScope() const
    {
        return ensureData().scope;
    }

    /**
     * ファイルのアクセス権を設定
     *
     * @param scope ファイルのアクセス権
     */
    void setScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
    }

    /**
     * ファイルのアクセス権を設定
     *
     * @param scope ファイルのアクセス権
     */
    UpdateDataObjectByUserIdRequest& withScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
        return *this;
    }

    /**
     * 公開するユーザIDリストを取得
     *
     * @return 公開するユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 公開するユーザIDリストを設定
     *
     * @param allowUserIds 公開するユーザIDリスト
     */
    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
    }

    /**
     * 公開するユーザIDリストを設定
     *
     * @param allowUserIds 公開するユーザIDリスト
     */
    UpdateDataObjectByUserIdRequest& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
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
    UpdateDataObjectByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    UpdateDataObjectByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateDataObjectByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DATASTORE_CONTROL_UPDATEDATAOBJECTBYUSERIDREQUEST_HPP_