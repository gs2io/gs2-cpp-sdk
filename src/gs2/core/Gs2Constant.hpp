/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_CORE_GS2CONSTANT_HPP_
#define GS2_CORE_GS2CONSTANT_HPP_

#include "common.hpp"

GS2_START_OF_NAMESPACE

class Gs2Constant {

public:
    /** リクエストのタイムスタンプの有効レンジ(±sec) */
    static const Int32 REQUEST_VALID_TIME_RANGE;

    /** リトライ回数 */
    static const Int32 RETRY_NUM;

    /** リトライウェイト(msec) */
    static const Int32 RETRY_WAIT;

    /** APIエンドポイント */
    static const Char* ENDPOINT_HOST;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_GS2CONSTANT_HPP_
