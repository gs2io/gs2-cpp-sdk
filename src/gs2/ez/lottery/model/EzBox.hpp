

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

#ifndef GS2_EZ_LOTTERY_MODEL_EZBOX_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZBOX_HPP_

#include <gs2/lottery/model/Box.hpp>


namespace gs2 { namespace ez { namespace lottery {

class EzBox : public gs2::Gs2Object
{
private:
    /** 排出確率テーブル名 */
    gs2::optional<StringHolder> m_PrizeTableName;
    /** 排出済み景品のインデックスのリスト */
    gs2::optional<List<Int32>> m_DrawnIndexes;

public:
    EzBox() = default;

    EzBox(gs2::lottery::Box box) :
        m_PrizeTableName(box.getPrizeTableName()),
        m_DrawnIndexes(box.getDrawnIndexes())
    {
    }

    gs2::lottery::Box ToModel() const
    {
        gs2::lottery::Box box;
        box.setPrizeTableName(*m_PrizeTableName);
        box.setDrawnIndexes(*m_DrawnIndexes);
        return box;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getPrizeTableName() const
    {
        return *m_PrizeTableName;
    }

    gs2::StringHolder& getPrizeTableName()
    {
        return *m_PrizeTableName;
    }

    const List<Int32>& getDrawnIndexes() const
    {
        return *m_DrawnIndexes;
    }

    List<Int32>& getDrawnIndexes()
    {
        return *m_DrawnIndexes;
    }

    // ========================================
    //   Setters
    // ========================================

    void setPrizeTableName(Char* prizeTableName)
    {
        m_PrizeTableName.emplace(prizeTableName);
    }

    void setDrawnIndexes(const List<Int32>& drawnIndexes)
    {
        m_DrawnIndexes = drawnIndexes;
    }

    void setDrawnIndexes(List<Int32>&& drawnIndexes)
    {
        m_DrawnIndexes = std::move(drawnIndexes);
    }

    EzBox& withPrizeTableName(Char* prizeTableName)
    {
        setPrizeTableName(prizeTableName);
        return *this;
    }

    EzBox& withDrawnIndexes(const List<Int32>& drawnIndexes)
    {
        setDrawnIndexes(drawnIndexes);
        return *this;
    }

    EzBox& withDrawnIndexes(List<Int32>&& drawnIndexes)
    {
        setDrawnIndexes(std::move(drawnIndexes));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZBOX_HPP_