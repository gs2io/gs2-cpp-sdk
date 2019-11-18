

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

#ifndef GS2_EZ_SHOWCASE_MODEL_EZSALESITEM_HPP_
#define GS2_EZ_SHOWCASE_MODEL_EZSALESITEM_HPP_

#include <gs2/showcase/model/SalesItem.hpp>
#include "EzConsumeAction.hpp"
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace showcase {

class EzSalesItem : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 商品名 */
        gs2::optional<StringHolder> name;
        /** 商品のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 消費アクションリスト */
        gs2::optional<List<EzConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        gs2::optional<List<EzAcquireAction>> acquireActions;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata)
        {
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::showcase::SalesItem& salesItem) :
            name(salesItem.getName()),
            metadata(salesItem.getMetadata())
        {
            consumeActions.emplace();
            if (salesItem.getConsumeActions())
            {
                for (int i = 0; i < salesItem.getConsumeActions()->getCount(); ++i)
                {
                    *consumeActions += EzConsumeAction((*salesItem.getConsumeActions())[i]);
                }
            }
            acquireActions.emplace();
            if (salesItem.getAcquireActions())
            {
                for (int i = 0; i < salesItem.getAcquireActions()->getCount(); ++i)
                {
                    *acquireActions += EzAcquireAction((*salesItem.getAcquireActions())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSalesItem() = default;
    EzSalesItem(const EzSalesItem& ezSalesItem) = default;
    EzSalesItem(EzSalesItem&& ezSalesItem) = default;
    ~EzSalesItem() = default;

    EzSalesItem(gs2::showcase::SalesItem salesItem) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(salesItem)
    {}

    EzSalesItem& operator=(const EzSalesItem& ezSalesItem) = default;
    EzSalesItem& operator=(EzSalesItem&& ezSalesItem) = default;

    EzSalesItem deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSalesItem);
    }

    gs2::showcase::SalesItem ToModel() const
    {
        gs2::showcase::SalesItem salesItem;
        salesItem.setName(getName());
        salesItem.setMetadata(getMetadata());
        {
            gs2::List<gs2::showcase::ConsumeAction> list;
            auto& consumeActions = getConsumeActions();
            for (int i = 0; i < consumeActions.getCount(); ++i)
            {
                list += consumeActions[i].ToModel();
            }
            salesItem.setConsumeActions(list);
        }
        {
            gs2::List<gs2::showcase::AcquireAction> list;
            auto& acquireActions = getAcquireActions();
            for (int i = 0; i < acquireActions.getCount(); ++i)
            {
                list += acquireActions[i].ToModel();
            }
            salesItem.setAcquireActions(list);
        }
        return salesItem;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return *ensureData().consumeActions;
    }

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return *ensureData().acquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setConsumeActions(List<EzConsumeAction> consumeActions)
    {
        ensureData().consumeActions = std::move(consumeActions);
    }

    void setAcquireActions(List<EzAcquireAction> acquireActions)
    {
        ensureData().acquireActions = std::move(acquireActions);
    }

    EzSalesItem& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzSalesItem& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzSalesItem& withConsumeActions(List<EzConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    EzSalesItem& withAcquireActions(List<EzAcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSALESITEM_HPP_