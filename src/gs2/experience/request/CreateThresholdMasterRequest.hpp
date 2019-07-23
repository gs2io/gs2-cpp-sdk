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

#ifndef GS2_EXPERIENCE_CONTROL_CREATETHRESHOLDMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_CREATETHRESHOLDMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ランクアップ閾値マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateThresholdMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ランクアップ閾値名 */
        optional<StringHolder> name;
        /** ランクアップ閾値マスターの説明 */
        optional<StringHolder> description;
        /** ランクアップ閾値のメタデータ */
        optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        optional<List<Int64>> values;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            values(data.values)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            values(std::move(data.values))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    CreateThresholdMasterRequest() :
        m_pData(nullptr)
    {}

    CreateThresholdMasterRequest(const CreateThresholdMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateThresholdMasterRequest(CreateThresholdMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateThresholdMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateThresholdMasterRequest& operator=(const CreateThresholdMasterRequest& createThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(createThresholdMasterRequest);
        Gs2Experience::operator=(createThresholdMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createThresholdMasterRequest.m_pData);

        return *this;
    }

    CreateThresholdMasterRequest& operator=(CreateThresholdMasterRequest&& createThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createThresholdMasterRequest));
        Gs2Experience::operator=(std::move(createThresholdMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createThresholdMasterRequest.m_pData;
        createThresholdMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateThresholdMasterRequest* operator->() const
    {
        return this;
    }

    CreateThresholdMasterRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    CreateThresholdMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * ランクアップ閾値名を取得
     *
     * @return ランクアップ閾値名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param name ランクアップ閾値名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param name ランクアップ閾値名
     */
    CreateThresholdMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * ランクアップ閾値マスターの説明を取得
     *
     * @return ランクアップ閾値マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ランクアップ閾値マスターの説明を設定
     *
     * @param description ランクアップ閾値マスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ランクアップ閾値マスターの説明を設定
     *
     * @param description ランクアップ閾値マスターの説明
     */
    CreateThresholdMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * ランクアップ閾値のメタデータを取得
     *
     * @return ランクアップ閾値のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * ランクアップ閾値のメタデータを設定
     *
     * @param metadata ランクアップ閾値のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * ランクアップ閾値のメタデータを設定
     *
     * @param metadata ランクアップ閾値のメタデータ
     */
    CreateThresholdMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * ランクアップ経験値閾値リストを取得
     *
     * @return ランクアップ経験値閾値リスト
     */
    const optional<List<Int64>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランクアップ経験値閾値リストを設定
     *
     * @param values ランクアップ経験値閾値リスト
     */
    void setValues(const List<Int64>& values)
    {
        ensureData().values.emplace(values);
    }

    /**
     * ランクアップ経験値閾値リストを設定
     *
     * @param values ランクアップ経験値閾値リスト
     */
    CreateThresholdMasterRequest& withValues(const List<Int64>& values)
    {
        ensureData().values.emplace(values);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateThresholdMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateThresholdMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateThresholdMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateThresholdMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_CREATETHRESHOLDMASTERREQUEST_HPP_