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

#ifndef GS2_LOTTERY_CONTROL_DELETEGROUPREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_DELETEGROUPREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LotteryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * グループの種類を削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteGroupRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** グループ名 */
        optional<StringHolder> groupName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    DeleteGroupRequest() :
        m_pData(nullptr)
    {}

    DeleteGroupRequest(const DeleteGroupRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lottery(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteGroupRequest(DeleteGroupRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lottery(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteGroupRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteGroupRequest& operator=(const DeleteGroupRequest& deleteGroupRequest)
    {
        Gs2BasicRequest::operator=(deleteGroupRequest);
        Gs2Lottery::operator=(deleteGroupRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteGroupRequest.m_pData);

        return *this;
    }

    DeleteGroupRequest& operator=(DeleteGroupRequest&& deleteGroupRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteGroupRequest));
        Gs2Lottery::operator=(std::move(deleteGroupRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteGroupRequest.m_pData;
        deleteGroupRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteGroupRequest* operator->() const
    {
        return this;
    }

    DeleteGroupRequest* operator->()
    {
        return this;
    }
    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    DeleteGroupRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteGroupRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    DeleteGroupRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    DeleteGroupRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteGroupRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_DELETEGROUPREQUEST_HPP_