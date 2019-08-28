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
    /** メッセージ */
    EzMessage m_Item;
    /** スタンプシート */
    StringHolder m_StampSheet;

public:
    EzReadResult(const gs2::inbox::ReadMessageResult& result) :
        m_Item(*result.getItem()),
        m_StampSheet(*result.getStampSheet())
    {
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
        return m_Item;
    }

    EzMessage& getItem()
    {
        return m_Item;
    }

    const gs2::StringHolder& getStampSheet() const
    {
        return m_StampSheet;
    }

    gs2::StringHolder& getStampSheet()
    {
        return m_StampSheet;
    }
};

typedef gs2::AsyncResult<EzReadResult> AsyncEzReadResult;

}}}

#endif //GS2_EZ_INBOX_EZREADRESULT_HPP_