// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <memory>

#include "flutter/fml/macros.h"
#include "impeller/entity/contents/contents.h"
#include "impeller/entity/contents/solid_stroke_contents.h"
#include "impeller/entity/entity.h"
#include "impeller/geometry/color.h"

namespace impeller {

struct Paint {
  enum class Style {
    kFill,
    kStroke,
  };

  Color color = Color::Black();
  Scalar stroke_width = 0.0;
  SolidStrokeContents::Cap stroke_cap = SolidStrokeContents::Cap::kButt;
  SolidStrokeContents::Join stroke_join = SolidStrokeContents::Join::kMiter;
  Scalar stroke_miter = 4.0;
  Style style = Style::kFill;
  Entity::BlendMode blend_mode = Entity::BlendMode::kSourceOver;
  std::shared_ptr<Contents> contents;

  std::shared_ptr<Contents> CreateContentsForEntity() const;
};

}  // namespace impeller
