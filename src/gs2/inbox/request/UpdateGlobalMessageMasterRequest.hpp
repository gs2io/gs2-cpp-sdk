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

#ifndef GS2_INBOX_CONTROL_UPDATEGLOBALMESSAGEMASTERREQUEST_HPP_
#define GS2_INBOX_CONTROL_UPDATEGLOBALMESSAGEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inbox/Gs2InboxConst.hpp>
#include <gs2/inbox/model/model.hpp>
#include <memory>

namespace gs2 { namespace inbox
{

/**
 * 全ユーザに向けたメッセージを開封 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateGlobalMessageMasterRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 全ユーザに向けたメッセージ名 */
        optional<StringHolder> globalMessageName;
        /** 全ユーザに向けたメッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** 開封時に実行する入手アクション */
        optional<List<AcquireAction>> readAcquireActions;
        /** メッセージを受信したあとメッセージが削除されるまでの期間 */
        optional<TimeSpan> expiresTimeSpan;
        /** 全ユーザに向けたメッセージの受信期限 */
        optional<Int64> expiresAt;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            globalMessageName(data.globalMessageName),
            metadata(data.metadata),
            expiresAt(data.expiresAt)
        {
            if (data.readAcquireActions)
            {
                readAcquireActions = data.readAcquireActions->deepCopy();
            }
            if (data.expiresTimeSpan)
            {
                expiresTimeSpan = data.expiresTimeSpan->deepCopy();
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
    UpdateGlobalMessageMasterRequest() = default;
    UpdateGlobalMessageMasterRequest(const UpdateGlobalMessageMasterRequest& updateGlobalMessageMasterRequest) = default;
    UpdateGlobalMessageMasterRequest(UpdateGlobalMessageMasterRequest&& updateGlobalMessageMasterRequest) = default;
    ~UpdateGlobalMessageMasterRequest() GS2_OVERRIDE = default;

    UpdateGlobalMessageMasterRequest& operator=(const UpdateGlobalMessageMasterRequest& updateGlobalMessageMasterRequest) = default;
    UpdateGlobalMessageMasterRequest& operator=(UpdateGlobalMessageMasterRequest&& updateGlobalMessageMasterRequest) = default;

    UpdateGlobalMessageMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateGlobalMessageMasterRequest);
    }

    const UpdateGlobalMessageMasterRequest* operator->() const
    {
        return this;
    }

    UpdateGlobalMessageMasterRequest* operator->()
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
    UpdateGlobalMessageMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージ名を取得
     *
     * @return 全ユーザに向けたメッセージ名
     */
    const optional<StringHolder>& getGlobalMessageName() const
    {
        return ensureData().globalMessageName;
    }

    /**
     * 全ユーザに向けたメッセージ名を設定
     *
     * @param globalMessageName 全ユーザに向けたメッセージ名
     */
    void setGlobalMessageName(StringHolder globalMessageName)
    {
        ensureData().globalMessageName.emplace(std::move(globalMessageName));
    }

    /**
     * 全ユーザに向けたメッセージ名を設定
     *
     * @param globalMessageName 全ユーザに向けたメッセージ名
     */
    UpdateGlobalMessageMasterRequest& withGlobalMessageName(StringHolder globalMessageName)
    {
        ensureData().globalMessageName.emplace(std::move(globalMessageName));
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを取得
     *
     * @return 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを設定
     *
     * @param metadata 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを設定
     *
     * @param metadata 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    UpdateGlobalMessageMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 開封時に実行する入手アクションを取得
     *
     * @return 開封時に実行する入手アクション
     */
    const optional<List<AcquireAction>>& getReadAcquireActions() const
    {
        return ensureData().readAcquireActions;
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    void setReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    UpdateGlobalMessageMasterRequest& withReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
        return *this;
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を取得
     *
     * @return メッセージを受信したあとメッセージが削除されるまでの期間
     */
    const optional<TimeSpan>& getExpiresTimeSpan() const
    {
        return ensureData().expiresTimeSpan;
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を設定
     *
     * @param expiresTimeSpan メッセージを受信したあとメッセージが削除されるまでの期間
     */
    void setExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        ensureData().expiresTimeSpan.emplace(std::move(expiresTimeSpan));
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を設定
     *
     * @param expiresTimeSpan メッセージを受信したあとメッセージが削除されるまでの期間
     */
    UpdateGlobalMessageMasterRequest& withExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        ensureData().expiresTimeSpan.emplace(std::move(expiresTimeSpan));
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を取得
     *
     * @return 全ユーザに向けたメッセージの受信期限
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を設定
     *
     * @param expiresAt 全ユーザに向けたメッセージの受信期限
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を設定
     *
     * @param expiresAt 全ユーザに向けたメッセージの受信期限
     */
    UpdateGlobalMessageMasterRequest& withExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGlobalMessageMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGlobalMessageMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INBOX_CONTROL_UPDATEGLOBALMESSAGEMASTERREQUEST_HPP_