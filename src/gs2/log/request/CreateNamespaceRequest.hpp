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

#ifndef GS2_LOG_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_LOG_CONTROL_CREATENAMESPACEREQUEST_HPP_

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
 * ネームスペースを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Log
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> name;
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
            name(data.name),
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
    CreateNamespaceRequest() = default;
    CreateNamespaceRequest(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest(CreateNamespaceRequest&& createNamespaceRequest) = default;
    ~CreateNamespaceRequest() GS2_OVERRIDE = default;

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest) = default;

    CreateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateNamespaceRequest);
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    CreateNamespaceRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateNamespaceRequest& withDescription(StringHolder description)
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
    CreateNamespaceRequest& withType(StringHolder type)
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
    CreateNamespaceRequest& withGcpCredentialJson(StringHolder gcpCredentialJson)
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
    CreateNamespaceRequest& withBigQueryDatasetName(StringHolder bigQueryDatasetName)
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
    CreateNamespaceRequest& withLogExpireDays(Int32 logExpireDays)
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
    CreateNamespaceRequest& withAwsRegion(StringHolder awsRegion)
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
    CreateNamespaceRequest& withAwsAccessKeyId(StringHolder awsAccessKeyId)
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
    CreateNamespaceRequest& withAwsSecretAccessKey(StringHolder awsSecretAccessKey)
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
    CreateNamespaceRequest& withFirehoseStreamName(StringHolder firehoseStreamName)
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
    CreateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOG_CONTROL_CREATENAMESPACEREQUEST_HPP_