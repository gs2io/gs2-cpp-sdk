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

#ifndef GS2_EZ_JOBQUEUE_MODEL_EZJOBENTRY_HPP_
#define GS2_EZ_JOBQUEUE_MODEL_EZJOBENTRY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace jobQueue {

class JobEntry;

}

namespace ez { namespace jobQueue {

class EzJobEntry : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スクリプト のGRN */
        gs2::optional<StringHolder> scriptId;
        /** 引数 */
        gs2::optional<StringHolder> args;
        /** 最大試行回数 */
        gs2::optional<Int32> maxTryCount;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::jobQueue::JobEntry& jobEntry);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzJobEntry() = default;
    EzJobEntry(const EzJobEntry& ezJobEntry) = default;
    EzJobEntry(EzJobEntry&& ezJobEntry) = default;
    ~EzJobEntry() = default;

    EzJobEntry(gs2::jobQueue::JobEntry jobEntry);

    EzJobEntry& operator=(const EzJobEntry& ezJobEntry) = default;
    EzJobEntry& operator=(EzJobEntry&& ezJobEntry) = default;

    EzJobEntry deepCopy() const;

    gs2::jobQueue::JobEntry ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getScriptId() const
    {
        return *ensureData().scriptId;
    }

    const StringHolder& getArgs() const
    {
        return *ensureData().args;
    }

    Int32 getMaxTryCount() const
    {
        return *ensureData().maxTryCount;
    }

    // ========================================
    //   Setters
    // ========================================

    void setScriptId(StringHolder scriptId)
    {
        ensureData().scriptId = std::move(scriptId);
    }

    void setArgs(StringHolder args)
    {
        ensureData().args = std::move(args);
    }

    void setMaxTryCount(Int32 maxTryCount)
    {
        ensureData().maxTryCount = maxTryCount;
    }

    EzJobEntry& withScriptId(StringHolder scriptId)
    {
        setScriptId(std::move(scriptId));
        return *this;
    }

    EzJobEntry& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }

    EzJobEntry& withMaxTryCount(Int32 maxTryCount)
    {
        setMaxTryCount(maxTryCount);
        return *this;
    }
};

}}}

#endif //GS2_EZ_JOBQUEUE_EZJOBENTRY_HPP_