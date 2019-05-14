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

#ifndef GS2_INVENTORY_CONTROL_CREATECATEGORYREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_CREATECATEGORYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * カテゴリを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateCategoryRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> name;
        /** カテゴリの説明 */
        optional<StringHolder> description;
        /** 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN */
        optional<StringHolder> overflowTriggerScriptId;
        /** 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRN */
        optional<StringHolder> overflowTriggerQueueId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerQueueId(data.overflowTriggerQueueId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerQueueId(std::move(data.overflowTriggerQueueId))
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
    CreateCategoryRequest() :
        m_pData(nullptr)
    {}

    CreateCategoryRequest(const CreateCategoryRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateCategoryRequest(CreateCategoryRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateCategoryRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateCategoryRequest& operator=(const CreateCategoryRequest& createCategoryRequest)
    {
        Gs2BasicRequest::operator=(createCategoryRequest);
        Gs2Inventory::operator=(createCategoryRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createCategoryRequest.m_pData);

        return *this;
    }

    CreateCategoryRequest& operator=(CreateCategoryRequest&& createCategoryRequest)
    {
        Gs2BasicRequest::operator=(std::move(createCategoryRequest));
        Gs2Inventory::operator=(std::move(createCategoryRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createCategoryRequest.m_pData;
        createCategoryRequest.m_pData = nullptr;

        return *this;
    }

    const CreateCategoryRequest* operator->() const
    {
        return this;
    }

    CreateCategoryRequest* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    CreateCategoryRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * カテゴリの説明を取得
     *
     * @return カテゴリの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * カテゴリの説明を設定
     *
     * @param description カテゴリの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * カテゴリの説明を設定
     *
     * @param description カテゴリの説明
     */
    CreateCategoryRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを取得
     *
     * @return 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    const optional<StringHolder>& getOverflowTriggerScriptId() const
    {
        return ensureData().overflowTriggerScriptId;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    void setOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    CreateCategoryRequest& withOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRNを取得
     *
     * @return 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRN
     */
    const optional<StringHolder>& getOverflowTriggerQueueId() const
    {
        return ensureData().overflowTriggerQueueId;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRNを設定
     *
     * @param overflowTriggerQueueId 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRN
     */
    void setOverflowTriggerQueueId(const Char* overflowTriggerQueueId)
    {
        ensureData().overflowTriggerQueueId.emplace(overflowTriggerQueueId);
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRNを設定
     *
     * @param overflowTriggerQueueId 入手上限に当たって入手できなかった数量を通知するジョブを追加する キュー のGRN
     */
    CreateCategoryRequest& withOverflowTriggerQueueId(const Char* overflowTriggerQueueId)
    {
        ensureData().overflowTriggerQueueId.emplace(overflowTriggerQueueId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateCategoryRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateCategoryRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateCategoryRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateCategoryRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INVENTORY_CONTROL_CREATECATEGORYREQUEST_HPP_