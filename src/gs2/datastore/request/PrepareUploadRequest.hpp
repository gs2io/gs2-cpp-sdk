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

#ifndef GS2_DATASTORE_CONTROL_PREPAREUPLOADREQUEST_HPP_
#define GS2_DATASTORE_CONTROL_PREPAREUPLOADREQUEST_HPP_

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
 * データオブジェクトをアップロード準備する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class PrepareUploadRequest : public Gs2BasicRequest, public Gs2Datastore
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** データの名前 */
        optional<StringHolder> name;
        /** アップロードするデータの MIME-Type */
        optional<StringHolder> contentType;
        /** ファイルのアクセス権 */
        optional<StringHolder> scope;
        /** 公開するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** 既にデータが存在する場合にエラーとするか、データを更新するか */
        optional<Bool> updateIfExists;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            name(data.name),
            contentType(data.contentType),
            scope(data.scope),
            updateIfExists(data.updateIfExists),
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
    PrepareUploadRequest() = default;
    PrepareUploadRequest(const PrepareUploadRequest& prepareUploadRequest) = default;
    PrepareUploadRequest(PrepareUploadRequest&& prepareUploadRequest) = default;
    ~PrepareUploadRequest() GS2_OVERRIDE = default;

    PrepareUploadRequest& operator=(const PrepareUploadRequest& prepareUploadRequest) = default;
    PrepareUploadRequest& operator=(PrepareUploadRequest&& prepareUploadRequest) = default;

    PrepareUploadRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PrepareUploadRequest);
    }

    const PrepareUploadRequest* operator->() const
    {
        return this;
    }

    PrepareUploadRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    PrepareUploadRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    PrepareUploadRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * データの名前を取得
     *
     * @return データの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * データの名前を設定
     *
     * @param name データの名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * データの名前を設定
     *
     * @param name データの名前
     */
    PrepareUploadRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * アップロードするデータの MIME-Typeを取得
     *
     * @return アップロードするデータの MIME-Type
     */
    const optional<StringHolder>& getContentType() const
    {
        return ensureData().contentType;
    }

    /**
     * アップロードするデータの MIME-Typeを設定
     *
     * @param contentType アップロードするデータの MIME-Type
     */
    void setContentType(StringHolder contentType)
    {
        ensureData().contentType.emplace(std::move(contentType));
    }

    /**
     * アップロードするデータの MIME-Typeを設定
     *
     * @param contentType アップロードするデータの MIME-Type
     */
    PrepareUploadRequest& withContentType(StringHolder contentType)
    {
        ensureData().contentType.emplace(std::move(contentType));
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
    PrepareUploadRequest& withScope(StringHolder scope)
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
    PrepareUploadRequest& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
        return *this;
    }

    /**
     * 既にデータが存在する場合にエラーとするか、データを更新するかを取得
     *
     * @return 既にデータが存在する場合にエラーとするか、データを更新するか
     */
    const optional<Bool>& getUpdateIfExists() const
    {
        return ensureData().updateIfExists;
    }

    /**
     * 既にデータが存在する場合にエラーとするか、データを更新するかを設定
     *
     * @param updateIfExists 既にデータが存在する場合にエラーとするか、データを更新するか
     */
    void setUpdateIfExists(Bool updateIfExists)
    {
        ensureData().updateIfExists.emplace(updateIfExists);
    }

    /**
     * 既にデータが存在する場合にエラーとするか、データを更新するかを設定
     *
     * @param updateIfExists 既にデータが存在する場合にエラーとするか、データを更新するか
     */
    PrepareUploadRequest& withUpdateIfExists(Bool updateIfExists)
    {
        ensureData().updateIfExists.emplace(updateIfExists);
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
    PrepareUploadRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    PrepareUploadRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PrepareUploadRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DATASTORE_CONTROL_PREPAREUPLOADREQUEST_HPP_