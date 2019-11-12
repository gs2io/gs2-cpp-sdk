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

#ifndef GS2_LOG_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_LOG_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/log/Gs2LogConst.hpp>
#include <gs2/log/model/model.hpp>
#include <memory>

namespace gs2 { namespace log
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Log
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ログの書き出し方法 */
        optional<StringHolder> type;
        /** GCPのクレデンシャル */
        optional<StringHolder> gcpCredentialJson;
        /** BigQueryのデータセット名 */
        optional<StringHolder> bigQueryDatasetName;
        /** ログの保存期間(日) */
        optional<Int32> logExpireDays;
        /** AWSのリージョン */
        optional<StringHolder> awsRegion;
        /** AWSのアクセスキーID */
        optional<StringHolder> awsAccessKeyId;
        /** AWSのシークレットアクセスキー */
        optional<StringHolder> awsSecretAccessKey;
        /** Kinesis Firehose のストリーム名 */
        optional<StringHolder> firehoseStreamName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            type(data.type),
            gcpCredentialJson(data.gcpCredentialJson),
            bigQueryDatasetName(data.bigQueryDatasetName),
            logExpireDays(data.logExpireDays),
            awsRegion(data.awsRegion),
            awsAccessKeyId(data.awsAccessKeyId),
            awsSecretAccessKey(data.awsSecretAccessKey),
            firehoseStreamName(data.firehoseStreamName)
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
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
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
     * ログの書き出し方法を取得
     *
     * @return ログの書き出し方法
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * ログの書き出し方法を設定
     *
     * @param type ログの書き出し方法
     */
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * ログの書き出し方法を設定
     *
     * @param type ログの書き出し方法
     */
    UpdateNamespaceRequest& withType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
        return *this;
    }

    /**
     * GCPのクレデンシャルを取得
     *
     * @return GCPのクレデンシャル
     */
    const optional<StringHolder>& getGcpCredentialJson() const
    {
        return ensureData().gcpCredentialJson;
    }

    /**
     * GCPのクレデンシャルを設定
     *
     * @param gcpCredentialJson GCPのクレデンシャル
     */
    void setGcpCredentialJson(StringHolder gcpCredentialJson)
    {
        ensureData().gcpCredentialJson.emplace(std::move(gcpCredentialJson));
    }

    /**
     * GCPのクレデンシャルを設定
     *
     * @param gcpCredentialJson GCPのクレデンシャル
     */
    UpdateNamespaceRequest& withGcpCredentialJson(StringHolder gcpCredentialJson)
    {
        ensureData().gcpCredentialJson.emplace(std::move(gcpCredentialJson));
        return *this;
    }

    /**
     * BigQueryのデータセット名を取得
     *
     * @return BigQueryのデータセット名
     */
    const optional<StringHolder>& getBigQueryDatasetName() const
    {
        return ensureData().bigQueryDatasetName;
    }

    /**
     * BigQueryのデータセット名を設定
     *
     * @param bigQueryDatasetName BigQueryのデータセット名
     */
    void setBigQueryDatasetName(StringHolder bigQueryDatasetName)
    {
        ensureData().bigQueryDatasetName.emplace(std::move(bigQueryDatasetName));
    }

    /**
     * BigQueryのデータセット名を設定
     *
     * @param bigQueryDatasetName BigQueryのデータセット名
     */
    UpdateNamespaceRequest& withBigQueryDatasetName(StringHolder bigQueryDatasetName)
    {
        ensureData().bigQueryDatasetName.emplace(std::move(bigQueryDatasetName));
        return *this;
    }

    /**
     * ログの保存期間(日)を取得
     *
     * @return ログの保存期間(日)
     */
    const optional<Int32>& getLogExpireDays() const
    {
        return ensureData().logExpireDays;
    }

    /**
     * ログの保存期間(日)を設定
     *
     * @param logExpireDays ログの保存期間(日)
     */
    void setLogExpireDays(Int32 logExpireDays)
    {
        ensureData().logExpireDays.emplace(logExpireDays);
    }

    /**
     * ログの保存期間(日)を設定
     *
     * @param logExpireDays ログの保存期間(日)
     */
    UpdateNamespaceRequest& withLogExpireDays(Int32 logExpireDays)
    {
        ensureData().logExpireDays.emplace(logExpireDays);
        return *this;
    }

    /**
     * AWSのリージョンを取得
     *
     * @return AWSのリージョン
     */
    const optional<StringHolder>& getAwsRegion() const
    {
        return ensureData().awsRegion;
    }

    /**
     * AWSのリージョンを設定
     *
     * @param awsRegion AWSのリージョン
     */
    void setAwsRegion(StringHolder awsRegion)
    {
        ensureData().awsRegion.emplace(std::move(awsRegion));
    }

    /**
     * AWSのリージョンを設定
     *
     * @param awsRegion AWSのリージョン
     */
    UpdateNamespaceRequest& withAwsRegion(StringHolder awsRegion)
    {
        ensureData().awsRegion.emplace(std::move(awsRegion));
        return *this;
    }

    /**
     * AWSのアクセスキーIDを取得
     *
     * @return AWSのアクセスキーID
     */
    const optional<StringHolder>& getAwsAccessKeyId() const
    {
        return ensureData().awsAccessKeyId;
    }

    /**
     * AWSのアクセスキーIDを設定
     *
     * @param awsAccessKeyId AWSのアクセスキーID
     */
    void setAwsAccessKeyId(StringHolder awsAccessKeyId)
    {
        ensureData().awsAccessKeyId.emplace(std::move(awsAccessKeyId));
    }

    /**
     * AWSのアクセスキーIDを設定
     *
     * @param awsAccessKeyId AWSのアクセスキーID
     */
    UpdateNamespaceRequest& withAwsAccessKeyId(StringHolder awsAccessKeyId)
    {
        ensureData().awsAccessKeyId.emplace(std::move(awsAccessKeyId));
        return *this;
    }

    /**
     * AWSのシークレットアクセスキーを取得
     *
     * @return AWSのシークレットアクセスキー
     */
    const optional<StringHolder>& getAwsSecretAccessKey() const
    {
        return ensureData().awsSecretAccessKey;
    }

    /**
     * AWSのシークレットアクセスキーを設定
     *
     * @param awsSecretAccessKey AWSのシークレットアクセスキー
     */
    void setAwsSecretAccessKey(StringHolder awsSecretAccessKey)
    {
        ensureData().awsSecretAccessKey.emplace(std::move(awsSecretAccessKey));
    }

    /**
     * AWSのシークレットアクセスキーを設定
     *
     * @param awsSecretAccessKey AWSのシークレットアクセスキー
     */
    UpdateNamespaceRequest& withAwsSecretAccessKey(StringHolder awsSecretAccessKey)
    {
        ensureData().awsSecretAccessKey.emplace(std::move(awsSecretAccessKey));
        return *this;
    }

    /**
     * Kinesis Firehose のストリーム名を取得
     *
     * @return Kinesis Firehose のストリーム名
     */
    const optional<StringHolder>& getFirehoseStreamName() const
    {
        return ensureData().firehoseStreamName;
    }

    /**
     * Kinesis Firehose のストリーム名を設定
     *
     * @param firehoseStreamName Kinesis Firehose のストリーム名
     */
    void setFirehoseStreamName(StringHolder firehoseStreamName)
    {
        ensureData().firehoseStreamName.emplace(std::move(firehoseStreamName));
    }

    /**
     * Kinesis Firehose のストリーム名を設定
     *
     * @param firehoseStreamName Kinesis Firehose のストリーム名
     */
    UpdateNamespaceRequest& withFirehoseStreamName(StringHolder firehoseStreamName)
    {
        ensureData().firehoseStreamName.emplace(std::move(firehoseStreamName));
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

#endif //GS2_LOG_CONTROL_UPDATENAMESPACEREQUEST_HPP_