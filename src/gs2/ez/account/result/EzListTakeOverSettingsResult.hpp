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

#ifndef GS2_EZ_ACCOUNT_EZLISTTAKEOVERSETTINGSRESULT_HPP_
#define GS2_EZ_ACCOUNT_EZLISTTAKEOVERSETTINGSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/account/result/DescribeTakeOversResult.hpp>


namespace gs2 { namespace ez { namespace account {

class EzListTakeOverSettingsResult : public gs2::Gs2Object
{
private:
    /** 引き継ぎ設定のリスト */
    List<EzTakeOver> m_Items;
    /** リストの続きを取得するためのページトークン */
    StringHolder m_NextPageToken;

public:
    EzListTakeOverSettingsResult(const gs2::account::DescribeTakeOversResult& result) :
        m_NextPageToken(*result.getNextPageToken())
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzTakeOver(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::account::DescribeTakeOversResult& result)
    {
        return
            result.getItems().has_value() &&
            result.getNextPageToken().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzTakeOver>& getItems() const
    {
        return m_Items;
    }

    List<EzTakeOver>& getItems()
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

typedef gs2::AsyncResult<EzListTakeOverSettingsResult> AsyncEzListTakeOverSettingsResult;

}}}

#endif //GS2_EZ_ACCOUNT_EZLISTTAKEOVERSETTINGSRESULT_HPP_