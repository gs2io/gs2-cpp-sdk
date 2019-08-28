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

#ifndef GS2_EZ_LIMIT_EZLISTCOUNTERSRESULT_HPP_
#define GS2_EZ_LIMIT_EZLISTCOUNTERSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/limit/result/DescribeCountersResult.hpp>


namespace gs2 { namespace ez { namespace limit {

class EzListCountersResult : public gs2::Gs2Object
{
private:
    /** カウンターのリスト */
    List<EzCounter> m_Items;
    /** リストの続きを取得するためのページトークン */
    StringHolder m_NextPageToken;

public:
    EzListCountersResult(const gs2::limit::DescribeCountersResult& result) :
        m_NextPageToken(*result.getNextPageToken())
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzCounter(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::limit::DescribeCountersResult& result)
    {
        return
            result.getItems().has_value() &&
            result.getNextPageToken().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzCounter>& getItems() const
    {
        return m_Items;
    }

    List<EzCounter>& getItems()
    {
        return m_Items;
    }

    const gs2::StringHolder& getNextPageToken() const
    {
        return m_NextPageToken;
    }

    gs2::StringHolder& getNextPageToken()
    {
        return m_NextPageToken;
    }
};

typedef gs2::AsyncResult<EzListCountersResult> AsyncEzListCountersResult;

}}}

#endif //GS2_EZ_LIMIT_EZLISTCOUNTERSRESULT_HPP_