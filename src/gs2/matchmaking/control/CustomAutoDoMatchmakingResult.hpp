/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace matchmaking
{

/**
 * @author Game Server Services, Inc.
 */
class CustomAutoDoMatchmakingResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** マッチメイキングが完了したか */
        optional<Bool> done;
        /** CustomAutoマッチメイキング ギャザリング */
        optional<CustomAutoGathering> item;
        /** 検索を再開するためのコンテキスト */
        optional<StringHolder> searchContext;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            done(data.done),
            item(data.item),
            searchContext(data.searchContext)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            done(std::move(data.done)),
            item(std::move(data.item)),
            searchContext(std::move(data.searchContext))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "done") == 0) {
                if (jsonValue.IsBool())
                {
                    this->done = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "searchContext") == 0) {
                if (jsonValue.IsString())
                {
                    this->searchContext.emplace(jsonValue.GetString());
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
    CustomAutoDoMatchmakingResult() :
        m_pData(nullptr)
    {}

    CustomAutoDoMatchmakingResult(const CustomAutoDoMatchmakingResult& customAutoDoMatchmakingResult) :
        Gs2Object(customAutoDoMatchmakingResult),
        m_pData(customAutoDoMatchmakingResult.m_pData != nullptr ? new Data(*customAutoDoMatchmakingResult.m_pData) : nullptr)
    {}

    CustomAutoDoMatchmakingResult(CustomAutoDoMatchmakingResult&& customAutoDoMatchmakingResult) :
        Gs2Object(std::move(customAutoDoMatchmakingResult)),
        m_pData(customAutoDoMatchmakingResult.m_pData)
    {
        customAutoDoMatchmakingResult.m_pData = nullptr;
    }

    ~CustomAutoDoMatchmakingResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CustomAutoDoMatchmakingResult& operator=(const CustomAutoDoMatchmakingResult& customAutoDoMatchmakingResult)
    {
        Gs2Object::operator=(customAutoDoMatchmakingResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*customAutoDoMatchmakingResult.m_pData);

        return *this;
    }

    CustomAutoDoMatchmakingResult& operator=(CustomAutoDoMatchmakingResult&& customAutoDoMatchmakingResult)
    {
        Gs2Object::operator=(std::move(customAutoDoMatchmakingResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = customAutoDoMatchmakingResult.m_pData;
        customAutoDoMatchmakingResult.m_pData = nullptr;

        return *this;
    }

    const CustomAutoDoMatchmakingResult* operator->() const
    {
        return this;
    }

    CustomAutoDoMatchmakingResult* operator->()
    {
        return this;
    }


    /**
     * マッチメイキングが完了したかを取得
     *
     * @return マッチメイキングが完了したか
     */
    const optional<Bool>& getDone() const
    {
        return ensureData().done;
    }

    /**
     * マッチメイキングが完了したかを設定
     *
     * @param done マッチメイキングが完了したか
     */
    void setDone(Bool done)
    {
        ensureData().done.emplace(done);
    }

    /**
     * CustomAutoマッチメイキング ギャザリングを取得
     *
     * @return CustomAutoマッチメイキング ギャザリング
     */
    const optional<CustomAutoGathering>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * CustomAutoマッチメイキング ギャザリングを設定
     *
     * @param item CustomAutoマッチメイキング ギャザリング
     */
    void setItem(const CustomAutoGathering& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 検索を再開するためのコンテキストを取得
     *
     * @return 検索を再開するためのコンテキスト
     */
    const optional<StringHolder>& getSearchContext() const
    {
        return ensureData().searchContext;
    }

    /**
     * 検索を再開するためのコンテキストを設定
     *
     * @param searchContext 検索を再開するためのコンテキスト
     */
    void setSearchContext(const Char* searchContext)
    {
        ensureData().searchContext.emplace(searchContext);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGRESULT_HPP_