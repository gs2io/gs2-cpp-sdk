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

#ifndef GS2_EZ_LOTTERY_MODEL_EZACQUIREACTION_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZACQUIREACTION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace lottery {

class AcquireAction;

}

namespace ez { namespace lottery {

class EzAcquireAction : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタンプシートで実行するアクションの種類 */
        StringHolder action;
        /** 入手リクエストのJSON */
        StringHolder request;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::lottery::AcquireAction& acquireAction);
        Data(const gs2::optional<gs2::lottery::AcquireAction>& acquireAction);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAcquireAction() = default;
    EzAcquireAction(const EzAcquireAction& ezAcquireAction) = default;
    EzAcquireAction(EzAcquireAction&& ezAcquireAction) = default;
    ~EzAcquireAction() = default;

    EzAcquireAction(gs2::lottery::AcquireAction acquireAction);
    EzAcquireAction(gs2::optional<gs2::lottery::AcquireAction> acquireAction);

    EzAcquireAction& operator=(const EzAcquireAction& ezAcquireAction) = default;
    EzAcquireAction& operator=(EzAcquireAction&& ezAcquireAction) = default;

    EzAcquireAction deepCopy() const;

    gs2::lottery::AcquireAction ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getAction() const
    {
        return ensureData().action;
    }

    const StringHolder& getRequest() const
    {
        return ensureData().request;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAction(StringHolder action)
    {
        ensureData().action = std::move(action);
    }

    void setRequest(StringHolder request)
    {
        ensureData().request = std::move(request);
    }

    EzAcquireAction& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    EzAcquireAction& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZACQUIREACTION_HPP_