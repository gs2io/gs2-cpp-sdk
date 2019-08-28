

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

#ifndef GS2_EZ_DISTRIBUTOR_MODEL_EZDISTRIBUTERESOURCE_HPP_
#define GS2_EZ_DISTRIBUTOR_MODEL_EZDISTRIBUTERESOURCE_HPP_

#include <gs2/distributor/model/DistributeResource.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzDistributeResource : public gs2::Gs2Object
{
private:
    /** スタンプシートで実行するアクションの種類 */
    gs2::optional<StringHolder> m_Action;
    /** 加算リクエストのJSON */
    gs2::optional<StringHolder> m_Request;

public:
    EzDistributeResource() = default;

    EzDistributeResource(gs2::distributor::DistributeResource distributeResource) :
        m_Action(distributeResource.getAction()),
        m_Request(distributeResource.getRequest())
    {
    }

    gs2::distributor::DistributeResource ToModel() const
    {
        gs2::distributor::DistributeResource distributeResource;
        distributeResource.setAction(*m_Action);
        distributeResource.setRequest(*m_Request);
        return distributeResource;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getAction() const
    {
        return *m_Action;
    }

    gs2::StringHolder& getAction()
    {
        return *m_Action;
    }

    const gs2::StringHolder& getRequest() const
    {
        return *m_Request;
    }

    gs2::StringHolder& getRequest()
    {
        return *m_Request;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAction(Char* action)
    {
        m_Action.emplace(action);
    }

    void setRequest(Char* request)
    {
        m_Request.emplace(request);
    }

    EzDistributeResource& withAction(Char* action)
    {
        setAction(action);
        return *this;
    }

    EzDistributeResource& withRequest(Char* request)
    {
        setRequest(request);
        return *this;
    }
};

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZDISTRIBUTERESOURCE_HPP_