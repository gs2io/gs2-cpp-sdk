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

#ifndef GS2_LOCK_CONTROL_GETMUTEXBYUSERIDRESULT_HPP_
#define GS2_LOCK_CONTROL_GETMUTEXBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lock/model/model.hpp>
#include <memory>

namespace gs2 { namespace lock
{

/**
 * ユーザIDを指定してミューテックスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMutexByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミューテックス */
        optional<Mutex> item;

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
    GetMutexByUserIdResult() = default;
    GetMutexByUserIdResult(const GetMutexByUserIdResult& getMutexByUserIdResult) = default;
    GetMutexByUserIdResult(GetMutexByUserIdResult&& getMutexByUserIdResult) = default;
    ~GetMutexByUserIdResult() = default;

    GetMutexByUserIdResult& operator=(const GetMutexByUserIdResult& getMutexByUserIdResult) = default;
    GetMutexByUserIdResult& operator=(GetMutexByUserIdResult&& getMutexByUserIdResult) = default;

    GetMutexByUserIdResult deepCopy() const;

    const GetMutexByUserIdResult* operator->() const
    {
        return this;
    }

    GetMutexByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * ミューテックスを取得
     *
     * @return ミューテックス
     */
    const optional<Mutex>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ミューテックスを設定
     *
     * @param item ミューテックス
     */
    void setItem(Mutex item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetMutexByUserIdResult> AsyncGetMutexByUserIdResult;

} }

#endif //GS2_LOCK_CONTROL_GETMUTEXBYUSERIDRESULT_HPP_