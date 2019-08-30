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

#ifndef GS2_EZ_LOTTERY_EZDESCRIBEBOXESRESULT_HPP_
#define GS2_EZ_LOTTERY_EZDESCRIBEBOXESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/lottery/result/DescribeBoxesResult.hpp>


namespace gs2 { namespace ez { namespace lottery {

class EzDescribeBoxesResult : public gs2::Gs2Object
{
private:
    /** ボックスのリスト */
    List<EzBox> m_Items;
    /** リストの続きを取得するためのページトークン */
    optional<StringHolder> m_NextPageToken;

public:
    EzDescribeBoxesResult(const gs2::lottery::DescribeBoxesResult& result) :
        m_NextPageToken(result.getNextPageToken())
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzBox(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::lottery::DescribeBoxesResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzBox>& getItems() const
    {
        return m_Items;
    }

    List<EzBox>& getItems()
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

typedef gs2::AsyncResult<EzDescribeBoxesResult> AsyncEzDescribeBoxesResult;

}}}

#endif //GS2_EZ_LOTTERY_EZDESCRIBEBOXESRESULT_HPP_