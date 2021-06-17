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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

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
        /** None */
        optional<StringHolder> status;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            type(data.type),
            gcpCredentialJson(data.gcpCredentialJson),
            bigQueryDatasetName(data.bigQueryDatasetName),
            logExpireDays(data.logExpireDays),
            awsRegion(data.awsRegion),
            awsAccessKeyId(data.awsAccessKeyId),
            awsSecretAccessKey(data.awsSecretAccessKey),
            firehoseStreamName(data.firehoseStreamName),
            status(data.status),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "gcpCredentialJson") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->gcpCredentialJson.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "bigQueryDatasetName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->bigQueryDatasetName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "logExpireDays") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->logExpireDays = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "awsRegion") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->awsRegion.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "awsAccessKeyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->awsAccessKeyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "awsSecretAccessKey") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->awsSecretAccessKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "firehoseStreamName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->firehoseStreamName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "status") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
    }

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
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * Noneを設定
     *
     * @param status None
     */
    void setStatus(StringHolder status)
    {
        ensureData().status.emplace(std::move(status));
    }

    /**
     * Noneを設定
     *
     * @param status None
     */
    Namespace& withStatus(StringHolder status)
    {
        setStatus(std::move(status));
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

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->gcpCredentialJson != lhr.m_pData->gcpCredentialJson)
        {
            return true;
        }
        if (lhs.m_pData->bigQueryDatasetName != lhr.m_pData->bigQueryDatasetName)
        {
            return true;
        }
        if (lhs.m_pData->logExpireDays != lhr.m_pData->logExpireDays)
        {
            return true;
        }
        if (lhs.m_pData->awsRegion != lhr.m_pData->awsRegion)
        {
            return true;
        }
        if (lhs.m_pData->awsAccessKeyId != lhr.m_pData->awsAccessKeyId)
        {
            return true;
        }
        if (lhs.m_pData->awsSecretAccessKey != lhr.m_pData->awsSecretAccessKey)
        {
            return true;
        }
        if (lhs.m_pData->firehoseStreamName != lhr.m_pData->firehoseStreamName)
        {
            return true;
        }
        if (lhs.m_pData->status != lhr.m_pData->status)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_NAMESPACE_HPP_