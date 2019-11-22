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

#ifndef GS2_INBOX_CONTROL_GETMESSAGEBYUSERIDRESULT_HPP_
#define GS2_INBOX_CONTROL_GETMESSAGEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inbox/model/model.hpp>
#include <memory>

namespace gs2 { namespace inbox
{

/**
 * ユーザーIDを指定してメッセージを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMessageByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<Message> item;

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
    GetMessageByUserIdResult() = default;
    GetMessageByUserIdResult(const GetMessageByUserIdResult& getMessageByUserIdResult) = default;
    GetMessageByUserIdResult(GetMessageByUserIdResult&& getMessageByUserIdResult) = default;
    ~GetMessageByUserIdResult() = default;

    GetMessageByUserIdResult& operator=(const GetMessageByUserIdResult& getMessageByUserIdResult) = default;
    GetMessageByUserIdResult& operator=(GetMessageByUserIdResult&& getMessageByUserIdResult) = default;

    GetMessageByUserIdResult deepCopy() const;

    const GetMessageByUserIdResult* operator->() const
    {
        return this;
    }

    GetMessageByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<Message>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * メッセージを設定
     *
     * @param item メッセージ
     */
    void setItem(Message item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetMessageByUserIdResult> AsyncGetMessageByUserIdResult;

} }

#endif //GS2_INBOX_CONTROL_GETMESSAGEBYUSERIDRESULT_HPP_