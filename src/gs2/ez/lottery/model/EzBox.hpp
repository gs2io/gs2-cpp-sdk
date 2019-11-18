

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 排出確率テーブル名 */
        gs2::optional<StringHolder> prizeTableName;
        /** 排出済み景品のインデックスのリスト */
        gs2::optional<List<Int32>> drawnIndexes;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            prizeTableName(data.prizeTableName)
        {
            if (data.drawnIndexes)
            {
                drawnIndexes = data.drawnIndexes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::lottery::Box& box) :
            prizeTableName(box.getPrizeTableName()),
            drawnIndexes(box.getDrawnIndexes())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzBox() = default;
    EzBox(const EzBox& ezBox) = default;
    EzBox(EzBox&& ezBox) = default;
    ~EzBox() = default;

    EzBox(gs2::lottery::Box box) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(box)
    {}

    EzBox& operator=(const EzBox& ezBox) = default;
    EzBox& operator=(EzBox&& ezBox) = default;

    EzBox deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBox);
    }

    gs2::lottery::Box ToModel() const
    {
        gs2::lottery::Box box;
        box.setPrizeTableName(getPrizeTableName());
        box.setDrawnIndexes(getDrawnIndexes());
        return box;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getPrizeTableName() const
    {
        return *ensureData().prizeTableName;
    }

    const List<Int32>& getDrawnIndexes() const
    {
        return *ensureData().drawnIndexes;
    }

    // ========================================
    //   Setters
    // ========================================

    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName = std::move(prizeTableName);
    }

    void setDrawnIndexes(List<Int32> drawnIndexes)
    {
        ensureData().drawnIndexes = std::move(drawnIndexes);
    }

    EzBox& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
        return *this;
    }

    EzBox& withDrawnIndexes(List<Int32> drawnIndexes)
    {
        setDrawnIndexes(std::move(drawnIndexes));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZBOX_HPP_