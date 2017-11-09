//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2017 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <cctype>
#include <algorithm>
#include <string>

#include "WebmDecoderFactory.h"
#include "WebmDecoder.h"

using namespace musik::core::sdk;

inline bool endsWith(const std::string& s, const std::string& suffix) {
    return
        s.size() >= suffix.size() &&
        s.rfind(suffix) == (s.size() - suffix.size());
}

WebmDecoderFactory::WebmDecoderFactory() {
}

WebmDecoderFactory::~WebmDecoderFactory() {
}

void WebmDecoderFactory::Release() {
    delete this;
}

IDecoder* WebmDecoderFactory::CreateDecoder() {
    return new WebmDecoder();
}

bool WebmDecoderFactory::CanHandle(const char* type) const {
    std::string str(type);
    std::transform(str.begin(), str.end(), str.begin(), tolower);

    return
        endsWith(type, ".webm") ||
        /* TODO: add support for playing just the audio track from video webm files */
        str.find("audio/webm") != std::string::npos;
}