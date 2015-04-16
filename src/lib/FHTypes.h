/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libfreehand project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef __FHTYPES_H__
#define __FHTYPES_H__

#include <vector>

namespace libfreehand
{

struct FHPageInfo
{
  double m_minX;
  double m_minY;
  double m_maxX;
  double m_maxY;
  FHPageInfo() : m_minX(0.0), m_minY(0.0), m_maxX(0.0), m_maxY(0.0) {}
};

struct FHBlock
{
  unsigned m_layerListId;
  unsigned m_defaultLayerId;
  FHBlock() : m_layerListId(0), m_defaultLayerId(0) {}
  FHBlock(unsigned layerListId, unsigned defaultLayerId)
    : m_layerListId(layerListId), m_defaultLayerId(defaultLayerId) {}
};

struct FHTail
{
  unsigned m_blockId;
  unsigned m_propLstId;
  unsigned m_fontId;
  FHTail() : m_blockId(0), m_propLstId(0), m_fontId(0) {}
};

struct FHList
{
  unsigned m_listType;
  std::vector<unsigned> m_elements;
  FHList() : m_listType(0), m_elements() {}
};

} // namespace libfreehand

#endif /* __FHTYPES_H__ */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */