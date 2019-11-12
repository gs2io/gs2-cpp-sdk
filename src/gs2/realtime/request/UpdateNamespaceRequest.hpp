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

#ifndef GS2_REALTIME_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_REALTIME_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/realtime/Gs2RealtimeConst.hpp>
#include <gs2/realtime/model/model.hpp>
#include <memory>

namespace gs2 { namespace realtime
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Realtime
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** サーバの種類 */
        optional<StringHolder> serverType;
        /** サーバのスペック */
        optional<StringHolder> serverSpec;
        /** ルームの作成が終わったときのプッシュ通知 */
        optional<NotificationSetting> createNotification;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            serverType(data.serverType),
            serverSpec(data.serverSpec)
        {
            if (data.createNotification)
            {
                createNotification = data.createNotification->deepCopy();
            }
            if (data.logSetting)
            {
                logSetting = data.logSetting->deepCopy();
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
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
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
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * サーバの種類を取得
     *
     * @return サーバの種類
     */
    const optional<StringHolder>& getServerType() const
    {
        return ensureData().serverType;
    }

    /**
     * サーバの種類を設定
     *
     * @param serverType サーバの種類
     */
    void setServerType(StringHolder serverType)
    {
        ensureData().serverType.emplace(std::move(serverType));
    }

    /**
     * サーバの種類を設定
     *
     * @param serverType サーバの種類
     */
    UpdateNamespaceRequest& withServerType(StringHolder serverType)
    {
        ensureData().serverType.emplace(std::move(serverType));
        return *this;
    }

    /**
     * サーバのスペックを取得
     *
     * @return サーバのスペック
     */
    const optional<StringHolder>& getServerSpec() const
    {
        return ensureData().serverSpec;
    }

    /**
     * サーバのスペックを設定
     *
     * @param serverSpec サーバのスペック
     */
    void setServerSpec(StringHolder serverSpec)
    {
        ensureData().serverSpec.emplace(std::move(serverSpec));
    }

    /**
     * サーバのスペックを設定
     *
     * @param serverSpec サーバのスペック
     */
    UpdateNamespaceRequest& withServerSpec(StringHolder serverSpec)
    {
        ensureData().serverSpec.emplace(std::move(serverSpec));
        return *this;
    }

    /**
     * ルームの作成が終わったときのプッシュ通知を取得
     *
     * @return ルームの作成が終わったときのプッシュ通知
     */
    const optional<NotificationSetting>& getCreateNotification() const
    {
        return ensureData().createNotification;
    }

    /**
     * ルームの作成が終わったときのプッシュ通知を設定
     *
     * @param createNotification ルームの作成が終わったときのプッシュ通知
     */
    void setCreateNotification(NotificationSetting createNotification)
    {
        ensureData().createNotification.emplace(std::move(createNotification));
    }

    /**
     * ルームの作成が終わったときのプッシュ通知を設定
     *
     * @param createNotification ルームの作成が終わったときのプッシュ通知
     */
    UpdateNamespaceRequest& withCreateNotification(NotificationSetting createNotification)
    {
        ensureData().createNotification.emplace(std::move(createNotification));
        return *this;
    }

    /**
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    UpdateNamespaceRequest& withLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_REALTIME_CONTROL_UPDATENAMESPACEREQUEST_HPP_