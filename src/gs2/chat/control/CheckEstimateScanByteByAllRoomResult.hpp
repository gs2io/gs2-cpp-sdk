/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_CHAT_CONTROL_CHECKESTIMATESCANBYTEBYALLROOMRESULT_HPP_
#define GS2_CHAT_CONTROL_CHECKESTIMATESCANBYTEBYALLROOMRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class CheckEstimateScanByteByAllRoomResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 予想されるスキャンサイズ */
        optional<Int64> scanSize;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            scanSize(data.scanSize)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            scanSize(std::move(data.scanSize))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "scanSize") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->scanSize = jsonValue.GetInt64();
                }
            }
        }
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
    CheckEstimateScanByteByAllRoomResult() :
        m_pData(nullptr)
    {}

    CheckEstimateScanByteByAllRoomResult(const CheckEstimateScanByteByAllRoomResult& checkEstimateScanByteByAllRoomResult) :
        Gs2Object(checkEstimateScanByteByAllRoomResult),
        m_pData(checkEstimateScanByteByAllRoomResult.m_pData != nullptr ? new Data(*checkEstimateScanByteByAllRoomResult.m_pData) : nullptr)
    {}

    CheckEstimateScanByteByAllRoomResult(CheckEstimateScanByteByAllRoomResult&& checkEstimateScanByteByAllRoomResult) :
        Gs2Object(std::move(checkEstimateScanByteByAllRoomResult)),
        m_pData(checkEstimateScanByteByAllRoomResult.m_pData)
    {
        checkEstimateScanByteByAllRoomResult.m_pData = nullptr;
    }

    ~CheckEstimateScanByteByAllRoomResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CheckEstimateScanByteByAllRoomResult& operator=(const CheckEstimateScanByteByAllRoomResult& checkEstimateScanByteByAllRoomResult)
    {
        Gs2Object::operator=(checkEstimateScanByteByAllRoomResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*checkEstimateScanByteByAllRoomResult.m_pData);

        return *this;
    }

    CheckEstimateScanByteByAllRoomResult& operator=(CheckEstimateScanByteByAllRoomResult&& checkEstimateScanByteByAllRoomResult)
    {
        Gs2Object::operator=(std::move(checkEstimateScanByteByAllRoomResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = checkEstimateScanByteByAllRoomResult.m_pData;
        checkEstimateScanByteByAllRoomResult.m_pData = nullptr;

        return *this;
    }

    const CheckEstimateScanByteByAllRoomResult* operator->() const
    {
        return this;
    }

    CheckEstimateScanByteByAllRoomResult* operator->()
    {
        return this;
    }


    /**
     * 予想されるスキャンサイズを取得
     *
     * @return 予想されるスキャンサイズ
     */
    const optional<Int64>& getScanSize() const
    {
        return ensureData().scanSize;
    }

    /**
     * 予想されるスキャンサイズを設定
     *
     * @param scanSize 予想されるスキャンサイズ
     */
    void setScanSize(Int64 scanSize)
    {
        ensureData().scanSize.emplace(scanSize);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_CONTROL_CHECKESTIMATESCANBYTEBYALLROOMRESULT_HPP_