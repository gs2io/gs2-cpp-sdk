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

#ifndef GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_
#define GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/script/model/model.hpp>
#include <memory>

namespace gs2 { namespace script
{

/**
 * スクリプトを実行します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DebugInvokeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータスコード */
        optional<Int32> code;
        /** 戻り値 */
        optional<StringHolder> result;
        /** スクリプトの実行時間(ミリ秒) */
        optional<Int32> executeTime;
        /** 費用の計算対象となった時間(秒) */
        optional<Int32> charged;
        /** 標準出力の内容のリスト */
        optional<List<StringHolder>> output;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DebugInvokeResult() = default;
    DebugInvokeResult(const DebugInvokeResult& debugInvokeResult) = default;
    DebugInvokeResult(DebugInvokeResult&& debugInvokeResult) = default;
    ~DebugInvokeResult() = default;

    DebugInvokeResult& operator=(const DebugInvokeResult& debugInvokeResult) = default;
    DebugInvokeResult& operator=(DebugInvokeResult&& debugInvokeResult) = default;

    DebugInvokeResult deepCopy() const;

    const DebugInvokeResult* operator->() const
    {
        return this;
    }

    DebugInvokeResult* operator->()
    {
        return this;
    }
    /**
     * ステータスコードを取得
     *
     * @return ステータスコード
     */
    const optional<Int32>& getCode() const
    {
        return ensureData().code;
    }

    /**
     * ステータスコードを設定
     *
     * @param code ステータスコード
     */
    void setCode(Int32 code)
    {
        ensureData().code.emplace(code);
    }

    /**
     * 戻り値を取得
     *
     * @return 戻り値
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * 戻り値を設定
     *
     * @param result 戻り値
     */
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * スクリプトの実行時間(ミリ秒)を取得
     *
     * @return スクリプトの実行時間(ミリ秒)
     */
    const optional<Int32>& getExecuteTime() const
    {
        return ensureData().executeTime;
    }

    /**
     * スクリプトの実行時間(ミリ秒)を設定
     *
     * @param executeTime スクリプトの実行時間(ミリ秒)
     */
    void setExecuteTime(Int32 executeTime)
    {
        ensureData().executeTime.emplace(executeTime);
    }

    /**
     * 費用の計算対象となった時間(秒)を取得
     *
     * @return 費用の計算対象となった時間(秒)
     */
    const optional<Int32>& getCharged() const
    {
        return ensureData().charged;
    }

    /**
     * 費用の計算対象となった時間(秒)を設定
     *
     * @param charged 費用の計算対象となった時間(秒)
     */
    void setCharged(Int32 charged)
    {
        ensureData().charged.emplace(charged);
    }

    /**
     * 標準出力の内容のリストを取得
     *
     * @return 標準出力の内容のリスト
     */
    const optional<List<StringHolder>>& getOutput() const
    {
        return ensureData().output;
    }

    /**
     * 標準出力の内容のリストを設定
     *
     * @param output 標準出力の内容のリスト
     */
    void setOutput(List<StringHolder> output)
    {
        ensureData().output.emplace(std::move(output));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DebugInvokeResult> AsyncDebugInvokeResult;

} }

#endif //GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_