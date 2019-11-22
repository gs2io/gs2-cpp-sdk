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

#ifndef GS2_EXCHANGE_MODEL_CONSUMEACTION_HPP_
#define GS2_EXCHANGE_MODEL_CONSUMEACTION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace exchange {

/**
 * 消費アクション
 *
 * @author Game Server Services, Inc.
 *
 */
class ConsumeAction : public Gs2Object
{
    friend bool operator!=(const ConsumeAction& lhs, const ConsumeAction& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプタスクで実行するアクションの種類 */
        optional<StringHolder> action;
        /** 消費リクエストのJSON */
        optional<StringHolder> request;

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
    ConsumeAction() = default;
    ConsumeAction(const ConsumeAction& consumeAction) = default;
    ConsumeAction(ConsumeAction&& consumeAction) = default;
    ~ConsumeAction() = default;

    ConsumeAction& operator=(const ConsumeAction& consumeAction) = default;
    ConsumeAction& operator=(ConsumeAction&& consumeAction) = default;

    ConsumeAction deepCopy() const;

    const ConsumeAction* operator->() const
    {
        return this;
    }

    ConsumeAction* operator->()
    {
        return this;
    }
    /**
     * スタンプタスクで実行するアクションの種類を取得
     *
     * @return スタンプタスクで実行するアクションの種類
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * スタンプタスクで実行するアクションの種類を設定
     *
     * @param action スタンプタスクで実行するアクションの種類
     */
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * スタンプタスクで実行するアクションの種類を設定
     *
     * @param action スタンプタスクで実行するアクションの種類
     */
    ConsumeAction& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    /**
     * 消費リクエストのJSONを取得
     *
     * @return 消費リクエストのJSON
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * 消費リクエストのJSONを設定
     *
     * @param request 消費リクエストのJSON
     */
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * 消費リクエストのJSONを設定
     *
     * @param request 消費リクエストのJSON
     */
    ConsumeAction& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ConsumeAction& lhs, const ConsumeAction& lhr);

inline bool operator==(const ConsumeAction& lhs, const ConsumeAction& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXCHANGE_MODEL_CONSUMEACTION_HPP_