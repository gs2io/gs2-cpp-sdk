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

#ifndef GS2_TIMER_MODEL_TIMER_HPP_
#define GS2_TIMER_MODEL_TIMER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace timer {

/**
 * タイマー
 *
 * @author Game Server Services, Inc.
 *
 */
class Timer : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** タイマーGRN */
        optional<StringHolder> timerId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** タイマープールGRN */
        optional<StringHolder> timerPoolId;
        /** コールバックHTTPメソッド */
        optional<StringHolder> callbackMethod;
        /** コールバックURL */
        optional<StringHolder> callbackUrl;
        /** コールバックボディ(PUT/POSTのときのみ有効) */
        optional<StringHolder> callbackBody;
        /** コールバック時間(エポック秒) */
        optional<Int32> executeTime;
        /** 最大リトライ回数 */
        optional<Int32> retryMax;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            timerId(data.timerId),
            ownerId(data.ownerId),
            timerPoolId(data.timerPoolId),
            callbackMethod(data.callbackMethod),
            callbackUrl(data.callbackUrl),
            callbackBody(data.callbackBody),
            executeTime(data.executeTime),
            retryMax(data.retryMax),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            timerId(std::move(data.timerId)),
            ownerId(std::move(data.ownerId)),
            timerPoolId(std::move(data.timerPoolId)),
            callbackMethod(std::move(data.callbackMethod)),
            callbackUrl(std::move(data.callbackUrl)),
            callbackBody(std::move(data.callbackBody)),
            executeTime(std::move(data.executeTime)),
            retryMax(std::move(data.retryMax)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "timerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->timerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "timerPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->timerPoolId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "callbackMethod") == 0) {
                if (jsonValue.IsString())
                {
                    this->callbackMethod.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "callbackUrl") == 0) {
                if (jsonValue.IsString())
                {
                    this->callbackUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "callbackBody") == 0) {
                if (jsonValue.IsString())
                {
                    this->callbackBody.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "executeTime") == 0) {
                if (jsonValue.IsInt())
                {
                    this->executeTime = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "retryMax") == 0) {
                if (jsonValue.IsInt())
                {
                    this->retryMax = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
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
    Timer() :
        m_pData(nullptr)
    {}

    Timer(const Timer& timer) :
        Gs2Object(timer),
        m_pData(timer.m_pData != nullptr ? new Data(*timer.m_pData) : nullptr)
    {}

    Timer(Timer&& timer) :
        Gs2Object(std::move(timer)),
        m_pData(timer.m_pData)
    {
        timer.m_pData = nullptr;
    }

    ~Timer()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Timer& operator=(const Timer& timer)
    {
        Gs2Object::operator=(timer);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*timer.m_pData);

        return *this;
    }

    Timer& operator=(Timer&& timer)
    {
        Gs2Object::operator=(std::move(timer));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = timer.m_pData;
        timer.m_pData = nullptr;

        return *this;
    }

    const Timer* operator->() const
    {
        return this;
    }

    Timer* operator->()
    {
        return this;
    }


    /**
     * タイマーGRNを取得
     *
     * @return タイマーGRN
     */
    const optional<StringHolder>& getTimerId() const
    {
        return ensureData().timerId;
    }

    /**
     * タイマーGRNを設定
     *
     * @param timerId タイマーGRN
     */
    void setTimerId(const Char* timerId)
    {
        ensureData().timerId.emplace(timerId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * タイマープールGRNを取得
     *
     * @return タイマープールGRN
     */
    const optional<StringHolder>& getTimerPoolId() const
    {
        return ensureData().timerPoolId;
    }

    /**
     * タイマープールGRNを設定
     *
     * @param timerPoolId タイマープールGRN
     */
    void setTimerPoolId(const Char* timerPoolId)
    {
        ensureData().timerPoolId.emplace(timerPoolId);
    }

    /**
     * コールバックHTTPメソッドを取得
     *
     * @return コールバックHTTPメソッド
     */
    const optional<StringHolder>& getCallbackMethod() const
    {
        return ensureData().callbackMethod;
    }

    /**
     * コールバックHTTPメソッドを設定
     *
     * @param callbackMethod コールバックHTTPメソッド
     */
    void setCallbackMethod(const Char* callbackMethod)
    {
        ensureData().callbackMethod.emplace(callbackMethod);
    }

    /**
     * コールバックURLを取得
     *
     * @return コールバックURL
     */
    const optional<StringHolder>& getCallbackUrl() const
    {
        return ensureData().callbackUrl;
    }

    /**
     * コールバックURLを設定
     *
     * @param callbackUrl コールバックURL
     */
    void setCallbackUrl(const Char* callbackUrl)
    {
        ensureData().callbackUrl.emplace(callbackUrl);
    }

    /**
     * コールバックボディ(PUT/POSTのときのみ有効)を取得
     *
     * @return コールバックボディ(PUT/POSTのときのみ有効)
     */
    const optional<StringHolder>& getCallbackBody() const
    {
        return ensureData().callbackBody;
    }

    /**
     * コールバックボディ(PUT/POSTのときのみ有効)を設定
     *
     * @param callbackBody コールバックボディ(PUT/POSTのときのみ有効)
     */
    void setCallbackBody(const Char* callbackBody)
    {
        ensureData().callbackBody.emplace(callbackBody);
    }

    /**
     * コールバック時間(エポック秒)を取得
     *
     * @return コールバック時間(エポック秒)
     */
    const optional<Int32>& getExecuteTime() const
    {
        return ensureData().executeTime;
    }

    /**
     * コールバック時間(エポック秒)を設定
     *
     * @param executeTime コールバック時間(エポック秒)
     */
    void setExecuteTime(Int32 executeTime)
    {
        ensureData().executeTime.emplace(executeTime);
    }

    /**
     * 最大リトライ回数を取得
     *
     * @return 最大リトライ回数
     */
    const optional<Int32>& getRetryMax() const
    {
        return ensureData().retryMax;
    }

    /**
     * 最大リトライ回数を設定
     *
     * @param retryMax 最大リトライ回数
     */
    void setRetryMax(Int32 retryMax)
    {
        ensureData().retryMax.emplace(retryMax);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_TIMER_MODEL_TIMER_HPP_