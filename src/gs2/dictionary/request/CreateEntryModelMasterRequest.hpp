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

#ifndef GS2_DICTIONARY_CONTROL_CREATEENTRYMODELMASTERREQUEST_HPP_
#define GS2_DICTIONARY_CONTROL_CREATEENTRYMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/dictionary/Gs2DictionaryConst.hpp>
#include <gs2/dictionary/model/model.hpp>
#include <memory>

namespace gs2 { namespace dictionary
{

/**
 * エントリーモデルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateEntryModelMasterRequest : public Gs2BasicRequest, public Gs2Dictionary
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** エントリーモデル名 */
        optional<StringHolder> name;
        /** エントリーモデルマスターの説明 */
        optional<StringHolder> description;
        /** エントリーモデルのメタデータ */
        optional<StringHolder> metadata;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata)
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
    CreateEntryModelMasterRequest() = default;
    CreateEntryModelMasterRequest(const CreateEntryModelMasterRequest& createEntryModelMasterRequest) = default;
    CreateEntryModelMasterRequest(CreateEntryModelMasterRequest&& createEntryModelMasterRequest) = default;
    ~CreateEntryModelMasterRequest() GS2_OVERRIDE = default;

    CreateEntryModelMasterRequest& operator=(const CreateEntryModelMasterRequest& createEntryModelMasterRequest) = default;
    CreateEntryModelMasterRequest& operator=(CreateEntryModelMasterRequest&& createEntryModelMasterRequest) = default;

    CreateEntryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateEntryModelMasterRequest);
    }

    const CreateEntryModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateEntryModelMasterRequest* operator->()
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
    CreateEntryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * エントリーモデル名を取得
     *
     * @return エントリーモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * エントリーモデル名を設定
     *
     * @param name エントリーモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * エントリーモデル名を設定
     *
     * @param name エントリーモデル名
     */
    CreateEntryModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * エントリーモデルマスターの説明を取得
     *
     * @return エントリーモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * エントリーモデルマスターの説明を設定
     *
     * @param description エントリーモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * エントリーモデルマスターの説明を設定
     *
     * @param description エントリーモデルマスターの説明
     */
    CreateEntryModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * エントリーモデルのメタデータを取得
     *
     * @return エントリーモデルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * エントリーモデルのメタデータを設定
     *
     * @param metadata エントリーモデルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * エントリーモデルのメタデータを設定
     *
     * @param metadata エントリーモデルのメタデータ
     */
    CreateEntryModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateEntryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateEntryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DICTIONARY_CONTROL_CREATEENTRYMODELMASTERREQUEST_HPP_