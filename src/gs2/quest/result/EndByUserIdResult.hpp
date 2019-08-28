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

#ifndef GS2_QUEST_CONTROL_ENDBYUSERIDRESULT_HPP_
#define GS2_QUEST_CONTROL_ENDBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエストを完了 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class EndByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト挑戦 */
        optional<Progress> item;
        /** 報酬付与処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            stampSheet(data.stampSheet)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            stampSheet(std::move(data.stampSheet))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "stampSheet") == 0) {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
        }
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
    EndByUserIdResult() :
        m_pData(nullptr)
    {}

    EndByUserIdResult(const EndByUserIdResult& endByUserIdResult) :
        Gs2Object(endByUserIdResult),
        m_pData(endByUserIdResult.m_pData != nullptr ? new Data(*endByUserIdResult.m_pData) : nullptr)
    {}

    EndByUserIdResult(EndByUserIdResult&& endByUserIdResult) :
        Gs2Object(std::move(endByUserIdResult)),
        m_pData(endByUserIdResult.m_pData)
    {
        endByUserIdResult.m_pData = nullptr;
    }

    ~EndByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    EndByUserIdResult& operator=(const EndByUserIdResult& endByUserIdResult)
    {
        Gs2Object::operator=(endByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*endByUserIdResult.m_pData);

        return *this;
    }

    EndByUserIdResult& operator=(EndByUserIdResult&& endByUserIdResult)
    {
        Gs2Object::operator=(std::move(endByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = endByUserIdResult.m_pData;
        endByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const EndByUserIdResult* operator->() const
    {
        return this;
    }

    EndByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * クエスト挑戦を取得
     *
     * @return クエスト挑戦
     */
    const optional<Progress>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クエスト挑戦を設定
     *
     * @param item クエスト挑戦
     */
    void setItem(const Progress& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 報酬付与処理の実行に使用するスタンプシートを取得
     *
     * @return 報酬付与処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 報酬付与処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 報酬付与処理の実行に使用するスタンプシート
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<EndByUserIdResult> AsyncEndByUserIdResult;

} }

#endif //GS2_QUEST_CONTROL_ENDBYUSERIDRESULT_HPP_