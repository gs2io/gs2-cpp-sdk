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

#ifndef GS2_EZ_INBOX_EZREADRESULT_HPP_
#define GS2_EZ_INBOX_EZREADRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inbox/result/ReadMessageResult.hpp>


namespace gs2 { namespace ez { namespace inbox {

class EzReadResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** メッセージ */
        EzMessage item;
        /** スタンプシート */
        StringHolder stampSheet;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inbox::ReadMessageResult& readMessageResult) :
            item(*readMessageResult.getItem()),
            stampSheet(*readMessageResult.getStampSheet())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzReadResult() = default;
    EzReadResult(const EzReadResult& result) = default;
    EzReadResult(EzReadResult&& result) = default;
    ~EzReadResult() = default;

    EzReadResult(gs2::inbox::ReadMessageResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzReadResult& operator=(const EzReadResult& result) = default;
    EzReadResult& operator=(EzReadResult&& result) = default;

    EzReadResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzReadResult);
    }

    static bool isConvertible(const gs2::inbox::ReadMessageResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getStampSheet().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzMessage& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getStampSheet() const
    {
        return ensureData().stampSheet;
    }
};

typedef gs2::AsyncResult<EzReadResult> AsyncEzReadResult;

}}}

#endif //GS2_EZ_INBOX_EZREADRESULT_HPP_