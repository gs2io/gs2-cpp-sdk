# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gs2-cpp-sdk-core

LOCAL_CPPFLAGS = -DGS2_CRYPTOPP_DISABLE_SSE4 -DGS2_CRYPTOPP_MANUALLY_INSTANTIATE_TEMPLATES

LOCAL_SRC_FILES :=
        AbstractGs2Client.cpp \
        Gs2Constant.cpp \
        Gs2Object.cpp \
        control/Gs2BasicRequest.cpp \
        json/Allocator.cpp \
        json/JsonParser.cpp \
        json/JsonWriter.cpp \
        model/BasicGs2Credential.cpp \
        model/IGs2Credential.cpp \
        model/Region.cpp \
        util/Base64.cpp \
        util/DefaultAllocator.cpp \
        util/SignUtil.cpp \
        util/StringHolder.cpp \
        util/StringVariable.cpp \
        util/UrlEncoder.cpp \
        external/cryptopp/algparam.cpp \
        external/cryptopp/asn.cpp \
        external/cryptopp/cpu.cpp \
        external/cryptopp/cryptlib.cpp \
        external/cryptopp/filters.cpp \
        external/cryptopp/fips140.cpp \
        external/cryptopp/hmac.cpp \
        external/cryptopp/integer.cpp \
        external/cryptopp/iterhash.cpp \
        external/cryptopp/misc.cpp \
        external/cryptopp/mqueue.cpp \
        external/cryptopp/nbtheory.cpp \
        external/cryptopp/osrng.cpp \
        external/cryptopp/pubkey.cpp \
        external/cryptopp/queue.cpp \
        external/cryptopp/rdtables.cpp \
        external/cryptopp/rijndael-simd.cpp \
        external/cryptopp/rijndael.cpp \
        external/cryptopp/rng.cpp \
        external/cryptopp/sha.cpp \
        external/cryptopp/sse-simd.cpp

include $(BUILD_STATIC_LIBRARY)
