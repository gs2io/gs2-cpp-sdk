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

#ifndef GS2_EZ_MISSION_EZLISTCOMPLETESRESULT_HPP_
#define GS2_EZ_MISSION_EZLISTCOMPLETESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/DescribeCompletesResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzListCompletesResult : public gs2::Gs2Object
{
private:
    /** 達成状況のリスト */
    List<EzComplete> m_Items;
    /** リストの続きを取得するためのページトークン */
    optional<StringHolder> m_NextPageToken;

public:
    EzListCompletesResult(const gs2::mission::DescribeCompletesResult& result) :
        m_NextPageToken(result.getNextPageToken())
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzComplete(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::mission::DescribeCompletesResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzComplete>& getItems() const
    {
        return m_Items;
    }

    List<EzComplete>& getItems()
    {
        return m_Items;
    }

    const optional<gs2::StringHolder>& getNextPageToken() const
    {
        return m_NextPageToken;
    }

    optional<gs2::StringHolder>& getNextPageToken()
    {
        return m_NextPageToken;
    }
};

typedef gs2::AsyncResult<EzListCompletesResult> AsyncEzListCompletesResult;

}}}

#endif //GS2_EZ_MISSION_EZLISTCOMPLETESRESULT_HPP_