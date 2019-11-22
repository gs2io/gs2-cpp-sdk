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

#ifndef GS2_EXCHANGE_MODEL_ACQUIREACTION_HPP_
#define GS2_EXCHANGE_MODEL_ACQUIREACTION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace exchange {

/**
 * 入手アクション
 *
 * @author Game Server Services, Inc.
 *
 */
class AcquireAction : public Gs2Object
{
    friend bool operator!=(const AcquireAction& lhs, const AcquireAction& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプシートで実行するアクションの種類 */
        optional<StringHolder> action;
        /** 入手リクエストのJSON */
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
    AcquireAction() = default;
    AcquireAction(const AcquireAction& acquireAction) = default;
    AcquireAction(AcquireAction&& acquireAction) = default;
    ~AcquireAction() = default;

    AcquireAction& operator=(const AcquireAction& acquireAction) = default;
    AcquireAction& operator=(AcquireAction&& acquireAction) = default;

    AcquireAction deepCopy() const;

    const AcquireAction* operator->() const
    {
        return this;
    }

    AcquireAction* operator->()
    {
        return this;
    }
    /**
     * スタンプシートで実行するアクションの種類を取得
     *
     * @return スタンプシートで実行するアクションの種類
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    AcquireAction& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    /**
     * 入手リクエストのJSONを取得
     *
     * @return 入手リクエストのJSON
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * 入手リクエストのJSONを設定
     *
     * @param request 入手リクエストのJSON
     */
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * 入手リクエストのJSONを設定
     *
     * @param request 入手リクエストのJSON
     */
    AcquireAction& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const AcquireAction& lhs, const AcquireAction& lhr);

inline bool operator==(const AcquireAction& lhs, const AcquireAction& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXCHANGE_MODEL_ACQUIREACTION_HPP_