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

#ifndef GS2_FORMATION_CONTROL_CREATEMOLDMODELMASTERREQUEST_HPP_
#define GS2_FORMATION_CONTROL_CREATEMOLDMODELMASTERREQUEST_HPP_

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
 * フォームの保存領域マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateMoldModelMasterRequest : public Gs2BasicRequest, public Gs2Formation
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** フォームの保存領域名 */
        optional<StringHolder> name;
        /** フォームの保存領域マスターの説明 */
        optional<StringHolder> description;
        /** フォームの保存領域のメタデータ */
        optional<StringHolder> metadata;
        /** フォームマスター */
        optional<StringHolder> formModelId;
        /** フォームを保存できる初期キャパシティ */
        optional<Int32> initialMaxCapacity;
        /** フォームを保存できるキャパシティ */
        optional<Int32> maxCapacity;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            formModelId(data.formModelId),
            initialMaxCapacity(data.initialMaxCapacity),
            maxCapacity(data.maxCapacity)
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
    CreateMoldModelMasterRequest() = default;
    CreateMoldModelMasterRequest(const CreateMoldModelMasterRequest& createMoldModelMasterRequest) = default;
    CreateMoldModelMasterRequest(CreateMoldModelMasterRequest&& createMoldModelMasterRequest) = default;
    ~CreateMoldModelMasterRequest() GS2_OVERRIDE = default;

    CreateMoldModelMasterRequest& operator=(const CreateMoldModelMasterRequest& createMoldModelMasterRequest) = default;
    CreateMoldModelMasterRequest& operator=(CreateMoldModelMasterRequest&& createMoldModelMasterRequest) = default;

    CreateMoldModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateMoldModelMasterRequest);
    }

    const CreateMoldModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateMoldModelMasterRequest* operator->()
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
    CreateMoldModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * フォームの保存領域名を取得
     *
     * @return フォームの保存領域名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    CreateMoldModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * フォームの保存領域マスターの説明を取得
     *
     * @return フォームの保存領域マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * フォームの保存領域マスターの説明を設定
     *
     * @param description フォームの保存領域マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * フォームの保存領域マスターの説明を設定
     *
     * @param description フォームの保存領域マスターの説明
     */
    CreateMoldModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * フォームの保存領域のメタデータを取得
     *
     * @return フォームの保存領域のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * フォームの保存領域のメタデータを設定
     *
     * @param metadata フォームの保存領域のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * フォームの保存領域のメタデータを設定
     *
     * @param metadata フォームの保存領域のメタデータ
     */
    CreateMoldModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * フォームマスターを取得
     *
     * @return フォームマスター
     */
    const optional<StringHolder>& getFormModelId() const
    {
        return ensureData().formModelId;
    }

    /**
     * フォームマスターを設定
     *
     * @param formModelId フォームマスター
     */
    void setFormModelId(StringHolder formModelId)
    {
        ensureData().formModelId.emplace(std::move(formModelId));
    }

    /**
     * フォームマスターを設定
     *
     * @param formModelId フォームマスター
     */
    CreateMoldModelMasterRequest& withFormModelId(StringHolder formModelId)
    {
        ensureData().formModelId.emplace(std::move(formModelId));
        return *this;
    }

    /**
     * フォームを保存できる初期キャパシティを取得
     *
     * @return フォームを保存できる初期キャパシティ
     */
    const optional<Int32>& getInitialMaxCapacity() const
    {
        return ensureData().initialMaxCapacity;
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    void setInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        ensureData().initialMaxCapacity.emplace(initialMaxCapacity);
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    CreateMoldModelMasterRequest& withInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        ensureData().initialMaxCapacity.emplace(initialMaxCapacity);
        return *this;
    }

    /**
     * フォームを保存できるキャパシティを取得
     *
     * @return フォームを保存できるキャパシティ
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    CreateMoldModelMasterRequest& withMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateMoldModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateMoldModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_CREATEMOLDMODELMASTERREQUEST_HPP_