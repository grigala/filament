/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAMENT_DETAULS_FRAMESKIPPER_H
#define TNT_FILAMENT_DETAULS_FRAMESKIPPER_H

#include "details/Fence.h"

#include <deque>

namespace filament {
namespace details {

class FEngine;

class FrameSkipper {
public:
    explicit FrameSkipper(FEngine& engine, size_t latency = 2) noexcept;
    ~FrameSkipper() noexcept;

    void endFrame() noexcept;

    bool skipFrameNeeded() const noexcept;

private:
    FEngine& mEngine;
    mutable std::deque<FFence *> mFences;
    mutable int mExtraSkipCount = 0;
};

} // namespace details
} // namespace filament

#endif // TNT_FILAMENT_DETAULS_FRAMESKIPPER_H
