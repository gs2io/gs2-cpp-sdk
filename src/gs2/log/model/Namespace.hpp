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

#ifndef GS2_LOG_MODEL_NAMESPACE_HPP_
#define GS2_LOG_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace log {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** カテゴリー名 */
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const;

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    Namespace& withType(StringHolder type)
    {
        setType(std::move(type));
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
    Namespace& withGcpCredentialJson(StringHolder gcpCredentialJson)
    {
        setGcpCredentialJson(std::move(gcpCredentialJson));
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
    Namespace& withBigQueryDatasetName(StringHolder bigQueryDatasetName)
    {
        setBigQueryDatasetName(std::move(bigQueryDatasetName));
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
    Namespace& withLogExpireDays(Int32 logExpireDays)
    {
        setLogExpireDays(logExpireDays);
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
    Namespace& withAwsRegion(StringHolder awsRegion)
    {
        setAwsRegion(std::move(awsRegion));
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
    Namespace& withAwsAccessKeyId(StringHolder awsAccessKeyId)
    {
        setAwsAccessKeyId(std::move(awsAccessKeyId));
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
    Namespace& withAwsSecretAccessKey(StringHolder awsSecretAccessKey)
    {
        setAwsSecretAccessKey(std::move(awsSecretAccessKey));
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
    Namespace& withFirehoseStreamName(StringHolder firehoseStreamName)
    {
        setFirehoseStreamName(std::move(firehoseStreamName));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Namespace& lhs, const Namespace& lhr);

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_NAMESPACE_HPP_