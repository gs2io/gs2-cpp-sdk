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

#ifndef GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace matchmaking
{

/**
 * 自分が参加できるギャザリングを探して参加する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DoMatchmakingResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリング */
        optional<Gathering> item;
        /** マッチメイキングの状態を保持するトークン */
        optional<StringHolder> matchmakingContextToken;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            matchmakingContextToken(data.matchmakingContextToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            matchmakingContextToken(std::move(data.matchmakingContextToken))
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
            else if (std::strcmp(name_, "matchmakingContextToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->matchmakingContextToken.emplace(jsonValue.GetString());
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
    DoMatchmakingResult() :
        m_pData(nullptr)
    {}

    DoMatchmakingResult(const DoMatchmakingResult& doMatchmakingResult) :
        Gs2Object(doMatchmakingResult),
        m_pData(doMatchmakingResult.m_pData != nullptr ? new Data(*doMatchmakingResult.m_pData) : nullptr)
    {}

    DoMatchmakingResult(DoMatchmakingResult&& doMatchmakingResult) :
        Gs2Object(std::move(doMatchmakingResult)),
        m_pData(doMatchmakingResult.m_pData)
    {
        doMatchmakingResult.m_pData = nullptr;
    }

    ~DoMatchmakingResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DoMatchmakingResult& operator=(const DoMatchmakingResult& doMatchmakingResult)
    {
        Gs2Object::operator=(doMatchmakingResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*doMatchmakingResult.m_pData);

        return *this;
    }

    DoMatchmakingResult& operator=(DoMatchmakingResult&& doMatchmakingResult)
    {
        Gs2Object::operator=(std::move(doMatchmakingResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = doMatchmakingResult.m_pData;
        doMatchmakingResult.m_pData = nullptr;

        return *this;
    }

    const DoMatchmakingResult* operator->() const
    {
        return this;
    }

    DoMatchmakingResult* operator->()
    {
        return this;
    }
    /**
     * ギャザリングを取得
     *
     * @return ギャザリング
     */
    const optional<Gathering>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ギャザリングを設定
     *
     * @param item ギャザリング
     */
    void setItem(const Gathering& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * マッチメイキングの状態を保持するトークンを取得
     *
     * @return マッチメイキングの状態を保持するトークン
     */
    const optional<StringHolder>& getMatchmakingContextToken() const
    {
        return ensureData().matchmakingContextToken;
    }

    /**
     * マッチメイキングの状態を保持するトークンを設定
     *
     * @param matchmakingContextToken マッチメイキングの状態を保持するトークン
     */
    void setMatchmakingContextToken(const Char* matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(matchmakingContextToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DoMatchmakingResult> AsyncDoMatchmakingResult;

} }

#endif //GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGRESULT_HPP_