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

#ifndef GS2_GATEWAY_CONTROL_SETFIREBASETOKENBYUSERIDRESULT_HPP_
#define GS2_GATEWAY_CONTROL_SETFIREBASETOKENBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/gateway/model/model.hpp>
#include <memory>

namespace gs2 { namespace gateway
{

/**
 * ユーザIDを指定してデバイストークンを設定 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SetFirebaseTokenByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したFirebaseデバイストークン */
        optional<FirebaseToken> item;

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
    SetFirebaseTokenByUserIdResult() = default;
    SetFirebaseTokenByUserIdResult(const SetFirebaseTokenByUserIdResult& setFirebaseTokenByUserIdResult) = default;
    SetFirebaseTokenByUserIdResult(SetFirebaseTokenByUserIdResult&& setFirebaseTokenByUserIdResult) = default;
    ~SetFirebaseTokenByUserIdResult() = default;

    SetFirebaseTokenByUserIdResult& operator=(const SetFirebaseTokenByUserIdResult& setFirebaseTokenByUserIdResult) = default;
    SetFirebaseTokenByUserIdResult& operator=(SetFirebaseTokenByUserIdResult&& setFirebaseTokenByUserIdResult) = default;

    SetFirebaseTokenByUserIdResult deepCopy() const;

    const SetFirebaseTokenByUserIdResult* operator->() const
    {
        return this;
    }

    SetFirebaseTokenByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 作成したFirebaseデバイストークンを取得
     *
     * @return 作成したFirebaseデバイストークン
     */
    const optional<FirebaseToken>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したFirebaseデバイストークンを設定
     *
     * @param item 作成したFirebaseデバイストークン
     */
    void setItem(FirebaseToken item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<SetFirebaseTokenByUserIdResult> AsyncSetFirebaseTokenByUserIdResult;

} }

#endif //GS2_GATEWAY_CONTROL_SETFIREBASETOKENBYUSERIDRESULT_HPP_