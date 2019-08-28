

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
    /** 商品名 */
    gs2::optional<StringHolder> m_Name;
    /** 商品のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 消費アクションリスト */
    gs2::optional<List<EzConsumeAction>> m_ConsumeActions;
    /** 入手アクションリスト */
    gs2::optional<List<EzAcquireAction>> m_AcquireActions;

public:
    EzSalesItem() = default;

    EzSalesItem(gs2::showcase::SalesItem salesItem) :
        m_Name(salesItem.getName()),
        m_Metadata(salesItem.getMetadata())
    {
        m_ConsumeActions.emplace();
        if (salesItem.getConsumeActions())
        {
            for (int i = 0; i < salesItem.getConsumeActions()->getCount(); ++i)
            {
                *m_ConsumeActions += EzConsumeAction((*salesItem.getConsumeActions())[i]);
            }
        }
        m_AcquireActions.emplace();
        if (salesItem.getAcquireActions())
        {
            for (int i = 0; i < salesItem.getAcquireActions()->getCount(); ++i)
            {
                *m_AcquireActions += EzAcquireAction((*salesItem.getAcquireActions())[i]);
            }
        }
    }

    gs2::showcase::SalesItem ToModel() const
    {
        gs2::showcase::SalesItem salesItem;
        salesItem.setName(*m_Name);
        salesItem.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::showcase::ConsumeAction> list;
            auto& consumeActions = *m_ConsumeActions;
            for (int i = 0; i < consumeActions.getCount(); ++i)
            {
                list += consumeActions[i].ToModel();
            }
            salesItem.setConsumeActions(list);
        }
        {
            gs2::List<gs2::showcase::AcquireAction> list;
            auto& acquireActions = *m_AcquireActions;
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

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return *m_ConsumeActions;
    }

    List<EzConsumeAction>& getConsumeActions()
    {
        return *m_ConsumeActions;
    }

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return *m_AcquireActions;
    }

    List<EzAcquireAction>& getAcquireActions()
    {
        return *m_AcquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setConsumeActions(const List<EzConsumeAction>& consumeActions)
    {
        m_ConsumeActions = consumeActions;
    }

    void setConsumeActions(List<EzConsumeAction>&& consumeActions)
    {
        m_ConsumeActions = std::move(consumeActions);
    }

    void setAcquireActions(const List<EzAcquireAction>& acquireActions)
    {
        m_AcquireActions = acquireActions;
    }

    void setAcquireActions(List<EzAcquireAction>&& acquireActions)
    {
        m_AcquireActions = std::move(acquireActions);
    }

    EzSalesItem& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzSalesItem& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzSalesItem& withConsumeActions(const List<EzConsumeAction>& consumeActions)
    {
        setConsumeActions(consumeActions);
        return *this;
    }

    EzSalesItem& withConsumeActions(List<EzConsumeAction>&& consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    EzSalesItem& withAcquireActions(const List<EzAcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
        return *this;
    }

    EzSalesItem& withAcquireActions(List<EzAcquireAction>&& acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_SHOWCASE_EZSALESITEM_HPP_