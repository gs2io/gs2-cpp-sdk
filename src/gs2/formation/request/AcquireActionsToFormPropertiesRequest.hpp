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

#ifndef GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESREQUEST_HPP_
#define GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/Gs2FormationConst.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * 署名付きスロットを使ってフォームを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AcquireActionsToFormPropertiesRequest : public Gs2BasicRequest, public Gs2Formation
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
        /** フォームの保存領域の名前 */
        optional<StringHolder> moldName;
        /** 保存領域のインデックス */
        optional<Int32> index;
        /** フォームのプロパティに適用する入手アクション */
        optional<AcquireAction> acquireAction;
        /** 入手処理を登録する GS2-JobQueue のネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 入手アクションに適用するコンフィグ */
        optional<List<AcquireActionConfig>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            moldName(data.moldName),
            index(data.index),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.acquireAction)
            {
                acquireAction = data.acquireAction->deepCopy();
            }
            if (data.config)
            {
                config = data.config->deepCopy();
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
    AcquireActionsToFormPropertiesRequest() = default;
    AcquireActionsToFormPropertiesRequest(const AcquireActionsToFormPropertiesRequest& acquireActionsToFormPropertiesRequest) = default;
    AcquireActionsToFormPropertiesRequest(AcquireActionsToFormPropertiesRequest&& acquireActionsToFormPropertiesRequest) = default;
    ~AcquireActionsToFormPropertiesRequest() GS2_OVERRIDE = default;

    AcquireActionsToFormPropertiesRequest& operator=(const AcquireActionsToFormPropertiesRequest& acquireActionsToFormPropertiesRequest) = default;
    AcquireActionsToFormPropertiesRequest& operator=(AcquireActionsToFormPropertiesRequest&& acquireActionsToFormPropertiesRequest) = default;

    AcquireActionsToFormPropertiesRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcquireActionsToFormPropertiesRequest);
    }

    const AcquireActionsToFormPropertiesRequest* operator->() const
    {
        return this;
    }

    AcquireActionsToFormPropertiesRequest* operator->()
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
    AcquireActionsToFormPropertiesRequest& withNamespaceName(StringHolder namespaceName)
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
    AcquireActionsToFormPropertiesRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * フォームの保存領域の名前を取得
     *
     * @return フォームの保存領域の名前
     */
    const optional<StringHolder>& getMoldName() const
    {
        return ensureData().moldName;
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param moldName フォームの保存領域の名前
     */
    void setMoldName(StringHolder moldName)
    {
        ensureData().moldName.emplace(std::move(moldName));
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param moldName フォームの保存領域の名前
     */
    AcquireActionsToFormPropertiesRequest& withMoldName(StringHolder moldName)
    {
        ensureData().moldName.emplace(std::move(moldName));
        return *this;
    }

    /**
     * 保存領域のインデックスを取得
     *
     * @return 保存領域のインデックス
     */
    const optional<Int32>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * 保存領域のインデックスを設定
     *
     * @param index 保存領域のインデックス
     */
    void setIndex(Int32 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * 保存領域のインデックスを設定
     *
     * @param index 保存領域のインデックス
     */
    AcquireActionsToFormPropertiesRequest& withIndex(Int32 index)
    {
        ensureData().index.emplace(index);
        return *this;
    }

    /**
     * フォームのプロパティに適用する入手アクションを取得
     *
     * @return フォームのプロパティに適用する入手アクション
     */
    const optional<AcquireAction>& getAcquireAction() const
    {
        return ensureData().acquireAction;
    }

    /**
     * フォームのプロパティに適用する入手アクションを設定
     *
     * @param acquireAction フォームのプロパティに適用する入手アクション
     */
    void setAcquireAction(AcquireAction acquireAction)
    {
        ensureData().acquireAction.emplace(std::move(acquireAction));
    }

    /**
     * フォームのプロパティに適用する入手アクションを設定
     *
     * @param acquireAction フォームのプロパティに適用する入手アクション
     */
    AcquireActionsToFormPropertiesRequest& withAcquireAction(AcquireAction acquireAction)
    {
        ensureData().acquireAction.emplace(std::move(acquireAction));
        return *this;
    }

    /**
     * 入手処理を登録する GS2-JobQueue のネームスペース のGRNを取得
     *
     * @return 入手処理を登録する GS2-JobQueue のネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 入手処理を登録する GS2-JobQueue のネームスペース のGRNを設定
     *
     * @param queueNamespaceId 入手処理を登録する GS2-JobQueue のネームスペース のGRN
     */
    void setQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
    }

    /**
     * 入手処理を登録する GS2-JobQueue のネームスペース のGRNを設定
     *
     * @param queueNamespaceId 入手処理を登録する GS2-JobQueue のネームスペース のGRN
     */
    AcquireActionsToFormPropertiesRequest& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
        return *this;
    }

    /**
     * スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRNを取得
     *
     * @return スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの発行に使用する GS2-Key の暗号鍵 のGRN
     */
    AcquireActionsToFormPropertiesRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }

    /**
     * 入手アクションに適用するコンフィグを取得
     *
     * @return 入手アクションに適用するコンフィグ
     */
    const optional<List<AcquireActionConfig>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * 入手アクションに適用するコンフィグを設定
     *
     * @param config 入手アクションに適用するコンフィグ
     */
    void setConfig(List<AcquireActionConfig> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * 入手アクションに適用するコンフィグを設定
     *
     * @param config 入手アクションに適用するコンフィグ
     */
    AcquireActionsToFormPropertiesRequest& withConfig(List<AcquireActionConfig> config)
    {
        ensureData().config.emplace(std::move(config));
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
    AcquireActionsToFormPropertiesRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    AcquireActionsToFormPropertiesRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AcquireActionsToFormPropertiesRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_ACQUIREACTIONSTOFORMPROPERTIESREQUEST_HPP_