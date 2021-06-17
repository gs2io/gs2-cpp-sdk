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

#ifndef GS2_EZ_INBOX_EZRECEIVEGLOBALMESSAGERESULT_HPP_
#define GS2_EZ_INBOX_EZRECEIVEGLOBALMESSAGERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inbox/result/ReceiveGlobalMessageResult.hpp>


namespace gs2 { namespace ez { namespace inbox {

class EzReceiveGlobalMessageResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 受信したメッセージ一覧 */
        List<EzMessage> item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inbox::ReceiveGlobalMessageResult& receiveGlobalMessageResult)
        {
            {
                auto& list = *receiveGlobalMessageResult.getItem();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    item += EzMessage(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzReceiveGlobalMessageResult() = default;
    EzReceiveGlobalMessageResult(const EzReceiveGlobalMessageResult& result) = default;
    EzReceiveGlobalMessageResult(EzReceiveGlobalMessageResult&& result) = default;
    ~EzReceiveGlobalMessageResult() = default;

    EzReceiveGlobalMessageResult(gs2::inbox::ReceiveGlobalMessageResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzReceiveGlobalMessageResult& operator=(const EzReceiveGlobalMessageResult& result) = default;
    EzReceiveGlobalMessageResult& operator=(EzReceiveGlobalMessageResult&& result) = default;

    EzReceiveGlobalMessageResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzReceiveGlobalMessageResult);
    }

    static bool isConvertible(const gs2::inbox::ReceiveGlobalMessageResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzMessage>& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzReceiveGlobalMessageResult> AsyncEzReceiveGlobalMessageResult;

}}}

#endif //GS2_EZ_INBOX_EZRECEIVEGLOBALMESSAGERESULT_HPP_